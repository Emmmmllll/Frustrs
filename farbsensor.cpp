#include <Arduino.h>
#include "farbsensor.h"

//TODO: Richtige Pins verwenden
#define FARBSENSOR_LINKS_PIN_ANA_IN A1
#define FARBSENSOR_RECHTS_PIN_ANA_IN A2


int lookup_sensor_at_pin(uint8_t pin); 

void farbsensor_setup() {
    pinMode(FARBSENSOR_LINKS_PIN_ANA_IN, INPUT);
    pinMode(FARBSENSOR_RECHTS_PIN_ANA_IN, INPUT);
}
  // 1 bei Schwarzer linie oder keiner Reflexion
  // 0 bei hellem Untergrund
int farbsensor_lookup(enum FarbsensorIndex idx) {
    switch (idx) {
        case FarbsensorIndex::SensorLinks:
        return lookup_sensor_at_pin(FARBSENSOR_LINKS_PIN_ANA_IN);
        case FarbsensorIndex::SensorRechts:
        return lookup_sensor_at_pin(FARBSENSOR_RECHTS_PIN_ANA_IN);
    }
    // Index ist invalide z.B. durch Casting: (enum FarbsensorIndex) 3;
    Serial.println("Warning: Trying to lookup Farbsensor of invalid index");
}

int lookup_sensor_at_pin(uint8_t pin) {
    //TODO: richtigen Lookup verwenden
    return digitalRead(pin);
}
