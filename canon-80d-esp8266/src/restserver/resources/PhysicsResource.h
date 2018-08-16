#ifndef PHYSICS_RESOURCE_H
#define PHYSICS_RESOURCE_H

#include "..\..\physics\Physics.h"
#include <stdio.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

class PhysicsResource{

private:
  Physics physics;
  ESP8266WebServer http_rest_server;
  char* getApproxTimeToImpact(JsonObject &jsonObj);
  char* getTimeToImpact(JsonObject &jsonObj);
  char* postTimetoImpact(JsonObject &jsonObj);
public:
  PhysicsResource (Physics &p);
  void registerResource(ESP8266WebServer &server);
  void handler(void(*funcPtr)(JsonObject&));
};

#endif
