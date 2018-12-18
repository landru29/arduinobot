#ifndef RADAR_H
#define RADAR_H

class Radar {
  public:
    Radar(int mTriggerPin, int mEchoPin);
    float distance();

 private:
  int triggerPin;
  int echoPin;
};

#endif
