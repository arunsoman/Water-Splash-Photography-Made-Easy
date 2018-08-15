#ifndef CONNECTOR_H
#define  CONNECTOR_H
#include <Arduino.h>

class Connector{

public:
  Connector();
  void focus();
  void shoot();

private:
  int FOCUS_PIN;
  int SHOOT_PIN;
  void click(int pin);

};
#endif
