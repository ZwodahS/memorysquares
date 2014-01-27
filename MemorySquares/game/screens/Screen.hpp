#ifndef _GAME_SCREENS_SCREEN_H_
#define _GAME_SCREENS_SCREEN_H_
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
class Game;
class Screen
{
public:
    Screen(Game& game);
    virtual ~Screen();
    
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(sf::RenderWindow& window, const sf::Time& delta) = 0;
    virtual void inputs(sf::RenderWindow& window, const sf::Time& delta) = 0;
    virtual void textInput(char c) = 0;
    virtual void screenEnter();
    virtual void screenExit();
    
    /**
     * Defines the state of the screen. Currently only Exited is used. THe others are states
     * that can be used by child
     */
    enum ScreenState
    {
        Setup, // the preparation state before the screen is entering.
        Entering, // The components of the screen is entering in.
        Active, // The screen is active and ready.
        Exiting, // The screen is exiting
        Exited, // The screen has exited and is ready to be disposed.
    };

    ScreenState screenState;
protected:
    
    Game& _game;
        

};
#endif
