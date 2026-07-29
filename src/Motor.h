#ifndef MOTOR_H
#define MOTOR_H

void motorInit();

void moveForward(uint8_t speed);
void moveBackward(uint8_t speed);
void turnLeft(uint8_t speed);
void turnRight(uint8_t speed);

void stopMotors();

#endif