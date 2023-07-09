void msgHandler (byte msg)
{
  msgbsy = 0; 
  switch(msg)
  {
    case ARM: 
      server.write("arm");
      arm = 1; //set up for next push
      Serial.print("Sending the Arm command.\n");
    break;
    case DISARM:
      server.write("disarm");
      arm = 0; //setup for next push
      Serial.print("Sending the Disarm command.\n");
    break; 
    case HOME:
      server.write("home");
      home = 1; //set up for next push
      Serial.print("Sending the Home command.\n");
    break;  
    case AWAY:
      server.write("away");
      home = 0; //set up for next push
      Serial.print("Sending the Away command.\n");
    break; 

  }

}