#ifndef _GAME_SCREENS_GAMESCREEN_H_
#define _GAME_SCREENS_GAMESCREEN_H_
#include "Screen.hpp"
#include "../logic/Board.hpp"
class GameScreen : public Screen
{
public:
    GameScreen(Game& game);
    ~GameScreen();

    virtual void draw(sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void inputs(sf::RenderWindow& window, const sf::Time& delta);
    virtual void textInput(char c);
private:
    Board* _board;
};
#endif
