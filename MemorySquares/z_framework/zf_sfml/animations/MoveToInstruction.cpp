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
#include "MoveToInstruction.hpp"
#include "iAnimatable.hpp"
namespace zf
{
    MoveToInstruction::MoveToInstruction(sf::Vector2f source, sf::Vector2f target, float delta)
        : _position(source), _target(target), _totalTime(delta)
        , _move((target-source)/delta), _runtime(0), _done(false)
    {
    }

    bool MoveToInstruction::update(sf::RenderWindow& window, const sf::Time& delta, iAnimatable& object)
    {
        if(!_done)
        {
            this->_position += _move * delta.asSeconds();
            _runtime += delta.asSeconds();
            // runtime is needed because if we have 2 moveto instruction you might screw up the timing and position
            // and there may not be a terminating condition
            if(overShootDestination() || _runtime >= _totalTime)
            {
                _done = true;
                _position = _target;
            }
            object.setPosition(_position);
        }
        return _done;
    }

    bool MoveToInstruction::isDone(iAnimatable& object)
    {
        return _done;
    }

    bool MoveToInstruction::overShootDestination()
    {
        bool x_done = false;
        bool y_done = false;
        if(_move.x > 0)
        {
            if(_position.x > _target.x)
            {
                x_done = true;
                _position.x = _target.x;
            }
        }
        else if(_move.x < 0)
        {
            if(_position.x < _target.x)
            {
                x_done = true;
                _position.x = _target.x;
            }
        }
        else
        {
            x_done =true;
        }


        if(_move.y > 0)
        {
            if(_position.y > _target.y)
            {
                y_done = true;
                _position.y = _target.y;
            }
        }
        else if(_move.y < 0)
        {
            if(_position.y < _target.y)
            {
                y_done = true;
                _position.y = _target.y;
            }
        }
        else
        {
            x_done =true;
        }
        return x_done && y_done;
    }
}
