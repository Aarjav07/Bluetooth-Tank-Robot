#ifndef CONFIG_H
#define CONFIG_H

// Motor Driver Pins
constexpr uint8_t ENA = 3;
constexpr uint8_t IN1 = 2;
constexpr uint8_t IN2 = 4;

constexpr uint8_t ENB = 5;
constexpr uint8_t IN3 = 12;
constexpr uint8_t IN4 = 13;

// Bluetooth Commands
constexpr char CMD_FORWARD  = 'W';
constexpr char CMD_BACKWARD = 'S';
constexpr char CMD_LEFT     = 'A';
constexpr char CMD_RIGHT    = 'D';
constexpr char CMD_STOP     = 'B';

#endif