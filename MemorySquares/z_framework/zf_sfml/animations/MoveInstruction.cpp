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
#include "MoveInstruction.hpp"
#include "iAnimatable.hpp"
namespace zf
{
    MoveInstruction::MoveInstruction(sf::Vector2f moveVector, float moveSecs)
        : _moveVector(moveVector), _timeMax(moveSecs), _timeCurrent(0), _done(false) 
    {
    }

    bool MoveInstruction::update(sf::RenderWindow& window, const sf::Time& delta, iAnimatable& object)
    {
        if(!_done)
        {
            float moveTime = delta.asSeconds();
            _timeCurrent += moveTime;
            if(_timeCurrent > _timeMax)
            {
                moveTime -= (_timeCurrent - _timeMax);
                _done = true;
            }
            object.move(moveTime * _moveVector);
        }
        return _done;
    }

    bool MoveInstruction::isDone(iAnimatable& object)
    {
        return _done;
    }
}
