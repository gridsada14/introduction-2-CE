int ledStateR = LOW;
int buttonStateR;
int lastButtonStateR= LOW; 
long lastDebounceTimeR= 0;

int ledStateM = LOW;
int buttonStateM;
int lastButtonStateM= LOW; 
long lastDebounceTimeM= 0;

int ledStateL = LOW;
int buttonStateL;
int lastButtonStateL= LOW; 
long lastDebounceTimeL= 0;

long debounceDelay= 50;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(12, INPUT);
}
void loop(){
  int readingR = digitalRead(8);
  int readingM = digitalRead(9);
  int readingL = digitalRead(12);

  // =========LEFT=========
  if (readingL != lastButtonStateL) {
    lastDebounceTimeL = millis();
  }
  if ((millis() - lastDebounceTimeL) > debounceDelay) {
      if (readingL != buttonStateL) {
        buttonStateL = readingL;

      if (buttonStateL == HIGH) {
        ledStateL = !ledStateL;  
      }
    }
  }
  digitalWrite(4, ledStateL);
  lastButtonStateL = readingL;
  
  // =========Mid==========
  if (readingM != lastButtonStateM) {
    lastDebounceTimeM = millis();
  }
  if ((millis() - lastDebounceTimeM) > debounceDelay) {
      if (readingM != buttonStateM) {
        buttonStateM = readingM;

      if (buttonStateM == LOW) {
        ledStateM = !ledStateM;  
      }
    }
  }
  digitalWrite(3, ledStateM);
  lastButtonStateM = readingM;
  
  // ========Right=========
  if (readingR != lastButtonStateR) {
    lastDebounceTimeR = millis();
  }
  if ((millis() - lastDebounceTimeR) > debounceDelay) {
      if (readingR != buttonStateR) {
        buttonStateR = readingR;

      if (buttonStateR == LOW) {
        ledStateR = !ledStateR;  
      }
    }
  }
  digitalWrite(2, ledStateR);
  lastButtonStateR = readingR;
  // ======================
}
