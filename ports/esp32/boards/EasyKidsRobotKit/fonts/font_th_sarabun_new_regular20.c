/**
* The MIT License (MIT)
*
* Copyright (c) 2015 Deaware System (http://www.deaware.com)
* Author: Surawut Aonjaiaow
*         Burin Sapsiri
*
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include "dw_font.h"

#define CONST_PREFIX           const

static CONST_PREFIX dw_font_bitmap_t symbol_20 = {
    .width = 0,
    .height = 0,
    .data = {
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_21 = {
    .width = 1,
    .height = 10,
    .data = {
        0xfe,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_22 = {
    .width = 3,
    .height = 3,
    .data = {
        0xb6,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_23 = {
    .width = 6,
    .height = 9,
    .data = {
        0x25,
        0x2f,
        0xd2,
        0x4b,
        0xf9,
        0x24,
        0x90,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_24 = {
    .width = 5,
    .height = 13,
    .data = {
        0x21,
        0x1d,
        0x18,
        0x41,
        0x83,
        0x0c,
        0x5c,
        0x42,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_25 = {
    .width = 10,
    .height = 10,
    .data = {
        0x61,
        0x24,
        0x89,
        0x22,
        0x50,
        0x95,
        0x9a,
        0x91,
        0x24,
        0x49,
        0x22,
        0x48,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_26 = {
    .width = 9,
    .height = 10,
    .data = {
        0x18,
        0x12,
        0x09,
        0x05,
        0x03,
        0x02,
        0x8a,
        0x25,
        0x0c,
        0xc2,
        0x3e,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_27 = {
    .width = 1,
    .height = 3,
    .data = {
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_28 = {
    .width = 3,
    .height = 12,
    .data = {
        0x2a,
        0x49,
        0x24,
        0x91,
        0x10,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_29 = {
    .width = 3,
    .height = 12,
    .data = {
        0x89,
        0x12,
        0x49,
        0x29,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2a = {
    .width = 5,
    .height = 5,
    .data = {
        0x51,
        0x3e,
        0x45,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2b = {
    .width = 7,
    .height = 7,
    .data = {
        0x10,
        0x20,
        0x47,
        0xf1,
        0x02,
        0x04,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2c = {
    .width = 1,
    .height = 3,
    .data = {
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2d = {
    .width = 4,
    .height = 1,
    .data = {
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2e = {
    .width = 1,
    .height = 1,
    .data = {
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_2f = {
    .width = 6,
    .height = 11,
    .data = {
        0x04,
        0x20,
        0x84,
        0x10,
        0x82,
        0x10,
        0x42,
        0x08,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_30 = {
    .width = 6,
    .height = 10,
    .data = {
        0x31,
        0x28,
        0x61,
        0x86,
        0x18,
        0x61,
        0x48,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_31 = {
    .width = 5,
    .height = 10,
    .data = {
        0x23,
        0x28,
        0x42,
        0x10,
        0x84,
        0x27,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_32 = {
    .width = 6,
    .height = 10,
    .data = {
        0x39,
        0x18,
        0x41,
        0x08,
        0x42,
        0x10,
        0x83,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_33 = {
    .width = 6,
    .height = 10,
    .data = {
        0x72,
        0x20,
        0x84,
        0x38,
        0x10,
        0x41,
        0x89,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_34 = {
    .width = 6,
    .height = 10,
    .data = {
        0x18,
        0xa4,
        0x92,
        0x8a,
        0x28,
        0xbf,
        0x08,
        0x20,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_35 = {
    .width = 6,
    .height = 10,
    .data = {
        0x3c,
        0x82,
        0x10,
        0x79,
        0x10,
        0x41,
        0x85,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_36 = {
    .width = 6,
    .height = 10,
    .data = {
        0x08,
        0xc4,
        0x10,
        0xfa,
        0x38,
        0x61,
        0x85,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_37 = {
    .width = 6,
    .height = 10,
    .data = {
        0xfc,
        0x10,
        0x84,
        0x10,
        0x42,
        0x08,
        0x20,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_38 = {
    .width = 5,
    .height = 10,
    .data = {
        0x74,
        0x63,
        0x17,
        0x46,
        0x31,
        0x8b,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_39 = {
    .width = 6,
    .height = 10,
    .data = {
        0x31,
        0x28,
        0x61,
        0x85,
        0x33,
        0x82,
        0x11,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3a = {
    .width = 1,
    .height = 6,
    .data = {
        0x84,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3b = {
    .width = 1,
    .height = 8,
    .data = {
        0x87,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3c = {
    .width = 6,
    .height = 8,
    .data = {
        0x04,
        0x23,
        0x30,
        0xc0,
        0x81,
        0x81,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3d = {
    .width = 6,
    .height = 3,
    .data = {
        0xfc,
        0x0f,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3e = {
    .width = 6,
    .height = 8,
    .data = {
        0x81,
        0x03,
        0x03,
        0x04,
        0x66,
        0x20,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_3f = {
    .width = 5,
    .height = 10,
    .data = {
        0x74,
        0x42,
        0x11,
        0x10,
        0x84,
        0x01,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_40 = {
    .width = 10,
    .height = 10,
    .data = {
        0x1f,
        0x08,
        0x24,
        0xe6,
        0x05,
        0x8f,
        0x64,
        0x59,
        0x16,
        0x3e,
        0x40,
        0x0f,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_41 = {
    .width = 8,
    .height = 10,
    .data = {
        0x18,
        0x18,
        0x24,
        0x24,
        0x24,
        0x42,
        0x7e,
        0x42,
        0x81,
        0x81,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_42 = {
    .width = 6,
    .height = 10,
    .data = {
        0xfa,
        0x18,
        0x61,
        0xfa,
        0x38,
        0x61,
        0x87,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_43 = {
    .width = 8,
    .height = 10,
    .data = {
        0x1f,
        0x60,
        0x40,
        0x80,
        0x80,
        0x80,
        0x80,
        0x40,
        0x60,
        0x1f,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_44 = {
    .width = 7,
    .height = 10,
    .data = {
        0xf9,
        0x0a,
        0x0c,
        0x18,
        0x30,
        0x60,
        0xc1,
        0x85,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_45 = {
    .width = 5,
    .height = 10,
    .data = {
        0xfc,
        0x21,
        0x0f,
        0xc2,
        0x10,
        0x87,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_46 = {
    .width = 6,
    .height = 10,
    .data = {
        0xfe,
        0x08,
        0x20,
        0x83,
        0xe8,
        0x20,
        0x82,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_47 = {
    .width = 8,
    .height = 10,
    .data = {
        0x1e,
        0x21,
        0x40,
        0x80,
        0x80,
        0x87,
        0x81,
        0x41,
        0x61,
        0x1f,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_48 = {
    .width = 7,
    .height = 10,
    .data = {
        0x83,
        0x06,
        0x0c,
        0x1f,
        0xf0,
        0x60,
        0xc1,
        0x83,
        0x04,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_49 = {
    .width = 1,
    .height = 10,
    .data = {
        0xff,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4a = {
    .width = 4,
    .height = 10,
    .data = {
        0x11,
        0x11,
        0x11,
        0x11,
        0x1e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4b = {
    .width = 7,
    .height = 10,
    .data = {
        0x85,
        0x12,
        0x45,
        0x0c,
        0x1c,
        0x24,
        0x44,
        0x85,
        0x04,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4c = {
    .width = 6,
    .height = 10,
    .data = {
        0x82,
        0x08,
        0x20,
        0x82,
        0x08,
        0x20,
        0x83,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4d = {
    .width = 9,
    .height = 10,
    .data = {
        0x80,
        0xe0,
        0xf0,
        0x78,
        0x5a,
        0x2d,
        0x16,
        0x53,
        0x29,
        0x94,
        0xc4,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4e = {
    .width = 7,
    .height = 10,
    .data = {
        0x83,
        0x86,
        0x8d,
        0x19,
        0x32,
        0x62,
        0xc3,
        0x87,
        0x04,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_4f = {
    .width = 9,
    .height = 10,
    .data = {
        0x1c,
        0x31,
        0x90,
        0x50,
        0x18,
        0x0c,
        0x06,
        0x02,
        0x82,
        0x63,
        0x0e,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_50 = {
    .width = 6,
    .height = 10,
    .data = {
        0xfa,
        0x18,
        0x61,
        0x8b,
        0xc8,
        0x20,
        0x82,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_51 = {
    .width = 9,
    .height = 11,
    .data = {
        0x1c,
        0x31,
        0x90,
        0x50,
        0x18,
        0x0c,
        0x06,
        0x02,
        0x82,
        0x63,
        0x0e,
        0x00,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_52 = {
    .width = 6,
    .height = 10,
    .data = {
        0xfa,
        0x18,
        0x61,
        0x8b,
        0xc8,
        0xa1,
        0x86,
        0x10,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_53 = {
    .width = 5,
    .height = 10,
    .data = {
        0x74,
        0x61,
        0x06,
        0x08,
        0x21,
        0x8b,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_54 = {
    .width = 8,
    .height = 10,
    .data = {
        0xff,
        0x10,
        0x10,
        0x10,
        0x10,
        0x10,
        0x10,
        0x10,
        0x10,
        0x10,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_55 = {
    .width = 7,
    .height = 10,
    .data = {
        0x83,
        0x06,
        0x0c,
        0x18,
        0x30,
        0x60,
        0xc1,
        0x44,
        0x70,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_56 = {
    .width = 8,
    .height = 10,
    .data = {
        0x81,
        0x42,
        0x42,
        0x42,
        0x24,
        0x24,
        0x24,
        0x18,
        0x18,
        0x18,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_57 = {
    .width = 12,
    .height = 10,
    .data = {
        0x86,
        0x18,
        0x61,
        0x86,
        0x14,
        0x92,
        0x49,
        0x24,
        0x92,
        0x29,
        0x42,
        0x94,
        0x30,
        0xc1,
        0x08,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_58 = {
    .width = 8,
    .height = 10,
    .data = {
        0x81,
        0x42,
        0x24,
        0x24,
        0x18,
        0x18,
        0x24,
        0x24,
        0x42,
        0x81,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_59 = {
    .width = 7,
    .height = 10,
    .data = {
        0x82,
        0x89,
        0x11,
        0x42,
        0x82,
        0x04,
        0x08,
        0x10,
        0x20,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5a = {
    .width = 8,
    .height = 10,
    .data = {
        0x7f,
        0x01,
        0x02,
        0x04,
        0x08,
        0x10,
        0x20,
        0x40,
        0x80,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5b = {
    .width = 3,
    .height = 12,
    .data = {
        0xf2,
        0x49,
        0x24,
        0x92,
        0x70,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5c = {
    .width = 6,
    .height = 11,
    .data = {
        0x82,
        0x04,
        0x10,
        0x20,
        0x81,
        0x04,
        0x08,
        0x20,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5d = {
    .width = 3,
    .height = 12,
    .data = {
        0xe4,
        0x92,
        0x49,
        0x24,
        0xf0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5e = {
    .width = 6,
    .height = 7,
    .data = {
        0x30,
        0xc5,
        0x12,
        0x4a,
        0x28,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_5f = {
    .width = 7,
    .height = 1,
    .data = {
        0xfe,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_60 = {
    .width = 2,
    .height = 2,
    .data = {
        0x90,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_61 = {
    .width = 5,
    .height = 7,
    .data = {
        0xf0,
        0x42,
        0xf8,
        0xc5,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_62 = {
    .width = 6,
    .height = 10,
    .data = {
        0x82,
        0x08,
        0x2e,
        0xc6,
        0x18,
        0x61,
        0xc6,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_63 = {
    .width = 6,
    .height = 7,
    .data = {
        0x39,
        0x18,
        0x20,
        0x81,
        0x03,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_64 = {
    .width = 6,
    .height = 10,
    .data = {
        0x04,
        0x10,
        0x5d,
        0x8e,
        0x18,
        0x61,
        0x8d,
        0xd0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_65 = {
    .width = 7,
    .height = 7,
    .data = {
        0x38,
        0x8a,
        0x0f,
        0xf8,
        0x08,
        0x0f,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_66 = {
    .width = 5,
    .height = 10,
    .data = {
        0x3a,
        0x11,
        0xe4,
        0x21,
        0x08,
        0x42,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_67 = {
    .width = 6,
    .height = 10,
    .data = {
        0x7e,
        0x28,
        0xa2,
        0x71,
        0x03,
        0x02,
        0x89,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_68 = {
    .width = 6,
    .height = 10,
    .data = {
        0x82,
        0x08,
        0x2e,
        0xc6,
        0x18,
        0x61,
        0x86,
        0x10,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_69 = {
    .width = 1,
    .height = 9,
    .data = {
        0xbf,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6a = {
    .width = 3,
    .height = 12,
    .data = {
        0x20,
        0x92,
        0x49,
        0x24,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6b = {
    .width = 5,
    .height = 10,
    .data = {
        0x84,
        0x21,
        0x19,
        0x53,
        0x14,
        0x94,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6c = {
    .width = 3,
    .height = 10,
    .data = {
        0x92,
        0x49,
        0x24,
        0x8c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6d = {
    .width = 11,
    .height = 7,
    .data = {
        0xb9,
        0xd8,
        0xc6,
        0x10,
        0xc2,
        0x18,
        0x43,
        0x08,
        0x61,
        0x08,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6e = {
    .width = 6,
    .height = 7,
    .data = {
        0xbb,
        0x18,
        0x61,
        0x86,
        0x18,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_6f = {
    .width = 6,
    .height = 7,
    .data = {
        0x7a,
        0x18,
        0x61,
        0x86,
        0x17,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_70 = {
    .width = 6,
    .height = 10,
    .data = {
        0xbb,
        0x18,
        0x61,
        0x87,
        0x2b,
        0xa0,
        0x82,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_71 = {
    .width = 6,
    .height = 10,
    .data = {
        0x76,
        0x38,
        0x61,
        0x86,
        0x37,
        0x41,
        0x04,
        0x10,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_72 = {
    .width = 3,
    .height = 7,
    .data = {
        0xba,
        0x49,
        0x20,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_73 = {
    .width = 4,
    .height = 7,
    .data = {
        0x78,
        0x86,
        0x11,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_74 = {
    .width = 4,
    .height = 9,
    .data = {
        0x44,
        0xf4,
        0x44,
        0x44,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_75 = {
    .width = 6,
    .height = 7,
    .data = {
        0x86,
        0x18,
        0x61,
        0x85,
        0x37,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_76 = {
    .width = 7,
    .height = 7,
    .data = {
        0x83,
        0x05,
        0x12,
        0x22,
        0x85,
        0x04,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_77 = {
    .width = 10,
    .height = 7,
    .data = {
        0x84,
        0x63,
        0x14,
        0xa9,
        0x4a,
        0x52,
        0x94,
        0xc2,
        0x10,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_78 = {
    .width = 6,
    .height = 7,
    .data = {
        0x85,
        0x23,
        0x04,
        0x31,
        0x28,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_79 = {
    .width = 7,
    .height = 10,
    .data = {
        0x83,
        0x09,
        0x12,
        0x42,
        0x86,
        0x04,
        0x10,
        0x21,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7a = {
    .width = 6,
    .height = 7,
    .data = {
        0x7c,
        0x21,
        0x08,
        0x21,
        0x0f,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7b = {
    .width = 3,
    .height = 12,
    .data = {
        0x69,
        0x24,
        0xb2,
        0x49,
        0x30,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7c = {
    .width = 1,
    .height = 14,
    .data = {
        0xff,
        0xfc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7d = {
    .width = 3,
    .height = 12,
    .data = {
        0xc9,
        0x24,
        0x9a,
        0x49,
        0x60,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7e = {
    .width = 7,
    .height = 2,
    .data = {
        0xe3,
        0x38,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_7f = {
    .width = 12,
    .height = 16,
    .data = {
        0xff,
        0xf8,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x1f,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b880 = {
    .width = 0,
    .height = 0,
    .data = {
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b881 = {
    .width = 6,
    .height = 8,
    .data = {
        0x72,
        0x24,
        0x61,
        0x86,
        0x18,
        0x61,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b882 = {
    .width = 7,
    .height = 8,
    .data = {
        0x73,
        0x96,
        0xaa,
        0x91,
        0x22,
        0x44,
        0x86,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b883 = {
    .width = 7,
    .height = 8,
    .data = {
        0x53,
        0x57,
        0xaf,
        0x91,
        0x22,
        0x44,
        0x8f,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b884 = {
    .width = 6,
    .height = 8,
    .data = {
        0x7a,
        0x3b,
        0x7d,
        0xc5,
        0x14,
        0x51,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b885 = {
    .width = 6,
    .height = 8,
    .data = {
        0x7a,
        0x9b,
        0x6d,
        0xf5,
        0x14,
        0x51,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b886 = {
    .width = 7,
    .height = 8,
    .data = {
        0x53,
        0x67,
        0x4e,
        0x92,
        0x2f,
        0x69,
        0xa1,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b887 = {
    .width = 5,
    .height = 8,
    .data = {
        0x11,
        0x47,
        0x14,
        0x94,
        0x61,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b888 = {
    .width = 6,
    .height = 8,
    .data = {
        0x3b,
        0x10,
        0x59,
        0x64,
        0x51,
        0x43,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b889 = {
    .width = 7,
    .height = 8,
    .data = {
        0x79,
        0x08,
        0x12,
        0x2a,
        0x4d,
        0x8e,
        0x92,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88a = {
    .width = 7,
    .height = 8,
    .data = {
        0x73,
        0x9a,
        0xaa,
        0x91,
        0x22,
        0x44,
        0x86,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88b = {
    .width = 7,
    .height = 8,
    .data = {
        0x53,
        0x5b,
        0x2e,
        0x91,
        0x22,
        0x44,
        0x86,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88c = {
    .width = 9,
    .height = 8,
    .data = {
        0x78,
        0xc2,
        0x59,
        0x30,
        0x98,
        0x4e,
        0x26,
        0xae,
        0x89,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88d = {
    .width = 8,
    .height = 11,
    .data = {
        0x71,
        0x89,
        0x69,
        0x89,
        0x89,
        0xc9,
        0xa9,
        0x46,
        0x00,
        0x0d,
        0x0e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88e = {
    .width = 8,
    .height = 12,
    .data = {
        0x1e,
        0x21,
        0x19,
        0x21,
        0x21,
        0x61,
        0xa1,
        0x41,
        0x09,
        0x1d,
        0x2f,
        0x11,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b88f = {
    .width = 8,
    .height = 12,
    .data = {
        0x1e,
        0x21,
        0x19,
        0x21,
        0x21,
        0x61,
        0xa1,
        0x41,
        0x11,
        0x31,
        0x57,
        0x2d,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b890 = {
    .width = 6,
    .height = 12,
    .data = {
        0x76,
        0x27,
        0x12,
        0xa9,
        0xa2,
        0x8e,
        0x01,
        0x6e,
        0xb6,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b891 = {
    .width = 8,
    .height = 8,
    .data = {
        0x52,
        0xab,
        0xcd,
        0xd5,
        0x29,
        0x29,
        0x31,
        0x31,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b892 = {
    .width = 9,
    .height = 8,
    .data = {
        0x48,
        0xda,
        0x69,
        0x3a,
        0x9a,
        0x4b,
        0x25,
        0x2e,
        0x89,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b893 = {
    .width = 9,
    .height = 8,
    .data = {
        0x70,
        0xc4,
        0x52,
        0x31,
        0x18,
        0x8e,
        0x4a,
        0xba,
        0x92,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b894 = {
    .width = 6,
    .height = 8,
    .data = {
        0x7a,
        0x19,
        0x6b,
        0x95,
        0x96,
        0x51,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b895 = {
    .width = 6,
    .height = 8,
    .data = {
        0x4a,
        0xda,
        0x75,
        0xb5,
        0x94,
        0x51,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b896 = {
    .width = 6,
    .height = 8,
    .data = {
        0x7a,
        0x16,
        0x71,
        0x87,
        0x1a,
        0x51,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b897 = {
    .width = 8,
    .height = 8,
    .data = {
        0x46,
        0xa6,
        0x6a,
        0x29,
        0x29,
        0x31,
        0x31,
        0x21,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b898 = {
    .width = 7,
    .height = 8,
    .data = {
        0xf3,
        0x19,
        0x80,
        0xe4,
        0x48,
        0x91,
        0x1c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b899 = {
    .width = 8,
    .height = 8,
    .data = {
        0x42,
        0xa2,
        0x62,
        0x22,
        0x22,
        0x22,
        0x2d,
        0x32,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89a = {
    .width = 8,
    .height = 8,
    .data = {
        0x41,
        0xa1,
        0x61,
        0x21,
        0x21,
        0x21,
        0x21,
        0x1e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89b = {
    .width = 8,
    .height = 11,
    .data = {
        0x01,
        0x01,
        0x01,
        0x41,
        0xa1,
        0x61,
        0x21,
        0x21,
        0x21,
        0x21,
        0x1e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89c = {
    .width = 6,
    .height = 8,
    .data = {
        0xc6,
        0x9c,
        0x61,
        0x86,
        0xdc,
        0xe1,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89d = {
    .width = 6,
    .height = 11,
    .data = {
        0x04,
        0x10,
        0x51,
        0xa7,
        0x18,
        0x61,
        0xb7,
        0x38,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89e = {
    .width = 8,
    .height = 8,
    .data = {
        0x49,
        0xa9,
        0x6d,
        0x35,
        0x35,
        0x33,
        0x21,
        0x21,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b89f = {
    .width = 8,
    .height = 11,
    .data = {
        0x01,
        0x01,
        0x01,
        0x49,
        0xa9,
        0x69,
        0x35,
        0x35,
        0x33,
        0x23,
        0x21,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a0 = {
    .width = 8,
    .height = 8,
    .data = {
        0x1e,
        0x61,
        0x11,
        0x21,
        0x21,
        0x61,
        0xa1,
        0x41,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a1 = {
    .width = 7,
    .height = 8,
    .data = {
        0x43,
        0x45,
        0x89,
        0x12,
        0x2c,
        0x6e,
        0xa3,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a2 = {
    .width = 6,
    .height = 8,
    .data = {
        0x67,
        0x5a,
        0x61,
        0x66,
        0x18,
        0x5e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a3 = {
    .width = 6,
    .height = 8,
    .data = {
        0x76,
        0x27,
        0x02,
        0x08,
        0x62,
        0x8c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a4 = {
    .width = 6,
    .height = 12,
    .data = {
        0x7a,
        0x16,
        0x61,
        0x87,
        0x1a,
        0x51,
        0x04,
        0x10,
        0x41,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a5 = {
    .width = 6,
    .height = 8,
    .data = {
        0x7a,
        0x13,
        0x53,
        0x87,
        0x1a,
        0x51,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a6 = {
    .width = 8,
    .height = 12,
    .data = {
        0x1e,
        0x61,
        0x11,
        0x21,
        0x21,
        0x61,
        0xa1,
        0x41,
        0x01,
        0x01,
        0x01,
        0x01,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a7 = {
    .width = 6,
    .height = 8,
    .data = {
        0x7a,
        0x10,
        0x41,
        0x04,
        0x31,
        0x42,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a8 = {
    .width = 6,
    .height = 9,
    .data = {
        0x05,
        0xe8,
        0xed,
        0xb6,
        0x94,
        0x51,
        0x44,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8a9 = {
    .width = 9,
    .height = 8,
    .data = {
        0x41,
        0x50,
        0x9a,
        0x46,
        0xb2,
        0xf1,
        0x08,
        0x84,
        0x3c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8aa = {
    .width = 6,
    .height = 9,
    .data = {
        0x05,
        0xe8,
        0xc5,
        0x6e,
        0x1c,
        0x69,
        0x44,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ab = {
    .width = 8,
    .height = 8,
    .data = {
        0x42,
        0xa5,
        0x62,
        0x25,
        0x29,
        0x29,
        0x31,
        0x21,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ac = {
    .width = 9,
    .height = 9,
    .data = {
        0x00,
        0xa1,
        0xa9,
        0x4c,
        0x62,
        0x91,
        0x68,
        0xd4,
        0x66,
        0x21,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ad = {
    .width = 7,
    .height = 8,
    .data = {
        0x79,
        0x08,
        0x8a,
        0x96,
        0x28,
        0x50,
        0x9e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ae = {
    .width = 6,
    .height = 8,
    .data = {
        0x76,
        0x2f,
        0x92,
        0xab,
        0x28,
        0x9c,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8af = {
    .width = 6,
    .height = 8,
    .data = {
        0x4e,
        0xd6,
        0x41,
        0x04,
        0x10,
        0x41,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b0 = {
    .width = 6,
    .height = 8,
    .data = {
        0x46,
        0x97,
        0x80,
        0x01,
        0x1a,
        0x5e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b1 = {
    .width = 6,
    .height = 3,
    .data = {
        0x46,
        0x97,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b2 = {
    .width = 5,
    .height = 8,
    .data = {
        0x74,
        0x42,
        0x10,
        0x84,
        0x21,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b3 = {
    .width = 8,
    .height = 12,
    .data = {
        0x40,
        0xa0,
        0x40,
        0x00,
        0x0e,
        0x11,
        0x01,
        0x01,
        0x01,
        0x01,
        0x01,
        0x01,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b4 = {
    .width = 6,
    .height = 3,
    .data = {
        0x7a,
        0x1f,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b5 = {
    .width = 6,
    .height = 4,
    .data = {
        0x05,
        0xd8,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b6 = {
    .width = 6,
    .height = 4,
    .data = {
        0x0d,
        0xd8,
        0xbe,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b7 = {
    .width = 6,
    .height = 4,
    .data = {
        0x15,
        0xd8,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b8 = {
    .width = 2,
    .height = 4,
    .data = {
        0xf5,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8b9 = {
    .width = 4,
    .height = 4,
    .data = {
        0xdd,
        0x57,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8ba = {
    .width = 1,
    .height = 1,
    .data = {
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8bb = {
    .width = 12,
    .height = 16,
    .data = {
        0xff,
        0xf8,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x1f,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8bc = {
    .width = 12,
    .height = 16,
    .data = {
        0xff,
        0xf8,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x1f,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8bd = {
    .width = 12,
    .height = 16,
    .data = {
        0xff,
        0xf8,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x1f,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8be = {
    .width = 12,
    .height = 16,
    .data = {
        0xff,
        0xf8,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x1f,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b8bf = {
    .width = 6,
    .height = 11,
    .data = {
        0x23,
        0xc8,
        0xa2,
        0x8b,
        0xe8,
        0x61,
        0x8d,
        0xc2,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b980 = {
    .width = 3,
    .height = 8,
    .data = {
        0x92,
        0x49,
        0xaa,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b981 = {
    .width = 6,
    .height = 8,
    .data = {
        0x92,
        0x49,
        0x24,
        0x93,
        0x6b,
        0x52,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b982 = {
    .width = 6,
    .height = 13,
    .data = {
        0x66,
        0x66,
        0x04,
        0x10,
        0x41,
        0x04,
        0x10,
        0x41,
        0x85,
        0x08,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b983 = {
    .width = 6,
    .height = 13,
    .data = {
        0x73,
        0x2a,
        0x94,
        0x10,
        0x41,
        0x04,
        0x10,
        0x41,
        0x85,
        0x08,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b984 = {
    .width = 6,
    .height = 13,
    .data = {
        0x92,
        0xc5,
        0x04,
        0x10,
        0x41,
        0x04,
        0x10,
        0x41,
        0x85,
        0x08,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b985 = {
    .width = 5,
    .height = 12,
    .data = {
        0x74,
        0x42,
        0x10,
        0x84,
        0x21,
        0x08,
        0x42,
        0x10,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b986 = {
    .width = 6,
    .height = 11,
    .data = {
        0x4a,
        0xdc,
        0x69,
        0x44,
        0x10,
        0x41,
        0x04,
        0x10,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b987 = {
    .width = 5,
    .height = 5,
    .data = {
        0x08,
        0x5d,
        0x5d,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b988 = {
    .width = 1,
    .height = 2,
    .data = {
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b989 = {
    .width = 5,
    .height = 4,
    .data = {
        0x45,
        0x55,
        0xc0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98a = {
    .width = 6,
    .height = 3,
    .data = {
        0x66,
        0x5d,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98b = {
    .width = 3,
    .height = 3,
    .data = {
        0x5d,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98c = {
    .width = 4,
    .height = 4,
    .data = {
        0x16,
        0xcc,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98d = {
    .width = 3,
    .height = 3,
    .data = {
        0x55,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98e = {
    .width = 4,
    .height = 5,
    .data = {
        0x74,
        0xa8,
        0xe0,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b98f = {
    .width = 7,
    .height = 7,
    .data = {
        0x38,
        0x8a,
        0xee,
        0x3c,
        0x6f,
        0x8e,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b990 = {
    .width = 7,
    .height = 6,
    .data = {
        0x7d,
        0x06,
        0x0c,
        0x18,
        0x2f,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b991 = {
    .width = 7,
    .height = 6,
    .data = {
        0x38,
        0x8a,
        0x4d,
        0x59,
        0xae,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b992 = {
    .width = 9,
    .height = 9,
    .data = {
        0x80,
        0x20,
        0x10,
        0x09,
        0x65,
        0xca,
        0xa5,
        0x22,
        0x81,
        0x3f,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b993 = {
    .width = 7,
    .height = 6,
    .data = {
        0x6d,
        0x26,
        0x4e,
        0x9b,
        0x2a,
        0x40,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b994 = {
    .width = 9,
    .height = 8,
    .data = {
        0x00,
        0x80,
        0x9f,
        0x90,
        0x08,
        0x84,
        0xa2,
        0x20,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b995 = {
    .width = 9,
    .height = 9,
    .data = {
        0x04,
        0x85,
        0x42,
        0xc7,
        0xc4,
        0x04,
        0x42,
        0x51,
        0x10,
        0x7f,
        0x80,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b996 = {
    .width = 8,
    .height = 8,
    .data = {
        0x80,
        0x80,
        0x7e,
        0x41,
        0x01,
        0x71,
        0x53,
        0x3e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b997 = {
    .width = 9,
    .height = 8,
    .data = {
        0x00,
        0x80,
        0x5b,
        0x32,
        0x59,
        0x2e,
        0x16,
        0x8a,
        0x86,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b998 = {
    .width = 8,
    .height = 8,
    .data = {
        0x01,
        0x01,
        0x7e,
        0x80,
        0x82,
        0x85,
        0xb3,
        0x4e,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b999 = {
    .width = 8,
    .height = 8,
    .data = {
        0x01,
        0x01,
        0x75,
        0x8a,
        0x88,
        0xa4,
        0xd2,
        0x61,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99a = {
    .width = 8,
    .height = 8,
    .data = {
        0xcf,
        0xb7,
        0x65,
        0x05,
        0x05,
        0x05,
        0x05,
        0x05,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99b = {
    .width = 12,
    .height = 7,
    .data = {
        0x70,
        0x08,
        0x80,
        0xbd,
        0x8a,
        0xf7,
        0xb6,
        0x88,
        0x80,
        0x70,
        0x00,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99c = {
    .width = 12,
    .height = 16,
    .data = {
        0xff,
        0xf8,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x1f,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99d = {
    .width = 12,
    .height = 16,
    .data = {
        0xff,
        0xf8,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x1f,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99e = {
    .width = 12,
    .height = 16,
    .data = {
        0xff,
        0xf8,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x1f,
        0xff,
    }
};

static CONST_PREFIX dw_font_bitmap_t symbol_e0b99f = {
    .width = 12,
    .height = 16,
    .data = {
        0xff,
        0xf8,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x18,
        0x01,
        0x80,
        0x1f,
        0xff,
    }
};

const dw_font_info_t font_th_sarabun_new_regular20 = {
    .count = 192,
    .font_size = 20,
    .height = 22,
    .symbols = {
        {.utf8=0x20, .offset_x=0, .offset_y=0, .cur_dist=4, .bitmap=&symbol_20},
        {.utf8=0x21, .offset_x=0, .offset_y=-10, .cur_dist=3, .bitmap=&symbol_21},
        {.utf8=0x22, .offset_x=0, .offset_y=-10, .cur_dist=4, .bitmap=&symbol_22},
        {.utf8=0x23, .offset_x=0, .offset_y=-9, .cur_dist=8, .bitmap=&symbol_23},
        {.utf8=0x24, .offset_x=0, .offset_y=-11, .cur_dist=7, .bitmap=&symbol_24},
        {.utf8=0x25, .offset_x=1, .offset_y=-10, .cur_dist=12, .bitmap=&symbol_25},
        {.utf8=0x26, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_26},
        {.utf8=0x27, .offset_x=1, .offset_y=-10, .cur_dist=2, .bitmap=&symbol_27},
        {.utf8=0x28, .offset_x=0, .offset_y=-11, .cur_dist=4, .bitmap=&symbol_28},
        {.utf8=0x29, .offset_x=1, .offset_y=-11, .cur_dist=4, .bitmap=&symbol_29},
        {.utf8=0x2a, .offset_x=0, .offset_y=-10, .cur_dist=6, .bitmap=&symbol_2a},
        {.utf8=0x2b, .offset_x=1, .offset_y=-7, .cur_dist=8, .bitmap=&symbol_2b},
        {.utf8=0x2c, .offset_x=0, .offset_y=-1, .cur_dist=3, .bitmap=&symbol_2c},
        {.utf8=0x2d, .offset_x=0, .offset_y=-4, .cur_dist=4, .bitmap=&symbol_2d},
        {.utf8=0x2e, .offset_x=1, .offset_y=-1, .cur_dist=3, .bitmap=&symbol_2e},
        {.utf8=0x2f, .offset_x=-1, .offset_y=-10, .cur_dist=5, .bitmap=&symbol_2f},
        {.utf8=0x30, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_30},
        {.utf8=0x31, .offset_x=1, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_31},
        {.utf8=0x32, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_32},
        {.utf8=0x33, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_33},
        {.utf8=0x34, .offset_x=1, .offset_y=-11, .cur_dist=8, .bitmap=&symbol_34},
        {.utf8=0x35, .offset_x=0, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_35},
        {.utf8=0x36, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_36},
        {.utf8=0x37, .offset_x=1, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_37},
        {.utf8=0x38, .offset_x=1, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_38},
        {.utf8=0x39, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_39},
        {.utf8=0x3a, .offset_x=1, .offset_y=-6, .cur_dist=3, .bitmap=&symbol_3a},
        {.utf8=0x3b, .offset_x=0, .offset_y=-6, .cur_dist=3, .bitmap=&symbol_3b},
        {.utf8=0x3c, .offset_x=0, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_3c},
        {.utf8=0x3d, .offset_x=1, .offset_y=-5, .cur_dist=8, .bitmap=&symbol_3d},
        {.utf8=0x3e, .offset_x=0, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_3e},
        {.utf8=0x3f, .offset_x=0, .offset_y=-10, .cur_dist=6, .bitmap=&symbol_3f},
        {.utf8=0x40, .offset_x=0, .offset_y=-8, .cur_dist=11, .bitmap=&symbol_40},
        {.utf8=0x41, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_41},
        {.utf8=0x42, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_42},
        {.utf8=0x43, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_43},
        {.utf8=0x44, .offset_x=1, .offset_y=-10, .cur_dist=9, .bitmap=&symbol_44},
        {.utf8=0x45, .offset_x=1, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_45},
        {.utf8=0x46, .offset_x=1, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_46},
        {.utf8=0x47, .offset_x=0, .offset_y=-10, .cur_dist=9, .bitmap=&symbol_47},
        {.utf8=0x48, .offset_x=1, .offset_y=-10, .cur_dist=9, .bitmap=&symbol_48},
        {.utf8=0x49, .offset_x=1, .offset_y=-10, .cur_dist=3, .bitmap=&symbol_49},
        {.utf8=0x4a, .offset_x=-1, .offset_y=-10, .cur_dist=5, .bitmap=&symbol_4a},
        {.utf8=0x4b, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_4b},
        {.utf8=0x4c, .offset_x=1, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_4c},
        {.utf8=0x4d, .offset_x=1, .offset_y=-10, .cur_dist=11, .bitmap=&symbol_4d},
        {.utf8=0x4e, .offset_x=1, .offset_y=-10, .cur_dist=9, .bitmap=&symbol_4e},
        {.utf8=0x4f, .offset_x=0, .offset_y=-10, .cur_dist=10, .bitmap=&symbol_4f},
        {.utf8=0x50, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_50},
        {.utf8=0x51, .offset_x=0, .offset_y=-10, .cur_dist=10, .bitmap=&symbol_51},
        {.utf8=0x52, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_52},
        {.utf8=0x53, .offset_x=1, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_53},
        {.utf8=0x54, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_54},
        {.utf8=0x55, .offset_x=1, .offset_y=-10, .cur_dist=9, .bitmap=&symbol_55},
        {.utf8=0x56, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_56},
        {.utf8=0x57, .offset_x=-1, .offset_y=-10, .cur_dist=12, .bitmap=&symbol_57},
        {.utf8=0x58, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_58},
        {.utf8=0x59, .offset_x=0, .offset_y=-10, .cur_dist=7, .bitmap=&symbol_59},
        {.utf8=0x5a, .offset_x=0, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_5a},
        {.utf8=0x5b, .offset_x=1, .offset_y=-10, .cur_dist=4, .bitmap=&symbol_5b},
        {.utf8=0x5c, .offset_x=0, .offset_y=-10, .cur_dist=5, .bitmap=&symbol_5c},
        {.utf8=0x5d, .offset_x=0, .offset_y=-10, .cur_dist=4, .bitmap=&symbol_5d},
        {.utf8=0x5e, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_5e},
        {.utf8=0x5f, .offset_x=0, .offset_y=3, .cur_dist=7, .bitmap=&symbol_5f},
        {.utf8=0x60, .offset_x=1, .offset_y=-10, .cur_dist=4, .bitmap=&symbol_60},
        {.utf8=0x61, .offset_x=0, .offset_y=-7, .cur_dist=7, .bitmap=&symbol_61},
        {.utf8=0x62, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_62},
        {.utf8=0x63, .offset_x=0, .offset_y=-7, .cur_dist=7, .bitmap=&symbol_63},
        {.utf8=0x64, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_64},
        {.utf8=0x65, .offset_x=0, .offset_y=-7, .cur_dist=8, .bitmap=&symbol_65},
        {.utf8=0x66, .offset_x=-1, .offset_y=-10, .cur_dist=4, .bitmap=&symbol_66},
        {.utf8=0x67, .offset_x=1, .offset_y=-7, .cur_dist=7, .bitmap=&symbol_67},
        {.utf8=0x68, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_68},
        {.utf8=0x69, .offset_x=1, .offset_y=-9, .cur_dist=3, .bitmap=&symbol_69},
        {.utf8=0x6a, .offset_x=-2, .offset_y=-9, .cur_dist=3, .bitmap=&symbol_6a},
        {.utf8=0x6b, .offset_x=1, .offset_y=-10, .cur_dist=6, .bitmap=&symbol_6b},
        {.utf8=0x6c, .offset_x=1, .offset_y=-10, .cur_dist=4, .bitmap=&symbol_6c},
        {.utf8=0x6d, .offset_x=1, .offset_y=-7, .cur_dist=13, .bitmap=&symbol_6d},
        {.utf8=0x6e, .offset_x=1, .offset_y=-7, .cur_dist=8, .bitmap=&symbol_6e},
        {.utf8=0x6f, .offset_x=1, .offset_y=-7, .cur_dist=8, .bitmap=&symbol_6f},
        {.utf8=0x70, .offset_x=1, .offset_y=-7, .cur_dist=8, .bitmap=&symbol_70},
        {.utf8=0x71, .offset_x=1, .offset_y=-7, .cur_dist=8, .bitmap=&symbol_71},
        {.utf8=0x72, .offset_x=0, .offset_y=-7, .cur_dist=4, .bitmap=&symbol_72},
        {.utf8=0x73, .offset_x=0, .offset_y=-7, .cur_dist=6, .bitmap=&symbol_73},
        {.utf8=0x74, .offset_x=-1, .offset_y=-9, .cur_dist=5, .bitmap=&symbol_74},
        {.utf8=0x75, .offset_x=1, .offset_y=-7, .cur_dist=8, .bitmap=&symbol_75},
        {.utf8=0x76, .offset_x=0, .offset_y=-7, .cur_dist=7, .bitmap=&symbol_76},
        {.utf8=0x77, .offset_x=0, .offset_y=-7, .cur_dist=10, .bitmap=&symbol_77},
        {.utf8=0x78, .offset_x=0, .offset_y=-7, .cur_dist=6, .bitmap=&symbol_78},
        {.utf8=0x79, .offset_x=-1, .offset_y=-7, .cur_dist=7, .bitmap=&symbol_79},
        {.utf8=0x7a, .offset_x=0, .offset_y=-7, .cur_dist=6, .bitmap=&symbol_7a},
        {.utf8=0x7b, .offset_x=-1, .offset_y=-10, .cur_dist=4, .bitmap=&symbol_7b},
        {.utf8=0x7c, .offset_x=1, .offset_y=-11, .cur_dist=3, .bitmap=&symbol_7c},
        {.utf8=0x7d, .offset_x=1, .offset_y=-10, .cur_dist=4, .bitmap=&symbol_7d},
        {.utf8=0x7e, .offset_x=0, .offset_y=-5, .cur_dist=8, .bitmap=&symbol_7e},
        {.utf8=0x7f, .offset_x=1, .offset_y=-16, .cur_dist=14, .bitmap=&symbol_7f},
        {.utf8=0xe0b880, .offset_x=0, .offset_y=0, .cur_dist=0, .bitmap=&symbol_e0b880},
        {.utf8=0xe0b881, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b881},
        {.utf8=0xe0b882, .offset_x=0, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b882},
        {.utf8=0xe0b883, .offset_x=0, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b883},
        {.utf8=0xe0b884, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b884},
        {.utf8=0xe0b885, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b885},
        {.utf8=0xe0b886, .offset_x=1, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b886},
        {.utf8=0xe0b887, .offset_x=-1, .offset_y=-8, .cur_dist=6, .bitmap=&symbol_e0b887},
        {.utf8=0xe0b888, .offset_x=0, .offset_y=-8, .cur_dist=7, .bitmap=&symbol_e0b888},
        {.utf8=0xe0b889, .offset_x=1, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b889},
        {.utf8=0xe0b88a, .offset_x=0, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b88a},
        {.utf8=0xe0b88b, .offset_x=0, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b88b},
        {.utf8=0xe0b88c, .offset_x=1, .offset_y=-8, .cur_dist=11, .bitmap=&symbol_e0b88c},
        {.utf8=0xe0b88d, .offset_x=0, .offset_y=-8, .cur_dist=10, .bitmap=&symbol_e0b88d},
        {.utf8=0xe0b88e, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b88e},
        {.utf8=0xe0b88f, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b88f},
        {.utf8=0xe0b890, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b890},
        {.utf8=0xe0b891, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b891},
        {.utf8=0xe0b892, .offset_x=1, .offset_y=-8, .cur_dist=11, .bitmap=&symbol_e0b892},
        {.utf8=0xe0b893, .offset_x=0, .offset_y=-8, .cur_dist=11, .bitmap=&symbol_e0b893},
        {.utf8=0xe0b894, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b894},
        {.utf8=0xe0b895, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b895},
        {.utf8=0xe0b896, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b896},
        {.utf8=0xe0b897, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b897},
        {.utf8=0xe0b898, .offset_x=-1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b898},
        {.utf8=0xe0b899, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b899},
        {.utf8=0xe0b89a, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b89a},
        {.utf8=0xe0b89b, .offset_x=0, .offset_y=-11, .cur_dist=9, .bitmap=&symbol_e0b89b},
        {.utf8=0xe0b89c, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b89c},
        {.utf8=0xe0b89d, .offset_x=1, .offset_y=-11, .cur_dist=8, .bitmap=&symbol_e0b89d},
        {.utf8=0xe0b89e, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b89e},
        {.utf8=0xe0b89f, .offset_x=0, .offset_y=-11, .cur_dist=9, .bitmap=&symbol_e0b89f},
        {.utf8=0xe0b8a0, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b8a0},
        {.utf8=0xe0b8a1, .offset_x=1, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b8a1},
        {.utf8=0xe0b8a2, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b8a2},
        {.utf8=0xe0b8a3, .offset_x=0, .offset_y=-8, .cur_dist=7, .bitmap=&symbol_e0b8a3},
        {.utf8=0xe0b8a4, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b8a4},
        {.utf8=0xe0b8a5, .offset_x=0, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b8a5},
        {.utf8=0xe0b8a6, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b8a6},
        {.utf8=0xe0b8a7, .offset_x=0, .offset_y=-8, .cur_dist=7, .bitmap=&symbol_e0b8a7},
        {.utf8=0xe0b8a8, .offset_x=1, .offset_y=-9, .cur_dist=8, .bitmap=&symbol_e0b8a8},
        {.utf8=0xe0b8a9, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b8a9},
        {.utf8=0xe0b8aa, .offset_x=0, .offset_y=-9, .cur_dist=8, .bitmap=&symbol_e0b8aa},
        {.utf8=0xe0b8ab, .offset_x=0, .offset_y=-8, .cur_dist=9, .bitmap=&symbol_e0b8ab},
        {.utf8=0xe0b8ac, .offset_x=0, .offset_y=-9, .cur_dist=9, .bitmap=&symbol_e0b8ac},
        {.utf8=0xe0b8ad, .offset_x=-1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b8ad},
        {.utf8=0xe0b8ae, .offset_x=1, .offset_y=-8, .cur_dist=7, .bitmap=&symbol_e0b8ae},
        {.utf8=0xe0b8af, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b8af},
        {.utf8=0xe0b8b0, .offset_x=0, .offset_y=-8, .cur_dist=7, .bitmap=&symbol_e0b8b0},
        {.utf8=0xe0b8b1, .offset_x=-5, .offset_y=-12, .cur_dist=0, .bitmap=&symbol_e0b8b1},
        {.utf8=0xe0b8b2, .offset_x=0, .offset_y=-8, .cur_dist=6, .bitmap=&symbol_e0b8b2},
        {.utf8=0xe0b8b3, .offset_x=-3, .offset_y=-12, .cur_dist=6, .bitmap=&symbol_e0b8b3},
        {.utf8=0xe0b8b4, .offset_x=-7, .offset_y=-12, .cur_dist=0, .bitmap=&symbol_e0b8b4},
        {.utf8=0xe0b8b5, .offset_x=-8, .offset_y=-13, .cur_dist=0, .bitmap=&symbol_e0b8b5},
        {.utf8=0xe0b8b6, .offset_x=-8, .offset_y=-13, .cur_dist=0, .bitmap=&symbol_e0b8b6},
        {.utf8=0xe0b8b7, .offset_x=-8, .offset_y=-13, .cur_dist=0, .bitmap=&symbol_e0b8b7},
        {.utf8=0xe0b8b8, .offset_x=-3, .offset_y=1, .cur_dist=0, .bitmap=&symbol_e0b8b8},
        {.utf8=0xe0b8b9, .offset_x=-5, .offset_y=1, .cur_dist=0, .bitmap=&symbol_e0b8b9},
        {.utf8=0xe0b8ba, .offset_x=-2, .offset_y=1, .cur_dist=0, .bitmap=&symbol_e0b8ba},
        {.utf8=0xe0b8bb, .offset_x=1, .offset_y=-16, .cur_dist=14, .bitmap=&symbol_e0b8bb},
        {.utf8=0xe0b8bc, .offset_x=1, .offset_y=-16, .cur_dist=14, .bitmap=&symbol_e0b8bc},
        {.utf8=0xe0b8bd, .offset_x=1, .offset_y=-16, .cur_dist=14, .bitmap=&symbol_e0b8bd},
        {.utf8=0xe0b8be, .offset_x=1, .offset_y=-16, .cur_dist=14, .bitmap=&symbol_e0b8be},
        {.utf8=0xe0b8bf, .offset_x=1, .offset_y=-10, .cur_dist=8, .bitmap=&symbol_e0b8bf},
        {.utf8=0xe0b980, .offset_x=1, .offset_y=-8, .cur_dist=5, .bitmap=&symbol_e0b980},
        {.utf8=0xe0b981, .offset_x=1, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b981},
        {.utf8=0xe0b982, .offset_x=-2, .offset_y=-14, .cur_dist=6, .bitmap=&symbol_e0b982},
        {.utf8=0xe0b983, .offset_x=-1, .offset_y=-13, .cur_dist=6, .bitmap=&symbol_e0b983},
        {.utf8=0xe0b984, .offset_x=-1, .offset_y=-13, .cur_dist=6, .bitmap=&symbol_e0b984},
        {.utf8=0xe0b985, .offset_x=-2, .offset_y=-8, .cur_dist=4, .bitmap=&symbol_e0b985},
        {.utf8=0xe0b986, .offset_x=0, .offset_y=-8, .cur_dist=8, .bitmap=&symbol_e0b986},
        {.utf8=0xe0b987, .offset_x=-6, .offset_y=-14, .cur_dist=0, .bitmap=&symbol_e0b987},
        {.utf8=0xe0b988, .offset_x=-2, .offset_y=-16, .cur_dist=0, .bitmap=&symbol_e0b988},
        {.utf8=0xe0b989, .offset_x=-4, .offset_y=-17, .cur_dist=0, .bitmap=&symbol_e0b989},
        {.utf8=0xe0b98a, .offset_x=-5, .offset_y=-17, .cur_dist=0, .bitmap=&symbol_e0b98a},
        {.utf8=0xe0b98b, .offset_x=-4, .offset_y=-16, .cur_dist=0, .bitmap=&symbol_e0b98b},
        {.utf8=0xe0b98c, .offset_x=-4, .offset_y=-17, .cur_dist=0, .bitmap=&symbol_e0b98c},
        {.utf8=0xe0b98d, .offset_x=-3, .offset_y=-12, .cur_dist=0, .bitmap=&symbol_e0b98d},
        {.utf8=0xe0b98e, .offset_x=-4, .offset_y=-14, .cur_dist=0, .bitmap=&symbol_e0b98e},
        {.utf8=0xe0b98f, .offset_x=1, .offset_y=-7, .cur_dist=9, .bitmap=&symbol_e0b98f},
        {.utf8=0xe0b990, .offset_x=1, .offset_y=-6, .cur_dist=9, .bitmap=&symbol_e0b990},
        {.utf8=0xe0b991, .offset_x=1, .offset_y=-6, .cur_dist=9, .bitmap=&symbol_e0b991},
        {.utf8=0xe0b992, .offset_x=0, .offset_y=-9, .cur_dist=10, .bitmap=&symbol_e0b992},
        {.utf8=0xe0b993, .offset_x=1, .offset_y=-6, .cur_dist=9, .bitmap=&symbol_e0b993},
        {.utf8=0xe0b994, .offset_x=1, .offset_y=-8, .cur_dist=11, .bitmap=&symbol_e0b994},
        {.utf8=0xe0b995, .offset_x=1, .offset_y=-9, .cur_dist=11, .bitmap=&symbol_e0b995},
        {.utf8=0xe0b996, .offset_x=0, .offset_y=-8, .cur_dist=10, .bitmap=&symbol_e0b996},
        {.utf8=0xe0b997, .offset_x=1, .offset_y=-8, .cur_dist=11, .bitmap=&symbol_e0b997},
        {.utf8=0xe0b998, .offset_x=1, .offset_y=-8, .cur_dist=10, .bitmap=&symbol_e0b998},
        {.utf8=0xe0b999, .offset_x=1, .offset_y=-8, .cur_dist=10, .bitmap=&symbol_e0b999},
        {.utf8=0xe0b99a, .offset_x=1, .offset_y=-8, .cur_dist=10, .bitmap=&symbol_e0b99a},
        {.utf8=0xe0b99b, .offset_x=1, .offset_y=-7, .cur_dist=14, .bitmap=&symbol_e0b99b},
        {.utf8=0xe0b99c, .offset_x=1, .offset_y=-16, .cur_dist=14, .bitmap=&symbol_e0b99c},
        {.utf8=0xe0b99d, .offset_x=1, .offset_y=-16, .cur_dist=14, .bitmap=&symbol_e0b99d},
        {.utf8=0xe0b99e, .offset_x=1, .offset_y=-16, .cur_dist=14, .bitmap=&symbol_e0b99e},
        {.utf8=0xe0b99f, .offset_x=1, .offset_y=-16, .cur_dist=14, .bitmap=&symbol_e0b99f},
    }
};

