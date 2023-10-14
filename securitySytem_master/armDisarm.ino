
void armDisarm(void)
{
  if(!arm&&!msgbsy)
  {
    digitalWrite(armLED, high); //show the user that we are armed
    msg = ARM; 
    arm = ARM;
    Serial.println("Armmed");
    
  }
  else if(arm&&!msgbsy)
  {
    digitalWrite(armLED, low); //tell the user that we are no longer armed
    msg = DISARM;
    arm = DISARM;
    Serial.println("Disarmmed");
  }
  msgbsy = 1; 
}

void homeAway(void)
{
  if(!home&&!msgbsy)
  {
    digitalWrite(homeLED, high); //show the user that we are armed
    msg = HOME;
    home = HOME; 
  }
  else if (home&&!msgbsy)
  {
    digitalWrite(homeLED, low); //show the user that we are armed
    msg = AWAY;
    home = NOT_HOME;
  }
  msgbsy = 1; 
}
void armState(void)
{
  
}