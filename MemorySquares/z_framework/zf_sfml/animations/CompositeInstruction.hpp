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
#ifndef _ZF_SFML_ANIMATIONS_COMPOSITEINSTRUCTION_H_
#define _ZF_SFML_ANIMATIONS_COMPOSITEINSTRUCTION_H_
#include "AnimationInstruction.hpp"
#include <vector>
namespace zf
{
    class CompositeInstruction : public AnimationInstruction
    {
        public:
            // if ordered is true , then the instruction is executed one after another.
            // if not ordered , the instruction is executed all at the same time.
            CompositeInstruction(bool ordered = false);
            ~CompositeInstruction();
            bool update(sf::RenderWindow& window, const sf::Time& delta,iAnimatable& animatable);
            bool isDone(iAnimatable& animatable);
            // Some advice when using composite instructions ...
            // Do NOT chain move and moveTo if it is not ordered. Things get extremely messy.
            // Even if ordered, moveTo is an extremely problematic movement.
            // This is because the movement vector is calculated based on the starting position and
            // the starting position may not be where expect it to be when the animation starts if you
            // have chained a move instruction before that. 
            // However, a moveto followed by a moveto in a ordered composite instruction is okay,
            // since you know the location of the object after the animation.
            
            // all functions here return the reference to itself to allow for chaining.
            // add a fade instruction using parameters.
            CompositeInstruction& fade(int startingAlpha, int endingAlpha, float time);
            // add a move to instruction, copying the information  from another move to instruction
            CompositeInstruction& moveTo(sf::Vector2f source, sf::Vector2f target, float delta);
            // add a move instruction.
            CompositeInstruction& move(sf::Vector2f moveVec, float duration);
            // wait before executing.
            CompositeInstruction& wait(float waitTime);
            // chanining of composite instruction. 
            CompositeInstruction& addCompositeInstruction(CompositeInstruction& compositeInstruction);
            // scaling
            CompositeInstruction& scale(float startingScale, float endingScale, float time);
        private:
            std::vector<AnimationInstruction*> _instructions;
            bool _ordered;
            bool _done;
            int currIn;
    };
}
#endif
