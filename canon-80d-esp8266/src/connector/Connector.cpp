#include <Arduino.h>

#include "Connector.h"

Connector::Connector(){
  FOCUS_PIN = 0;
  SHOOT_PIN = 1;
#ifndef SIMULATOR
 // pinMode(FOCUS_PIN, OUTPUT);
 // pinMode(SHOOT_PIN, OUTPUT);
#endif
};

void Connector::click(int pin)
{
  #ifndef SIMULATOR
  digitalWrite(pin, HIGH);
#endif
  delayMicroseconds(1000);
  #ifndef SIMULATOR
  digitalWrite(pin, HIGH);
  #endif
  Serial.println("clicked");
}
/*********************************************************************
* Comment
*********************************************************************/
void Connector::focus()
{
  click(FOCUS_PIN);
}
/*********************************************************************
* Comment
*********************************************************************/
void Connector::shoot()
{
  click(SHOOT_PIN);
}
