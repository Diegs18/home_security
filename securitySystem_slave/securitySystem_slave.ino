#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define ARM  1
#define DISARM  0
#define HOME 1
#define AWAY 0
#define ARM_MSG 2
#define HOME_MSG 3
#define GETSTAT_MSG 4


//WiFiClient client;
int status = WL_IDLE_STATUS;
const char ssid[] = "FBI_Spotter_Van";
const char password[] = "security";

byte homeStat = 0; 
byte armStat = 0;
byte msg = 0;
WiFiServer server(80);
float hallVal=27, hallValAve=27;
byte hallFlag = 0; 


void setup() {
  Serial.print("The unitialized msg is: ");
  Serial.println(msg);
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
  //hallDecision(); 
  WiFiClient client = server.available();   // listen for incoming clients
  if (client) // if you get a client,
  {       
               
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) // loop while the client's connected
    {   
      if(client.available())
      { 
        msg = client.read();
        if(msg != -1)
        {
          Serial.print("The message outside the function is: ");
          Serial.println(msg);
          msg = msgHandler(msg, client);
        }
      }
    }
  
  }
}


//void IRAM_ATTR timer0_ISR()
void hallDecision(void)
{
  //timerStop(timer0);
  //timerWrite(timer0, 0);

  hallVal = hallRead(); 
  hallValAve = 0.99*hallValAve + 0.01*hallVal;
  hallFlag = 1;
  Serial.print("Hall Value is: ");
  Serial.println(hallValAve);
  //Serial.println("reset the counter");
  
  //timerStart(timer0);
  //timerAlarmenable(timer0);

}