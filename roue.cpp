#include <Arduino.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include "roue.h"


Roue::Roue(int mTriggerDroite, int mTriggerGauche) {
  pinMode(mTriggerDroite, INPUT);
  pinMode(mTriggerGauche, INPUT);
  Roue::resetAll();
  attachInterrupt(digitalPinToInterrupt(mTriggerDroite), Roue::processRight, RISING);
  attachInterrupt(digitalPinToInterrupt(mTriggerGauche), Roue::processLeft, RISING);
}

unsigned long Roue::compteurDroite() {
  return Roue::counterRight;
}

unsigned long Roue::compteurGauche() {
  return Roue::counterLeft;
}

void Roue::reset() {
  Roue::resetAll();
}

void Roue::resetDroite() {
  Roue::resetRight();
}
void Roue::resetGauche() {
  Roue::resetLeft();
}

void Roue::resetAll() {
  Roue::resetRight();
  Roue::resetLeft();
}

void Roue::processRight() {
  counterRight++;
}

void Roue::processLeft() {
  counterLeft++;
}

void Roue::resetLeft() {
  Roue::counterLeft = 0;
}

void Roue::resetRight() {
  Roue::counterRight = 0;
}

unsigned long Roue::counterRight = 0;
unsigned long Roue::counterLeft = 0;

/**
 * 20 Trous dans la roue
 */
static int Roue::steps = 20;
