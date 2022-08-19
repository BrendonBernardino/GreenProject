#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#define IDMQTT        "GreenProject_01"
#define TEMPPUBLISH   "BETemperature"
#define LUMIPUBLISH   "BELuminosity"
#define SOILPUBLISH   "BESoil"
#define RAINPUBLISH  "BERain"

void setup_protocols(void);
void loop_mqtt(void);
void publish_sensors_mqtt(String temperature, String light, String humidity_soil, String rain);
void mantemConexoes(void);
void conectaWiFi(void);
void conectaMQTT(void);