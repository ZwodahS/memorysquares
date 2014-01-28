#include "MainScreen.hpp"
#include "../Game.hpp"
MainScreen::MainScreen(Game& game)
    : Screen(game)
    , _startButton(sf::Text("New Game", game.assets.font_main, 14), Start_Button_Bound.width, Start_Button_Bound.height, Button_BorderColor, Button_BaseColor, Button_HoveredColor, Button_SelectedColor, Button_DisabledColor)
    , _exitButton(sf::Text("Exit Game", game.assets.font_main, 14), Exit_Button_Bound.width, Exit_Button_Bound.height, Button_BorderColor, Button_BaseColor, Button_HoveredColor, Button_SelectedColor, Button_DisabledColor)
    , _nameText("Memory", game.assets.font_main, 24, sf::Color::White)
    , _nameSquare("2", game.assets.font_main, 18)
    , _helpText1("Click the square in order.", game.assets.font_main, 14, sf::Color::White)
    , _helpText2("Don't blink ! ", game.assets.font_main, 14, sf::Color::White)
{
    _startButton.setPosition(Start_Button_Bound.left, Start_Button_Bound.top);
    _exitButton.setPosition(Exit_Button_Bound.left, Exit_Button_Bound.top);

    _nameText.setAlignment(zf::AlignmentData(), sf::FloatRect(0, 50, 296, 40));
    _nameSquare.setPosition(sf::Vector2f(220, 50));
    _nameSquare.setColor(sf::Color::White);

    _helpText1.setAlignment(zf::AlignmentData(), sf::FloatRect(0, 130, 296, 20));
    _helpText2.setAlignment(zf::AlignmentData(), sf::FloatRect(0, 160, 296, 20));
}

MainScreen::~MainScreen()
{
}

void MainScreen::draw(sf::RenderWindow& window)
{
    _nameText.draw(window);
    window.draw(_nameSquare);
    _startButton.draw(window);
    _exitButton.draw(window);
    _helpText1.draw(window);
    _helpText2.draw(window);
}

void MainScreen::update(sf::RenderWindow& window, const sf::Time& delta)
{
    sf::Vector2f mousePosition = _game.mouse.getWorldPosition(window);
    _startButton.setHovered(_startButton.contains(mousePosition));
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

void MainScreen::buttonclick_exitGame()
{
    _game.exitGame();
}

