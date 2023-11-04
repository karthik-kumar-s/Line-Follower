int leftSensorPin = 2;  // Left infrared sensor connected to digital pin 2
int rightSensorPin = 3; // Right infrared sensor connected to digital pin 3
int leftMotorPin = 5;   // Left motor control pin (PWM) connected to digital pin 5
int rightMotorPin = 6;  // Right motor control pin (PWM) connected to digital pin 6

void setup() {
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
}

void loop() {
  int leftSensorValue = digitalRead(leftSensorPin);
  int rightSensorValue = digitalRead(rightSensorPin);

  // If both sensors are on the line, move forward
  if (leftSensorValue == HIGH && rightSensorValue == HIGH) {
    moveForward();
  }
  // If both sensors are off the line, stop
  else if (leftSensorValue == LOW && rightSensorValue == LOW) {
    stopMoving();
  }
  // If left sensor is on the line, turn right
  else if (leftSensorValue == HIGH) {
    turnRight();
  }
  // If right sensor is on the line, turn left
  else if (rightSensorValue == HIGH) {
    turnLeft();
  }
}

void moveForward() {
  analogWrite(leftMotorPin, 200);  // Left motor forward at half speed
  analogWrite(rightMotorPin, 200); // Right motor forward at half speed
}

void stopMoving() {
  analogWrite(leftMotorPin, 0);  // Left motor stop
  analogWrite(rightMotorPin, 0); // Right motor stop
}

void turnLeft() {
  analogWrite(leftMotorPin, 0);   // Left motor stop
  analogWrite(rightMotorPin, 200); // Right motor forward at half speed (turn left)
}

void turnRight() {
  analogWrite(leftMotorPin, 200);  // Left motor forward at half speed (turn right)
  analogWrite(rightMotorPin, 0);   // Right motor stop
}
