#include "AlignmentData.hpp"

namespace zf
{
    AlignmentData::AlignmentData(AlignmentX x, AlignmentY y, sf::Vector2f o)
        : alignmentX(x), alignmentY(y), offset(o)
    {
    }
}
