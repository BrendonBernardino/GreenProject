#include <Arduino.h>
#include <stdlib.h>
#include <stdio.h>

#include "sensors.h"
#include "protocols.h"
#include "display.h"
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, PIN_SCL, PIN_SDA, U8X8_PIN_NONE); 

float delayTime = 0;

void setup() {
  u8g2.begin();
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_timR14_tf);
  u8g2.drawStr(15,25,"Inicializando");
  u8g2.drawStr(25,45,"sensores...");
  u8g2.sendBuffer();
}

void loop() {

}

// void enviaValores() {
//   // digitalWrite(pinLedRed, LOW); 
//   if(millis() - delayTime > 5000) {  
//     // digitalWrite(pinLedRed, HIGH); 
          
//     float h = dht.readHumidity();
//     float t = dht.readTemperature();
//     float l = GY30.readLightLevel();
//     float hs = analogRead(umidadePin);
//     float c = analogRead(chuvaPin);

//     String temp = String(t,2);
//     String humi = String(h,2);
//     String lux = String(l,2);
//     String humiditySoil = String(hs,2);
//     String rain = String(c,2);

//     MQTT.publish(TEMPPUBLISH, temp.c_str(), true);
//     MQTT.publish(HUMIPUBLISH, humi.c_str(), true);
//     MQTT.publish(LUMIPUBLISH, lux.c_str(), true);
//     MQTT.publish(IRRADPUBLISH, humiditySoil.c_str(), true);
//     MQTT.publish(SOILPUBLISH, rain.c_str(), true);
    
//     Serial.println("Dados enviados via MQTT");
//     Serial.print(F("Humidity: "));
//     Serial.print(h);
//     Serial.print(F("%  Temperature: "));
//     Serial.println(t);
//     Serial.print("Lumi: ");
//     Serial.println(l);
//     Serial.print("Soil: ");
//     Serial.println(hs);
//     Serial.print("Chuva: ");
//     Serial.println(c);
    
//     delayTime = millis();
//   }
// }

// void setup() {
//   Serial.begin(115200);
//   Serial.println(F("DHTxx test!"));

//   pinMode(pinLedBlue, OUTPUT);
//   pinMode(pinLedGreen, OUTPUT);
//   pinMode(pinLedRed, OUTPUT);
//   pinMode(umidadePin, INPUT);

//   Wire.begin();  
//   GY30.begin();
//   dht.begin();

//   conectaWiFi();
//   MQTT.setServer(BROKERMQTT, BROKERPORT); 
// }

// void loop() {
//   mantemConexoes();
//   enviaValores();
//   MQTT.loop();
// }