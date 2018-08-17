#ifndef DROPPER_H
#define DROPPER_H
#include<vector>
class Dropper{
public:
  Dropper( );
  void drip();
  void stop();
  void reset(std::vector<long> x, long, long);
private:
  std::vector<long>::iterator it;
  std::vector<long> schedule;
  long shutterSpeed;
  int SolenoidValvePin;
  void drop();
};
#endif
