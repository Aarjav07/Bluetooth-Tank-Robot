#include <Arduino.h>

#include "Config.h"
#include "Motor.h"

void setup()
{
    Serial.begin(9600);

    motorInit();

    Serial.println("Robot Started");
}

void loop()
{

}