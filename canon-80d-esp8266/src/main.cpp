#include <Arduino.h>
#include "connector\Connector.h"
#include "dropper\Dropper.h"
#include "physics\Physics.h"
#include "restserver\resources\PhysicsResource.h"
#include "restserver\RestServer.h"

 Connector e3Connector;
 Dropper* dropper = new Dropper(2,50000, 200);
 PhysicsResource physicsRes;
 RestServer restServer;

void setup() {
  physicsRes.registerResource(restServer.getServer());
    // put your setup code here, to run once:
}

void loop() {
  restServer.handleClient();
  int timeToImpact = physicsRes.getModel()->getTimeToImpact();
  dropper->drip();
  delay(timeToImpact);
  e3Connector.shoot();
}
