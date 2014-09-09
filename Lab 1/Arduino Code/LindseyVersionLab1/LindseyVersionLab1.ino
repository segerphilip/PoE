const int ledG = 12;
const int ledY = 11;
const int ledR = 10;
const int button = 7;

//button counters
int buttonPush = 0;
int buttonState = 0;
int buttonLast = 0;


int ledGState = LOW;
int ledRState = LOW; 
int ledYState = LOW;

long previousMillis = 0; 
long interval = 50; 

void setup() {
  pinMode(button, INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
}

void loop() {
  buttonState = digitalRead(button);
  
  
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) { 
    previousMillis = currentMillis;
    
    if (buttonState != buttonLast) {
      if (buttonState == HIGH) {
        buttonPush++;
        if (buttonPush == 4) {
          buttonPush = 0;
        }
      Serial.println('buttonPush');
      }
    }
    buttonLast = buttonState;
  
    if (buttonPush == 0) {
      digitalWrite(ledG, LOW); 
      digitalWrite(ledR, LOW);
      digitalWrite(ledY, LOW);
    }
    else if (buttonPush == 1) {
      digitalWrite(ledY, LOW); 
      digitalWrite(ledR, LOW);
      
      if(ledGState == LOW){
        ledGState = HIGH;
      }else{
        ledGState = LOW;
      }
      digitalWrite(ledG, ledGState);
    } 
    else if (buttonPush == 2) {
      digitalWrite(ledG, LOW); 
      digitalWrite(ledR, LOW);
      digitalWrite(ledY, HIGH);
    }
    else if (buttonPush == 3) {
      digitalWrite(ledG, LOW); 
      digitalWrite(ledY, LOW);
      
     if(ledRState == LOW){
        ledRState = HIGH;
      }else{
        ledRState = LOW;
      }
      digitalWrite(ledR, ledRState); 
    }
  }
}

 
    
       
