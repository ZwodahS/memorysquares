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
 * A button that uses VertexArray instead of sprite.
 */
#ifndef _ZF_SFML_VERTEXBUTTON_H_
#define _ZF_SFML_VERTEXBUTTON_H_
#include "Mouse.hpp"
#include <SFML/Graphics.hpp>
namespace zf
{
    class VertexButton
    {
    public:
        VertexButton();
        ~VertexButton();
        VertexButton(sf::Color borderColor, sf::Color backgroundColor, sf::FloatRect bound, sf::Text text);
        VertexButton(const sf::Text& text, const float& width, const float& height, const sf::Color& borderColor = sf::Color::White, const sf::Color& baseColor = sf::Color(100, 100, 100), const sf::Color& hoveredColor = sf::Color(150, 150, 100), const sf::Color& selectedColor = sf::Color(150, 150, 100), const sf::Color& disabledColor = sf::Color(20, 20, 20));
        // deprecated
        void draw(sf::RenderWindow& window, const sf::Time& delta);
        void draw(sf::RenderWindow& window);
        void update(sf::RenderWindow& window, const sf::Time& delta);
        bool inputs(sf::RenderWindow& window, const sf::Time& delta, const zf::Mouse& mouse);

        bool contains(const sf::Vector2f& position);
        void setString(std::string string);
        void setFontColor(const sf::Color& color, const bool& setAlpha = true);
        void setPosition(const sf::Vector2f& position);
        void setPosition(const float& x, const float& y);
        void setBorderColor(const sf::Color& color);
        void setBaseColor(const sf::Color& color);
        void setHoveredColor(const sf::Color& color);
        void setSelectedColor(const sf::Color& color);
        void setDisabledColor(const sf::Color& color);
        void setSelected(bool selection);
        void setHovered(bool hovered);
        void setDisabled(bool disabled);
        bool isHovered();
        bool isSelected();
        bool isDisabled();
    private:
        sf::VertexArray _border;
        sf::VertexArray _background;
        sf::FloatRect _bound;
        sf::Color _borderColor;
        sf::Color _backgroundColor;
        sf::Color _hoveredColor;
        sf::Color _selectedColor;
        sf::Color _disabledColor;
        sf::Text _text;
        bool _isHovered;
        bool _isSelected;
        bool _isDisabled;

        void updatePosition();
        void updateColor();
    };
}
#endif
