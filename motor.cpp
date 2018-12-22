#include <Arduino.h>
#include "motor.h"
#include "roue.h"
#include "radar.h"

/**
 * Les moteurs sont couplés:
 *   - les moteurs gauches ensembles
 *   - les moteurs droits ensembles
 * Ils sont pilotés avec in1, in2, in3, in4
 * 
 * pour faire tourner les moteurs droits vers l'avant, il faut:
 *   - in3 -> HIGH
 *   - in4 -> LOW
 *   
 * pour faire tourner les moteurs droits vers l'arrière, il faut:
 *   - in3 -> LOW
 *   - in4 -> HIGH
 *   
 * pour faire tourner les moteurs gauches vers l'avant, il faut:
 *   - in1 -> HIGH
 *   - in2 -> LOW
 * 
 * pour faire tourner les moteurs gauches vers l'arrière, il faut:
 *   - in1 -> LOW
 *   - in2 -> HIGH
 */


const unsigned int PERIMETRE = 212;

Motor::Motor(int mIN1, int mIN2, int mIN3, int mIN4) {
  in1 = mIN1;
  in2 = mIN2;
  in3 = mIN3;
  in4 = mIN4;

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void Motor::avant(int pas) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  if (pas>0) {
    Roue::resetAll();
    while (Roue::counterLeft < pas) {
      Serial.println(String("[M] Avant ") + Roue::counterLeft + String(" / 20"));
      delay(100);
    }
    arret();
    Serial.println(String("[M] Avant ") + Roue::counterLeft + String(" / 20"));
  }
}

void Motor::avant(Radar radar, float distanceMm) {
  if (distanceMm <= 0) return;
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  bool distanceReached = false;
  while (!distanceReached) {
    distanceReached = (radar.distance() < distanceMm);
    delay(300);
  }
}

void Motor::arriere(int pas) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  if (pas>0) {
    Roue::resetAll();
    while (Roue::counterLeft < pas) {
      Serial.println(String("[M] Arrière ") + Roue::counterLeft + String(" / 20"));
      delay(50);
    }
    arret();
    Serial.println(String("[M] Arrière ") + Roue::counterLeft + String(" / 20"));
  }
}

void Motor::arriere(Radar radar, float distanceMm) {
  if (distanceMm <= 0) return;
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  bool distanceReached = false;
  while (!distanceReached) {
    distanceReached = (radar.distance() < distanceMm);
    delay(300);
  }
}

void Motor::avantDroite(int pas) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  if (pas>0) {
    Roue::resetLeft();
    while (Roue::counterLeft < pas) {
      Serial.println(String("[M] Avant-droite ") + Roue::counterLeft + String(" / 20"));
      delay(50);
    }
    arret();
    Serial.println(String("[M] Avant-droite ") + Roue::counterLeft + String(" / 20"));
  }
}

void Motor::avantGauche(int pas) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  if (pas>0) {
    Roue::resetRight();
    while (Roue::counterRight < pas) {
      Serial.println(String("[M] Avant-gauche ") + Roue::counterRight + String(" / 20"));
      delay(50);
    }
    arret();
    Serial.println(String("[M] Avant-gauche ") + Roue::counterRight + String(" / 20"));
  }
}

void Motor::droite(int pas) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  if (pas>0) {
    Roue::resetLeft();
    while (Roue::counterLeft < pas) {
      Serial.println(String("[M] Droite ") + Roue::counterLeft + String(" / 20"));
      delay(50);
    }
    arret();
    Serial.println(String("[M] Droite ") + Roue::counterLeft + String(" / 20"));
  }
}

void Motor::gauche(int pas) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  if (pas>0) {
    Roue::resetRight();
    while (Roue::counterRight < pas) {
      Serial.println(String("[M] Gauche ") + Roue::counterRight + String(" / 20"));
      delay(50);
    }
    arret();
    Serial.println(String("[M] Gauche ") + Roue::counterRight + String(" / 20"));
  }
}

void Motor::arriereDroite(int pas) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  if (pas>0) {
    Roue::resetLeft();
    while (Roue::counterLeft < pas) {
      Serial.println(String("[M] Arrière-droite ") + Roue::counterLeft + String(" / 20"));
      delay(50);
    }
    arret();
    Serial.println(String("[M] Arrière-droite ") + Roue::counterLeft + String(" / 20"));
  }
}

void Motor::arriereGauche(int pas) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  if (pas>0) {
    Roue::resetRight();
    while (Roue::counterRight < pas) {
      Serial.println(String("[M] Arrière-gauche ") + Roue::counterRight + String(" / 20"));
      delay(50);
    }
    arret();
    Serial.println(String("[M] Arrière-gauche ") + Roue::counterRight + String(" / 20"));
  }
}

void Motor::arret() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
