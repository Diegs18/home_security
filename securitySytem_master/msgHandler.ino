void msgHandler (byte msg, WiFiClient client)
{
  msgbsy = 0; 
  Serial.print("Getting status before command\n");
  client.write(GETSTAT_MSG);
  switch(msg)
  {
    case ARM_MSG: 
      client.write(armStat);
      //arm = 1; //set up for next push
      Serial.print("Sending the Arm command.\n");
    break; 
    case HOME_MSG:
      client.write(homeStat);
      //home = 1; //set up for next push
      Serial.print("Sending the Home command.\n");
    break;  
  }
  Serial.print("Getting status after command\n");
  client.write(GETSTAT_MSG);
}