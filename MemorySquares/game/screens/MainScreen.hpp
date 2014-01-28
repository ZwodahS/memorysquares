#ifndef _GAME_SCREENS_MAINSCREEN_H_
#define _GAME_SCREENS_MAINSCREEN_H_
#include "Screen.hpp"
#include "../../z_framework/zf_sfml/VertexButton.hpp"
#include "../../z_framework/zf_sfml/ManagedText.hpp"
class MainScreen : public Screen
{
public :
    static const sf::Vector2f Button_Size;
    static const sf::FloatRect Start_Button_Bound;
    static const sf::FloatRect Exit_Button_Bound;
    static const sf::FloatRect Previous_Button_Bound;
    static const sf::FloatRect Next_Button_Bound;
    static const sf::FloatRect ConfirmStart_Button_Bound;
    static const sf::FloatRect Cancel_Button_Bound;

    static const sf::Color Button_FontColor;
    static const sf::Color Button_BorderColor;
    static const sf::Color Button_BaseColor;
    static const sf::Color Button_HoveredColor;
    static const sf::Color Button_SelectedColor;
    static const sf::Color Button_DisabledColor;

    MainScreen(Game& game);
    ~MainScreen();
    
    virtual void draw(sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void inputs(sf::RenderWindow& window, const sf::Time& delta);
    virtual void textInput(char c);

private:

    zf::VertexButton _startButton;
    zf::VertexButton _exitButton;

    sf::Vector2f _mouseDownPosition;

    zf::ManagedText _nameText;
    sf::Text _nameSquare;
    zf::ManagedText _helpText1;
    zf::ManagedText _helpText2;

    void buttonclick_startGame();
    void buttonclick_exitGame();

};
#endif
