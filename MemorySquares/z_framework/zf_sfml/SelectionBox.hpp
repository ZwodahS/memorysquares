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
#ifndef _Z_FRAMEWORK_SFML_SELECTION_BOX_H_
#define _Z_FRAMEWORK_SFML_SELECTION_BOX_H_
#include "../zf_common/Grid.hpp"
#include <SFML/Graphics.hpp>
namespace zf
{
/**
 * Selection Box defines a box around a rectangle region. 
 * It has 4 sprites, 1 for each of the corner.
 * It works in such a way that the top left of the rectangle will align with the top left corner of the top left sprite.
 * The top right of the rectangle will align with the top right corner of the top right sprite ...
 */
    class SelectionBox
    {
        public:
            SelectionBox(int width, int height, int maxOffSet, int minOffSet, float movementPerSecs);
            void setSprites(sf::Sprite topLeft, sf::Sprite topRight, sf::Sprite bottomRight, sf::Sprite bottomLeft);

            void setPosition(sf::Vector2f newPos);
            void update(sf::RenderWindow& window, const sf::Time& delta);
            void draw(sf::RenderWindow& window, const sf::Time& delta);
        private:
            sf::Vector2f _position;
            int _width;
            int _height;
            int _maxOffset;
            int _minOffset;
            float _offset;
            float _movement;

            int _multiplier;
            

            sf::Sprite _topLeft;
            sf::Sprite _topRight;
            sf::Sprite _bottomLeft;
            sf::Sprite _bottomRight;
    };
}
#endif
