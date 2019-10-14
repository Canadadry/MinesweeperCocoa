#ifndef _CLOCK_
#define _CLOCK_

class Clock
{
public :

    Clock();
    unsigned int getElapsedTime() const;
    void reset();

private :

    unsigned int myStartTime;
};

#endif //end of _CLOCK_