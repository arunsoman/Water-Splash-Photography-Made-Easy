#include "Physics.h"


/*********************************************************************
* Comment
*********************************************************************/
int Physics::getApproxTimeToImpact(double height)
{
  //TODO compute the time given height, mass
  return 1000;
}
/*********************************************************************
* Comment
*********************************************************************/
void Physics::setTimeToImpactAs(int t)
{
  timeToImpact = t;
}
/*********************************************************************
* Comment
*********************************************************************/
int Physics::getTimeToImpact()
{
  return timeToImpact;
}
