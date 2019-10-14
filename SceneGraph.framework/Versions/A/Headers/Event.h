#ifndef _EVENT_HPP
#define _EVENT_HPP

namespace Mouse
{
    enum Button
    {
        Left,
        Right,
        Middle
    };
}

class Event
{
public :

    struct MouseEvent
    {
        int           X;
        int           Y;
        Mouse::Button Button;
    };

    struct MouseWheelEvent
    {
        int Delta;
    };

    struct SizeEvent
    {
        unsigned int Width;
        unsigned int Height;
    };

    enum EventType
    {
        Closed,
        Resized,
        LostFocus,
        GainedFocus,
        MouseWheelMoved,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseEntered,
        MouseLeft
    };

    EventType Type;

    union
    {
        MouseEvent       Mouse;
        MouseWheelEvent  Wheel;
        SizeEvent        Size;
    };
};

#endif // end of _EVENT_HPP
