#include "ManagedText.hpp"
#include "f_common.hpp"
namespace zf
{
    ManagedText::ManagedText()
    {
    }
    ManagedText::ManagedText(const sf::Text& t)
        : text(t)
    {
    }

    ManagedText::ManagedText(const sf::String& string, const sf::Font& font, unsigned int characterSize, const sf::Color& color)
        : text(string, font, characterSize)
    {
        text.setColor(color);
    }

    ManagedText::~ManagedText()
    {
        text.setString(" ");
    }

    void ManagedText::setText(const sf::Text& t)
    {
        text = t;
        updatePosition();
    }

    void ManagedText::setAlignment(const zf::AlignmentData& data, const sf::FloatRect& bBox)
    {
        alignmentData = data;
        boundingBox = bBox;
        updatePosition();
    }
    
    void ManagedText::setString(const sf::String& string)
    {
        text.setString(string);
        updatePosition();
    }

    void ManagedText::setPosition(sf::Vector2f position)
    {
        boundingBox.left = position.x;
        boundingBox.top = position.y;
        updatePosition();
    }

    void ManagedText::setPosition(float x, float y)
    {
        boundingBox.left = x;
        boundingBox.top = y;
        updatePosition();
    }

    void ManagedText::setColor(const sf::Color& color)
    {
        text.setColor(color);
    }

    void ManagedText::setAlpha(const sf::Uint8& alpha)
    {
        zf::setAlpha(text, alpha);
    }

    void ManagedText::updatePosition()
    {
        zf::alignText(text, boundingBox, alignmentData);
    }

    void ManagedText::draw(sf::RenderWindow& window)
    {
        window.draw(text);
    }
    void ManagedText::draw(sf::RenderWindow& window, const sf::Time& delta)
    {
        window.draw(text);
    }

    void ManagedText::update(sf::RenderWindow& window, const sf::Time& delta)
    {
    }
}
