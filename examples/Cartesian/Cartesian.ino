#include <Tlv493d.h>

// Tlv493d Opject
Tlv493d Tlv493dMagnetic3DSensor = Tlv493d();

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Tlv493dMagnetic3DSensor.begin();
  digitalWrite(14, HIGH);
}

void loop() {
  Tlv493dMagnetic3DSensor.updateData();
  delay(100);

  Serial.print("X = ");
  Serial.print(Tlv493dMagnetic3DSensor.getX());
  Serial.print(" mT; Y = ");
  Serial.print(Tlv493dMagnetic3DSensor.getY());
  Serial.print(" mT; Z = ");
  Serial.print(Tlv493dMagnetic3DSensor.getZ());
  Serial.println(" mT");
   
  delay(500);
}

