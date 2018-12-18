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

  

  moteur.avantDroite(5 * Roue::steps);

  /* while (true) {
    Serial.println(radarAvant.mesure());
    Serial.println(radarArriere.mesure());

    if (radarAvant.mesure() < 100) {
      moteur.arret();
    }
    
    delay(1000);

    
  }*/

  radarAvant.distance();

  while (true) {

    //Serial.println(roues.compteurGauche());
    //Serial.println(roues.compteurDroite());
  
    delay(1000);
  }

  delay(1000);
}
