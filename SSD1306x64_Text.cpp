/**
 * @file ?/SSD1306x64_Text.cpp
 * @version 0.1
 *
 * @section License
 * Copyright (C) 2014, jediunix
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 */

#include "SSD1306x64_Text.hh"

const uint8_t SSD1306x64_Text::script[] __PROGMEM = {
  DISPLAY_OFF, 0,                               // 0xae
  SET_DISPLAY_CLOCK_DIV, 1, 0x80,               // 0xd5 0x80
  SET_MULTIPLEX, 1, 0x3f,                       // 0xa8 0x3f
  SET_DISPLAY_OFFSET, 1, 0,                     // 0xd3 0x00
  SET_START_LINE, 0,                            // 0x40
  CHARGE_PUMP, 1, 0x14,                         // 0x8d 0x14
  MEMORY_MODE, 1, 0x02,                         // 0x20 0x02
  SEG_REMAP | 0x1, 0,                           // 0xa0 | 0x1
  COM_SCAN_DEC, 0,                              // 0xc8
  SET_COMPINS, 1, 0x12,                         // 0xda 0x12
  SET_CONTRAST, 1, 0xcf,                        // 0x81 0xcf
  SET_PRECHARGE, 1, 0xf1,                       // 0xd9 0xf1
  SET_VCOM_DETECT, 1, 0x40,                     // 0xdb 0x40
  DEACTIVATE_SCROLL, 0,                         // 0x2e
  DISPLAY_ALL_ON_RESUME, 0,                     // 0xa4
  NORMAL_DISPLAY, 0,                            // 0xa6
  DISPLAY_ON, 0,                                // 0xaf
  OLED_IO::SCRIPT_END
};

SSD1306x64_Text::SSD1306x64_Text(OLED_IO* io, Font* font, Board::DigitalPin reset_pin) :
  SH1106_Text(io, font, reset_pin)
{
  // Override SH1106

  m_column_offset = 0;
}

SSD1306x64_Text::SSD1306x64_Text(OLED_IO* io, Font* font) :
  SH1106_Text(io, font)
{
  // Override SH1106

  m_column_offset = 0;
}

bool
SSD1306x64_Text::begin()
{
  return (shared_begin(script));
}
