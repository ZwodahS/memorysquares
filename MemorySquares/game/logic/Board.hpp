#ifndef _GAME_LOGIC_BOARD_H_
#define _GAME_LOGIC_BOARD_H_
#include "../../z_framework/zf_common/TwoDSpace.hpp"
#include <SFML/Graphics.hpp>
class Tile;
class Game;
class Board
{
public:
    static const float Show_Duration;
    Board(Game& _game);
    ~Board();

    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window, const sf::Time& delta);

    sf::Vector2f getTilePosition(const int& row, const int& col);

    void startGame();
private:
    Game& _game;
    sf::Vector2f _position;

    zf::TwoDSpace<Tile*> _tiles;

    enum State
    {
        State_Init,
        State_Showing, //showing the starting square.
        State_Hiding, // fading the squares
        State_Hidden,
        State_Moving, // moving the squares around,
        State_Solving,
        State_Solved,
    } _state;
    int _currentLevel;
    int _moveCounter;
    float _showTimer;
    void update_stateInit(sf::RenderWindow& window, const sf::Time& delta);
    void update_stateShowing(sf::RenderWindow& window, const sf::Time& delta);
    void update_stateHiding(sf::RenderWindow& window, const sf::Time& delta);
    void update_stateHidden(sf::RenderWindow& window, const sf::Time& delta);
    void update_stateMoving(sf::RenderWindow& window, const sf::Time& delta);
    void update_stateSolving(sf::RenderWindow& window, const sf::Time& delta);
    void update_stateSolved(sf::RenderWindow& window, const sf::Time& delta);

    Tile* _outgoingTile;
    // if rowOrCol == 0 , then shift row, else col
    // if inOrOut == 0 , then shift in the negative direction ,else positive
    void shift(int rowOrCol, int rowColNum, int inOrOut);

    sf::VertexArray _cover;
};
#endif
