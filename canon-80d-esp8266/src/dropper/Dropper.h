#ifndef DROPPER_H
#define DROPPER_H
class Dropper{
public:
  Dropper(int secondDrop, int interval, int x);
  void drip();
  void stop();
  void reset(int secondDrop, int interval, int x);
private:
  int wait;
  int secondDrop;
  int interval;
  int shutterSpeed;
  int SolenoidValvePin;
  void drop();
};
#endif
