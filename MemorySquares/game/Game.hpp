#ifndef _GAME_GAME_H_
#define _GAME_GAME_H_

#include "Assets.hpp"
#include "../z_framework/zf_sfml/Mouse.hpp"
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
class Screen;
class Game
{
    public:
        static const sf::Vector2f ScreenSize;
        Game();
        ~Game();
        void run(); 

        const sf::Int32 width;
        const sf::Int32 height;
        std::string title;
        sf::RenderWindow window; 
        zf::Mouse mouse;
        bool isFocused;
        Assets assets;
        void loadAssets();

        // from mainscreen
        void startGame();
        void loadGame();
        void exitGame();

        // from gamescreen
        void exitToMainScreen();

    private:
        void update(sf::Time delta);
        void draw(sf::Time delta);
        
        Screen* _currentScreen;        
        Screen* _nextScreen;

        bool _quit;

};


#endif

