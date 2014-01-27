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
#ifndef _ZF_COMMON_INPUTSTATE_H_
#define _ZF_COMMON_INPUTSTATE_H_
namespace zf
{
    struct InputState
    {
        bool thisDown; // bool representing if this key is down this frame.
        bool lastDown; // bool representing if this key is down last frame.
        bool thisPressed; // bool representing if this key is pressed this frame.
        bool thisHeld; // bool representing if this key is pressed this frame and last frame.
        bool thisReleased; // bool representing if this key is released this frame.
        float timeHeld; // the time between thisDown and thisReleased. // if thisDown is false and lastDown is false then this will be 0
        //thisPressed = Keystates[keycode]  && !lastDown
        //thisHeld = Keystates[keycode] && lastDown
        //thisReleased = !Keystates[keycode] && lastDown
        InputState();
    };
}
#endif
