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
#include "Direction.hpp"
namespace zf
{
    zf::Direction oppositeOf(const zf::Direction& direction)
    {
        switch(direction)
        {
            case None  : return None;
            case North : return South;
            case South : return North;
            case East  : return West;
            case West  : return East;
            case NorthEast : return SouthWest;
            case NorthWest : return SouthEast;
            case SouthEast : return NorthWest;
            case SouthWest : return NorthEast;
        }
    }

    zf::Grid getModifier(const zf::Direction& direction)
    {
        zf::Grid grid(0, 0);
        switch(direction)
        {
            case None      : grid.row = 0  ; grid.col = 0  ; break ;
            case North     : grid.row = -1 ; grid.col = 0  ; break ; 
            case East      : grid.row = 0  ; grid.col = 1  ; break ; 
            case South     : grid.row = 1  ; grid.col = 0  ; break ; 
            case West      : grid.row = 0  ; grid.col = -1 ; break ; 
            case NorthEast : grid.row = -1 ; grid.col = 1  ; break ; 
            case SouthEast : grid.row = 1  ; grid.col = 1  ; break ; 
            case SouthWest : grid.row = 1  ; grid.col = -1 ; break ; 
            case NorthWest : grid.row = -1 ; grid.col = -1 ; break ; 
            // default : none 
        }
        return grid;
    }
}
