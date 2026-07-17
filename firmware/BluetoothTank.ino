#include <ctype.h>
#include <arduino.h>

// LED Pin Definitions
const int leftMotorForward = 2;
const int leftMotorBackward = 3;
const int rightMotorForward = 4;
const int rightMotorBackward = 5;

// Define Constants
const char CMD_FORWARD = 'W';
const char CMD_BACKWARD = 'S';
const char CMD_LEFT = 'A';
const char CMD_RIGHT = 'D';
const char CMD_STOP = 'B';

void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void stopMotors();

char readCommand();
void executeCommand(char cmd);

void setup() {

  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);

  Serial.begin(9600);

  Serial.println("Mini Tank Ready!");
  Serial.println("Commands: W(forward) S(backward) A(left) D(right) B(stop)");

}

enum RobotState {
  STOPPED,
  MOVING_FORWARD,
  MOVING_BACKWARD,
  TURNING_LEFT,
  TURNING_RIGHT
};

RobotState currentState = STOPPED;

void moveForward(void){
       stopMotors();

       digitalWrite(leftMotorForward, HIGH);
       digitalWrite(rightMotorForward, HIGH);

       currentState = MOVING_FORWARD;

       Serial.println("Moving Forward");
}
void moveBackward(void){
       stopMotors();

       digitalWrite(leftMotorBackward, HIGH);
       digitalWrite(rightMotorBackward, HIGH);

       currentState = MOVING_BACKWARD;
       Serial.println("Moving Backward");
}
void turnLeft(void){
        stopMotors();

        digitalWrite(leftMotorBackward, HIGH);
        digitalWrite(rightMotorForward, HIGH);

        currentState = TURNING_LEFT;

        Serial.println("Turning Left");
}
void turnRight(void){
        stopMotors();

        digitalWrite(leftMotorForward, HIGH);
        digitalWrite(rightMotorBackward, HIGH);

        currentState = TURNING_RIGHT;
        Serial.println("Turning Right");
}
void stopMotors(void){
       digitalWrite(leftMotorForward, LOW);
       digitalWrite(leftMotorBackward, LOW);
       digitalWrite(rightMotorForward, LOW);
       digitalWrite(rightMotorBackward, LOW);

       currentState = STOPPED;
}

char readCommand() {

  if (Serial.available() > 0) {
    return toupper(Serial.read());
  }

  return '\0';
}

void loop() {

  char cmd = readCommand();

  if (cmd != '\0') {
    executeCommand(cmd);
  }
}

void executeCommand(char cmd) {

  switch (cmd) {

    case CMD_FORWARD:
      moveForward();
      break;

    case CMD_BACKWARD:
      moveBackward();
      break;

    case CMD_LEFT:
      turnLeft();
      break;

    case CMD_RIGHT:
      turnRight();
      break;

    case CMD_STOP:
      stopMotors();
      Serial.println("Stopped");
      break;

    default:
      Serial.println("Invalid Command");
  }

}