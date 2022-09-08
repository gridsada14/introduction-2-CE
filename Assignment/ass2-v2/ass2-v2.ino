int button1 = 7;
int button2 = 6;
int button3 = 5;

int led1 = 10;
int led2 = 9;
int led3 = 8;

bool ledState1 = LOW;
bool ledState2 = LOW;
bool ledState3 = LOW;

bool buttonState1 = HIGH;
bool buttonState2 = HIGH;
bool buttonState3 = LOW;

bool lastButtonState1 = HIGH;
bool lastButtonState2 = HIGH;
bool lastButtonState3 = LOW;

long lastDebounceTime1 = 0;
long lastDebounceTime2 = 0;
long lastDebounceTime3 = 0;
long debounceDelay = 50;

long lastTimer1 = 0;
long lastTimer2 = 0;
long lastTimer3 = 0;

long blinkTimer = 0;
bool blinkFlag = 0;


void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // =============== #1 green ====================
  int reading1 = digitalRead(button1);

  if(reading1 != lastButtonState1){
    lastDebounceTime1 = millis();
  }

  if(millis() - lastDebounceTime1 > debounceDelay){
    if(reading1 != buttonState1){
      buttonState1 = reading1;
      
      if(reading1 == LOW){
        if(ledState1 == 0 && !ledState3){
          lastTimer1 = millis();
        }
        ledState1 = !ledState1;
      }
    }
    if(millis() - lastTimer1 > 3000){
      ledState1 = LOW;
    }
  }
  digitalWrite(led1, ledState1);
  lastButtonState1 = reading1;
  
  // =============== #2 yellow ====================
  int reading2 = digitalRead(button2);

  if(reading2 != lastButtonState2){
    lastDebounceTime2 = millis();
  }

  if(millis() - lastDebounceTime2 > debounceDelay){
    if(reading2 != buttonState2){
      buttonState2 = reading2;
      
      if(reading2 == LOW){
        if(ledState2 == 0 && !ledState3 && !ledState1){
          lastTimer2 = millis();
          blinkFlag = 1;
        }
      }
    }
    if(millis() - blinkTimer > 500 && blinkFlag == 1){
      blinkTimer = millis();
      ledState2 = !ledState2;
      
    }
    if(millis() - lastTimer2 > 2000){
      ledState2 = LOW;
      blinkFlag = 0;
    }
  }
  digitalWrite(led2, ledState2);
  lastButtonState2 = reading2;
  
  // =============== #3 red ====================
  int reading3 = digitalRead(button3);

  if(reading3 != lastButtonState3){
    lastDebounceTime3 = millis();
  }

  if(millis() - lastDebounceTime3 > debounceDelay){
    if(reading3 != buttonState3){
      buttonState3 = reading3;
      
      if(reading3 == HIGH){
        if(ledState3 == 0){
          lastTimer3 = millis();
        }
        ledState3 = !ledState3;
      }
    }
    if(millis() - lastTimer3 > 3000){
      ledState3 = LOW;
    }
  }
  digitalWrite(led3, ledState3);
  lastButtonState3 = reading3;
}
