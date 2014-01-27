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
 * Right now , I haven't take into the setOrigin of the sprite.
 * I will need to handle it later.
 */
#ifndef _Z_FRAMEWORK_ZF_SFML_ANIMATIONS_ANIMATABLESPRITE_H_
#define _Z_FRAMEWORK_ZF_SFML_ANIMATIONS_ANIMATABLESPRITE_H_
#include <SFML/Graphics.hpp>
#include "AnimationComponent.hpp"
#include "iAnimatable.hpp"
#include "iAnimationComponentWrapper.hpp"
#include "../iCenterable.hpp"
#include "../iBoundable.hpp"
#include "../f_common.hpp"
namespace zf
{
    class AnimatableSprite : public iAnimatable, public iBoundable, public iCenterable, public iAnimationComponentWrapper
    {
    public:
        AnimatableSprite();
        AnimatableSprite(sf::Sprite sprite);
        /************** Need to override these because of _animator ****************/
        AnimatableSprite(const AnimatableSprite& copy);
        ~AnimatableSprite();
        AnimatableSprite& operator=(const AnimatableSprite& animatable);
        /**
         * Set sprite allows the new sprite to retain some of the properties of the old sprite.
         * The current properties that is kept is
         * 1) the current scale of the old sprite.
         * 2) the CENTER position of the old sprite.
         * 3) the color of the old sprite
         */
        void setSprite(sf::Sprite newSprite);
        /************** iAnimatable/iBoundable ****************/
        // see iAnimatable and iBoundable for the specification of these methods
        void setPosition(sf::Vector2f position);
        void setAlpha(float alpha);
        void move(sf::Vector2f move);
        sf::Vector2f getPosition();
        void setScale(float x, float y);
        void setColor(sf::Color color);
        sf::FloatRect getBoundingBox();
        /************** iCenterable ****************/
        // see iCenterable for the specification for these methods
        void setCenterPosition(sf::Vector2f position);
        sf::Vector2f getCenterPosition();
        /************** iAnimationComponent Wrapper ****************/
        bool animateFade(int startingAlpha, int targetAlpha, float time);
        bool animateMoveTo(sf::Vector2f source, sf::Vector2f target, float time);
        bool animateMove(sf::Vector2f moveVectorPerSec, float duration);
        bool animateComposite(CompositeInstruction& instruction);
        CompositeInstruction& createCompositeAnimation(bool ordered = false);
        /************** draw/update ****************/
        void update(sf::RenderWindow& window, const sf::Time& delta);
        void draw(sf::RenderWindow& window, const sf::Time& delta);
        void draw(sf::RenderWindow& window);
        /**
         * Do not use this unless necessary.
         */
        sf::Sprite& getSprite();
        bool isAnimating() const;
    private:
        sf::Sprite _sprite;
        AnimationComponent _animator;
    };
}
#endif
