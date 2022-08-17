#include "sensors.h"

float lux = 0;
float leitura_temp = 0;
float leitura_chuva = 0;
float leitura_umid = 0;

BH1750 gy30(0x23);

/*ponteiro de vetor de float*/void get_sensors() {
    float lux = gy30.readLightLevel();
    float leitura_temp = (analogRead(tempPin)/1023.0)*500.0;
    float leitura_chuva = (analogRead(chuvaPin))/4;
    float leitura_umid = analogRead(umidadePin);
}