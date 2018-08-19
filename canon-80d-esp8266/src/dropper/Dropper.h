#ifndef DROPPER_H
#define DROPPER_H
class Dropper{
public:
  Dropper( );
  void drip();
  void stop();
  void reset(long* delay, int size);
  int getShutterSpeed();
  void setShutterSpeed(int s);
private:
  int it;
  int size;
  long* schedule;
  int shutterSpeed;
  int SolenoidValvePin;
  void drop();
};
#endif
