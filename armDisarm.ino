
void armDisarm(void)
{
  if(!arm)
  {
    digitalWrite(armLED, high); //show the user that we are armed
    arm = 1; //arm it
  }
  else
  {
    digitalWrite(armLED, low); //tell the user that we are no longer armed
    arm = 0; //disarm it
  }
}

void homeAway(void)
{
  if(!home)
  {
    digitalWrite(homeLED, high); //show the user that we are armed
    home = 1; //arm it 
  }
  else
  {
    digitalWrite(homeLED, low); //show the user that we are armed
    home = 0; //arm it
  }
}
void armState(void)
{
  
}