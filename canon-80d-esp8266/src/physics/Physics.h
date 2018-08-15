#ifndef PHYSICS_H
#define PHYSICS_H

class Physics{
public:
  int getApproxTimeToImpact(double volume, double height);
  void setTimeToImpactAs(int t);
  int getTimeToImpact();
private:
  int timeToImpact;
};

#endif
