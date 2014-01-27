/*
 *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
 *                   Version 2, December 2004
 * 
 * Copyright (C) 2013 ZwodahS(ericnjf@gmail.com) 
 * zwodahs.wordpress.com
 * 
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 * 
 *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 * 
 *  0. You just DO WHAT THE **** YOU WANT TO.
 * 
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. 
 */
#ifndef _ZF_COMMON_F_CONVERSION_H_
#define _ZF_COMMON_F_CONVERSION_H_
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
namespace zf
{
    // convert string to int.
    bool toInt(std::string str, int &value);
    // convert string to unsigned short (mainly used for port)
    bool toUShort(std::string str, unsigned short& value);
    // convert int to string.
    std::string toString(int i);
    std::string floatToString(float f);
    // convert int to string with sign (automatically comes with a + or a -)
    std::string toStringSigned(int i);
    std::vector<std::string> tokenize(std::string);
}
#endif
