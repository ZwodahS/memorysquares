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
#include "f_conversion.hpp"
namespace zf
{
    bool toInt(std::string str, int& value)
    {
        std::istringstream buffer(str);
        int temp;
        buffer >> temp;
        if(str != toString(temp)) //if the converted value is different then return 0 (similar to atoi)
        {
            return false;
        }
        value = temp;
        return true;
    }
    bool toUShort(std::string str, unsigned short& value)
    {
        std::istringstream buffer(str);
        unsigned short temp;
        buffer >> temp;
        if(str != toString(temp)) //if the converted value is different then return 0 (similar to atoi)
        {
            return false;
        }
        value = temp;
        return true;
    }
    std::string toString(int i)
    {
        std::stringstream sstr;
        sstr << i;
        std::string str1 = sstr.str();
        return str1;
    }
    std::string floatToString(float f)
    {
        std::stringstream sstr;
        sstr << f;
        std::string str1 = sstr.str();
        return str1;
    }
    std::string toStringSigned(int i)
    {
        std::stringstream sstr;
        sstr << i;
        std::string str1 = sstr.str();
        if(i > 0)
        {
            str1 = "+" + str1;
        }
        return str1;
    }
    std::vector<std::string> tokenize(std::string str)
    {
        std::vector<std::string> strings;
        std::stringstream ss(str);
        std::string token;
        while(ss >> token)
        {
            strings.push_back(token);
        }
        return strings;
    }
}
