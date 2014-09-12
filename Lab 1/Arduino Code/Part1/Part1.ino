const int ledG = 12;
const int ledY = 11;
const int ledR = 10;
const int button = 7;
const int pin = 5;

//led states
int ledGState = LOW;
int ledYState = LOW;
int ledRState = LOW;

//timing variables
long previousMillis = 0;
long interval = 50;

//button counters
int buttonPush = 0;
int buttonState = 0;
int buttonLast = 0;

//counting!
int count = 0;

void setup() {
  pinMode(button, INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
}

void loop() {
  interval = analogRead(pin) / 2;
  unsigned long currentMillis = millis();
  buttonState = digitalRead(button);
  
  if(currentMillis - previousMillis > interval) {
      previousMillis = currentMillis;
      
      if(buttonState != buttonLast) {
        if(buttonState == HIGH) {
          buttonPush++;
          if(buttonPush == 6) {
            buttonPush = 0;
          }
        }
      }
      buttonLast = buttonState;
      digitalWrite(ledG, LOW);
      digitalWrite(ledY, LOW);
      digitalWrite(ledR, LOW);
      
      if(buttonPush == 0) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledY, LOW);
        digitalWrite(ledR, LOW);
      }
      if(buttonPush == 1) {
        if(ledGState == LOW)
          ledGState = HIGH;
        else
          ledGState = LOW;
        digitalWrite(ledG, ledGState);
      }
      if(buttonPush == 2) {
        if(ledYState == LOW)
          ledYState = HIGH;
        else
          ledYState = LOW;
        digitalWrite(ledY, ledYState);
      }
      if(buttonPush == 3) {
        if(ledRState == LOW)
          ledRState = HIGH;
        else
          ledRState = LOW;
        digitalWrite(ledR, ledRState);
      }
      if(buttonPush == 4) {
        if(ledGState != LOW)
          ledGState = LOW;
        else
          ledGState = HIGH;
        digitalWrite(ledG, ledGState);
        digitalWrite(ledY, ledGState);
        digitalWrite(ledR, ledGState);
      }
      if(buttonPush == 5) {
        if(count == 0) {
          ledGState = HIGH;
          ledYState = LOW;
          ledRState = LOW;
          count++;
        }
        else if(count == 1) {
          ledGState = LOW;
          ledYState = HIGH;
          ledRState = LOW;
          count++;
        }
        else if(count == 2) {
          ledGState = LOW;
          ledYState = LOW;
          ledRState = HIGH;
          count++;
        }
        else if(count == 3) {
          ledGState = LOW;
          ledYState = HIGH;
          ledRState = LOW;
          count = 0;
        }
        digitalWrite(ledG, ledGState);
        digitalWrite(ledY, ledYState);
        digitalWrite(ledR, ledRState);
      }
  }
}
