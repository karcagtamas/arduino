#include <MaxMatrix.h>

int DIN = 7;
int CLK = 6;
int CS = 5;
int maxInUse = 2;

MaxMatrix m(DIN, CS, CLK, maxInUse);

byte A[] = {4, 8, 
            B01111110,
            B00010001,
            B00010001,
            B01111110,
           };

void setup() {
  // put your setup code here, to run once:
  m.init();
  m.setIntensity(8);
  // m.writeSprite(2, 0, A);
  m.setDot(15, 0, true);
  m.setDot(14, 0, true);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 16; i++){
    m.shiftLeft(false, false);
    delay(500);
  }
  m.clear();
  m.setDot(15, 0, true);
  m.setDot(14, 0, true);
}
