#ifndef ROBOT_H
#define ROBOT_H

enum class RobotState
{
    STOPPED,
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

void robotInit();

void processCommand(char command);

RobotState getRobotState();

void setSpeed(uint8_t speed);

uint8_t getSpeed();

#endif