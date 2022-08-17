#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <BH1750.h>

#define PIN_SCL 22
#define PIN_SDA 21

#define pinLedRed   2
#define umidadePin  39
#define chuvaPin    34
#define tempPin     35

#include <stdint.h>

extern float lux;
extern float leitura_temp;
extern float leitura_chuva;
extern float leitura_umid;

// int8_t AverageThreeBytes(int8_t a, int8_t b, int8_t c);