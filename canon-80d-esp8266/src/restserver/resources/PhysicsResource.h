#ifndef PHYSICS_RESOURCE_H
#define PHYSICS_RESOURCE_H

#include "..\..\physics\Physics.h"
#include <stdio.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

class PhysicsResource{

private:
  Physics physics;
  ESP8266WebServer *http_rest_server;
  void getApproxTimeToImpact();
  void getTimeToImpact();
  void postTimetoImpact();
public:
  Physics* getModel();
  void registerResource(ESP8266WebServer*);
  JsonObject&  handler();
};

#endif
