#ifndef DROPPER_H
#define DROPPER_H
#include<vector>
class Dropper{
public:
  Dropper( );
  void drip();
  void stop();
  void reset(long* delay, int size, long shutterSpeed);
private:
  int it;
  int size;
  long* schedule;
  long shutterSpeed;
  int SolenoidValvePin;
  void drop();
};
#endif
