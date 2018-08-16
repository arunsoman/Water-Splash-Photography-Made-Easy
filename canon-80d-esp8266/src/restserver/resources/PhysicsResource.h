#ifndef PHYSICS_RESOURCE_H
#define PHYSICS_RESOURCE_H

#include "..\..\physics\Physics.h"
#include <stdio.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

class PhysicsResource{

private:
  Physics physics;
  void getApproxTimeToImpact( ESP8266WebServer*);
  void getTimeToImpact();
  void postTimetoImpact();
  JsonObject&  handler( ESP8266WebServer*);
public:
  Physics* getModel();
  void registerResource( ESP8266WebServer*);

};

#endif
