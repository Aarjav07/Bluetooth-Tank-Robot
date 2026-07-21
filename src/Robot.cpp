#include <Arduino.h>

#include "Robot.h"
#include "Motor.h"
#include "Config.h"

static RobotState currentState = RobotState::STOPPED;

RobotState getRobotState()
{
    return currentState;
}

void robotInit()
{
    Serial.println("[Robot] Initialized");
}

void processCommand(char command)
{
    switch(command)
    {
        case CMD_FORWARD:
            if (currentState != RobotState::FORWARD)
            {
            moveForward();
            currentState = RobotState::FORWARD;

            Serial.println("[Robot] Moving Forward");
            }
            break;

        case CMD_BACKWARD:
            if (currentState != RobotState::BACKWARD)
            {
            moveBackward();
            currentState = RobotState::BACKWARD;

            Serial.println("[Robot] Moving Backward");
            }
            break;

        case CMD_LEFT:
            if (currentState != RobotState::LEFT)
            {
            turnLeft();
            currentState = RobotState::LEFT;

            Serial.println("[Robot] Turning Left");
            }
            break;

        case CMD_RIGHT:
            if (currentState != RobotState::RIGHT)
            {
            turnRight();
            currentState = RobotState::RIGHT;

            Serial.println("[Robot] Turning Right");
            }
            break;

        case CMD_STOP:
            if (currentState != RobotState::STOPPED)
            {
            stopMotors();
            currentState = RobotState::STOPPED;

            Serial.println("[Robot] Stopped");
            }
            break;

        default:
            Serial.print("[Robot] Unknown command: ");
            Serial.println(command);
            break;
    }
}
