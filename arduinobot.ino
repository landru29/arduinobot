#include "distance.h"
#include "motor.h"

// Distance frontIntruder(DISTANCE_FRONT_TRIGGER_PIN, DISTANCE_FRONT_ECHO_PIN);

Motor moteur(28, 26, 24, 22);

void setup() {
  // Serial.begin(115200);

}

void loop() {

  delay(1000);

  //int dist = frontIntruder.measure();

  moteur.right();

  //Serial.println(dist);
  delay(1000);
}
