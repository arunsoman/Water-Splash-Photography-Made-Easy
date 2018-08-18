#include <Arduino.h>

#include "connector\Connector.h"
#include "dropper\Dropper.h"
#include "restServer\resources\Infra.h"

#define SIMULATOR
int ARRAY_SIZE =5;

Infra* infra;
void setup() {
  Serial.begin(115200);
  infra = new Infra();
}

void loop() {
    if(infra->restServer.handleClient()== RestServer::START){
      int timeToImpact = infra->physicsRes.getModel()->getTimeToImpact();
      infra->dropper->drip();
      delay(timeToImpact);
      infra->connector->shoot();
  }
}
