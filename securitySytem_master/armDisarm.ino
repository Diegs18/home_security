
void armDisarm(void)
{
  msgbsy = 1; 
  
  if(!arm)
  {
    digitalWrite(armLED, high); //show the user that we are armed
    msg = ARM; 
  }
  else
  {
    digitalWrite(armLED, low); //tell the user that we are no longer armed
    msg = DISARM;
  }
}

void homeAway(void)
{
  msgbsy = 1; 
  if(!home)
  {
    digitalWrite(homeLED, high); //show the user that we are armed
    msg = HOME;
  }
  else
  {
    digitalWrite(homeLED, low); //show the user that we are armed
    msg = AWAY;
  }
}
void armState(void)
{
  
}