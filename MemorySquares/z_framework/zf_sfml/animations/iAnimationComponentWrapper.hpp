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
 * AnimationComponentWrapper is for class that want to provide an interface to the
 * AnimationComponent that is contains in the class itself.
 *
 * The easy way out is to make the component public so anyone can access it.
 * The other way is to provide an interface that everyone MUST implement.
 * I kind of choose the second way.
 */
#ifndef _ZF_SFML_ANIMATIONS_IANIMATIONCOMPONENTWRAPPER_H_
#define _ZF_SFML_ANIMATIONS_IANIMATIONCOMPONENTWRAPPER_H_
namespace zf
{
    class iAnimationComponentWrapper
    {
    public:
        virtual bool animateFade(int startingAlpha, int targetAlpha, float time) = 0;
        virtual bool animateMoveTo(sf::Vector2f source, sf::Vector2f target, float time) = 0;
        virtual bool animateMove(sf::Vector2f moveVectorPerSec, float duration) = 0;
        virtual bool animateComposite(CompositeInstruction& instruction) = 0;
        virtual CompositeInstruction& createCompositeAnimation(bool ordered = false) = 0;
    };
}
#endif
