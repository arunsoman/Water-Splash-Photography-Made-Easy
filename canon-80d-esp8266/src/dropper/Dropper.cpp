#include "Dropper.h"
#include <Arduino.h>
using namespace std;

/*********************************************************************
* Comment
*********************************************************************/
Dropper::Dropper()
{
  SolenoidValvePin = 3;
}

void Dropper::reset(vector<long> x, long y, long z){
  schedule = x;
  repeatCycle = y;
  shutterSpeed = z;
  index = 0;
}
void Dropper::drip(){
  delay(schedule[index++]);
  drop();
}

void Dropper::drop(){
  digitalWrite(SolenoidValvePin, HIGH);
  delayMicroseconds(shutterSpeed);
  digitalWrite(SolenoidValvePin, HIGH);
}
void Dropper::stop(){

}
