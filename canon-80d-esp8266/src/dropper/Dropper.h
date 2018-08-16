#ifndef DROPPER_H
#define DROPPER_H

using namespace std;
class Dropper{
public:
  Dropper( );
  void drip();
  void stop();
  void reset(vector<long> x, long, long);
private:
  long index = 0;
  long repeatCycle;
  vector<long> schedule;
  long shutterSpeed;
  int SolenoidValvePin;
  void drop();
};
#endif
