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

#include "VertexButton.hpp"
#include "f_common.hpp"
namespace zf
{
    VertexButton::VertexButton()
        : _border(sf::LinesStrip, 5), _background(sf::Quads, 4), _bound(0,0,0,0)
    {
    }

    VertexButton::~VertexButton()
    {
        _text.setString(" ");
    }

    VertexButton::VertexButton(sf::Color borderColor, sf::Color backgroundColor, sf::FloatRect bound, sf::Text text)
        : _bound(bound), _borderColor(borderColor), _backgroundColor(backgroundColor), _text(text), _isHovered(false)
    {
        _border = zf::toVertexArrayLinesStrip(bound);
        _background = zf::toVertexArrayQuads(bound);
        updateColor();
    }

    VertexButton::VertexButton(const sf::Text& text, const float& width, const float& height, const sf::Color& borderColor, const sf::Color& baseColor, const sf::Color& hoveredColor, const sf::Color& selectedColor, const sf::Color& disabledColor)
        : _bound(0, 0, width, height), _borderColor(borderColor), _backgroundColor(baseColor), _hoveredColor(hoveredColor), _selectedColor(selectedColor), _disabledColor(disabledColor), _text(text)
        , _isHovered(false), _isSelected(false), _isDisabled(false)
    {
        _border = zf::toVertexArrayLinesStrip(_bound);
        _background = zf::toVertexArrayQuads(_bound);
        updateColor();
    }

    void VertexButton::setPosition(const sf::Vector2f& position)
    {
        _bound.left = position.x;
        _bound.top = position.y;
        updatePosition();
    }

    void VertexButton::setPosition(const float& x, const float& y)
    {
        _bound.left = x;
        _bound.top = y;
        updatePosition();
    }

    void VertexButton::updatePosition()
    {
        zf::moveVertexArray(_border, sf::Vector2f(_bound.left, _bound.top + 1)); 
        zf::moveVertexArray(_background, sf::Vector2f(_bound.left, _bound.top));
        zf::alignText(_text, _bound, AlignmentData());
    }

    bool VertexButton::contains(const sf::Vector2f& position)
    {
        return _bound.contains(position);
    }

    void VertexButton::updateColor()
    {
        if(_isSelected)
        {
            zf::setColor(_background, _selectedColor);
        }
        else if(_isDisabled)
        {
            zf::setColor(_background, _disabledColor);
        }
        else if(_isHovered)
        {
            zf::setColor(_background, _hoveredColor);
        }
        else
        {
            zf::setColor(_background, _backgroundColor);
        }
    }

    void VertexButton::setBorderColor(const sf::Color& color)
    {
        _borderColor = color;
        _border[0].color = _borderColor;
        _border[1].color = _borderColor;
        _border[2].color = _borderColor;
        _border[3].color = _borderColor;
        _border[4].color = _borderColor;
    }

    void VertexButton::setBaseColor(const sf::Color& color)
    {
        _backgroundColor = color;
        if(!_isHovered && !_isSelected)
        {
            zf::setColor(_background, color);
        }
    }

    void VertexButton::setHoveredColor(const sf::Color& color)
    {
        _hoveredColor = color;
        if(_isHovered && !_isSelected)
        {
            zf::setColor(_background, color);
        }
    }

    void VertexButton::setSelectedColor(const sf::Color& color)
    {
        _selectedColor = color;
        if(_isSelected)
        {
            zf::setColor(_background, color);
        }
    }

    void VertexButton::setDisabledColor(const sf::Color& color)
    {
        _disabledColor = color;
        if(!_isSelected && _isDisabled)
        {
            zf::setColor(_background, color);
        }
    }

    void VertexButton::setSelected(bool selection)
    {
        if(_isSelected == selection)
        {
            return;
        }
        _isSelected = selection;
        updateColor();
    }

    void VertexButton::setDisabled(bool disabled)
    {
        if(_isDisabled == disabled)
        {
            return;
        }
        _isDisabled = disabled;
        updateColor();
    }

    bool VertexButton::isSelected()
    {
        return _isSelected;
    }

    bool VertexButton::isDisabled()
    {
        return _isDisabled;
    }

    bool VertexButton::isHovered()
    {
        return _isHovered;
    }
    
    void VertexButton::draw(sf::RenderWindow& window, const sf::Time& delta)
    {
        draw(window);
    }

    void VertexButton::draw(sf::RenderWindow& window)
    {
        window.draw(_background);
        window.draw(_border);
        window.draw(_text);
    }

    void VertexButton::update(sf::RenderWindow& window, const sf::Time& delta)
    {
    }

    bool VertexButton::inputs(sf::RenderWindow& window, const sf::Time& delta, const zf::Mouse& mouse)
    {
        sf::Vector2f mousePos = mouse.getWorldPosition(window);
        setHovered(_bound.contains(mousePos));
        return _isHovered;
    }

    void VertexButton::setString(std::string str)
    {
        _text.setString(str);
        zf::alignText(_text, _bound, AlignmentData());
    }

    void VertexButton::setFontColor(const sf::Color& color, const bool& setAlpha)
    {
        zf::setColor(_text, color, setAlpha);
    }

    void VertexButton::setHovered(bool hovered)
    {
        if(_isHovered == hovered)
        {
            return;
        }
        _isHovered = hovered;
        updateColor();
    }

}
