#include <Arduino.h>
#include "Logger.h"

void loggerInit()
{
    // Reserved for future configuration
}

void logInfo(const char* message)
{
    Serial.print("[INFO] ");
    Serial.println(message);
}

void logWarning(const char* message)
{
    Serial.print("[WARN] ");
    Serial.println(message);
}

void logError(const char* message)
{
    Serial.print("[ERROR] ");
    Serial.println(message);
}