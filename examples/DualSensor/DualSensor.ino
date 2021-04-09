#include <Wire.h>
#include <Tlv493d.h>

#define POWER_PIN1 LED1 //Sensor 1 VDD is connected to POWER_PIN1
#define POWER_PIN2 LED2 //Sensor 2 VDD is connected to POWER_PIN2

// Tlv493d Opject
Tlv493d Tlv493d_Sensor1 = Tlv493d();
Tlv493d Tlv493d_Sensor2 = Tlv493d();

void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  //Power up and configure sensor 2
  pinMode(POWER_PIN2, OUTPUT);
  digitalWrite(POWER_PIN2, HIGH);
  delay(50);
  Tlv493dMagnetic3DSensor.begin(Wire, TLV493D_ADDRESS2, true);

  //power up and configure sensor 1
  pinMode(POWER_PIN1, OUTPUT);
  digitalWrite(POWER_PIN1, HIGH);
  delay(50);
  Tlv493dMagnetic3DSensor.begin();  //automatically configured to TLV493D_ADDRESS1
  
}

void loop() {
  Tlv493d_Sensor1.updateData();
  Tlv493d_Sensor2.updateData();
  delay(100);
  Serial.println("Sensor 1:");
  Serial.print("X = ");
  Serial.print(Tlv493d_Sensor1.getX());
  Serial.print(" mT; Y = ");
  Serial.print(Tlv493d_Sensor1.getY());
  Serial.print(" mT; Z = ");
  Serial.print(Tlv493d_Sensor1.getZ());
  Serial.println(" mT");
  Serial.println("Sensor 2:");
  Serial.print("X = ");
  Serial.print(Tlv493d_Sensor2.getX());
  Serial.print(" mT; Y = ");
  Serial.print(Tlv493d_Sensor2.getY());
  Serial.print(" mT; Z = ");
  Serial.print(Tlv493d_Sensor2.getZ());
  Serial.println(" mT");
  Serial.println();
  delay(500);
}