#include "GameScreen.hpp"

GameScreen::GameScreen(Game& game)
    : Screen(game)
{
    _board = new Board(game);
    _board->startGame();
}

GameScreen::~GameScreen()
{
    if(_board != 0)
    {
        delete _board;
    }
}

void GameScreen::draw(sf::RenderWindow& window)
{
    if(_board != 0)
    {
        _board->draw(window);
    }
}

void GameScreen::update(sf::RenderWindow& window, const sf::Time& delta)
{
    if(_board != 0)
    {
        _board->update(window, delta);
    }
}

void GameScreen::inputs(sf::RenderWindow& window, const sf::Time& delta)
{
}

void GameScreen::textInput(char c)
{
}

