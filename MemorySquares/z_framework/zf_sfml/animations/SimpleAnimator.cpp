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
#include "SimpleAnimator.hpp"
#include "FadeInstruction.hpp"
#include "MoveToInstruction.hpp"
#include "MoveInstruction.hpp"
#include "WaitInstruction.hpp"
#include "CompositeInstruction.hpp"
namespace zf
{
    SimpleAnimator::SimpleAnimator()
    {
    }

    SimpleAnimator::~SimpleAnimator()
    {
        for(int i = 0 ; i < _objects.size() ; i++)
        {
            delete _objects[i];
        }
    }

    void SimpleAnimator::update(sf::RenderWindow& window, const sf::Time& delta)
    {
        for(int i = _objects.size() - 1 ; i >= 0 ; i--)
        {
            if(_objects[i]->update(window,delta))
            {
                delete _objects[i];
                _objects.erase(_objects.begin() + i);
            }
        }
    }

    void SimpleAnimator::fade(iAnimatable& animatable,int startingAlpha, int targetAlpha, float time)
    {
        FadeInstruction* fi = new FadeInstruction(startingAlpha, targetAlpha, time);
        AnimationObject* obj = new AnimationObject(animatable, *fi);
        _objects.push_back(obj);
    }
    void SimpleAnimator::moveTo(iAnimatable& animatable, sf::Vector2f source, sf::Vector2f target, float time)
    {
        MoveToInstruction* mi = new MoveToInstruction(source, target, time);
        AnimationObject* obj = new AnimationObject(animatable, *mi);
        _objects.push_back(obj);
    }
    void SimpleAnimator::move(iAnimatable& animatable, sf::Vector2f moveVec, float duration)
    {
        MoveInstruction* mi = new MoveInstruction(moveVec, duration);
        AnimationObject* obj = new AnimationObject(animatable, *mi);
        _objects.push_back(obj);
    }

    CompositeInstruction& SimpleAnimator::composite(bool ordered)
    {
        return *(new CompositeInstruction(ordered));
    }

    void SimpleAnimator::composite(iAnimatable& animatable, CompositeInstruction& instruction)
    {
        AnimationObject* obj = new AnimationObject(animatable, instruction);
        _objects.push_back(obj);
    }
    
    void SimpleAnimator::free(iAnimatable& animatable)
    {
        for(std::vector<AnimationObject*>::iterator it = _objects.begin() ; it != _objects.end() ; )
        {
            if(&(**it)._animatable == &animatable)
            {
                delete (*it);
                it = _objects.erase(it);
                continue;
            }
            ++it;
        }
    }

    bool SimpleAnimator::isAnimating(iAnimatable& animatable)
    {
        for(std::vector<AnimationObject*>::iterator it = _objects.begin() ; it != _objects.end() ; ++it)
        {
            if(&(**it)._animatable == &animatable)
            {
                return true;
            }
        }
        return false;
    }

    bool SimpleAnimator::hasAnimations()
    {
        return _objects.size() == 0;
    }
    ////// INNER CLASS ///////
    SimpleAnimator::AnimationObject::AnimationObject(iAnimatable& animatable, AnimationInstruction& instruction)
        : _animatable(animatable), _instruction(&instruction)
    {
    }

    bool SimpleAnimator::AnimationObject::update(sf::RenderWindow& window, const sf::Time& delta)
    {
        if(isDone())
        {
            return true;
        }
        bool doneness = _instruction->update(window, delta, _animatable);
        return doneness;
    }

    bool SimpleAnimator::AnimationObject::isDone()
    {
        return _instruction == 0 ? true : _instruction->isDone(_animatable);
    }
}

