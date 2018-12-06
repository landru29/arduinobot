#ifndef DISTANCE_H
#define DISTANCE_H

class Distance {
  public:
    Distance(int mTriggerPin, int mEchoPin);
    void init();
    float measure();

 private:
  int triggerPin;
  int echoPin;
};

#endif
