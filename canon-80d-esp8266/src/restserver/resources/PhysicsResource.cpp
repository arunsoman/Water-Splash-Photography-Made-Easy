#include "..\..\physics\Physics.h"
#include "PhysicsResource.h"
#include <stdio.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

PhysicsResource::PhysicsResource(Physics& p){
  physics = p;
};

void PhysicsResource::registerResource(ESP8266WebServer& server){
  http_rest_server = server;
  http_rest_server.on("/physics", HTTP_GET, handler(getApproxTimeToImpact));
  http_rest_server.on("/physics", HTTP_POST, handler(getTimeToImpact));
  http_rest_server.on("/physics", HTTP_GET, handler(getTimeToImpact));
}

void PhysicsResource::handler(void(*funcPtr)(&JsonObject)){
  StaticJsonBuffer<500> jsonBuffer;
  String post_body = http_rest_server.arg("plain");
  Serial.println(post_body);
  JsonObject& jsonBody = jsonBuffer.parseObject(post_body);
  Serial.print("HTTP Method: ");
  Serial.println(http_rest_server.method());

  if (!jsonBody.success()) {
    Serial.println("error in parsin json body");
    http_rest_server.send(400);
  }
  else {
    http_rest_server.send(200, "application/json", funcPtr(&jsonBody); );
  }
}

char* PhysicsResource::getApproxTimeToImpact(JsonObject& jsonBody){
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& jsonObj = jsonBuffer.createObject();
  char JSONmessageBuffer[200];
  jsonObj["Approx Time To Impact"] = physics.getApproxTimeToImpact(jsonBody["height"], jsonBody["mass"]);
  jsonObj.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
  return JSONmessageBuffer;
}

char* PhysicsResource::getTimeToImpact(JsonObject& jsonBody){

}
char* PhysicsResource::postTimetoImpact(JsonObject& jsonBody){

};
