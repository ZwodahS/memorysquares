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
#ifndef _ZF_SFML_ANIMATIONS_EFFECTMAKER_H_
#define _ZF_SFML_ANIMATIONS_EFFECTMAKER_H_
#include "CompositeInstruction.hpp"
namespace zf
{
    class EffectFactory
    {
    public:
        static CompositeInstruction& createBounceEffect(float bounceDistance, float timePerBounce, int numberOfBounce)
        {
            CompositeInstruction* ci = new CompositeInstruction(true);
            for(int i = 0 ; i < numberOfBounce ; i++)
            {
                ci->move(sf::Vector2f(0, -bounceDistance), timePerBounce/2);
                ci->move(sf::Vector2f(0, bounceDistance), timePerBounce/2);
            }
            return *ci;
        }
        
        static CompositeInstruction& createPulseEffect(float startScale, float maxScale, float minScale, float timeToMax, float timeToMin, float timeToBasic)
        {
            CompositeInstruction* ci = new CompositeInstruction(true);
            ci->scale(startScale, maxScale, timeToMax);
            ci->scale(maxScale, minScale, timeToMin);
            ci->scale(minScale, startScale, timeToBasic);
            return *ci;
        }
    };
};
#endif
