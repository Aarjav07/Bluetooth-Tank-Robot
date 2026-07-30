#ifndef CONFIG_H
#define CONFIG_H

// Motor Driver Pins
constexpr uint8_t ENA = 3;
constexpr uint8_t IN1 = 2;
constexpr uint8_t IN2 = 4;

constexpr uint8_t ENB = 5;
constexpr uint8_t IN3 = 12;
constexpr uint8_t IN4 = 13;

constexpr uint8_t DEFAULT_SPEED = 255;

// Bluetooth Commands
constexpr char CMD_FORWARD  = 'W';
constexpr char CMD_BACKWARD = 'S';
constexpr char CMD_LEFT     = 'A';
constexpr char CMD_RIGHT    = 'D';
constexpr char CMD_STOP     = 'B';

// Speed Commands
constexpr char CMD_SPEED_25  = '1';
constexpr char CMD_SPEED_50  = '2';
constexpr char CMD_SPEED_75  = '3';
constexpr char CMD_SPEED_100 = '4';

// Speed PWM Commands
constexpr uint8_t SPEED_25_PWM  = 64;
constexpr uint8_t SPEED_50_PWM  = 128;
constexpr uint8_t SPEED_75_PWM  = 192;
constexpr uint8_t SPEED_100_PWM = 255;

#endif