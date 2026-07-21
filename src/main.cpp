#include <Arduino.h>

#include "Config.h"
#include "Motor.h"
#include "Bluetooth.h"
#include "Robot.h"

void setup()
{
    Serial.begin(9600);

    motorInit();
    bluetoothInit();
    robotInit();

    Serial.println("Robot Started");
}

void loop()
{
     if (bluetoothAvailable())
    {
        char command = readBluetoothCommand();

        processCommand(command);
    }
}