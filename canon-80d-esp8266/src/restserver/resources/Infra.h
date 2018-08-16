#ifndef INFRA_H
#define INFRA_H
using namespace std;

#include <ESP8266WebServer.h>
#include "..\..\dropper\Dropper.h"
#include "..\..\connector\Connector.h"

class Infra{
public:
  Infra();
  void registerResource(ESP8266WebServer*);
  Dropper* getDropper();
  Connector* getConnector();
private:
  Dropper* dropper;
  Connector* connector;
  void handleGetRepeateInterval(ESP8266WebServer*);
  void handleGetDripSequence(ESP8266WebServer*);
  void handlePostDripSequence(ESP8266WebServer*);

};

Infra::Infra(){
  vector<long> sch;
  long y = 500; long z = 50000;
  dropper = new Dropper();
  dropper->reset(sch,y,z);
  connector = new Connector();
}
void Infra::registerResource(ESP8266WebServer* server){
  handleGetDripSequence(server);
  handleGetRepeateInterval(server);
  handlePostDripSequence(server);
}
Dropper* Infra::getDropper(){return dropper;}
Connector* Infra::getConnector(){return connector;}

void Infra::handleGetRepeateInterval(ESP8266WebServer*server){}
void Infra::handleGetDripSequence(ESP8266WebServer*server){}
void Infra::handlePostDripSequence(ESP8266WebServer*server){}
#endif
