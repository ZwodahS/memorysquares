/* *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
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
/**
 * This is an interface for objects that wished to be positioned by their center point
 * instead of the top left corner. 
 *
 * The simpliest way to use this is also to use iBoundable, then use the function in
 * the zf_sfml/f_common.hpp (setCenterPosition) to implement the following functions.
 */
#ifndef _ZF_SFML_ICENTERABLE_H_
#define _ZF_SFML_ICENTERABLE_H_
#include <SFML/Graphics.hpp>
namespace
{
    class iCenterable
    {
    public :
        /**
         * get the center position of this iCenterable
         */
        virtual sf::Vector2f getCenterPosition() = 0;
        
        /**
         * set the iCenterable based on the center position 
         */
        virtual void setCenterPosition(sf::Vector2f position) = 0;
    };
}
#endif
