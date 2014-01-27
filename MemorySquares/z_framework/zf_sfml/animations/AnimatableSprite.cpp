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
#include "AnimatableSprite.hpp"

namespace zf
{
    AnimatableSprite::AnimatableSprite()
        : _animator(*this)
    {
    }

    AnimatableSprite::AnimatableSprite(sf::Sprite sprite)
        : _sprite(sprite), _animator(*this)
    {
    }

    AnimatableSprite::AnimatableSprite(const AnimatableSprite& copy)
        : _sprite(copy._sprite), _animator(*this)
    {
    }

    AnimatableSprite::~AnimatableSprite()
    {
    }

    void AnimatableSprite::setSprite(sf::Sprite sprite)
    {
        sf::Vector2f center = getCenterPosition();
        sf::Vector2f scale = _sprite.getScale();
        sf::Color color = _sprite.getColor();
        sprite.setScale(scale);
        sprite.setColor(color);
        _sprite = sprite;
        setCenterPosition(center);
    }

    void AnimatableSprite::setColor(sf::Color color)
    {
        _sprite.setColor(color);
    }

    void AnimatableSprite::setPosition(sf::Vector2f position)
    {
        _sprite.setPosition(position);
    }

    void AnimatableSprite::setAlpha(float alpha)
    {
        zf::setAlpha(_sprite, alpha);
    }

    void AnimatableSprite::move(sf::Vector2f move)
    {
        setPosition(getPosition() + move);
    }

    sf::Vector2f AnimatableSprite::getPosition()
    {
        sf::FloatRect bound = _sprite.getGlobalBounds();
        return sf::Vector2f(bound.left, bound.top);
    }

    void AnimatableSprite::draw(sf::RenderWindow& window, const sf::Time& delta)
    {
        window.draw(_sprite);
    }

    void AnimatableSprite::draw(sf::RenderWindow& window)
    {
        window.draw(_sprite);
    }

    void AnimatableSprite::update(sf::RenderWindow& window, const sf::Time& delta)
    {
        _animator.update(window, delta);
    }

    void AnimatableSprite::setScale(float x, float y)
    {
        sf::Vector2f center = getCenterPosition();
        _sprite.setScale(x, y);
        setCenterPosition(center);
    }

    sf::FloatRect AnimatableSprite::getBoundingBox()
    {
        return _sprite.getGlobalBounds();
    }

    AnimatableSprite& AnimatableSprite::operator=(const AnimatableSprite& animatable)
    {
        _sprite = animatable._sprite;
        return *this;
    }

    sf::Vector2f AnimatableSprite::getCenterPosition()
    {
        sf::FloatRect bound = _sprite.getGlobalBounds();
        float x = bound.width == 0 ? bound.left : bound.left + bound.width / 2;
        float y = bound.height == 0 ? bound.top : bound.top + bound.height / 2;
        return sf::Vector2f(x, y);
    }

    void AnimatableSprite::setCenterPosition(sf::Vector2f position)
    {
        sf::FloatRect bound = _sprite.getGlobalBounds();
        float x = bound.width == 0 ? position.x : position.x - bound.width / 2;
        float y = bound.height == 0 ? position.y : position.y - bound.height / 2;
        _sprite.setPosition(x, y);
    }

    bool AnimatableSprite::animateFade(int startingAlpha, int targetAlpha, float time)
    {
        return _animator.fade(startingAlpha, targetAlpha, time);
    }
    bool AnimatableSprite::animateMoveTo(sf::Vector2f source, sf::Vector2f target, float time)
    {
        return _animator.moveTo(source, target, time);
    }
    bool AnimatableSprite::animateMove(sf::Vector2f moveVectorPerSec, float duration)
    {
        return _animator.move(moveVectorPerSec, duration);
    }
    bool AnimatableSprite::animateComposite(CompositeInstruction& instruction)
    {
        return _animator.composite(instruction);
    }
    CompositeInstruction& AnimatableSprite::createCompositeAnimation(bool ordered)
    {
        return _animator.composite(ordered);
    }

    sf::Sprite& AnimatableSprite::getSprite()
    {
        return _sprite;
    }

    bool AnimatableSprite::isAnimating() const
    {
        return _animator.isAnimating();
    }
}
