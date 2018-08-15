#include <Arduino.h>
#include "connector\Connector.h"
#include "dropper\Dropper.h"
#include "physics\Physics.h"

 Connector e3Connector;
 Dropper* dropper = new Dropper(2,50000, 200);
 Physics physics;

void setup() {
    // put your setup code here, to run once:
}

void loop() {
  int timeToImpact = physics.getTimeToImpact();
  dropper->drip();
  delay(timeToImpact);
  e3Connector.shoot();
}
