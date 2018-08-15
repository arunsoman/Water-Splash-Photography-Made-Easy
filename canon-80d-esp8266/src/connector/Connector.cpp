#include <Arduino.h>

#include "Connector.h"

Connector::Connector(){
  FOCUS_PIN = 0;
  SHOOT_PIN = 1;
  pinMode(FOCUS_PIN, OUTPUT);
  pinMode(SHOOT_PIN, OUTPUT);
};

void Connector::click(int pin)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(pin, HIGH);
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
