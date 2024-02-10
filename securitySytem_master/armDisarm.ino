
void armDisarm(void)
{
  Serial.println("button pressed, deboucing now");

  if(debounced)
  {
    timerStart(timer0);
    debounced = 0;
    armStat = !armStat;
    msg = ARM_MSG;
    msgbsy = 1; 
  }
}

void homeAway(void)
{
  if(debounced)
  {
    timerStart(timer0);
    debounced = 0;
    msg = HOME_MSG;
    homeStat = !homeStat; 
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