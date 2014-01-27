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
#ifndef _ZF_SFML_ANIMATIONS_SIMPLEANIMATOR_H_
#define _ZF_SFML_ANIMATIONS_SIMPLEANIMATOR_H_
#include "iAnimatable.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
namespace zf
{
    class CompositeInstruction;
    class AnimationInstruction;
    class SimpleAnimator
    {
        // DO NOT reuse ANY instruction.
        public:
            SimpleAnimator();
            ~SimpleAnimator();
            // update the simple animator. All managed objects will be updated.    
            void update(sf::RenderWindow& window, const sf::Time& delta);
            /*
             * fade an iAnimatable from a starting alpha to target alpha.
             * The iAnimatable will be set to the startingAlpha when the animation starts.
             */
            void fade(iAnimatable& animatable, int startingAlpha, int targetAlpha, float time);
            /*
             * move an iAnimatable to a target position
             * The iAnimatable will have a getPosition() and the movement will be based on the starting position
             */
            void moveTo(iAnimatable& animatable, sf::Vector2f source, sf::Vector2f target, float time);
            /**
             * move an iAnimatable by a vector. 
             */
            void move(iAnimatable& animatable, sf::Vector2f moveVec, float time);
            /**
             * color shift a iAnimatable
             */
            void colorshift(iAnimatable& animatable, sf::Color sourceColor, sf::Color targetColor, float duration);
            /**
             * Composite animations
             * to construct, use animatior.composite(ianimatable, animator.composite().move(...).fade(..)
             * Do not manage the composite instruction that is return and also do not free the memory.
             * This will be done internally here.
             */
            CompositeInstruction& composite(bool ordered = false);
            void composite(iAnimatable& animatable, CompositeInstruction& instruction);
            /**
             * In case there is a need to free the ianimatable before it finish animation, call this to remove it from the list.
             */
            void free(iAnimatable& animatable);
            /**
             * returns true if this animatable is animating.
             */
            bool isAnimating(iAnimatable& animatable);
            /**
             * returns true if there is at least one object animating.
             */
            bool hasAnimations();
        private:
            /**
             * AnimationObject is to wrap around the iAnimatable that is animating.
             * Since this class should only be known to SimpleAnimator, I shall not put it in a separate class.
             */
            class AnimationObject
            {
            public:
                // the instruction will be freed once this animation object is done animating.
                // Therefore, do NOT reuse animation instruction.
                AnimationObject(iAnimatable& animatable, AnimationInstruction& instruction);
                bool update(sf::RenderWindow& window, const sf::Time& delta);
                bool isDone();
                iAnimatable& _animatable;
                AnimationInstruction* _instruction;
            };
            std::vector<AnimationObject*> _objects;
    };
}
#endif
