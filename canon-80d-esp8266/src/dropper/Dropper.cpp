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
  for (vector<long>::iterator it = schedule.begin(); it != schedule.end(); ++it) {
    delete &it;
  }
  delete &schedule;
  schedule = x;
  schedule.push_back(new long (y));
  it = schedule.begin();
  shutterSpeed = z;
}
void Dropper::drip(){
  if(it == schedule.end()){
    // memory leak ?? it;
    it = schedule.begin();
  }
  delay(*it);
  it++;
  drop();
}

void Dropper::drop(){
  digitalWrite(SolenoidValvePin, HIGH);
  delayMicroseconds(shutterSpeed);
  digitalWrite(SolenoidValvePin, HIGH);
}
void Dropper::stop(){

}
