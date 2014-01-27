#include "MainScreen.hpp"
#include "../Game.hpp"
MainScreen::MainScreen(Game& game)
    : Screen(game)
    , _startButton(sf::Text("New Game", game.assets.font_main, 14), Start_Button_Bound.width, Start_Button_Bound.height, Button_BorderColor, Button_BaseColor, Button_HoveredColor, Button_SelectedColor, Button_DisabledColor)
    , _loadButton(sf::Text("Load Game", game.assets.font_main, 14), Load_Button_Bound.width, Load_Button_Bound.height, Button_BorderColor, Button_BaseColor, Button_HoveredColor, Button_SelectedColor, Button_DisabledColor)
    , _exitButton(sf::Text("Exit Game", game.assets.font_main, 14), Exit_Button_Bound.width, Exit_Button_Bound.height, Button_BorderColor, Button_BaseColor, Button_HoveredColor, Button_SelectedColor, Button_DisabledColor)
{
    _startButton.setPosition(Start_Button_Bound.left, Start_Button_Bound.top);
    _loadButton.setPosition(Load_Button_Bound.left, Load_Button_Bound.top);
    _exitButton.setPosition(Exit_Button_Bound.left, Exit_Button_Bound.top);

}

MainScreen::~MainScreen()
{
}

void MainScreen::draw(sf::RenderWindow& window)
{
    _startButton.draw(window);
    _loadButton.draw(window);
    _exitButton.draw(window);
}

void MainScreen::update(sf::RenderWindow& window, const sf::Time& delta)
{
    sf::Vector2f mousePosition = _game.mouse.getWorldPosition(window);
    _startButton.setHovered(_startButton.contains(mousePosition));
    _loadButton.setHovered(_loadButton.contains(mousePosition));
    _exitButton.setHovered(_exitButton.contains(mousePosition));
}

void MainScreen::inputs(sf::RenderWindow& window, const sf::Time& delta)
{
    sf::Vector2f mousePosition = _game.mouse.getWorldPosition(window);
    if(_game.mouse.left.thisPressed)
    {
        _mouseDownPosition = mousePosition;
    }
    if(_game.mouse.left.thisReleased)
    {
        if(_startButton.contains(_mouseDownPosition) && _startButton.contains(mousePosition))
        {
            buttonclick_startGame();
        }
        else if(_loadButton.contains(_mouseDownPosition) && _loadButton.contains(mousePosition))
        {
            buttonclick_loadGame();
        }
        else if(_exitButton.contains(_mouseDownPosition) && _exitButton.contains(mousePosition))
        {
            buttonclick_exitGame();
        }
    }
}

void MainScreen::textInput(char c)
{
}

void MainScreen::buttonclick_startGame()
{
    _game.startGame();
}

void MainScreen::buttonclick_loadGame()
{
    _game.loadGame();
}

void MainScreen::buttonclick_exitGame()
{
    _game.exitGame();
}

