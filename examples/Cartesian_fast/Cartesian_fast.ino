#include <Tlv493d.h>

// Tlv493d Opject
Tlv493d Tlv493dMagnetic3DSensor = Tlv493d();

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Tlv493dMagnetic3DSensor.begin();
  Tlv493dMagnetic3DSensor.setAccessMode(Tlv493dMagnetic3DSensor.MASTERCONTROLLEDMODE);
  Tlv493dMagnetic3DSensor.disableTemp();
}

void loop() {
  delay(Tlv493dMagnetic3DSensor.getMeasurementDelay());
  Tlv493dMagnetic3DSensor.updateData();

  Serial.print(Tlv493dMagnetic3DSensor.getX());
  Serial.print(" ; ");
  Serial.print(Tlv493dMagnetic3DSensor.getY());
  Serial.print(" ; ");
  Serial.println(Tlv493dMagnetic3DSensor.getZ());
}
