const int ledG = 12;
const int ledY = 11;
const int ledR = 10;
const int button = 7;

//button counters
int buttonPush = 0;
int buttonState = 0;
int buttonLast = 0;

void setup() {
  pinMode(button, INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
}

void loop() {
  buttonState = digitalRead(button);
  if (buttonState != buttonLast) {
    if (buttonState == HIGH) {
      buttonPush++;
      if (buttonPush == 15) {
        buttonPush = 0;
      }
      Serial.println(buttonPush);
    }
  }
  buttonLast = buttonState;
  
  if (buttonPush == 1) {
    digitalWrite(ledG, HIGH);
  }
  else if (buttonPush == 2) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
  }
  else if (buttonPush == 3) {
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH);
  }
  else if (buttonPush == 4) {
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    delay(50);
    digitalWrite(ledG, LOW);
  }
  else if (buttonPush == 5) {
    digitalWrite(ledY, HIGH);
    delay(50);
    digitalWrite(ledY, LOW);
  }
  else if (buttonPush == 6) {
    digitalWrite(ledR, HIGH);
    delay(50);
    digitalWrite(ledR, LOW);
  }
  else if (buttonPush == 7) {
    digitalWrite(ledG, HIGH);
  }
  else if (buttonPush == 8) {
    digitalWrite(ledY, HIGH);
  }
  else if (buttonPush == 9) {
    digitalWrite(ledR, HIGH);
  }
  else if (buttonPush == 10) {
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    delay(50);
    digitalWrite(ledG, LOW);
  }
  else if (buttonPush == 11) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    delay(50);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
  }
  else if (buttonPush == 12) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    delay(50);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
  }
  else if (buttonPush == 13) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    delay(50);
    digitalWrite(ledR, LOW);
    delay(50);
    digitalWrite(ledG, HIGH);
    delay(50);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(50);
  }
  else if (buttonPush == 14) {
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    delay(100);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    delay(50);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH);
    delay(100);
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, HIGH);
    delay(50);
    //digitalWrite(ledY, LOW);
    //digitalWrite(ledG, HIGH);
    //delay(50);
  }
  else {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
  }
  delay(50);
}
