#ifndef INFRA_H
#define INFRA_H

#include <ESP8266WebServer.h>
#include "..\..\dropper\Dropper.h"
#include "..\..\connector\Connector.h"
#include "PhysicsResource.h"
#include "..\RestServer.h"

class Infra{
public:
  Infra();
   Dropper* dropper;
   Connector* connector;
   RestServer restServer;
   PhysicsResource physicsRes;
private:
  void registerResource();
  void handleGetRepeateInterval(ESP8266WebServer*);
  void handleGetDripSequence(ESP8266WebServer*);
  void handlePostDripSequence(ESP8266WebServer*);
  long sch[5] = {2000, 6000, 9000};

};

Infra::Infra(){
   long y = 3; long z = 5000;
  dropper = new Dropper();
   dropper->reset(sch,y,z);
  connector = new Connector();
registerResource();
}
void Infra::registerResource(){
  physicsRes.registerResource(restServer.getServer());
  handleGetDripSequence(restServer.getServer());
  handleGetRepeateInterval(restServer.getServer());
  handlePostDripSequence(restServer.getServer());
}

void Infra::handleGetRepeateInterval(ESP8266WebServer*server){}
void Infra::handleGetDripSequence(ESP8266WebServer*server){}
void Infra::handlePostDripSequence(ESP8266WebServer*server){}
#endif
