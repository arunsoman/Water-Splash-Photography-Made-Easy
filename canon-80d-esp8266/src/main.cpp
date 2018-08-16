#include <Arduino.h>
#include "connector\Connector.h"
#include "dropper\Dropper.h"
#include "physics\Physics.h"
#include "restserver\resources\PhysicsResource.h"
#include "restserver\RestServer.h"
#include "restServer\resources\Infra.h"

Infra infra;
PhysicsResource physicsRes;
RestServer restServer;
Dropper* dropper = infra.getDropper();
Connector* connector = infra.getConnector();

void setup() {
  physicsRes.registerResource(restServer.getServer());
  infra.registerResource(restServer.getServer());
  // put your setup code here, to run once:
}

void loop() {
  restServer.handleClient();
  int timeToImpact = physicsRes.getModel()->getTimeToImpact();
  dropper->drip();
  delay(timeToImpact);
  connector->shoot();
}
