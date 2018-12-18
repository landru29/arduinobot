#include <Arduino.h>
#include "radar.h"

/** 
 *  Constantes pour le timeout: 25ms = ~8m à 340m/s
 *  En informatique, un "timeout" c'est le temps au bout duquel on abandonne.
 *  Ici, on considère que si au bout de 25ms (qui correspondrait un un obstable à 8m),
 *  on n'a pas reçu l'écho, on arrête la mesure)
 */
const unsigned long MEASURE_TIMEOUT = 25000UL;

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

Radar::Radar(int mTriggerPin, int mEchoPin) {
  triggerPin = mTriggerPin;
  echoPin = mEchoPin;
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

/**
 * Renvoie la distance en millimètre
 */
float Radar::distance() {
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(echoPin, HIGH, MEASURE_TIMEOUT);

  /* 3. Calcul la distance à partir du temps mesuré */
  float result = measure / 2.0 * SOUND_SPEED;

  Serial.println(String("[R] Distance ") + result + String(" / mm"));

  
  return  result;
}
