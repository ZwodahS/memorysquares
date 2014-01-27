#ifndef _Z_FRAMEWORK_ZFSFML_ANIMATIONS_ANIMATABLE_H_
#define _Z_FRAMEWORK_ZFSFML_ANIMATIONS_ANIMATABLE_H_
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
/**
 * The idea behind iAnimatable is to provide a way to move things that are not part of sfml.
 * When using iAnimatable, Simple Animator will not draw it.
 *
 */
#include <SFML/Graphics.hpp>
namespace zf
{
    class iAnimatable
    {
    public:

        /**
         * Set the TOP LEFT position of this iAnimatable
         */
        virtual void setPosition(const sf::Vector2f& position) = 0;

        /**
         * Set the alpha for the iAnimatable
         */
        virtual void setAlpha(const float& alpha) = 0;

        /**
         * Move this iAnimatable by this vector.
         */
        virtual void move(const sf::Vector2f& move) = 0;
        
        /**
         * Get the position of this iAnimatable
         */
        virtual sf::Vector2f getPosition() = 0;

        /**
         * Set the scale of the iAnimatable. 
         * The origin of scale is up to the iAnimatable.
         */
        virtual void setScale(const float& x, const float& y) = 0;
    };
}
#endif
