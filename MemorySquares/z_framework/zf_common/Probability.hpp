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
#ifndef _ZF_COMMON_PROBABILITY_H_
#define _ZF_COMMON_PROBABILITY_H_
// the idea of the this probability class is to define a chance in maxRow to return true or false.
namespace zf
{
    struct Probability
    {
        int chance;
        int maxRoll;
        
        Probability(int chance = 0, int max = 100);
        // roll using the default system rand() function. 
        // TODO: create a RNG ? 
        bool roll(int bonusChance = 0) const;
        /**
         * precision is the number of decimal place to consider.
         */
        static Probability makeProbability(float amount, int precision=0);
        static Probability makeProbabilityAlwaysTrue();
    private:
        bool _alwaysTrue;
    };
}
#endif
