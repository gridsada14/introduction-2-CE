int ledState = LOW;
int buttonState;
int lastButtonState = LOW; 
long lastDebounceTime = 0;
long debounceDelay = 50;

void setup(){
  pinMode(4, OUTPUT);
  pinMode(12, INPUT);
}

void loop(){
  int reading = digitalRead(12);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
      if (reading != buttonState) {
        buttonState= reading;

        if (buttonState == HIGH) {
          ledState = !ledState;
        }
      }
  }
  digitalWrite(4, ledState);
  lastButtonState = reading;
}
