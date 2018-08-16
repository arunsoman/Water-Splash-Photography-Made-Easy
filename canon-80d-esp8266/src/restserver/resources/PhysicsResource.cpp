#include "..\..\physics\Physics.h"
#include "PhysicsResource.h"
#include <stdio.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

Physics* PhysicsResource::getModel(){
  return &physics;
}

void PhysicsResource::registerResource(ESP8266WebServer *server){
  server->on("/physics", HTTP_GET, getApproxTimeToImpact);
  server->on("/physics", HTTP_POST, getTimeToImpact);
  server->on("/physics", HTTP_GET, getTimeToImpact);
}

JsonObject& PhysicsResource::handler(){
  StaticJsonBuffer<500> jsonBuffer;
  String post_body = http_rest_server->arg("plain");
  Serial.println(post_body);
  JsonObject& jsonBody = jsonBuffer.parseObject(post_body);
  Serial.print("HTTP Method: ");
  Serial.println(http_rest_server->method());
  return jsonBody;
}

void PhysicsResource::getApproxTimeToImpact(){
  JsonObject& jsonBody = handler();
  if (!jsonBody.success()) {
    Serial.println("error in parsing json body");
    http_rest_server->send(400);
  }
  else {
    StaticJsonBuffer<200> jsonBuffer1;
    JsonObject& jsonObj1 = jsonBuffer1.createObject();
    char JSONmessageBuffer[200];
    jsonObj1["Approx Time To Impact"] = physics.getApproxTimeToImpact(jsonBody["height"], jsonBody["mass"]);
    jsonObj1.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));

    http_rest_server->send(200, "application/json", JSONmessageBuffer );
  }
}

void PhysicsResource::getTimeToImpact(){

}
void PhysicsResource::postTimetoImpact(){

};
