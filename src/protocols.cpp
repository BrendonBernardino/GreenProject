#include "protocols.h"

//WiFi
const char* SSID = "GVTX-9999";
const char* PASSWORD = "bwh4ck34d0";
WiFiClient wifiClient;                        
 
//MQTT Server
const char* BROKERMQTT = "mqtt.eclipseprojects.io";
int BROKERPORT = 1883;

PubSubClient MQTT(wifiClient);

// void mantemConexoes() {
//     if (!MQTT.connected()) {
//        conectaMQTT(); 
//     }
//     conectaWiFi();
// }

// void conectaWiFi() {
//   if (WiFi.status() == WL_CONNECTED) {
//     return;
//   }       
//   Serial.print("Conectando-se na rede: ");
//   Serial.print(SSID);
//   Serial.println("  Aguarde!");

//   WiFi.begin(SSID, PASSWORD);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(100);
//     Serial.print(".");
//   }
  
//   Serial.println();
//   Serial.print("Conectado com sucesso, na rede: ");
//   Serial.print(SSID);  
//   Serial.print("  IP obtido: ");
//   Serial.println(WiFi.localIP()); 
// }

// void conectaMQTT() { 
//   while (!MQTT.connected()) {
//     Serial.print("Conectando ao Broker MQTT: ");
//     Serial.println(BROKERMQTT);
//     if (MQTT.connect(IDMQTT)) {
//       Serial.println("Conectado ao Broker com sucesso!");
//     } 
//     else {
//       Serial.println("Nao foi possivel se conectar ao broker.");
//       Serial.println("Nova tentatica de conexao em 10s");
//       delay(10000);
//     }
//   }
// }