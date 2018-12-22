#ifndef MOTOR_H
#define MOTOR_H

#include "radar.h"

class Motor {
  public:
    Motor(int mIN1, int mIN2, int mIN3, int mIN4);
    void avant(int tours);
    void avant(Radar radar, float distanceMm);
    void arriere(int tours);
    void arriere(Radar radar, float distanceMm);
    void droite(int tours);
    void avantDroite(int tours);
    void arriereDroite(int tours);
    void gauche(int tours);
    void avantGauche(int tours);
    void arriereGauche(int tours);
    void arret();

 private:
  int in1;
  int in2;
  int in3;
  int in4;
};

#endif
