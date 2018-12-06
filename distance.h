#ifndef DISTANCE_H
#define DISTANCE_H

class Distance {
  public:
    Distance(int mTriggerPin, int mEchoPin);
    float measure();

 private:
  int triggerPin;
  int echoPin;
};

#endif
