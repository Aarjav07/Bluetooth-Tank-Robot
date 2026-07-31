#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

void timerStart(unsigned long &timer);

bool timerExpired(unsigned long timer,
                  unsigned long interval);

#endif