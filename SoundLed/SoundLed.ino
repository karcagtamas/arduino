#include <SoftwareSerial.h>

// 6 - RX
// 5 - TX
SoftwareSerial BluetoothStick(6, 5);
char flag = '1';
bool run = true;
int LED = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BluetoothStick.begin(38400);
  pinMode(LED, OUTPUT);
  Serial.println("Ready to connect\nDefault password is 1234 or 000");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BluetoothStick.available()) {
    // flag = BluetoothStick.read();
    // Serial.write(BluetoothStick.read());
  }

  if (Serial.available()) {
    char input = Serial.read();
    flag = input[0];
  }

  if (flag == '1') {
    digitalWrite(LED, HIGH);
    Serial.println("Led ON");  
  }
  else if (flag == '0') {
    digitalWrite(LED, LOW);
    Serial.println("Led OFF");
  }
  delay(500);
}
