
void armDisarm(void)
{
  Serial.println("button pressed");

  if(debounced)
  {
    timerStart(timer0);
    debounced = 0;
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
}

void homeAway(void)
{
  if(debounced)
  {
    timerStart(timer0);
    debounced = 0;
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
}
void armState(void)
{
  
}


void IRAM_ATTR timer0_ISR()
{
  timerAlarmDisable(timer0);
  timerStop(timer0);
  Serial.println("Timer overflow");
  timerRestart(timer0);
  debounced = 1; 
}