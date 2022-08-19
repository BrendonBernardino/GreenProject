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

float delayTime = 0;

void setup() {
  pinMode(tempPin, INPUT);
  init_sensors();
  
  display_welcome(0x3C);
  setup_protocols();
}

void loop() {
  mantemConexoes();
  action_sensors();
  loop_mqtt();
}