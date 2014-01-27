#ifndef _ZF_SFML_ALIGNMENTDATA_H_
#define _ZF_SFML_ALIGNMENTDATA_H_
#include "../zf_common/Alignment.hpp"
#include <SFML/System.hpp>
namespace zf
{
    struct AlignmentData
    {
        AlignmentData(AlignmentX x = zf::X_Center, AlignmentY y = zf::Y_Center, sf::Vector2f o = sf::Vector2f(0,0));
        AlignmentX alignmentX;
        AlignmentY alignmentY;
        sf::Vector2f offset;
    };
}
#endif
