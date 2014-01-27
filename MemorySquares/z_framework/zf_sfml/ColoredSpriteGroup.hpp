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
#ifndef _ZF_SFML_COLORSPRITEGROUP_H_
#define _ZF_SFML_COLORSPRITEGROUP_H_
#include "animations/iAnimatable.hpp"
#include <SFML/Graphics.hpp>
namespace zf
{
    class ColoredSpriteGroup : public iAnimatable
    {
    public:
        const int& state;
        const sf::FloatRect& bound;

        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y);

        ColoredSpriteGroup();
        ColoredSpriteGroup(const ColoredSpriteGroup& button);
        ColoredSpriteGroup(sf::Sprite sprite, std::vector<sf::Color> colors);

        void setState(int state);
        int getState();

        ColoredSpriteGroup& operator=(const ColoredSpriteGroup& rhs);

        void draw(sf::RenderWindow& window, const sf::Time& delta);
        void setAlpha(float alpha);
        void move(sf::Vector2f moveVec);
        void setColor(sf::Color color);
        sf::Vector2f getPosition();
        void setSprite(sf::Sprite sprite);
        bool contains(sf::Vector2f mousePos);
        void setScale(float scaleX, float scaleY);
    private:
        int _state;
        sf::FloatRect _bound;
        std::vector<sf::Color> _colors;
        sf::Sprite _mainSprite;

    };
}
#endif
