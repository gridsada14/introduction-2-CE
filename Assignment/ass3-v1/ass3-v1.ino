int number;
int bitPattern[10] = {B0111111,B0000110,B1011011,B1010111,B1100110,B1110101,B1111101,B0000111,B1111111,B1110111};   // must reverse pattern -> g f e d ...
const byte numPins = 7;
const int segmentPins[7] = {6, 7, 8, 9, 10, 11, 12};    // a b c d ...
void setup () {
  Serial.begin(9600);
  for (int i = 0; i < numPins; i++)
    pinMode(segmentPins[i], OUTPUT);

}
void loop () {
    boolean isBitSet;

  for(int n = 0; n < 10; n++){
    for (int segment = 0; segment < 8; segment++){
      isBitSet = bitRead(bitPattern[n], segment);
      digitalWrite(segmentPins[segment], !isBitSet);
    }
    Serial.println(n);
    delay(500);
  }
  
}
