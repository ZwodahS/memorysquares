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
#include "ScaleInstruction.hpp"
#include "iAnimatable.hpp"

namespace zf
{
    ScaleInstruction::ScaleInstruction(float startingScale, float endingScale, float time)
        : _targetScale(endingScale), _currentScale(startingScale), _changeScale((endingScale - startingScale)/ time)
        , _direction( endingScale > startingScale ? 1 : - 1), _done(false)
    {
    }

    bool ScaleInstruction::update(sf::RenderWindow& window, const sf::Time& delta, iAnimatable& object)
    {
        if(!_done)
        {
            _currentScale += _changeScale * delta.asSeconds();
            if(_direction > 0) // increasing alpha
            {
                if(_currentScale >= _targetScale) 
                {
                    _done = true; 
                    _currentScale = _targetScale;
                }
            }
            else
            {
                if(_currentScale <= _targetScale)
                {
                    _done = true;
                    _currentScale = _targetScale;
                }
            }
            object.setScale(_currentScale, _currentScale);
        }
        return _done;
    }

    bool ScaleInstruction::isDone(iAnimatable& object)
    {
        return _done;
    }
}
