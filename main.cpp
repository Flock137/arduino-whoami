#include <Arduino.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  
  Wire.begin();
  
  Serial.println("Reading WHO_AM_I register...");
  
  Wire.beginTransmission(0x68);
  Wire.write(0x75); // WHO_AM_I register
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 1);
  
  if (Wire.available()) {
    byte whoAmI = Wire.read();
    Serial.print("WHO_AM_I = 0x");
    Serial.println(whoAmI, HEX);
    Serial.println();
    
    //if (whoAmI == 0x71) Serial.println("This is MPU-9250");
    //else if (whoAmI == 0x73) Serial.println("This is MPU-9255");
    //else if (whoAmI == 0x70) Serial.println("This is MPU-6500");
    //else if (whoAmI == 0x68) Serial.println("This is MPU-6050");
    //else Serial.println("Unknown sensor!");
  }
}

void loop() {
  // Nothing
}
