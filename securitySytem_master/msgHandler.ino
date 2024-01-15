void msgHandler (byte msg, WiFiClient client)
{
  msgbsy = 0; 
  Serial.print("Getting status before command\n");
  client.write("getStat\n");
  switch(msg)
  {
    case ARM: 
      client.write("arm\n");
      arm = 1; //set up for next push
      Serial.print("Sending the Arm command.\n");
    break;
    case DISARM:
      client.write("disarm\n");
      arm = 0; //setup for next push
      Serial.print("Sending the Disarm command.\n");
    break; 
    case HOME:
      client.write("home\n");
      home = 1; //set up for next push
      Serial.print("Sending the Home command.\n");
    break;  
    case AWAY:
      client.write("away\n");
      home = 0; //set up for next push
      Serial.print("Sending the Away command.\n");
    break; 

  }
  Serial.print("Getting status after command\n");
  client.write("getStat\n");
}