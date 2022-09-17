#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <BH1750.h>
#include <Wire.h>
#include "protocols.h"
#include "DHT.h"

#define PIN_SCL 22
#define PIN_SDA 21

#define DHTPIN 35
#define DHTTYPE DHT11   // DHT 11

#define pinLedRed   2
#define umidadePin  39
#define chuvaPin    34
#define tempPin     35

extern float lux;
extern float leitura_temp;
extern float leitura_chuva;
extern float leitura_umid;

extern String rain_str;

// extern BH1750 gy30(0x23);

// void get_sensors();
void init_sensors(void);
void action_sensors(void);

// int8_t AverageThreeBytes(int8_t a, int8_t b, int8_t c);