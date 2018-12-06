#include "config.h"
#include "distance.h"

Distance frontIntruder(DISTANCE_FRONT_TRIGGER_PIN, DISTANCE_FRONT_ECHO_PIN);

void setup() {


  Serial.begin(115200);
  frontIntruder.init();

}

void loop() {

  int dist = frontIntruder.measure();

  Serial.println(dist);
  delay(1000);
}
