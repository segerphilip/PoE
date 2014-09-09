const int ledG = 12;
const int ledY = 11;
const int ledR = 10;
const int button = 7;

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

void setup() {
  pinMode(button, INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  buttonState = digitalRead(button);
  
  if(currentMillis - previousMillis > interval) {
      previousMillis = currentMillis;
      
      if(buttonState != buttonLast) {
        if(buttonState == HIGH) {
          buttonPush++;
          if(buttonPush == 5) {
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
  }
}
