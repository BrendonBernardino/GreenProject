/**
 * @file main.cpp
 * @author Brendon Bernardino (brendonrsb@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <Arduino.h>
#include <stdlib.h>
#include <stdio.h>

#include "sensors.h"
#include "protocols.h"
#include "display.h"
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, PIN_SCL, PIN_SDA, U8X8_PIN_NONE);
BH1750 gy30(0x23);

float delayTime = 0;

void setup() {
  pinMode(tempPin, INPUT);
  
  u8g2.begin();
  Wire.begin();
  gy30.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
  
  Wire.beginTransmission(0x3C);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_timR14_tf);
  u8g2.drawStr(15,25,"Inicializando");
  u8g2.drawStr(25,45,"sensores...");
  u8g2.sendBuffer();
  Wire.endTransmission();
}

void loop() {
  float lux = gy30.readLightLevel();
  float leitura_temp = analogRead(tempPin);
  float temp = (leitura_temp/1023.0)*500.0;
  float leitura_chuva = (analogRead(chuvaPin))/4;
  float leitura_umid = analogRead(umidadePin);

  //Convertendo chuva em porcentagem
  int percent_rain = 100 - ((leitura_chuva*100.0)/1023.0);
  printf("leitura_chuva: %f\n", leitura_chuva);

  if (leitura_chuva >900){
    printf("\n--SEM CHUVA--\n");
  }
  else if (leitura_chuva >600 && leitura_chuva <900){
    printf("\n--NEBLINA--\n");
  }
  else if (leitura_chuva >400 && leitura_chuva <600){
    printf("\n--CHOVENDO--\n");
  }
  else if (leitura_chuva <400){
    printf("\n--CHUVA FORTE--\n");
  }    

  printf("Luminosidade: %f lumens\n", lux);
  Wire.beginTransmission(0x3C);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_timR14_tf);
  u8g2.drawStr(12,25,"Luminosidade");
  u8g2.setCursor(25,45);
  u8g2.print(lux);
  // u8g2.drawStr(25,45,"sensores...");
  u8g2.sendBuffer();
  Wire.endTransmission();
  delay(500);

  printf("Temperatura: %f ºC\n", temp);
  Wire.beginTransmission(0x3C);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_timR14_tf);
  u8g2.drawStr(12,25,"Temperatura");
  u8g2.setCursor(25,45);
  u8g2.print(temp);
  // u8g2.drawStr(25,45,"sensores...");
  u8g2.sendBuffer();
  Wire.endTransmission();
  delay(500);

  printf("Chuva: %d %\n", percent_rain);
  Wire.beginTransmission(0x3C);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_timR14_tf);
  u8g2.drawStr(12,25,"Chuva");
  u8g2.setCursor(25,45);
  u8g2.print(percent_rain);
  // u8g2.drawStr(25,45,"sensores...");
  u8g2.sendBuffer();
  Wire.endTransmission();
  delay(500);
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

//   conectaWiFi();
//   MQTT.setServer(BROKERMQTT, BROKERPORT); 
// }

// void loop() {
//   mantemConexoes();
//   enviaValores();
//   MQTT.loop();
// }