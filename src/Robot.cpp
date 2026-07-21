#include <Arduino.h>

#include "Robot.h"
#include "Motor.h"
#include "Config.h"

void robotInit()
{
    Serial.println("[Robot] Initialized");
}

void processCommand(char command)
{
    switch(command)
    {
        case CMD_FORWARD:
            moveForward();
            break;

        case CMD_BACKWARD:
            moveBackward();
            break;

        case CMD_LEFT:
            turnLeft();
            break;

        case CMD_RIGHT:
            turnRight();
            break;

        case CMD_STOP:
            stopMotors();
            break;

        default:
            break;
    }
}