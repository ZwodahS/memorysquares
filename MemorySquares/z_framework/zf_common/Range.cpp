#include "Range.hpp"
#include <iostream>
namespace zf
{
    int randomRange(int rng, Range<int> range)
    {
        return randomRange(rng, range.min, range.max, range.minInclusive, range.maxInclusive);
    }
    
    int randomRange(int rng, int min, int max, bool minInclusive, bool maxInclusive)
    {
        max = maxInclusive ? max + 1: max;
        min = minInclusive ? min : min + 1;
        int v = max <= min ? 0 : rng % (max - min);
        v += min;
        return v;
    }
}
