#include "Dropper.h"
#include <Arduino.h>

/*********************************************************************
* Comment
*********************************************************************/
Dropper::Dropper()
{
  SolenoidValvePin = 3;
  it = 0;
   // pinMode(SolenoidValvePin, OUTPUT);
}

void Dropper::reset(long* d, int si, long z){
  schedule = d;
  Serial.print(schedule [0]);
  Serial.print(schedule [1]);
  Serial.print(schedule [2]);
  size = si;
  shutterSpeed = z;
}

void Dropper::drip(){
  long l = schedule [it];
  Serial.print("Dripping in ");
Serial.print(l);
  delay(l);
  drop();
  it++;
  if(it==size)
  {it =0;}
}

void Dropper::drop(){
  digitalWrite(SolenoidValvePin, HIGH);
  Serial.print("..Droped ");
  delayMicroseconds(shutterSpeed);
  Serial.print(shutterSpeed);
  digitalWrite(SolenoidValvePin, HIGH);
  Serial.println(" & closed ");
}
void Dropper::stop(){

}
