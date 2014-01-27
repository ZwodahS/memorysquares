#include "Board.hpp"
#include "Tile.hpp"
#include "../../z_framework/zf_sfml/f_common.hpp"
#include <cstdlib>
const float Board::Show_Duration = 2.0f;
Board::Board(Game& game)
    : _game(game), _tiles(3, 3, 0), _position(0, 0), _state(State_Init), _showTimer(0), _currentLevel(1), _moveCounter(0), _outgoingTile(0)
{
    int i = 1 ;
    for(int r = 0 ; r < 3 ; r++)
    {
        for(int c = 0 ; c < 3 ; c++, i++)
        {
            Tile* tile = new Tile(_game, i);
            tile->setPosition(getTilePosition(r, c));
            _tiles.set(r, c, tile);
        }
    }
    _cover = zf::toVertexArrayQuads(sf::FloatRect(0, 296, 296, 100));
    zf::setColor(_cover, sf::Color(0, 0, 0, 255), true);
}

Board::~Board()
{
    if(_outgoingTile != 0)
    {
        delete _outgoingTile;
    }
    for(zf::TwoDSpace<Tile*>::Iterator it = _tiles.iteratesColRow(); !it.end(); ++it)
    {
        Tile* tile = it.get();
        if(tile != 0)
        {
            delete tile;
        }
    }
}

void Board::draw(sf::RenderWindow& window)
{
    if(_outgoingTile != 0)
    {
        _outgoingTile->draw(window);
    }
    for(zf::TwoDSpace<Tile*>::Iterator it = _tiles.iteratesColRow(); !it.end(); ++it)
    {
        (*it.get()).draw(window);
    }
    window.draw(_cover);
}

void Board::update(sf::RenderWindow& window, const sf::Time& delta)
{
    for(zf::TwoDSpace<Tile*>::Iterator it = _tiles.iteratesColRow(); !it.end(); ++it)
    {
        (*it.get()).update(window, delta);
    }
    if(_outgoingTile != 0)
    {
        _outgoingTile->update(window, delta);
    }
    switch(_state)
    {
        case State_Init : update_stateInit(window, delta); break;
        case State_Showing : update_stateShowing(window, delta); break;
        case State_Hiding : update_stateHiding(window, delta); break;
        case State_Hidden : update_stateHidden(window, delta); break;
        case State_Moving : update_stateMoving(window, delta); break;
        case State_Solving : update_stateSolving(window, delta); break;
        case State_Solved : update_stateSolved(window, delta); break;
    }
}

void Board::update_stateInit(sf::RenderWindow& window, const sf::Time& delta)
{
}

void Board::update_stateShowing(sf::RenderWindow& window, const sf::Time& delta)
{
    _showTimer -= delta.asSeconds();
    if(_showTimer <= 0)
    {
        _state = State_Hiding;
        for(zf::TwoDSpace<Tile*>::Iterator it = _tiles.iteratesColRow(); !it.end(); ++it)
        {
            (*it.get()).hide();
        }
    }
}

void Board::update_stateHiding(sf::RenderWindow& window, const sf::Time& delta)
{
    bool hidden = true;
    for(zf::TwoDSpace<Tile*>::Iterator it = _tiles.iteratesColRow(); !it.end(); ++it)
    {
        if((*it.get()).isAnimating())
        {
            hidden = false;
            break;
        }
    }
    if(hidden)
    {
        _state = State_Hidden;
        _moveCounter = 0;
    }
}

void Board::update_stateHidden(sf::RenderWindow& window, const sf::Time& delta)
{
    if(_moveCounter < _currentLevel)
    {
        // decide how to move
        int rowOrCol = std::rand() % 2;
        int rowColNum = std::rand() % 3;
        int inOrOut = std::rand() % 2;
        shift(rowOrCol, rowColNum, inOrOut);
        _state = State_Moving;
        _moveCounter++;
    }
}

void Board::update_stateMoving(sf::RenderWindow& window, const sf::Time& delta)
{
    bool moving = false;
    for(zf::TwoDSpace<Tile*>::Iterator it = _tiles.iteratesColRow(); !it.end(); ++it)
    {
        if((*it.get()).isAnimating())
        {
            moving = true;
            break;
        }
    }
    if(!moving)
    {
        _state = State_Hidden;
        delete _outgoingTile;
        _outgoingTile = 0;
    }
}

void Board::update_stateSolving(sf::RenderWindow& window, const sf::Time& delta)
{
}

void Board::update_stateSolved(sf::RenderWindow& window, const sf::Time& delta)
{
}


sf::Vector2f Board::getTilePosition(const int& row, const int& col)
{
    return _position + sf::Vector2f(100 * col, 100 * row);
}

void Board::startGame()
{
    if(_state != State_Init)
    {
        return;
    }
    _state = State_Showing;
    _showTimer = Show_Duration;
    _moveCounter = 0;
    _currentLevel = 10;
    int i = 1;
    for(zf::TwoDSpace<Tile*>::Iterator it = _tiles.iteratesColRow() ; !it.end() ; ++it)
    {
        (*it.get()).setIntValue(i);
        i++;
    }
}

void Board::shift(int rowOrCol, int rowColNum, int inOrOut)
{
    if(rowOrCol == 0) // shift row
    {
        if(inOrOut == 0) // shift left
        {
            // move the first to -1 space
            _outgoingTile = _tiles.get(rowColNum, 0);
            _outgoingTile->moveTo(getTilePosition(rowColNum, -1));
            
            for(int i = 0 ; i < _tiles.col - 1 ; i++)
            {
                _tiles.set(rowColNum, i, _tiles.get(rowColNum, i + 1)); 
                _tiles.get(rowColNum, i)->moveTo(getTilePosition(rowColNum, i));
            }
            _tiles.set(rowColNum, _tiles.col - 1, new Tile(_game, _outgoingTile->getValue()));
            _tiles.get(rowColNum, _tiles.col - 1)->instantHide();
            _tiles.get(rowColNum, _tiles.col - 1)->setPosition(getTilePosition(rowColNum, _tiles.col));
            _tiles.get(rowColNum, _tiles.col - 1)->moveTo(getTilePosition(rowColNum, _tiles.col - 1));
        }
        else // shift right
        {
            _outgoingTile = _tiles.get(rowColNum, _tiles.row - 1);
            _outgoingTile->moveTo(getTilePosition(rowColNum, _tiles.row));

            for(int i = _tiles.col - 1; i > 0 ; i--)
            {
                _tiles.set(rowColNum, i, _tiles.get(rowColNum, i - 1)); 
                _tiles.get(rowColNum, i)->moveTo(getTilePosition(rowColNum, i));
            }

            _tiles.set(rowColNum, 0, new Tile(_game, _outgoingTile->getValue()));
            _tiles.get(rowColNum, 0)->instantHide();
            _tiles.get(rowColNum, 0)->setPosition(getTilePosition(rowColNum, -1));
            _tiles.get(rowColNum, 0)->moveTo(getTilePosition(rowColNum, 0));
        }
    }
    else // shift col
    {
        if(inOrOut == 0) // shift up
        {
            _outgoingTile = _tiles.get(0, rowColNum);
            _outgoingTile->moveTo(getTilePosition(-1, rowColNum));

            for(int i = 0 ; i < _tiles.row - 1 ; i++)
            {
                _tiles.set(i, rowColNum, _tiles.get(i + 1, rowColNum)); 
                _tiles.get(i, rowColNum)->moveTo(getTilePosition(i, rowColNum));
            }

            _tiles.set(_tiles.row - 1, rowColNum, new Tile(_game, _outgoingTile->getValue()));
            _tiles.get(_tiles.row - 1, rowColNum)->instantHide();
            _tiles.get(_tiles.row - 1, rowColNum)->setPosition(getTilePosition(_tiles.row, rowColNum));
            _tiles.get(_tiles.row - 1, rowColNum)->moveTo(getTilePosition(_tiles.row - 1, rowColNum));
        }
        else  // shift down
        {
            _outgoingTile = _tiles.get(_tiles.col - 1, rowColNum);
            _outgoingTile->moveTo(getTilePosition(_tiles.col, rowColNum));

            for(int i = _tiles.row - 1; i > 0 ; i--)
            {
                _tiles.set(i, rowColNum, _tiles.get(i - 1, rowColNum)); 
                _tiles.get(i, rowColNum)->moveTo(getTilePosition(i, rowColNum));
            }

            _tiles.set(0, rowColNum, new Tile(_game, _outgoingTile->getValue()));
            _tiles.get(0, rowColNum)->instantHide();
            _tiles.get(0, rowColNum)->setPosition(getTilePosition(-1, rowColNum));
            _tiles.get(0, rowColNum)->moveTo(getTilePosition(0, rowColNum));
        }
    }
}
