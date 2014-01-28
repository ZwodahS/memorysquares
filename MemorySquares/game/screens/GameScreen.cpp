#include "GameScreen.hpp"
#include "../Game.hpp"
#include "../../z_framework/zf_common/f_conversion.hpp"
GameScreen::GameScreen(Game& game)
    : Screen(game)
    , _gameoverText("Gameover", game.assets.font_main, 24, sf::Color::White)
    , _scoreText("Score : 0", game.assets.font_main, 24, sf::Color::White)
    , _inGameScoreText("Score : 0", game.assets.font_main, 24, sf::Color::White)
    , _newGameButton(sf::Text("New", game.assets.font_main, 14), 100, 30)
    , _quitButton(sf::Text("Quit", game.assets.font_main, 14), 100, 30) 
{
    _board = new Board(game);
    _board->startGame();
    _gameoverText.setAlignment(zf::AlignmentData(), sf::FloatRect(0, 100, 296, 40));
    _scoreText.setAlignment(zf::AlignmentData(), sf::FloatRect(0, 140, 296, 40));
    _inGameScoreText.setAlignment(zf::AlignmentData(zf::X_Left, zf::Y_Center, sf::Vector2f(5, 0)), sf::FloatRect(0, 300, 296, 40));
    _newGameButton.setPosition(30, 180);
    _quitButton.setPosition(166, 180);
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
        _inGameScoreText.draw(window);
        if(_board->isGameOver())
        {
            _gameoverText.draw(window);
            _scoreText.draw(window);
            _newGameButton.draw(window);
            _quitButton.draw(window);
        }
    }
}

void GameScreen::update(sf::RenderWindow& window, const sf::Time& delta)
{
    if(_board != 0)
    {
        _board->update(window, delta);
        if(_board->isGameOver())
        {
            sf::Vector2f position = _game.mouse.getWorldPosition(window);
            _newGameButton.setHovered(_newGameButton.contains(position));
            _quitButton.setHovered(_quitButton.contains(position));
        }
    }
}

void GameScreen::inputs(sf::RenderWindow& window, const sf::Time& delta)
{
    sf::Vector2f position = _game.mouse.getWorldPosition(window);
    if(_board != 0)
    {
        if(_game.mouse.left.thisReleased)
        {
            if(!_board->isGameOver())
            {
                if(_board->click(position))
                {
                    if(_board->isGameOver())
                    {
                        _scoreText.setString("Score :" + zf::toString(_board->getScore()));
                    }
                    else
                    {
                        _inGameScoreText.setString("Score :" + zf::toString(_board->getScore()));
                    }
                }
            }
            else 
            {
                if(_newGameButton.contains(position))
                {
                    _board->startGame();
                    _inGameScoreText.setString("Score :" + zf::toString(_board->getScore()));
                }
                else if(_quitButton.contains(position))
                {
                    _game.exitGame();
                }
            }
        }
    }
}

void GameScreen::textInput(char c)
{
}

