#include <Arduino.h>

#include "Config.h"
#include "Motor.h"
#include "Bluetooth.h"
#include "Robot.h"
#include "Logger.h"

void setup()
{
    Serial.begin(9600);

    loggerInit();

    motorInit();
    bluetoothInit();
    robotInit();

    logInfo("Robot Started");
}

void loop()
{
    if (bluetoothAvailable())
    {
        char command = readBluetoothCommand();
        processCommand(command);
    }

    checkBluetoothTimeout();   
}