String get_wifi_status(int status){
    switch(status){
        case WL_IDLE_STATUS:
        return "WL_IDLE_STATUS";
        case WL_SCAN_COMPLETED:
        return "WL_SCAN_COMPLETED";
        case WL_NO_SSID_AVAIL:
        return "WL_NO_SSID_AVAIL";
        case WL_CONNECT_FAILED:
        return "WL_CONNECT_FAILED";
        case WL_CONNECTION_LOST:
        return "WL_CONNECTION_LOST";
        case WL_CONNECTED:
        return "WL_CONNECTED";
        case WL_DISCONNECTED:
        return "WL_DISCONNECTED";
    }
}

/*

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
}*/