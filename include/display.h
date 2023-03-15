#include <U8g2lib.h>
#include "sensors.h"

void init_Oled(void);
void turnoff_Oled(void);
void action_Oled(void);
void display_welcome(int _address_oled);
void show_display_temp(int _address_oled);
void show_display_lumi(int _address_oled);
void show_display_soil(int _address_oled, int _percent);
void show_display_rain(int _address_oled, int _percent);