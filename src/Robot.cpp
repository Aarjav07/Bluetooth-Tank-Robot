#include <Arduino.h>

#include "Robot.h"
#include "Motor.h"
#include "Config.h"
#include "Timer.h"

bool isMovementCommand(char command);
bool isSpeedCommand(char command);
bool isDiagnosticCommand(char command);

void handleMovementCommand(char command);
void handleSpeedCommand(char command);
void handleDiagnosticCommand(char command);

const CommandGroup commandGroups[] =
{
    { isMovementCommand,   handleMovementCommand },
    { isSpeedCommand,      handleSpeedCommand },
    { isDiagnosticCommand, handleDiagnosticCommand }
};

static RobotState currentState = RobotState::STOPPED;
static uint8_t currentSpeed = DEFAULT_SPEED;
static unsigned long lastCommandTime = 0;

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
     timerStart(lastCommandTime);

    Serial.println("[Robot] Initialized");
}

void updateCommandTimestamp()
{
    timerStart(lastCommandTime);
}

void processCommand(char command)
{
    updateCommandTimestamp();

    for (const auto& group : commandGroups)
    {
        if (group.matcher(command))
        {
            group.handler(command);
            return;
        }
    }

    Serial.print("[Robot] Unknown command: ");
    Serial.println(command);
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
            setSpeed(SPEED_25_PWM);
            applyCurrentMovement();
            Serial.println("[Robot] Speed set to 25%");
            break;

        case CMD_SPEED_50:
            setSpeed(SPEED_50_PWM);
            applyCurrentMovement();
            Serial.println("[Robot] Speed set to 50%");
            break;

        case CMD_SPEED_75:
            setSpeed(SPEED_75_PWM);
            applyCurrentMovement();
            Serial.println("[Robot] Speed set to 75%");
            break;

        case CMD_SPEED_100:
            setSpeed(SPEED_100_PWM);
            applyCurrentMovement();
            Serial.println("[Robot] Speed set to 100%");
            break;

        default:
            break;
    }
}

void applyCurrentMovement()
{
    switch (currentState)
    {
        case RobotState::FORWARD:
            moveForward(getSpeed());
            break;

        case RobotState::BACKWARD:
            moveBackward(getSpeed());
            break;

        case RobotState::LEFT:
            turnLeft(getSpeed());
            break;

        case RobotState::RIGHT:
            turnRight(getSpeed());
            break;

        case RobotState::STOPPED:
            // Nothing to update
            break;
    }
}

bool isDiagnosticCommand(char command)
{
    return command == CMD_STATUS;
}

void handleDiagnosticCommand(char command)
{
    switch (command)
    {
        case CMD_STATUS:
            printRobotStatus();
            break;

        default:
            break;
    }
}

void printRobotStatus()
{
    Serial.println();
    Serial.println("========== ROBOT STATUS ==========");

    Serial.print("State : ");

    switch (currentState)
    {
        case RobotState::STOPPED:
            Serial.println("STOPPED");
            break;

        case RobotState::FORWARD:
            Serial.println("FORWARD");
            break;

        case RobotState::BACKWARD:
            Serial.println("BACKWARD");
            break;

        case RobotState::LEFT:
            Serial.println("LEFT");
            break;

        case RobotState::RIGHT:
            Serial.println("RIGHT");
            break;
    }

    Serial.print("Speed : ");
    Serial.println(getSpeed());

    Serial.println("==================================");
    Serial.println();
}

void checkBluetoothTimeout()
{
    if (currentState == RobotState::STOPPED)
    {
        return;
    }

    if (timerExpired(lastCommandTime, BLUETOOTH_TIMEOUT_MS))
    {
        stopMotors();
        currentState = RobotState::STOPPED;

        Serial.println("[Robot] Bluetooth Timeout - Emergency Stop");
    }
}