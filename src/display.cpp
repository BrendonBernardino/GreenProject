#include "display.h"

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, PIN_SCL, PIN_SDA, U8X8_PIN_NONE);

void init_Oled(void) {
    u8g2.begin();
}

void display_welcome(int _address_oled) {
    Wire.beginTransmission(_address_oled);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_timR14_tf);
    u8g2.drawStr(15,25,"Inicializando");
    u8g2.drawStr(25,45,"sensores...");
    u8g2.sendBuffer();
    Wire.endTransmission();
}

void show_display_temp(int _address_oled) {
    printf("Temperatura: %f ºC\n", leitura_temp);
    Wire.beginTransmission(_address_oled);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_timR14_tf);
    u8g2.drawStr(12,25,"Temperatura");
    u8g2.setCursor(25,45);
    u8g2.print(leitura_temp);
    u8g2.drawStr(70,45,"C");
    u8g2.sendBuffer();
    Wire.endTransmission();
}

void show_display_lumi(int _address_oled) {
    printf("Luminosidade: %f lumens\n", lux);
    Wire.beginTransmission(_address_oled);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_timR14_tf);
    u8g2.drawStr(8,25,"Luminosidade");
    u8g2.setCursor(25,45);
    u8g2.print(lux);
    u8g2.drawStr(85,45,"lux");
    u8g2.sendBuffer();
    Wire.endTransmission();
}

void show_display_soil(int _address_oled, int _percent) {
    printf("Umidade do solo: %d %\n", _percent);
    Wire.beginTransmission(_address_oled);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_timR14_tf);
    u8g2.drawStr(8,25,"Umidade Solo");
    u8g2.setCursor(25,45);
    u8g2.print(_percent);
    u8g2.drawStr(70,45,"%");
    u8g2.sendBuffer();
    Wire.endTransmission();
}

void show_display_rain(int _address_oled, int _percent) {
    printf("Chuva: %d %\n", _percent);
    Wire.beginTransmission(_address_oled);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_timR14_tf);
    u8g2.drawStr(12,25,"Chuva");
    // u8g2.setCursor(25,45);
    // u8g2.print(_percent);
    if (leitura_chuva >900){
        rain_str = "Sem Chuva";
        printf("\n--SEM CHUVA--\n");
        u8g2.drawStr(15,45,"Sem Chuva");
    }
    else if (leitura_chuva >600 && leitura_chuva <900){
        rain_str = "Neblina";
        printf("\n--NEBLINA--\n");
        u8g2.drawStr(15,45,"Neblina");
    }
    else if (leitura_chuva >400 && leitura_chuva <600){
        rain_str = "Chovendo";
        printf("\n--CHOVENDO--\n");
        u8g2.drawStr(15,45,"Chovendo");
    }
    else if (leitura_chuva <400){
        rain_str = "Chuva Forte";
        printf("\n--CHUVA FORTE--\n");
        u8g2.drawStr(15,45,"Temporal");
    }   
    u8g2.sendBuffer();
    Wire.endTransmission();
}