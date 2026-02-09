#include <Servo.h>

char command;
bool autoMode = false;

int motor1A = 8;
int motor1B = 9;
int motor2A = 10;
int motor2B = 11;
int enable1 = 5;
int enable2 = 6;

int trigPin = 2;
int echoPin = 3;
int servoPin = 4;

Servo scanServo;

void setup() {
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  scanServo.attach(servoPin);
  scanServo.write(90);

  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    command = Serial.read();

    if (command == 'A') autoMode = true;
    if (command == 'M') autoMode = false;

    if (!autoMode) manualControl();
  }

  if (autoMode) autoDrive();
}

void manualControl() {
  if (command == 'F') forward();
  else if (command == 'B') backward();
  else if (command == 'L') left();
  else if (command == 'R') right();
  else if (command == 'S') stopCar();
}

void autoDrive() {
  long distance = getDistance();

  if (distance < 20) {
    stopCar();
    delay(300);

    scanServo.write(30);
    delay(400);
    long leftDist = getDistance();

    scanServo.write(150);
    delay(400);
    long rightDist = getDistance();

    scanServo.write(90);

    if (leftDist > rightDist) left();
    else right();

    delay(500);
  } else {
    forward();
  }
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  long distance = duration * 0.034 / 2;
  return distance;
}

void forward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  analogWrite(enable1, 200);
  analogWrite(enable2, 200);
}

void backward() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

void left() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void right() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

void stopCar() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}
