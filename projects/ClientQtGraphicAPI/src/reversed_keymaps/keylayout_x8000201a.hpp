#pragma once

#include "keylayout_r.hpp"

namespace x8000201a{ 

const static int LCID = 0x201a;

const static char * const locale_name = "bs-Cy";

const Keylayout_r::KeyLayoutMap_t noMod
{
    { 0x001b, 0x1 },
    { 0x0031, 0x2 },
    { 0x0032, 0x3 },
    { 0x0033, 0x4 },
    { 0x0034, 0x5 },
    { 0x0035, 0x6 },
    { 0x0036, 0x7 },
    { 0x0037, 0x8 },
    { 0x0038, 0x9 },
    { 0x0039, 0xa },
    { 0x0030, 0xb },
    { 0x0027, 0xc },
    { 0x002b, 0xd },
    { 0x0008, 0xe },
    { 0x0009, 0xf },
    { 0x0459, 0x10 },
    { 0x045a, 0x11 },
    { 0x0435, 0x12 },
    { 0x0440, 0x13 },
    { 0x0442, 0x14 },
    { 0x0437, 0x15 },
    { 0x0443, 0x16 },
    { 0x0438, 0x17 },
    { 0x043e, 0x18 },
    { 0x043f, 0x19 },
    { 0x0448, 0x1a },
    { 0x0452, 0x1b },
    { 0x000d, 0x1c },
    { 0x0430, 0x1e },
    { 0x0441, 0x1f },
    { 0x0434, 0x20 },
    { 0x0444, 0x21 },
    { 0x0433, 0x22 },
    { 0x0445, 0x23 },
    { 0x0458, 0x24 },
    { 0x043a, 0x25 },
    { 0x043b, 0x26 },
    { 0x0447, 0x27 },
    { 0x045b, 0x28 },
    { 0x0060, 0x29 },
    { 0x0436, 0x2b },
    { 0x0455, 0x2c },
    { 0x045f, 0x2d },
    { 0x0446, 0x2e },
    { 0x0432, 0x2f },
    { 0x0431, 0x30 },
    { 0x043d, 0x31 },
    { 0x043c, 0x32 },
    { 0x002c, 0x33 },
    { 0x002e, 0x34 },
    { 0x002d, 0x35 },
    { 0x002a, 0x37 },
    { 0x0020, 0x39 },
    { 0x0037, 0x47 },
    { 0x0038, 0x48 },
    { 0x0039, 0x49 },
    { 0x002d, 0x4a },
    { 0x0034, 0x4b },
    { 0x0035, 0x4c },
    { 0x0036, 0x4d },
    { 0x002b, 0x4e },
    { 0x0031, 0x4f },
    { 0x0032, 0x50 },
    { 0x0033, 0x51 },
    { 0x0030, 0x52 },
    { 0x002c, 0x53 },
    { 0x003c, 0x56 },
    { 0x002f, 0x62 },
    { 0x000d, 0x64 },
};


const Keylayout_r::KeyLayoutMap_t shift
{
    { 0x001b, 0x1 },
    { 0x0021, 0x2 },
    { 0x0022, 0x3 },
    { 0x0023, 0x4 },
    { 0x0024, 0x5 },
    { 0x0025, 0x6 },
    { 0x0026, 0x7 },
    { 0x002f, 0x8 },
    { 0x0028, 0x9 },
    { 0x0029, 0xa },
    { 0x003d, 0xb },
    { 0x003f, 0xc },
    { 0x002a, 0xd },
    { 0x0008, 0xe },
    { 0x0409, 0x10 },
    { 0x040a, 0x11 },
    { 0x0415, 0x12 },
    { 0x0420, 0x13 },
    { 0x0422, 0x14 },
    { 0x0417, 0x15 },
    { 0x0423, 0x16 },
    { 0x0418, 0x17 },
    { 0x041e, 0x18 },
    { 0x041f, 0x19 },
    { 0x0428, 0x1a },
    { 0x0402, 0x1b },
    { 0x000d, 0x1c },
    { 0x0410, 0x1e },
    { 0x0421, 0x1f },
    { 0x0414, 0x20 },
    { 0x0424, 0x21 },
    { 0x0413, 0x22 },
    { 0x0425, 0x23 },
    { 0x0408, 0x24 },
    { 0x041a, 0x25 },
    { 0x041b, 0x26 },
    { 0x0427, 0x27 },
    { 0x040b, 0x28 },
    { 0x007e, 0x29 },
    { 0x0416, 0x2b },
    { 0x0405, 0x2c },
    { 0x040f, 0x2d },
    { 0x0426, 0x2e },
    { 0x0412, 0x2f },
    { 0x0411, 0x30 },
    { 0x041d, 0x31 },
    { 0x041c, 0x32 },
    { 0x003b, 0x33 },
    { 0x003a, 0x34 },
    { 0x005f, 0x35 },
    { 0x002a, 0x37 },
    { 0x0020, 0x39 },
    { 0x002d, 0x4a },
    { 0x002b, 0x4e },
    { 0x002c, 0x53 },
    { 0x003e, 0x56 },
    { 0x007f, 0x63 },
    { 0x000d, 0x64 },
    { 0x002f, 0x68 },
};


const Keylayout_r::KeyLayoutMap_t altGr
{
    { 0x001b, 0x1 },
    { 0x005e, 0x4 },
    { 0x00b0, 0x6 },
    { 0x0008, 0xe },
    { 0x0009, 0xf },
    { 0x005c, 0x10 },
    { 0x007c, 0x11 },
    { 0x20ac, 0x12 },
    { 0x000d, 0x1c },
    { 0x005b, 0x21 },
    { 0x005d, 0x22 },
    { 0x0040, 0x2f },
    { 0x007b, 0x30 },
    { 0x007d, 0x31 },
    { 0x00a7, 0x32 },
    { 0x003c, 0x33 },
    { 0x003e, 0x34 },
    { 0x002a, 0x37 },
    { 0x002d, 0x4a },
    { 0x002b, 0x4e },
    { 0x002f, 0x62 },
    { 0x000d, 0x64 },
};


const Keylayout_r::KeyLayoutMap_t shiftAltGr
{
    { 0x001b, 0x1 },
    { 0x0008, 0xe },
    { 0x0009, 0xf },
    { 0x000d, 0x1c },
    { 0x002a, 0x37 },
    { 0x002d, 0x4a },
    { 0x002b, 0x4e },
    { 0x002f, 0x62 },
    { 0x000d, 0x64 },
};


const Keylayout_r::KeyLayoutMap_t capslock_noMod
{
    { 0x001b, 0x1 },
    { 0x0031, 0x2 },
    { 0x0032, 0x3 },
    { 0x0033, 0x4 },
    { 0x0034, 0x5 },
    { 0x0035, 0x6 },
    { 0x0036, 0x7 },
    { 0x0037, 0x8 },
    { 0x0038, 0x9 },
    { 0x0039, 0xa },
    { 0x0030, 0xb },
    { 0x0027, 0xc },
    { 0x002b, 0xd },
    { 0x0008, 0xe },
    { 0x0009, 0xf },
    { 0x0409, 0x10 },
    { 0x040a, 0x11 },
    { 0x0415, 0x12 },
    { 0x0420, 0x13 },
    { 0x0422, 0x14 },
    { 0x0417, 0x15 },
    { 0x0423, 0x16 },
    { 0x0418, 0x17 },
    { 0x041e, 0x18 },
    { 0x041f, 0x19 },
    { 0x0428, 0x1a },
    { 0x0402, 0x1b },
    { 0x000d, 0x1c },
    { 0x0410, 0x1e },
    { 0x0421, 0x1f },
    { 0x0414, 0x20 },
    { 0x0424, 0x21 },
    { 0x0413, 0x22 },
    { 0x0425, 0x23 },
    { 0x0408, 0x24 },
    { 0x041a, 0x25 },
    { 0x041b, 0x26 },
    { 0x0427, 0x27 },
    { 0x040b, 0x28 },
    { 0x0060, 0x29 },
    { 0x0416, 0x2b },
    { 0x0405, 0x2c },
    { 0x040f, 0x2d },
    { 0x0426, 0x2e },
    { 0x0412, 0x2f },
    { 0x0411, 0x30 },
    { 0x041d, 0x31 },
    { 0x041c, 0x32 },
    { 0x002c, 0x33 },
    { 0x002e, 0x34 },
    { 0x002d, 0x35 },
    { 0x002a, 0x37 },
    { 0x0020, 0x39 },
    { 0x002d, 0x4a },
    { 0x002b, 0x4e },
    { 0x002c, 0x53 },
    { 0x003c, 0x56 },
    { 0x002f, 0x62 },
    { 0x000d, 0x64 },
};


const Keylayout_r::KeyLayoutMap_t capslock_shift
{
    { 0x001b, 0x1 },
    { 0x0021, 0x2 },
    { 0x0022, 0x3 },
    { 0x0023, 0x4 },
    { 0x0024, 0x5 },
    { 0x0025, 0x6 },
    { 0x0026, 0x7 },
    { 0x002f, 0x8 },
    { 0x0028, 0x9 },
    { 0x0029, 0xa },
    { 0x003d, 0xb },
    { 0x003f, 0xc },
    { 0x002a, 0xd },
    { 0x0008, 0xe },
    { 0x0009, 0xf },
    { 0x0459, 0x10 },
    { 0x045a, 0x11 },
    { 0x0435, 0x12 },
    { 0x0440, 0x13 },
    { 0x0442, 0x14 },
    { 0x0437, 0x15 },
    { 0x0443, 0x16 },
    { 0x0438, 0x17 },
    { 0x043e, 0x18 },
    { 0x043f, 0x19 },
    { 0x0448, 0x1a },
    { 0x0452, 0x1b },
    { 0x000d, 0x1c },
    { 0x0430, 0x1e },
    { 0x0441, 0x1f },
    { 0x0434, 0x20 },
    { 0x0444, 0x21 },
    { 0x0433, 0x22 },
    { 0x0445, 0x23 },
    { 0x0458, 0x24 },
    { 0x043a, 0x25 },
    { 0x043b, 0x26 },
    { 0x0447, 0x27 },
    { 0x045b, 0x28 },
    { 0x007e, 0x29 },
    { 0x0436, 0x2b },
    { 0x0455, 0x2c },
    { 0x045f, 0x2d },
    { 0x0446, 0x2e },
    { 0x0432, 0x2f },
    { 0x0431, 0x30 },
    { 0x043d, 0x31 },
    { 0x043c, 0x32 },
    { 0x003b, 0x33 },
    { 0x003a, 0x34 },
    { 0x005f, 0x35 },
    { 0x002a, 0x37 },
    { 0x0020, 0x39 },
    { 0x002d, 0x4a },
    { 0x002b, 0x4e },
    { 0x002c, 0x53 },
    { 0x003e, 0x56 },
    { 0x002f, 0x62 },
    { 0x000d, 0x64 },
};


const Keylayout_r::KeyLayoutMap_t capslock_altGr
{
    { 0x001b, 0x1 },
    { 0x005e, 0x4 },
    { 0x00b0, 0x6 },
    { 0x0008, 0xe },
    { 0x0009, 0xf },
    { 0x005c, 0x10 },
    { 0x007c, 0x11 },
    { 0x20ac, 0x12 },
    { 0x000d, 0x1c },
    { 0x005b, 0x21 },
    { 0x005d, 0x22 },
    { 0x0040, 0x2f },
    { 0x007b, 0x30 },
    { 0x007d, 0x31 },
    { 0x00a7, 0x32 },
    { 0x003c, 0x33 },
    { 0x003e, 0x34 },
    { 0x002a, 0x37 },
    { 0x002d, 0x4a },
    { 0x002b, 0x4e },
    { 0x002f, 0x62 },
    { 0x000d, 0x64 },
};


const Keylayout_r::KeyLayoutMap_t capslock_shiftAltGr
{
    { 0x001b, 0x1 },
    { 0x0008, 0xe },
    { 0x0009, 0xf },
    { 0x000d, 0x1c },
    { 0x002a, 0x37 },
    { 0x002d, 0x4a },
    { 0x002b, 0x4e },
    { 0x002f, 0x62 },
    { 0x000d, 0x64 },
};


const Keylayout_r::KeyLayoutMap_t ctrl
{
    { 0x001b, 0x1 },
    { 0x0008, 0xe },
    { 0x0009, 0xf },
    { 0x000d, 0x1c },
    { 0x002a, 0x37 },
    { 0x0020, 0x39 },
    { 0x002d, 0x4a },
    { 0x002b, 0x4e },
    { 0x002f, 0x62 },
    { 0x000d, 0x64 },
};


const Keylayout_r::KeyLayoutMap_t deadkeys
{
    { 0x27, 0xc},
    { 0x43a, 0x45c},
    { 0x413, 0x403},
    { 0x433, 0x453},
    { 0x41a, 0x40c},
    { 0x20, 0x27},
};


const static uint8_t nbDeadkeys = 1;

}

static const Keylayout_r keylayout_x8000201a( x8000201a::LCID
                                 , x8000201a::locale_name
                                 , x8000201a::noMod
                                 , x8000201a::shift
                                 , x8000201a::altGr
                                 , x8000201a::shiftAltGr
                                 , x8000201a::ctrl
                                 , x8000201a::capslock_noMod
                                 , x8000201a::capslock_shift
                                 , x8000201a::capslock_altGr
                                 , x8000201a::capslock_shiftAltGr
                                 , x8000201a::deadkeys
                                 , x8000201a::nbDeadkeys

);

