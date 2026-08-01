#include <Arduino.h>
#include <SoftwareSerial.h>

#include "Bluetooth.h"
#include "Logger.h"

SoftwareSerial bluetooth(10, 11);

void bluetoothInit()
{
    bluetooth.begin(9600);

    logInfo("[Bluetooth] Initialized");
}

bool bluetoothAvailable()
{
    return bluetooth.available();
}

char readBluetoothCommand()
{
    if (bluetooth.available())
    {
        return bluetooth.read();
    }

    return '\0';
}