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
#ifndef _ZF_COMMON_RANGE_H_
#define _ZF_COMMON_RANGE_H_
/**
 * Defines a min max.
 */
namespace zf
{
    template <class T>
    struct Range
    {
        /*
         *
         */
        T min;
        T max;
        bool minInclusive;
        bool maxInclusive;
        bool in(T value)
        {
            return (minInclusive ? value >= min : value > min) && (maxInclusive ? value <= max : value < max);
        }
        
        /**
         * This is just the default un-init value. Do not use the value here. It will 
         * produce unpredictable result.
         */
        Range()
        {
        }
        /**
         * By default min is inclusive and max is exclusive, (useful for array etc)
         */
        Range(T min_, T max_, bool minInclusive_ = true, bool maxInclusive_ = false)
            :min(min_) ,max(max_), minInclusive(minInclusive_), maxInclusive(maxInclusive_)
        {
        }

        int randomRange(int rng);
    };
    /** 
     * Randomly get a number from the range.
     * The Range MUST be int.
     * num is the random number that is generated from a RNG .
     */
    int randomRange(int rng, Range<int> range);
    /**
     * Return a random number between min / max .
     * rng = the number generated from any random number generator.
     * min = min value
     * max = max value
     * minInclusive = bool representing if min is included.
     * maxInclusive = bool representing if max is included.
     *
     * Note that this do NOT randomize. It just take a number generated by a RNG and convert to a number 
     * that is within the range. I KNOW it is stupid to call this function randomRange, which I might
     * change it when I am using it for something else. But for now, this will do.
     *
     * Special case :
     *      if (max - min <= 0)
     *          returns minInclusive ? min : min + 1
     *
     * returns rng % (newmax - newmin) + newmin ; where
     *      newmax = maxInclusive ? max + 1 : max 
     *      newmin = minInclusive ? min + 1 : min 
     */    
    int randomRange(int rng , int min, int max, bool minInclusive = true, bool maxInclusive = false);
}
#endif
