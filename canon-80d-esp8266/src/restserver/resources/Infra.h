#ifndef INFRA_H
#define INFRA_H

#include <ESP8266WebServer.h>
#include <Arduino.h>
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
  void handleShutter(ESP8266WebServer *);
  long y = 3;
  long sch[3] = {2000, 6000, 9000};

};

Infra::Infra()
{

  dropper = new Dropper();
  dropper->reset(sch, y);
  dropper->setShutterSpeed(5000);
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
  restServer.getServer()->on("/SolinoidShutter", HTTP_GET, [this, server]() {
    this->handleShutter(server);
  });
}
void Infra::handleShutter(ESP8266WebServer *server)
{
 String op = server->arg("op");
  if (op.compareTo("set") == 0)
  {
    String value = server->arg("value");
    int len =  value.length();
    if(len == 0){
      server->send(200, "text/html", "value parameter not found");
      return;
    }
      dropper->setShutterSpeed(value.toInt());

    }
    String msg =   String(dropper->getShutterSpeed());
    server->send(200, "text/html", msg);
}
void Infra::handleDripSequence(ESP8266WebServer *server)
{
  String op = server->arg("op");
  Serial.println("op = "+op);
  if (op.compareTo("set") == 0)
  {
    String value = server->arg("value");
  Serial.println("value = "+value);

    int cnt = 0;
    int prev = 0;
    int len =  value.length();
    if(len == 0){
      server->send(200, "text/html", "value parameter not found");
      return;
    }
    for (int i = 0; i <len; i++) {
      if (value.substring(i, i+1) == ",") {
        sch[cnt] = value.substring(prev, i).toInt();
        if(++cnt > y){
          break;
        }
        prev = ++i;
      }
    }
  }
    String msg =  "current drip sequence : ";
    String delim =",";
    for (int i = 0; i < y; i++){
      msg += sch[i];
      msg += delim;
    }
    server->send(200, "text/html", msg);
}
#endif
