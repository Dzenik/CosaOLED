/**
 * @file ?/SSD1306x32_Text.hh
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

#ifndef COSA_X_SSD1306X32_TEXT_HH
#define COSA_X_SSD1306X32_TEXT_HH

#include "SSD1306x64_Text.hh"

/**
 * SSD1306x32 Dot Matrix OLED/PLED Segment/Common Driver with Controller
 * for LCD/IOStream access.
 *
 * SSD1306x32 is manufactured by Solomon Systech Ltd.
 */
class SSD1306x32_Text : public SSD1306x64_Text {
public:
  /**
   * Construct SSD1306x32_Text OLED connected to given io port handler. The
   * display is initialized when calling begin(). 
   * @param[in] io handler.
   * @param[in] font font to display.
   * @param[in] display reset pin (optional).
   */
  SSD1306x32_Text(OLED_IO* io, Font* font, Board::DigitalPin reset_pin);

  SSD1306x32_Text(OLED_IO* io, Font* font);

protected:
  /**
   * Initialization script (in program memory).
   */
  static const uint8_t script[] PROGMEM;
};
#endif