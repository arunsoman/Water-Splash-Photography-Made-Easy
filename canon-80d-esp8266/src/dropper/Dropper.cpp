#include "Dropper.h"
#include <Arduino.h>


/*********************************************************************
* Comment
*********************************************************************/
Dropper::Dropper(int d, int i, int x)
{
    SolenoidValvePin = 3;
    secondDrop = d;
    interval = i;
    shutterSpeed= x;
    wait = secondDrop;
}

void Dropper::reset(int d, int i, int x){
  secondDrop = d;
  interval = i;
  shutterSpeed= x;
  wait = secondDrop;
}
void Dropper::drip(){
  delay(wait);
  wait = (wait == secondDrop)? interval:secondDrop;
  drop();
}

void Dropper::drop(){
  digitalWrite(SolenoidValvePin, HIGH);
  delayMicroseconds(shutterSpeed);
  digitalWrite(SolenoidValvePin, HIGH);
}
void Dropper::stop(){

}
