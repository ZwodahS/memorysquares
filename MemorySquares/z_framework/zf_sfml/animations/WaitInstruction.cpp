#include "WaitInstruction.hpp"
namespace zf
{
    WaitInstruction::WaitInstruction(float waitTime)
        : _waitTimeLeft(waitTime)
    {
    }

    bool WaitInstruction::update(sf::RenderWindow& window, const sf::Time& delta, iAnimatable& object)
    {
        if(_waitTimeLeft < 0)
        {
            return true;
        }
        _waitTimeLeft -= delta.asSeconds();
        return false;
    }

    bool WaitInstruction::isDone(iAnimatable& object)
    {
        return _waitTimeLeft < 0;
    }
}
