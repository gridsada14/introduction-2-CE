#define pressed HIGH
#define pressedUp LOW

int ledState = LOW;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);  
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT);

  Serial.begin(9600); 
}

void loop() {
  int reading = digitalRead(12);
  
  
  if (reading != lastButtonState){
    lastDebounceTime = millis(); 
  }
  if((millis() - lastDebounceTime) > debounceDelay){
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(4, ledState);
  lastButtonState = buttonState;
  /*
  if(digitalRead(10) == HIGH){
    Serial.println("Press Switch1.");
    digitalWrite(4, !digitalRead(4));
  }
  if(digitalRead(9) == LOW){
    Serial.println("Press Switch2."); 
    digitalWrite(3, !digitalRead(3)); 
  }
  if(digitalRead(8) == LOW){
    Serial.println("Press Switch3.");
    digitalWrite(2, !digitalRead(2));   
  }
  delay(50);
  */
} 
