#ifndef MOTOR_H
#define MOTOR_H

class Motor {
  public:
    Motor(int mIN1, int mIN2, int mIN3, int mIN4);
    void forward();
    void backyard();
    void right();
    void left();

 private:
  int in1;
  int in2;
  int in3;
  int in4;
};

#endif
