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
#include "AnimationComponent.hpp"
#include "iAnimatable.hpp"
#include "AnimationInstruction.hpp"
#include "FadeInstruction.hpp"
#include "MoveToInstruction.hpp"
#include "MoveInstruction.hpp"
#include "CompositeInstruction.hpp"
#include <iostream>
namespace zf
{
    AnimationComponent::AnimationComponent(iAnimatable& animatable)
        :_animatable(animatable) , _instruction(0)
    {
    }

    bool AnimationComponent::update(sf::RenderWindow& window, const sf::Time& delta)
    {
        if(_instruction != 0)
        {
            _instruction->update(window, delta, _animatable);
            if(_instruction->isDone(_animatable))
            {
                // free the instruction, we are done
                delete _instruction;
                _instruction = 0;
                return true;
            }
        }
        return false;
    }

    bool AnimationComponent::fade(int startingAlpha, int targetAlpha, float time)
    {
        if(_instruction != 0)
        {
            return false;
        } 
        _instruction = new FadeInstruction(startingAlpha, targetAlpha, time);
        return true;
    }

    bool AnimationComponent::moveTo(sf::Vector2f source, sf::Vector2f target, float time)
    {
        if(_instruction != 0)
        {
            return false;
        }
        _instruction = new MoveToInstruction(source, target, time);
        return true;
    }

    bool AnimationComponent::move(sf::Vector2f moveVec, float duration)
    {
        if(_instruction != 0)
        {
            return false;
        } 
        _instruction = new MoveInstruction(moveVec, duration);
        return true;
    }
    CompositeInstruction& AnimationComponent::composite(bool ordered)
    {
        return *(new CompositeInstruction(ordered));
    }
    bool AnimationComponent::composite(CompositeInstruction& instruction)
    {
        if(_instruction != 0)
        {
            return false;
        }
        _instruction = &instruction;
        return true;
    }

    bool AnimationComponent::isAnimating() const
    {
        return _instruction != 0 ;
    }
}
