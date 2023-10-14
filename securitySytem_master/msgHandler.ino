void msgHandler (byte msg, WiFiClient client)
{
  msgbsy = 0; 
  switch(msg)
  {
    case ARM: 
      client.write("arm");
      arm = 1; //set up for next push
      Serial.print("Sending the Arm command.\n");
    break;
    case DISARM:
      client.write("disarm");
      arm = 0; //setup for next push
      Serial.print("Sending the Disarm command.\n");
    break; 
    case HOME:
      client.write("home");
      home = 1; //set up for next push
      Serial.print("Sending the Home command.\n");
    break;  
    case AWAY:
      client.write("away");
      home = 0; //set up for next push
      Serial.print("Sending the Away command.\n");
    break; 

  }

}