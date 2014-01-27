#ifndef _GAME_ASSETS_
#define _GAME_ASSETS_
#include <SFML/Graphics.hpp>
#include "../z_framework/zf_sfml/SpriteSheet.hpp"
#include "../z_framework/zf_sfml/TextureRegion.hpp"

struct Assets
{
    sf::Texture master1;
    zf::SpriteSheet masterS1;
    zf::SpriteSheet icons32S;

    sf::Font font_main;
};
#endif
