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

void handleMovementCommand(char command);

void handleSpeedCommand(char command);

bool isMovementCommand(char command);

bool isSpeedCommand(char command);

void applyCurrentMovement();

void printRobotStatus();

bool isDiagnosticCommand(char command);

void handleDiagnosticCommand(char command);

#endif