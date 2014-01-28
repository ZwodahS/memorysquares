#include "Tile.hpp"
#include "../Game.hpp"
#include "../../z_framework/zf_sfml/f_common.hpp"
#include "../../z_framework/zf_common/f_conversion.hpp"
Tile::Tile(Game& game, int value)
    : _game(game), _value(value), _position(0, 0)
    , _number(zf::toString(value), game.assets.font_main, 24, sf::Color::White)
    , _animation(*this), _state(State_Revealed), _bound(0, 0, 96, 96)
{
    _border = zf::toVertexArrayLinesStrip(sf::FloatRect(0, 0, 96, 96));
    _bg = zf::toVertexArrayQuads(sf::FloatRect(0, 0, 96, 96));
    zf::setColor(_bg, sf::Color(50, 50, 50), true);
    _number.setAlignment(zf::AlignmentData(), sf::FloatRect(0, 0, 96,96 ));
}

Tile::~Tile()
{
}

void Tile::draw(sf::RenderWindow& window)
{
    window.draw(_bg);
    window.draw(_border);
    if(_state != State_Hidden)
    {
        _number.draw(window);
    }
}

void Tile::update(sf::RenderWindow& window, const sf::Time& delta)
{
    _animation.update(window, delta);
    if(_state == State_Hiding && !_animation.isAnimating())
    {
        _state = State_Hidden;
    }
    else if(_state == State_Revealing && !_animation.isAnimating())
    {
        _state = State_Revealed;
    }
}

bool Tile::isAnimating()
{
    return _animation.isAnimating();
}

void Tile::setPosition(const sf::Vector2f& position)
{
    _position = position;
    zf::setPosition(_border, position);
    zf::setPosition(_bg, position);
    _number.setPosition(position);
    _bound.left = position.x;
    _bound.top = position.y;
}

void Tile::setAlpha(const float& alpha)
{
    // for tile, the set alpha is only used for setting the number.
    _number.setAlpha(alpha);
}

void Tile::move(const sf::Vector2f& move)
{
    setPosition(getPosition() + move);
}

sf::Vector2f Tile::getPosition()
{
    return _position;
}

void Tile::setScale(const float& x, const float& y)
{
}


void Tile::reveal()
{
    _animation.fade(0, 255, 1);
    _state = State_Revealing;
}

void Tile::hide()
{
    _animation.fade(255, 0, 1);
    _state = State_Hiding;
}

void Tile::setIntValue(int i)
{
    _value = i;
    _number.setString(zf::toString(_value));
}

int Tile::getValue()
{
    return _value;
}

void Tile::instantHide()
{
    _state = State_Hidden;
    _number.setAlpha(0);
    _animation.stopAll();
}

void Tile::instantReveal()
{
    _state = State_Revealed;
    _number.setAlpha(255);
    _animation.stopAll();
}

void Tile::moveTo(const sf::Vector2f& position, const float& duration)
{
    _animation.moveTo(_position, position, duration);
}

bool Tile::contains(const sf::Vector2f& position)
{
    return _bound.contains(position);
}
