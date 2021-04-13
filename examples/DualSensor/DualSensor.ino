#include <Wire.h>
#include <Tlv493d.h>

#define POWER_PIN1 LED2 //Sensor 1 VDD is connected to POWER_PIN1
#define POWER_PIN2 LED1 //Sensor 2 VDD is connected to POWER_PIN2

// Tlv493d Opject
Tlv493d Tlv493d_Sensor1 = Tlv493d();  //Sensor 1 shall have I²C address 1
Tlv493d Tlv493d_Sensor2 = Tlv493d();  //Sensor 2 shall have I²C address 2

void setup() {
  Serial.begin(9600);
  while(!Serial);

  //Switch off both sensors
  pinMode(POWER_PIN1, OUTPUT);
  pinMode(POWER_PIN2, OUTPUT);
  digitalWrite(POWER_PIN1, LOW);
  digitalWrite(POWER_PIN2, LOW);
  delay(500);
  
  //Power up and configure sensor 2
  digitalWrite(POWER_PIN2, HIGH);
  delay(50);
  //Configure sensor 2 to address 2 at first, so it will not respond when later address 1 is configured.
  Tlv493d_Sensor2.begin(Wire, TLV493D_ADDRESS2, true);  

  //power up and configure sensor 1
  digitalWrite(POWER_PIN1, HIGH);
  delay(50);
  //Configure sensor 1 to address 1. 
  //IMPORTANT: Don't perform an I²C sensor reset (last bool argument) as this would also reset sensor 2
  //           -> Then sensor 2 would again respond to address 1, what we need to avoid.
  Tlv493d_Sensor1.begin(Wire, TLV493D_ADDRESS1, false); 
  
}

void loop() {
  //Read both sensors
  Tlv493d_Sensor1.updateData();
  Tlv493d_Sensor2.updateData();
  
  //Output sensor 1 data
  Serial.println("Sensor 1:");
  Serial.print("X = ");
  Serial.print(Tlv493d_Sensor1.getX());
  Serial.print(" mT; Y = ");
  Serial.print(Tlv493d_Sensor1.getY());
  Serial.print(" mT; Z = ");
  Serial.print(Tlv493d_Sensor1.getZ());
  Serial.println(" mT");
  //Output sensor 2 data
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