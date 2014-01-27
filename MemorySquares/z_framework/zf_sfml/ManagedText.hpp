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
#ifndef _ZF_SFML_MANAGEDTEXT_H_
#define _ZF_SFML_MANAGEDTEXT_H_
#include <SFML/Graphics.hpp>
#include "AlignmentData.hpp"
namespace zf
{
    class ManagedText
    {
    public:
        ManagedText();
        ManagedText(const sf::Text& text);
        ManagedText(const sf::String& string, const sf::Font& font, unsigned int characterSize, const sf::Color& color = sf::Color::Black);
        ~ManagedText();

        void setText(const sf::Text& text);
        void setAlignment(const zf::AlignmentData& data, const sf::FloatRect& boundingBox);
        /**
         * This will shift the position of the top left corner of the bounding box and align the text to it.
         */
        void setPosition(sf::Vector2f position); 
        void setPosition(float x, float y);
        void setColor(const sf::Color& color);
        void setAlpha(const sf::Uint8& alpha);
        
        void setString(const sf::String& string);
        zf::AlignmentData alignmentData;
        sf::Text text;
        sf::FloatRect boundingBox;
    
        void draw(sf::RenderWindow& window);
        // Deprecated
        void draw(sf::RenderWindow& window, const sf::Time& delta);
        void update(sf::RenderWindow& window, const sf::Time& delta);
    private:
        void updatePosition();

    };
}
#endif
