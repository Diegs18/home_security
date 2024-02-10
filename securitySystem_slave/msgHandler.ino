#include <stdio.h>
#include <string.h>

byte msgHandler(byte msg, WiFiClient client)
{
  Serial.print("The message in the function is:");
  Serial.println(msg);
  
  switch(msg)
  {
    case GETSTAT_MSG: 
      server.write(armStat);
      server.write(homeStat);
    break; 
    case ARM_MSG:
      armStat = msg; 
    break;
    case HOME_MSG:
      homeStat = msg; 
    break; 
  }

  return 0;
}