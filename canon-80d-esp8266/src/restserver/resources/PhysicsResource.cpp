#include "..\..\physics\Physics.h"
#include "PhysicsResource.h"
#include <stdio.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

Physics* PhysicsResource::getModel(){
  return &physics;
}

void PhysicsResource::registerResource( ESP8266WebServer *server){
  server->on("/physics/ApproxTimeToImpact", HTTP_GET, [this,&server](){
    this->getApproxTimeToImpact(server);
  });
   server->on("/physics/TimeToImpact", HTTP_POST, [this,&server](){
     this->getTimeToImpact(server);});
  // server->on("/physics", HTTP_GET, getTimeToImpact);
  Serial.println("physics/ApproxTimeToImpact");
}


void PhysicsResource::getApproxTimeToImpact( ESP8266WebServer *http_rest_server){
  // String height = http_rest_server->arg('height');
  // if(!height){
  //   float h = height.toFloat();
  //   http_rest_server->send(200, "application/json",std::string.to_string (physics.getApproxTimeToImpact(h)) );
  // }
}

void PhysicsResource::getTimeToImpact( ESP8266WebServer *http_rest_server){

}
void PhysicsResource::postTimetoImpact( ESP8266WebServer *http_rest_server){

};
