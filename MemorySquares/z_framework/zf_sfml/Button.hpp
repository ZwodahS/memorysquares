/* *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
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
 * Buttons offers the implementation for a few type of buttons.
 * Currently available :
 *      1.  2 Sprites button. (TSB)
 *          The button is made up of 2 sprites, one for hovered and one for when not hovered.
 *      2.  2 Sprites + 1 Text button. (TSTB, reads as Two Sprites Text Button)
 *          The button is made up of 2 sprites, like the one above with an additional text for display on
 *          top of the sprites background.
 *      3.  X Sprites + 1 Text (MSTB , reads as multiple sprites text button)
 *          Similar to the 2 sprite, however, the state is being set by the user instead of interally managed.
 *          Pretty similar to using SpriteGroup + text.
 *          Use this when you need to have different state like disabled, hovered or special cases.
 *          However, it is assumed that sprites[0] is for default sprite, and [1] is for "hovered". 
 *          This means that you can still use update to update the button. It will set the state to 1 if it is
 *          hovered and the current state is 0. Similarly it will set it to 0 when it 1 and not hovered.
 *          If you do not want the managed function, pass the managed variable as false.
 * I want to allow Button to be freely copied around, which is why I didn't opt for a inheritance based button.     
 * Maybe when I know how to do it, I will change this.
 *
 * To be honest, TSTB is the same as MSTB with 2 sprites. I kind of want to merge them, but I am too lazy
 * to remove them since that I have already split them up.
 *
 */
#ifndef _ZF_SFML_BUTTON_H_
#define _ZF_SFML_BUTTON_H_
#include "AlignmentData.hpp"
#include "../zf_common/Alignment.hpp"
#include "Mouse.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
namespace zf
{
    class Button
    {
    public:
        /**
         * The constructor (TSB)
         * Assumption : size of both sprites is the same.
         */
        Button(sf::Sprite selectedSprite, sf::Sprite unselectedSprite);        
        /**
         * The constructor (TSTB)
         */
        /* 
         * This create a default position of
         *  AlignmentX = center,
         *  AlignmentY = center
         *  offset = {0,0}
         * Assumption : size of both sprites is the same.
         */
        Button(sf::Sprite selectedSprite, sf::Sprite unselectedSprite, sf::Text text);
        Button(sf::Sprite selectedSprite, sf::Sprite unselectedSprite, sf::Text text, AlignmentData position);
        /**
         * The constructor (MSTB)
         * Assumption : sprites is of size != 0
         */
        Button(std::vector<sf::Sprite> sprites, sf::Text text, bool managed = true);
        Button(std::vector<sf::Sprite> sprites, sf::Text text, AlignmentData position, bool managed = true);
        /**
         * Empty Button
         */
        Button();
        
        /**
         * Set the position of this button and update the drawable accordingly.
         */
        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y);
        /**
         * Set the string value of the button
         */
        void setString(std::string displayString);
        /**
         * Set the state for the button.
         * Probably does nothing except for MSTB.
         */
        void setState(int state);
        /**
         * Get the state for this button.
         * The state will means nothing except for MSTB
         */
        int getState() const; 
        /**
         * Return true if the bound of this object contains the mouse position.
         * Make sure that the position is relative to the view this button is in.
         */
        bool contains(sf::Vector2f mousePosition) const;
        /**
         * update this button.
         * It will do state changed if this is internally managed.
         * It is automatically internally managed for TSB and TSTB.
         * For MSTB, if the managed value is false when constructed, then it will be externally managed
         * using the setState method.
         */
        void update(sf::RenderWindow& window, const sf::Time& delta, const zf::Mouse& mouse);
        /**
         * Draw the button.
         */
        void draw(sf::RenderWindow& window, const sf::Time& delta);
    private:
        enum 
        {
            None, // empty constructor called
            TSB,
            TSTB,
            MSTB,
        } _buttonType;
        /**
         * This is almost always the same as _sprites[0].getGlobalBounds()
         */
        sf::FloatRect _clickBound;
        /**
         * Internall interpreted.
         * (TSTB) stores the text in the first position.
         */
        std::vector<sf::Text> _texts;
        /** 
         * This is only used when there is text involved.
         */
        AlignmentData _textPositionData;
        /**
         * Internally interpreted.
         * (TSB) and (TSTB) stores the 2 sprites here, [0] for the unselected and [1] for the selected sprite
         */
        std::vector<sf::Sprite> _sprites;
        int _state;
        /**
         * update all drawables based on the current position of the button defined by _clickBound.
         */
        void updatePosition();            
        /**
         * Whether the state is managed by this button
         */
        bool _internalStateManaged;
    };
}
#endif
