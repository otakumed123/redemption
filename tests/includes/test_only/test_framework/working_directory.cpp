/*
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

Product name: redemption, a FLOSS RDP proxy
Copyright (C) Wallix 2010-2018
Author(s): Jonathan Poelen
*/
#include "test_only/test_framework/redemption_unit_tests.hpp"

#include "working_directory.hpp"
#include "utils/fileutils.hpp"
#include "utils/pp.hpp"
#include "utils/sugar/algostring.hpp"
#include "utils/sugar/scope_exit.hpp"
#include "cxx/compiler_version.hpp"
#include "cxx/cxx.hpp"

#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <string_view>

#include <cerrno>
#include <cassert>
#include <cstring>
#include <cstdio>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>


#include <boost/test/framework.hpp>


namespace
{
    std::string_view tempbase()
    {
        static const std::string base = []{
            std::string dirname;
            char const* s = std::getenv("TMPDIR");
            if (s) {
                if (*s) {
                    dirname = s;
                    if (dirname.back() != '/') {
                        dirname += '/';
                    }
                }
            }
            else {
                dirname = "/tmp/";
            }
            char buf[1024*4];
            auto dsz = dirname.size();
            dirname += getcwd(buf, sizeof(buf));
            for (char& c : array_view_char(dirname).array_from_offset(dsz)) {
                if (c == '/') {
                    c = ':';
                }
            }
            return dirname;
        }();
        return base;
    }

    std::string_view test_module_name()
    {
        static const std::string name = []{
            std::string modname = boost::unit_test::framework::master_test_suite().p_name.get();
            auto pos = std::find_if(modname.begin(), modname.end(), [](char c) {
                return c != '.' && c != '/';
            });
            pos = std::transform(pos, modname.end(), modname.begin(), [](char c){
                return c == '/' ? '-' : c;
            });
            modname.erase(pos, modname.end());
            return modname;
        }();
        return name;
    }

    std::string suffix_by_test(std::string_view name)
    {
        using namespace boost::unit_test::framework;
        std::string_view suffix_comp =
            "@" RED_PP_STRINGIFY(REDEMPTION_COMP_NAME) "-"
            REDEMPTION_COMP_STRING_VERSION;
        std::string test_module = master_test_suite().p_name.get();
        return str_concat(
            tempbase(),
            '@',
            current_test_case().p_name.get(),
            '@',
            test_module_name(),
            suffix_comp,
            "__"_av,
            name,
            '/'
        );
    }

#define WD_ERROR_S(ostream_expr) RED_ERROR("WorkingDirectory: " ostream_expr)
#define WD_ERROR(ostream_expr) RED_ERROR("WorkingDirectory: " << ostream_expr)
}

std::ostream& operator<<(std::ostream& out, WorkingFileBase const& wf)
{
    return out << wf.string();
}

WorkingFile::WorkingFile(std::string_view name)
: WorkingFileBase(suffix_by_test({}))
, start_error_count(RED_ERROR_COUNT)
{
    recursive_delete_directory(this->c_str());
    if (-1 == mkdir(this->c_str(), 0755) && errno != EEXIST) {
        WD_ERROR(strerror(errno) << ": " << this->string());
    }

    this->filename_ += name;
}

WorkingFile::~WorkingFile()
{
    if (!this->is_removed) {
        if (this->start_error_count == RED_ERROR_COUNT) {
            RED_TEST_FUNC(unlink, (this->filename_.c_str()) == 0);
        }
        else {
            RED_TEST_FUNC(file_exist, (this->filename_.c_str()));
        }
    }
}


WorkingDirectory::SubDirectory::SubDirectory(
    WorkingDirectory& wd, std::string fullpath, std::size_t dirname_pos)
: wd_(wd)
, fullpath(std::move(fullpath))
, dirname_pos(dirname_pos)
{}

std::string_view WorkingDirectory::SubDirectory::subdirname() const noexcept
{
    auto* s = this->fullpath.c_str();
    return {s + this->dirname_pos, this->fullpath.size() - this->dirname_pos};
}

WorkingFileBase WorkingDirectory::SubDirectory::add_file(std::string_view file)
{
    return this->wd_.add_file(str_concat(this->subdirname(), file));
}

WorkingDirectory::SubDirectory& WorkingDirectory::SubDirectory::add_files(
    std::initializer_list<std::string_view> files)
{
    for (auto sv : files) {
        (void)this->wd_.add_file_(str_concat(this->subdirname(), sv));
    }
    return *this;
}

WorkingDirectory::SubDirectory& WorkingDirectory::SubDirectory::remove_files(
    std::initializer_list<std::string_view> files)
{
    for (auto sv : files) {
        (void)this->wd_.remove_files({str_concat(this->subdirname(), sv)});
    }
    return *this;
}

std::string WorkingDirectory::SubDirectory::path_of(std::string_view path) const
{
    return this->wd_.path_of(str_concat(this->dirname(), path));
}


WorkingDirectory::Path::Path() noexcept = default;

WorkingDirectory::Path::Path(std::string name, int counter_id) noexcept
: name(std::move(name))
, type(this->name.back() == '/' ? Type::Directory : Type::File)
, counter_id(counter_id)
{}

bool WorkingDirectory::Path::operator == (Path const& other) const
{
    return this->name == other.name;
}


std::size_t WorkingDirectory::HashPath::operator()(Path const& path) const
{
    return std::hash<std::string>()(path.name);
}


WorkingDirectory::WorkingDirectory(std::string_view name)
: dirname_(suffix_by_test(name))
, start_error_count_(RED_ERROR_COUNT)
{
    recursive_delete_directory(this->dirname_);
    if (-1 == mkdir(this->dirname_, 0755) && errno != EEXIST) {
        WD_ERROR(strerror(errno) << ": " << this->dirname_);
    }
}

WorkingDirectory::SubDirectory WorkingDirectory::create_subdirectory(std::string_view dirname)
{
    auto pos = dirname.find_first_not_of('/');
    if (pos) {
        dirname = dirname.substr(pos+1);
    }

    if (dirname.empty()) {
        WD_ERROR_S("empty dirname");
    }

    if (dirname.back() == '/') {
        dirname = dirname.substr(0, dirname.size()-1);
    }

    auto path = this->add_file(str_concat(dirname, '/'));
    recursive_create_directory(path.c_str(), 0755, -1);
    return SubDirectory(*this, std::move(path), this->dirname_.size());
}

std::string const& WorkingDirectory::add_file_(std::string file)
{
    auto [it, b] = this->paths_.emplace(std::move(file), this->counter_id_);
    if (!b) {
        this->has_error_ = true;
        WD_ERROR(it->name << " already exists");
    }
    this->is_checked_ = false;
    return it->name;
}

void WorkingDirectory::remove_file_(std::string file)
{
    // transparent compare to C++20
    Path path(std::move(file), 0);
    if (!this->paths_.erase(path)) {
        this->has_error_ = true;
        WD_ERROR_S("unknown file '" << path.name << '\'');
    }
}

WorkingFileBase WorkingDirectory::add_file(std::string file)
{
    return WorkingFileBase(this->path_of(this->add_file_(std::move(file))));
}

WorkingDirectory& WorkingDirectory::add_files(std::initializer_list<std::string_view> files)
{
    for (auto const& sv : files) {
        this->add_file_(str_concat(sv));
    }
    return *this;
}

void WorkingDirectory::remove_file(std::string file)
{
    this->remove_file_(std::move(file));
    this->is_checked_ = false;
}

WorkingDirectory& WorkingDirectory::remove_files(std::initializer_list<std::string_view> files)
{
    for (auto const& sv : files) {
        this->remove_file_(str_concat(sv));
    }
    this->is_checked_ = false;
    return *this;
}

std::string WorkingDirectory::path_of(std::string_view path) const
{
    return str_concat(this->dirname_, path);
}

std::string WorkingDirectory::unmached_files()
{
    this->is_checked_ = true;
    ++this->counter_id_;

    Path path(this->dirname_, 0);
    Path filename;
    std::string err;

    auto unmached_files_impl = [&](auto recursive) -> bool
    {
        DIR * dir = opendir(path.name.c_str());
        if (!dir) {
            str_append(err, "opendir ", path.name, " error: ", strerror(errno), '\n');
            return false;
        }
        SCOPE_EXIT(closedir(dir));

        auto const original_path_len = path.name.size();
        auto const original_filename_len = filename.name.size();

        bool has_entry = false;

        while (struct dirent* ent = readdir(dir)) {
            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
                continue;
            }

            has_entry = true;

            path.name += ent->d_name;
            filename.name += ent->d_name;

            struct stat statbuf;
            auto const type = (!stat(path.name.c_str(), &statbuf) && S_ISDIR(statbuf.st_mode))
              ? Type::Directory : Type::File;

            if (type == Type::Directory) {
                path.name += '/';
                filename.name += '/';
            }

            auto it = this->paths_.find(filename);
            if (it == this->paths_.end()) {
                if (type == Type::Directory) {
                    if(!recursive(recursive)) {
                        str_append(err, path.name, " unknown\n");
                    }
                }
                else {
                    str_append(err, path.name, " unknown\n");
                }
            }
            else {
                it->counter_id = this->counter_id_;
                if (it->type != type) {
                    str_append(err, path.name, " unmatching file type\n");
                }
                else if (type == Type::Directory){
                    recursive(recursive);
                }
            }

            path.name.resize(original_path_len);
            filename.name.resize(original_filename_len);
        }

        return has_entry;
    };

    unmached_files_impl(unmached_files_impl);

    for (auto const& p : this->paths_) {
        if (p.counter_id != this->counter_id_) {
            str_append(err, p.name, ' ', this->path_of(p.name), " not found\n");
        }
    }

    this->has_error_ = this->has_error_ || !err.empty();

    return err;
}

WorkingDirectory::~WorkingDirectory() noexcept(false)
{
    if (!this->has_error_) {
        if (!this->is_checked_) {
            WD_ERROR_S("unchecked entries");
        }
        if (this->start_error_count_ == RED_ERROR_COUNT) {
            recursive_delete_directory(this->dirname_.c_str());
        }
    }
}