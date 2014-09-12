//locations of leds, button, and pin of potentiometer - Never change
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

//counting! Used for bounce blinking
int count = 0;

//setup which pins go to the leds and button
void setup() {
  pinMode(button, INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
}

//code used for all the blinks
void loop() {
  //set the interval based on potentiometer location
  interval = analogRead(pin) / 2;
  unsigned long currentMillis = millis();
  buttonState = digitalRead(button);
  
  //timing used for delays
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
      
      //always set everything to off between button clicks
      if(buttonPush == 0) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledY, LOW);
        digitalWrite(ledR, LOW);
      }
      //set green led to blink
      if(buttonPush == 1) {
        if(ledGState == LOW)
          ledGState = HIGH;
        else
          ledGState = LOW;
        digitalWrite(ledG, ledGState);
      }
      //set yellow led to blink
      if(buttonPush == 2) {
        if(ledYState == LOW)
          ledYState = HIGH;
        else
          ledYState = LOW;
        digitalWrite(ledY, ledYState);
      }
      //set red led to blink
      if(buttonPush == 3) {
        if(ledRState == LOW)
          ledRState = HIGH;
        else
          ledRState = LOW;
        digitalWrite(ledR, ledRState);
      }
      //set all to blink
      if(buttonPush == 4) {
        if(ledGState != LOW)
          ledGState = LOW;
        else
          ledGState = HIGH;
        digitalWrite(ledG, ledGState);
        digitalWrite(ledY, ledGState);
        digitalWrite(ledR, ledGState);
      }
      //set the leds to bounce from one end to another
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
