#include "radar.h"
#include "motor.h"
#include "roue.h"

// radarArriere(violet, bleu)
Radar radarArriere(52, 53);

// radarAvant(jaune, vert)
Radar radarAvant(50, 51);

// moteur (violet, bleu, vert, jaune)
Motor moteur(28, 26, 24, 22);

// roues(gris, blanc) ==> on ne peut utiliser que 2, 3, 18, 19, 20, 21
Roue roues(20, 21);



void setup() {
  Serial.begin(115200);

}

void loop() {

  moteur.avant(radarAvant, 100);
  delay(500);
  moteur.arriereDroite(100);
  delay(500);

}
