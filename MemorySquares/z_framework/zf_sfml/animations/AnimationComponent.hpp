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
#ifndef _ZF_SFML_ANIMATIONS_SINGLEANIMATOR_H_
#define _ZF_SFML_ANIMATIONS_SINGLEANIMATOR_H_
#include <SFML/Graphics.hpp>
/**
 * This class is one of the possible component in the framework. It allow an object to 
 * animate without knowing how to do so.
 *
 * The class of concern just need to include this component and implement the iAnimatable interface.
 * Afterwhich, just call any of the function here to create an instruction to animate.
 *
 * READ ME !!! 
 *      It is extrememly important to override the copy constructor of anyone who has this component.
 *      If it is not done, this component will end up with a freed object reference instead.
 *
 * 01:57 December 11, 2013
 *      This is the first version of this component so expect limitation.
 *      Right now, only one instruction is allowed, instruction sent while the object is still animating
 *      will be ignored and a value of "false" will be returned.
 */
namespace zf
{
    class CompositeInstruction;
    class AnimationInstruction;
    class iAnimatable;
    class AnimationComponent
    {
    public:
        AnimationComponent(iAnimatable& iAnimatable);

        bool update(sf::RenderWindow& window, const sf::Time& delta);
        bool fade(int startingAlpha, int targetAlpha, float time);
        bool moveTo(sf::Vector2f source, sf::Vector2f target, float time);
        bool move(sf::Vector2f moveVecPerSec, float duration);
        CompositeInstruction& composite(bool ordered = false); // use this to construct the instructionn for the method below.
        // if composite returns false, outside MUST delete the instruction.
        bool composite(CompositeInstruction& instruction);

        bool isAnimating() const;
    private:
        iAnimatable& _animatable;
        AnimationInstruction* _instruction;
    };
}
#endif
