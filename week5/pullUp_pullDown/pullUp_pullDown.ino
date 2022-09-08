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
  delay(500);
} 
