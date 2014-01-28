#include "Game.hpp"
#include "screens/Screen.hpp"
#include "screens/MainScreen.hpp"
#include "screens/GameScreen.hpp"
#include "../ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#define CLEAR_COLOR sf::Color(20,20,20,255)
#define GAME_TITLE "Memory Squares"


Game::Game()
    :width(ScreenSize.x), height(ScreenSize.y), title(GAME_TITLE),
    window(sf::VideoMode(width,height),title),mouse(), isFocused(true), _currentScreen(0), _nextScreen(0), _quit(false)
{
    window.setFramerateLimit(120);
    //window.setSize(sf::Vector2u(640, 720));
}

Game::~Game()
{

}

void Game::run()
{
    loadAssets();
    sf::Clock clock; // set up the clock for delta

    _currentScreen = new MainScreen(*this);
    // Default Generator
    while((!_quit || _currentScreen != 0) && window.isOpen())
    {
        // update clock 
        sf::Time delta = clock.restart();
        // update mouse.
        mouse.update(delta);
        

        // check for events, especially mousewheel
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                _quit = true;
            }
            else if(event.type == sf::Event::MouseWheelMoved)
            {
                mouse.wheelDelta = event.mouseWheel.delta;
            }
            else if(event.type == sf::Event::LostFocus)
            {
                isFocused = false;
            }
            else if(event.type == sf::Event::GainedFocus)
            {
                isFocused = true;
            }
        }

        // if not quit , update then draw.
        if(!_quit)
        {
            update(delta);
            draw(delta);
        }
    }
}

void Game::update(sf::Time delta)
{
    if(_currentScreen != 0)
    {
        if(isFocused || true)
        {
            _currentScreen->inputs(window, delta);
        }
        _currentScreen->update(window, delta);    
        if(_currentScreen->screenState == Screen::Exited)
        {
            delete _currentScreen;
            _currentScreen = 0;
            if(_nextScreen != 0)
            {
                _currentScreen = _nextScreen;
                _nextScreen = 0;
                _currentScreen->screenEnter();
            }
        }
    }
}

void Game::draw(sf::Time delta)
{
    window.clear(CLEAR_COLOR);
    if(_currentScreen != 0)
    {
        _currentScreen->draw(window);   
    }
    window.display();
}

void Game::startGame()
{
    _currentScreen->screenExit();
    GameScreen* gs = new GameScreen(*this);
    _nextScreen = gs;
}

void Game::exitGame()
{
    _currentScreen->screenExit();
    _quit = true;
}

void Game::exitToMainScreen()
{
    _currentScreen->screenExit();
    MainScreen* ms = new MainScreen(*this);
    _nextScreen = ms;
}

