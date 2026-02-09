int forwardBtn = 2;
int backwardBtn = 3;
int leftBtn = 4;
int rightBtn = 5;
int stopBtn = 6;
int autoBtn = 7;

void setup() {
  pinMode(forwardBtn, INPUT_PULLUP);
  pinMode(backwardBtn, INPUT_PULLUP);
  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);
  pinMode(stopBtn, INPUT_PULLUP);
  pinMode(autoBtn, INPUT_PULLUP);

  Serial.begin(9600); // Bluetooth
}

void loop() {

  if (digitalRead(forwardBtn) == LOW) {
    Serial.write('F');
    delay(200);
  }
  else if (digitalRead(backwardBtn) == LOW) {
    Serial.write('B');
    delay(200);
  }
  else if (digitalRead(leftBtn) == LOW) {
    Serial.write('L');
    delay(200);
  }
  else if (digitalRead(rightBtn) == LOW) {
    Serial.write('R');
    delay(200);
  }
  else if (digitalRead(stopBtn) == LOW) {
    Serial.write('S');
    delay(200);
  }
  else if (digitalRead(autoBtn) == LOW) {
    Serial.write('A');
    delay(300);
  }
}
