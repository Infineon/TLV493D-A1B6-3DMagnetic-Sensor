#include <Tlv493d.h>

// Tlv493d Opject
Tlv493d Tlv493dMagnetic3DSensor = Tlv493d();

void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  //For the Evalkit "TLV493D-A1B6 MS2GO" uncommend following 3 lines:
  //pinMode(LED2, OUTPUT);	//Sensor-VDD as output
  //digitalWrite(LED2, HIGH);	//Power on the sensor
  //delay(50);
  
  Tlv493dMagnetic3DSensor.begin();
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

