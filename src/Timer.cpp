#include "Timer.h"

void timerStart(unsigned long &timer)
{
    timer = millis();
}

bool timerExpired(unsigned long timer,
                  unsigned long interval)
{
    return (millis() - timer) >= interval;
}