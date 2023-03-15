#include "sensors.h"
#include "display.h"
#include <esp_task_wdt.h>

BH1750 gy30(0x23);
DHT dht(DHTPIN, DHTTYPE);

float lux = 0;
float leitura_temp = 0;
float leitura_chuva = 0;
float leitura_umid = 0;
String rain_str;

void init_sensors(void) {
    init_Oled();
    Wire.begin();
    gy30.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
}

static /*ponteiro de vetor de float*/void get_sensors() {
    lux = gy30.readLightLevel();
    // leitura_temp = (analogRead(tempPin)/1023.0)*500.0;
    leitura_temp = dht.readTemperature();
    leitura_chuva = (analogRead(chuvaPin))/4;
    leitura_umid = analogRead(umidadePin);
    
}

void action_sensors(void) {
    // init_Oled();
    // Wire.begin();
    get_sensors();

    //Convertendo chuva em porcentagem
    int percent_rain = 100 - ((leitura_chuva*100.0)/1023.0);
    printf("leitura_chuva: %f\n", leitura_chuva);

    int percent_soilmoisture = map(leitura_umid, 0, 2950, 100, 0);
    printf("leitura_umid: %f\n", leitura_umid);

    esp_task_wdt_reset();

    show_display_temp(0x3C);
    delay(500);
    show_display_lumi(0x3C);
    delay(500);
    show_display_soil(0x3C, percent_soilmoisture);
    delay(500);
    show_display_rain(0x3C, percent_rain);
    delay(500);
    esp_task_wdt_reset();

    String temp = String(leitura_temp,2);
    String lumi = String(lux,2);
    String humiditySoil = String(percent_soilmoisture);

    publish_sensors_mqtt(temp, lumi, humiditySoil, rain_str);

    esp_task_wdt_reset();

    // turnoff_Oled();
    // Wire.end();
    // delay(5000);
}