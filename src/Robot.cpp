#include <Arduino.h>

#include "Robot.h"
#include "Motor.h"
#include "Config.h"

static RobotState currentState = RobotState::STOPPED;
static uint8_t currentSpeed = DEFAULT_SPEED;

RobotState getRobotState()
{
    return currentState;
}

void setSpeed(uint8_t speed)
{
    currentSpeed = speed;
}

uint8_t getSpeed()
{
    return currentSpeed;
}

void robotInit()
{
    Serial.println("[Robot] Initialized");
}

void processCommand(char command)
{
    if (isMovementCommand(command))
    {
        handleMovementCommand(command);
    }
    else if (isSpeedCommand(command))
    {
        handleSpeedCommand(command);
    }
    else
    {
        Serial.print("[Robot] Unknown command: ");
        Serial.println(command);
    }
}

bool isMovementCommand(char command)
{
    return command == CMD_FORWARD  ||
           command == CMD_BACKWARD ||
           command == CMD_LEFT     ||
           command == CMD_RIGHT    ||
           command == CMD_STOP;
}

void handleMovementCommand(char command)
{
    switch(command)
    {
        case CMD_FORWARD:
            if (currentState != RobotState::FORWARD)
            {
                moveForward(getSpeed());
                currentState = RobotState::FORWARD;
                Serial.println("[Robot] Moving Forward");
            }
            break;

        case CMD_BACKWARD:
            if (currentState != RobotState::BACKWARD)
            {
                moveBackward(getSpeed());
                currentState = RobotState::BACKWARD;
                Serial.println("[Robot] Moving Backward");
            }
            break;

        case CMD_LEFT:
            if (currentState != RobotState::LEFT)
            {
                turnLeft(getSpeed());
                currentState = RobotState::LEFT;
                Serial.println("[Robot] Turning Left");
            }
            break;

        case CMD_RIGHT:
            if (currentState != RobotState::RIGHT)
            {
                turnRight(getSpeed());
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
            break;
    }
}

bool isSpeedCommand(char command)
{
    return command == CMD_SPEED_25  ||
           command == CMD_SPEED_50  ||
           command == CMD_SPEED_75  ||
           command == CMD_SPEED_100;
} 

void handleSpeedCommand(char command)
{
    switch(command)
    {
        case CMD_SPEED_25:
            setSpeed(64);
            Serial.println("[Robot] Speed set to 25%");
            break;

        case CMD_SPEED_50:
            setSpeed(128);
            Serial.println("[Robot] Speed set to 50%");
            break;

        case CMD_SPEED_75:
            setSpeed(192);
            Serial.println("[Robot] Speed set to 75%");
            break;

        case CMD_SPEED_100:
            setSpeed(255);
            Serial.println("[Robot] Speed set to 100%");
            break;

        default:
            break;
    }
}