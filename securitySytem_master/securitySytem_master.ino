#define ARM  1
#define DISARM  0
#define HOME 2
#define AWAY 3
#define NOT_HOME 0

byte arm = 0;
byte home = 1;
byte msgbsy = 0;
byte msg; 
byte cnt = 0;
byte ip[] = { 192, 168, 4, 2};
byte debounced = 0;
hw_timer_t *timer0 = NULL;

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define debugLED 2   // Set the GPIO pin where you connected your test LED or comment this line out if your dev board has a built-in LED

#define armButton 4
#define armLED 0 

#define homeButton 16
#define homeLED 17

#define high 1
#define low 0
// Set these to your desired credentials.
const char *ssid = "FBI_Spotter_Van";
const char *password = "security";

void msgHandler (byte msg, WiFiClient client);
void armDisarm(void);
void homeAway(void);
void IRAM_ATTR timer0_ISR();

void setup() 
{
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(armLED, OUTPUT);
  pinMode(armButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(armButton), armDisarm, RISING);

  pinMode(homeLED, OUTPUT);
  pinMode(homeButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(homeButton), homeAway, RISING);

  timer0 = timerBegin(0, 80, true);
  timerAttachInterrupt(timer0, &timer0_ISR, true);
  timerAlarmWrite(timer0, 500000, true);
  timerAlarmEnable(timer0);

  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  // a valid password must have more than 7 characters
  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while(1);
  } 
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

}

void loop() 
{
  WiFiClient client;

    if (client.connect(ip, 80)) 
    {
      Serial.println("connected to the server");
      while (client.connected()) 
      {
        //if (client.available()) {
        if(msgbsy)
        {
          msgHandler(msg, client);
        }
      }
      //client.stop();
      //Serial.println("Disconnected from server");
    }
    else
    {
      Serial.println("didn't connect, trying again");
    }
}

