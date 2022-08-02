#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#define IDMQTT        "GreenProject_01"
#define TEMPPUBLISH   "BETemperature"
#define LUMIPUBLISH   "BELuminosity"
#define SOILPUBLISH   "BESoil"
#define IRRADPUBLISH  "BEIrradiation"