#include "Screen.hpp"
#include "../Game.hpp"

Screen::Screen(Game& game)
    :_game(game), screenState(Setup)
{
}
Screen::~Screen()
{
}
void Screen::screenEnter()
{
    screenState = Active;
}

void Screen::screenExit()
{
    screenState = Exited;
}
