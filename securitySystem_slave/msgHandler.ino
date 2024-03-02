#include <stdio.h>
#include <string.h>
byte msgHandler(byte msg, WiFiClient client)
{
  Serial.print("The message in the function is:");
  Serial.println(msg);

  switch(msg)
  {
    case GETSTAT_MSG: 
      client.write(armStat);
      client.write(homeStat);
    break; 
    case ARM_MSG:
      armStat = !armStat; 
      client.write(armStat);
      client.write(homeStat);
    break;
    case HOME_MSG:
      homeStat = !homeStat;
      client.write(armStat);
      client.write(homeStat); 
    break; 
  }

  return 0;
}