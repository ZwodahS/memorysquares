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
#include "Probability.hpp"
#include <stdlib.h>
#include <math.h>
namespace zf
{
    Probability::Probability(int c,int m)
        :chance(c), maxRoll(m), _alwaysTrue(false)
    {
    }

    bool Probability::roll(int bonusChance) const
    {
        if(_alwaysTrue)
        {
            return _alwaysTrue;
        }
        if(chance + bonusChance< 0)
        {
            return false;
        }
        return (rand() % maxRoll < (chance + bonusChance));
    }

    Probability Probability::makeProbability(float amount, int precision)
    {
        int max = 100;
        if(precision > 0)
        {
            max = 100 * (pow(10,precision));
        }
        return zf::Probability(amount * max, max);
    }

    Probability Probability::makeProbabilityAlwaysTrue()
    {
        Probability prob;
        prob._alwaysTrue = true;
        return prob;
    }
}
