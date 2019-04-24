/*
This file is part of the Gamebuino-Meta library,
Copyright (c) Aadalie 2017

This is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License (LGPL)
as published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

This is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License (LGPL) for more details.

You should have received a copy of the GNU Lesser General Public
License (LGPL) along with the library.
If not, see <http://www.gnu.org/licenses/>.

Authors:
 - Sorunome
*/

#ifndef _GAMEBUINO_META_MISC_H_
#define _GAMEBUINO_META_MISC_H_

#include "../../config/config.h"

#ifdef ADAFRUIT_PYBADGE_M4_EXPRESS
 // doesn't have an SD card, use QSPI instead!
 #include <Adafruit_SPIFlash.h>
 #include <Adafruit_SPIFlash_FatFs.h>
 #include "Adafruit_QSPI_GD25Q.h"
 extern Adafruit_M0_Express_CircuitPython SD;
#else
  #if USE_SDFAT
   #include "../SdFat.h"
   extern SdFat SD;
  #endif
#endif

namespace Gamebuino_Meta {

void intToStr(int32_t i, char* buf);

int32_t sdPathNoDuplicate(char* name, uint8_t offset, uint8_t digits, int32_t start = 0);

struct RGB888 {
	uint8_t r, g, b;
};

uint16_t rgb888Torgb565(RGB888 c);
RGB888 rgb565Torgb888(uint16_t c);

#if USE_SDFAT
uint16_t f_read16(File* f);

uint32_t f_read32(File* f);

void f_write32(uint32_t b, File* f);

void f_write16(uint16_t b, File* f);
#endif // USE_SDFAT

} // namespace Gamebuino_Meta

#endif // _GAMEBUINO_META_MISC_H_
