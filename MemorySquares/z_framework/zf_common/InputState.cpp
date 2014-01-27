#include "InputState.hpp"

namespace zf
{
    // just in case , set all the default value
    InputState::InputState()
        :thisDown(false), lastDown(false), thisPressed(false), thisHeld(false), thisReleased(false), timeHeld(0)
    {
    }
}
