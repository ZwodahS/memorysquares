/**
 * This file stores all the constants variable.
 * The main reason is to specifically decide which constants gets defined first in case there are dependency.
 */
#include "Game.hpp"
#include "screens/MainScreen.hpp"
#include "screens/GameScreen.hpp"
#include "../z_framework/zf_sfml/f_common.hpp"
// Game
const sf::Vector2f Game::ScreenSize = sf::Vector2f(296, 360);

// MainScreen
const sf::Vector2f MainScreen::Button_Size = sf::Vector2f(150, 30);
const sf::FloatRect MainScreen::Start_Button_Bound = sf::FloatRect((Game::ScreenSize.x / 2) - (Button_Size.x/2), 100 , Button_Size.x, Button_Size.y);
const sf::FloatRect MainScreen::Load_Button_Bound = sf::FloatRect((Game::ScreenSize.x / 2) - (Button_Size.x/2), 150 , Button_Size.x, Button_Size.y);
const sf::FloatRect MainScreen::Exit_Button_Bound = sf::FloatRect((Game::ScreenSize.x / 2) - (Button_Size.x/2), 200 , Button_Size.x, Button_Size.y);

const sf::Color MainScreen::Button_FontColor = sf::Color(0, 0, 0);
const sf::Color MainScreen::Button_BorderColor = sf::Color(255, 255, 255);
const sf::Color MainScreen::Button_BaseColor = sf::Color(100, 100, 100);
const sf::Color MainScreen::Button_HoveredColor = sf::Color(150, 150, 100);
const sf::Color MainScreen::Button_SelectedColor = sf::Color(150, 150, 100);
const sf::Color MainScreen::Button_DisabledColor = sf::Color(20, 20, 20);

// GameScreen
