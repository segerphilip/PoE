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
          if(buttonPush == 3) {
            buttonPush = 0;
          }
        }
      }
      buttonLast = buttonState;
      
      if(buttonPush == 1) {
        if(ledGState == LOW)
          ledGState = HIGH;
        else
          ledGState = LOW;
        digitalWrite(ledG, ledGState);
      }
  }
}
