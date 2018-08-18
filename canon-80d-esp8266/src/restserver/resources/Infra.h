#ifndef INFRA_H
#define INFRA_H

#include <ESP8266WebServer.h>
#include <string>
#include "..\..\dropper\Dropper.h"
#include "..\..\connector\Connector.h"
#include "PhysicsResource.h"
#include "..\RestServer.h"

class Infra
{
public:
  Infra();
  Dropper *dropper;
  Connector *connector;
  RestServer restServer;
  PhysicsResource physicsRes;

private:
  void registerResource();
  void handleDripSequence(ESP8266WebServer *);
  long y = 3;
  long sch[3] = {2000, 6000, 9000};

};

Infra::Infra()
{
  
  long z = 5000;
  dropper = new Dropper();
  dropper->reset(sch, y, z);
  connector = new Connector();
  registerResource();
}
void Infra::registerResource()
{
  ESP8266WebServer *server = restServer.getServer();
  physicsRes.registerResource(server);
  restServer.getServer()->on("/DripSequence", HTTP_GET, [this, server]() {
    this->handleDripSequence(server);
  });
}

void Infra::handleDripSequence(ESP8266WebServer *server)
{
  String op = server->arg("op");
  // if (op.compare("set") != 0)
  // {
  //   std::stringstream ss(server->arg("value"));
  //   std::string token;
  //   int i = 0;
  //   while (std::getline(ss, token, ','))
  //   {
  //     if(i >= y){
  //       break;
  //     }
  //     sch[i] = token.toLong();
  //   }
  // }
  // else
  // { //assume get
  // }
}
#endif
