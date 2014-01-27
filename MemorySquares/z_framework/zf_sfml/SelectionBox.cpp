#include "SelectionBox.hpp"
namespace zf
{
    SelectionBox::SelectionBox(int width, int height, int maxOffset, int minOffset, float movementPerSec = 2)
    {
        this->_width = width;
        this->_height = height;
        this->_maxOffset = maxOffset;
        this->_minOffset = minOffset;
        this->_offset = 0;
        this->_multiplier = 1;
        this->_movement = movementPerSec;
    }

    void SelectionBox::setSprites(sf::Sprite topLeft, sf::Sprite topRight, sf::Sprite bottomRight, sf::Sprite bottomLeft)
    {
        this->_topLeft = topLeft;
        this->_topRight = topRight;
        this->_bottomRight = bottomRight;
        this->_bottomLeft = bottomLeft;
        _position = sf::Vector2f(0,0);
    }

    void SelectionBox::setPosition(sf::Vector2f newPosition)
    {
        _position = newPosition;
    }

    void SelectionBox::update(sf::RenderWindow& window, const sf::Time& delta)
    {
        _offset += _multiplier * (delta.asSeconds() * _movement);
        if(_multiplier == -1 && _offset <= _minOffset )
        {
            _multiplier = 1;
        }
        else if(_multiplier == 1 && _offset >= _maxOffset)
        {
            _multiplier = -1;
        }
        _topLeft.setPosition(_position.x-_offset, _position.y-_offset);
        _topRight.setPosition(_position.x+_offset+_width-_topRight.getGlobalBounds().width, _position.y-_offset);
        _bottomLeft.setPosition(_position.x-_offset,_position.y+_offset+_height-_bottomLeft.getGlobalBounds().height);
        _bottomRight.setPosition(_position.x+_offset+_width-_bottomRight.getGlobalBounds().width, _position.y+_offset+_height-_bottomRight.getGlobalBounds().height);
    }
    void SelectionBox::draw(sf::RenderWindow& window, const sf::Time& delta)
    {
        window.draw(_topLeft);
        window.draw(_topRight);
        window.draw(_bottomLeft);
        window.draw(_bottomRight);
    }
}
