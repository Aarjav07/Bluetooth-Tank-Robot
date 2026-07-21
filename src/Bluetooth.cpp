#include <Arduino.h>
#include <SoftwareSerial.h>

#include "Bluetooth.h"

SoftwareSerial bluetooth(10, 11);

void bluetoothInit()
{
    bluetooth.begin(9600);

    Serial.println("[Bluetooth] Initialized");
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