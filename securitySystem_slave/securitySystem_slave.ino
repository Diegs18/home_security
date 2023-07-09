#include <WiFi.h>
#include <WiFiClient.h>
WiFiClient client;
int status = WL_IDLE_STATUS;
const char ssid[] = "FBI_Spotter_Van";
const char pass[] = "security";
//IPAddress server(74,125,115,105); /192.168.4.1
IPAddress server(192,168,4,1); //192.168.4.1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);

    WiFi.mode(WIFI_STA); //Optional
    WiFi.begin(ssid, pass);
    Serial.println("\nConnecting");

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        status = WiFi.status();
        Serial.println(get_wifi_status(status));
        delay(100);
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    IPAddress myIP = WiFi.localIP();
    Serial.println(myIP);
    if (client.connect(myIP, 80))
    {
      Serial.println("connected to the server");
    }
    else 
    {
      Serial.println("The final status is");
      status = WiFi.status();
      Serial.println(get_wifi_status(status));
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (client.available()) 
  {
    char c = client.read();
    Serial.print(c);
  }
}
