#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
WiFiClient client;
int status = WL_IDLE_STATUS;
const char ssid[] = "FBI_Spotter_Van";
const char password[] = "security";
//IPAddress server(74,125,115,105); /192.168.4.1
//IPAddress server(192,168,4,1); //192.168.4.1

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
} 

void loop() {
  WiFiClient client;
  if (client.connect("192.168.4.1", 80)) {

    while (client.connected()) {
      if (client.available()) {
        String data = client.readStringUntil('\n');
        Serial.println(data);
      }
    }
    client.stop();
    Serial.println("Disconnected from server");
  }
}