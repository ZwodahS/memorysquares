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
#include "FadeInstruction.hpp"
#include "iAnimatable.hpp"
#include <iostream>
namespace zf
{
    FadeInstruction::FadeInstruction(int startingAlpha, int endingAlpha, float time)
        : _targetAlpha(endingAlpha), _currentAlpha(startingAlpha), _changeAlpha((endingAlpha - startingAlpha)/ time)
        , _direction( endingAlpha > startingAlpha ? 1 : - 1), _done(false)
    {
    }
    bool FadeInstruction::update(sf::RenderWindow& window, const sf::Time& delta, iAnimatable& object)
    {
        if(!_done)
        {
            _currentAlpha += _changeAlpha * delta.asSeconds();
            if(_direction > 0) // increasing alpha
            {
                if(_currentAlpha >= _targetAlpha) 
                {
                    _done = true; 
                    _currentAlpha = _targetAlpha;
                }
            }
            else
            {
                if(_currentAlpha <= _targetAlpha)
                {
                    _done = true;
                    _currentAlpha = _targetAlpha;
                }
            }
            object.setAlpha(_currentAlpha);
        }
        return _done;
    }

    bool FadeInstruction::isDone(iAnimatable& object)
    {
        return _done;
    }
}
