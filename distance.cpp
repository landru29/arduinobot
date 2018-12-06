#include "distance.h"

#include <Arduino.h>

/* Constantes pour le timeout: 25ms = ~8m à 340m/s */
const unsigned long MEASURE_TIMEOUT = 25000UL;

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

Distance::Distance(int mTriggerPin, int mEchoPin) {
  triggerPin = mTriggerPin;
  echoPin = mEchoPin;
  pinMode(mTriggerPin, OUTPUT);
  pinMode(mEchoPin, INPUT);
}

/**
 * Renvoie la distance en millimètres
 */
float Distance::measure() {
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(echoPin, HIGH, MEASURE_TIMEOUT);

  /* 3. Calcul la distance à partir du temps mesuré */
  return measure / 2.0 * SOUND_SPEED;
}
