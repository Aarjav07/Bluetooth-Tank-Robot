#include <Arduino.h>
#include "Config.h"
#include "Motor.h"

void motorInit()
{
    pinMode(ENA, OUTPUT);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    pinMode(ENB, OUTPUT);

    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    stopMotors();
}

void stopMotors()
{
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void moveForward()
{
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
    
    digitalWrite(IN3, HIGH); 
    digitalWrite(IN4, LOW);
}

void moveBackward()
{
    analogWrite(ENA, 255); 
    analogWrite(ENB, 255); 
    
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH); 
    
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, HIGH);
}