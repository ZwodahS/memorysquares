#ifndef _GAME_LOGIC_TILE_H_
#define _GAME_LOGIC_TILE_H_
#include "../../z_framework/zf_sfml/ManagedText.hpp"
#include "../../z_framework/zf_sfml/animations/iAnimatable.hpp"
#include "../../z_framework/zf_sfml/animations/AnimationComponent.hpp"
class Game;
class Tile : public zf::iAnimatable
{
public:
    Tile(Game& game, int value);
    ~Tile();

    int getValue();

    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window, const sf::Time& delta);

    void setPosition(const sf::Vector2f& position);
    void setAlpha(const float& alpha);
    void move(const sf::Vector2f& move);
    sf::Vector2f getPosition();
    void setScale(const float& x, const float& y);
    void moveTo(const sf::Vector2f& target, const float& duration = 1.0f);

    void setIntValue(int i);
    bool isAnimating();

    void reveal();
    void hide();
    void instantHide();
private:
    Game& _game;
    int _value;
    
    sf::Vector2f _position;
    sf::VertexArray _border;
    sf::VertexArray _bg;
    zf::ManagedText _number;

    zf::AnimationComponent _animation;
    
    enum State
    {
        State_Hidden,
        State_Hiding,
        State_Revealing,
        State_Revealed,
    } _state;
};
#endif
