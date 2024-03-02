void msgHandler (byte msg, WiFiClient client)
{
  msgbsy = 0; 
  //Serial.print("Getting status before command\n");
  //client.write(GETSTAT_MSG);
  switch(msg)
  {
    case ARM_MSG: 
      client.write(ARM_MSG);
      //arm = 1; //set up for next push
      Serial.print("Sending the Arm command.\n");
    break; 
    case HOME_MSG:
      client.write(HOME_MSG);
      //home = 1; //set up for next push
      Serial.print("Sending the Home command.\n");
    break;  
  }
  //Serial.print("Getting status after command\n");
  //client.write(GETSTAT_MSG);
}

void rxmsgHandler(WiFiClient client)
{

    rxmsg = client.read();
    if(rxmsg<=0) //if we are getting a normal status message
    {
      if(!rxFlg)
      {
        armState(rxmsg);
        rxFlg = !rxFlg;
      }
      else
      {
        homeState(rxmsg);
        rxFlg = !rxFlg;
      }
    }
    //if(rxmsg)//alert sound alarms

}