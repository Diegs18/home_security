#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
//WiFiClient client;
int status = WL_IDLE_STATUS;
const char ssid[] = "FBI_Spotter_Van";
const char password[] = "security";
//IPAddress server(74,125,115,105); /192.168.4.1
//IPAddress server(192,168,4,1); //192.168.4.1
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
} 

void loop() {
  WiFiClient client = server.available();   // listen for incoming clients
  if (client) // if you get a client,
  {                             
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) // loop while the client's connected
    {      
        String data = client.readStringUntil('\n');
        Serial.println(data);
        
    }
  }
}