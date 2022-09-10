int number;
int bitPattern[10] = {B0111111,B0000110,B1011011,B1010111,B1100110,B1110101,B1111101,B0000111,B1111111,B1110111};   // must reverse pattern -> g f e d ...
const byte numPins = 7;
const int segmentPins[7] = {6, 7, 8, 9, 10, 11, 12};  // a b c d ...

int buttonStateA;
int buttonStateB;
int lastButtonStateA = LOW;
int lastButtonStateB = LOW;
long lastDebounceTimeA = 0;
long lastDebounceTimeB = 0;

long debounceDelay = 50;

int n = 1;
bool flag = 1;
bool runNum = 1;
bool slowdownA = 0;

long preTime = 0;
int randomNum;

void setup () {
  Serial.begin(9600);
  for (int i = 0; i < numPins; i++)
    pinMode(segmentPins[i], OUTPUT);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  randomSeed(analogRead(A0));
  randomNum= random(1, 10);

  boolean isBitSet;
  for (int segment = 0; segment < 8; segment++){
    isBitSet = bitRead(bitPattern[1], segment);
    digitalWrite(segmentPins[segment], !isBitSet);
  } 
}
void loop () {
  boolean isBitSet;
  unsigned long currTime = millis();

  int btnA = digitalRead(2);
  int btnB = digitalRead(3);

  // ==================== button A ========================
  // Protect hold switch case
  if (btnA != lastButtonStateA){
    lastDebounceTimeA = millis();
  }

  Serial.print("Guess: ");
  Serial.print(n);
  Serial.print(", ");
  Serial.print("Random: ");
  Serial.println(randomNum);
  
  if((millis() - lastDebounceTimeA) > debounceDelay){
    if(btnA != buttonStateA){
      buttonStateA = btnA;  
    
      if(btnA == LOW){
        n++; 
        if(n >= 10){
          n = 0;
        }
        for (int segment = 0; segment < 8; segment++){
          isBitSet = bitRead(bitPattern[n], segment);
          digitalWrite(segmentPins[segment], !isBitSet);
        } 
        
      }
    }
  }

  lastButtonStateA = btnA;


  // ===================== button B ================================
  if(btnB != lastButtonStateB){
    lastDebounceTimeB = millis();
  }
  if(millis() - lastDebounceTimeB > debounceDelay){
    if(btnB != buttonStateB){
      buttonStateB = btnB;

      if(btnB == LOW){
        
        if(n == randomNum){
          for (int segment = 0; segment < 8; segment++){
            isBitSet = bitRead(B0111111, segment);
            digitalWrite(segmentPins[segment], !isBitSet);
          } 
          randomNum= random(1, 10);
        }
        else if(n > randomNum){
          for (int segment = 0; segment < 8; segment++){
            isBitSet = bitRead(B0111101, segment);
            digitalWrite(segmentPins[segment], !isBitSet);
          } 
        }
        else if(n < randomNum){
          for (int segment = 0; segment < 8; segment++){
            isBitSet = bitRead(B0111000, segment);
            digitalWrite(segmentPins[segment], !isBitSet);
          } 
        }
        
      }
    }
  }
  lastButtonStateB = btnB;
}
