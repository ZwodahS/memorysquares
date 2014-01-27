#include "f_common.hpp"
namespace zf
{
    void setAlpha(sf::Sprite& sprite, const sf::Int32 alpha, sf::Uint8 max, sf::Uint8 min)
    {
        sf::Color c = sprite.getColor();
        c.a = alpha > max ? max : alpha < min ? min : alpha;
        sprite.setColor(c);
    }

    void setAlpha(sf::Text& text, sf::Uint8 alpha)
    {
        sf::Color c = text.getColor();
        c.a = alpha;
        text.setColor(c);
    }

    void setColor(sf::Text& text, const sf::Color& color, const bool& changeAlpha)
    {
        if(!changeAlpha)
        {
            sf::Color c = text.getColor();
            c.r = color.r;
            c.g = color.g;
            c.b = color.b;
            text.setColor(c);
        }
        else
        {
            text.setColor(color);
        }
    }

    void setColor(sf::Sprite& sprite, const sf::Color& color, const bool& changeAlpha)
    {
        if(!changeAlpha)
        {
            sf::Color c = sprite.getColor();
            c.r = color.r;
            c.g = color.g;
            c.b = color.b;
            sprite.setColor(c);
        }
        else
        {
            sprite.setColor(color);
        }
    }

    void setColor(sf::VertexArray& array, const sf::Color& color, const bool& changeAlpha)
    {
        for(int i = 0 ; i < array.getVertexCount(); i++)
        {
            if(!changeAlpha)
            {
                sf::Color c = array[i].color;
                c.r = color.r;
                c.g = color.g;
                c.b = color.b;
                array[i].color = c;
            }
            else
            {
                array[i].color = color;
            }
        }
    }
    /**
     * This is to replace the bug in sf::String which when an empty string is freed, causes a seg fault.
     *
     */
    void setString(sf::Text& text, const std::string& value)
    {
        if(value == "")
        {
            text.setString(" ");
        }
        else
        {
            text.setString(value);
        }
    }

    void alignSpriteCenter(sf::Sprite& sprite, const sf::Vector2f& position)
    {
        sf::FloatRect rect = sprite.getGlobalBounds();
        sprite.setPosition(position.x - (rect.width/2), position.y - (rect.height/2));
    }

    /**
     * Align a text based on some data and a position.
     * How this works ?
     * Say I have a text that have a width of 100 and height of 30.
     * Now I want to align it inside a rectangle. I can do it in many ways.
     * If I want to align it to the left side of the rectangle, I can specify a alignmentData of AlignmentX = X_Left, AlignmentY = Y_Center.
     * In this case the offset value is the offset from position. The position is the position of the rectangle that you want the text
     * to align to.
     * The final position of the text will be 
     *      x = (position.x + offset.x)
     *      y = (position.y + height/2 |(15)| + offset.y)
     * Example 2:
     * If I want to align the text to bottom right , I will specify the position value to be the bottom right position That I want to align to.
     * The final position of the text will be
     *      x = (position.x - width |(100)| - offset.x) <- (-)offset.x because you want to "move AWAY" from the position. a negative value will move it towards the position
     *      y = (position.y - height |(30)| - offset.y) <- (-)offset.y , same reason as offset.x
     * 
     * For the case of alignment to center, a positive value will move it downwards, and a negative value will move it upwards.
     */
    void alignText(sf::Text& text, const sf::Vector2f& position, const AlignmentData& alignmentData)
    {
        // need to take into account the non-zero value in the local bound of text.
        // see http://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
        sf::FloatRect rect = text.getLocalBounds();
        sf::Vector2f finalPosition;
        if(alignmentData.alignmentX == X_Left)
        {
            finalPosition.x = position.x - rect.left + alignmentData.offset.x;
        }
        else if(alignmentData.alignmentX == X_Center)
        {
            finalPosition.x = position.x - rect.left - (rect.width/2) + alignmentData.offset.x;
        }
        else //if(alignmentData.alignmentX == X_Right)
        {
            finalPosition.x = position.x - rect.left - rect.width - alignmentData.offset.x;
        }

        if(alignmentData.alignmentY == Y_Top)
        {
            finalPosition.y = position.y - rect.top + alignmentData.offset.y;
        }
        else if(alignmentData.alignmentY == Y_Center)
        {
            finalPosition.y = position.y - rect.top - (rect.height/2) + alignmentData.offset.y;
        }
        else //if(alignmentData.alignmentY == Y_Bottom)
        {
            finalPosition.y = position.y - rect.top - rect.height - alignmentData.offset.y;
        }
        text.setPosition(finalPosition);
    }
    /**
     * This is the method for aligning a text withing a bound. It makes use of the align Text based on position.
     */ 
    void alignText(sf::Text& text, const sf::FloatRect& bound, const AlignmentData& alignmentData)
    {
        // need to take into account the non-zero value in the local bound of text.
        // see http://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
        sf::FloatRect rect = text.getLocalBounds();
        sf::Vector2f finalPosition;
        if(alignmentData.alignmentX == X_Left)
        {
            finalPosition.x = bound.left - rect.left + alignmentData.offset.x;
        }
        else if(alignmentData.alignmentX == X_Center)
        {
            finalPosition.x = bound.left + (bound.width/2) - rect.left - (rect.width/2) + alignmentData.offset.x;
        }
        else //if(alignmentData.alignmentX == X_Right)
        {
            finalPosition.x = bound.left + bound.width - rect.left - rect.width - alignmentData.offset.x;
        }
        if(alignmentData.alignmentY == Y_Top)
        {
            finalPosition.y = bound.top - rect.top + alignmentData.offset.y;
        }
        else if(alignmentData.alignmentY == Y_Center)
        {
            finalPosition.y = bound.top + (bound.height/2) - rect.top - (rect.height/2) + alignmentData.offset.y;
        }
        else //if(alignmentData.alignmentY == Y_Bottom)
        {
            finalPosition.y = bound.top + bound.height - rect.top - rect.height - alignmentData.offset.y;
        }
        text.setPosition(finalPosition);
    }
    /**
     * Return the bound of this grid.
     * order ==> 
     * top left, top right, bottom right, bottom left
     */
    std::vector<sf::Vector2f> toVector2f(const zf::Grid& grid, const float& width, const float& height)
    {
        std::vector<sf::Vector2f> positions;
        positions.push_back(sf::Vector2f(grid.col * width, grid.row * height));
        positions.push_back(sf::Vector2f((grid.col + 1) * width , grid.row * height));
        positions.push_back(sf::Vector2f((grid.col + 1) * width , (grid.row + 1) * height ));
        positions.push_back(sf::Vector2f(grid.col * width, (grid.row + 1) * height ));
        return positions;
    }

    sf::FloatRect toFloatRect(const zf::Grid& grid, const float& width, const float& height)
    {
        return sf::FloatRect(grid.col * width, grid.row * height, width, height);
    }

    sf::Vector2f centerOf(const zf::Grid grid, const float& width, const float& height)
    {
        return sf::Vector2f(grid.col * width + (width/2), grid.row * height + (height / 2));
    }
    
    sf::Vector2f getTopLeftPosition(const sf::FloatRect& boundingBox, const sf::Vector2f& centerPoint)
    {
        sf::Vector2f finalPosition = sf::Vector2f(
                centerPoint.x - boundingBox.width / 2,
                centerPoint.y - boundingBox.height / 2);
        return finalPosition;
    }

    void setCenterPosition(iBoundable& boundable, const sf::Vector2f& position)
    {
        sf::Vector2f finalPosition = getTopLeftPosition(boundable.getBoundingBox(), position);
        boundable.setPosition(finalPosition);
    }

    sf::VertexArray toVertexArrayLinesStrip(const sf::FloatRect& bound)
    {
        sf::VertexArray array(sf::LinesStrip, 5);
        array[0] = sf::Vector2f(bound.left, bound.top + 1);
        array[1] = sf::Vector2f(bound.left + bound.width , bound.top + 1);
        array[2] = sf::Vector2f(bound.left + bound.width - 1, bound.top + bound.height );
        array[3] = sf::Vector2f(bound.left, bound.top + bound.height);
        array[4] = sf::Vector2f(bound.left, bound.top + 1);
        return array;
    }

    sf::VertexArray toVertexArrayQuads(const sf::FloatRect& bound)
    {
        sf::VertexArray array(sf::Quads, 4);
        array[0] = sf::Vector2f(bound.left, bound.top);
        array[1] = sf::Vector2f(bound.left + bound.width, bound.top);
        array[2] = sf::Vector2f(bound.left + bound.width, bound.top + bound.height);
        array[3] = sf::Vector2f(bound.left, bound.top + bound.height);
        return array;
    }

    sf::VertexArray calculateVertexArrayPosition(const sf::VertexArray& vArray, const sf::Vector2f& position)
    {
        sf::VertexArray array = vArray;
        for(int i = 0 ; i < vArray.getVertexCount() ; i++)
        {
            array[i].position = position + vArray[i].position - vArray[0].position;
        }
        return array;
    }
    void setPosition(sf::VertexArray& array, const sf::Vector2f& position)
    {
        sf::Vector2f origin = array[0].position;
        for(int i = 0 ; i < array.getVertexCount() ; i++)
        {
            array[i].position = position + array[i].position - origin;
        }
    }


    void moveVertexArray(sf::VertexArray& vArray, const sf::Vector2f& position)
    {
        sf::Vector2f origin = vArray[0].position;
        for(int i = 0 ; i < vArray.getVertexCount() ; i++)
        {
            vArray[i].position = position + vArray[i].position - origin;
        }
    }

}
