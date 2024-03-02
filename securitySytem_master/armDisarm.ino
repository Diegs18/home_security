
void armDisarm(void)
{
  Serial.println("button pressed, deboucing now");

  if(debounced)
  {
    timerStart(timer0);
    debounced = 0;
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
void armState(byte msg)
{
  Serial.print("Arm State is: ");
  Serial.println(msg);
  armStat = msg;
  digitalWrite(armLED, msg);
}
void homeState(byte msg)
{
  Serial.print("Home State is: ");
  Serial.println(msg);
  homeStat = msg;
  digitalWrite(homeLED, msg);
}

void IRAM_ATTR timer0_ISR()
{
  timerAlarmDisable(timer0);
  timerStop(timer0);
  Serial.println("Timer overflow");
  timerRestart(timer0);
  debounced = 1; 
}