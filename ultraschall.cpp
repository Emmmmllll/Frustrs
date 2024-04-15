#include <Arduino.h>
#include "ultraschall.h"

#define ULTRASCHALL_SENSOR_PIN_DIG_OUT 5
#define ULTRASCHALL_SENSOR_PIN_ANA_IN A4

void uss_setup() {
    pinMode(ULTRASCHALL_SENSOR_PIN_DIG_OUT, OUTPUT);
    pinMode(ULTRASCHALL_SENSOR_PIN_ANA_IN, INPUT);
}


//TODO: keine Ahnung, ob das so funktioniert
void trigger_uss_lookup() {
    digitalWrite(ULTRASCHALL_SENSOR_PIN_DIG_OUT, HIGH);
    delay(1);
    digitalWrite(ULTRASCHALL_SENSOR_PIN_DIG_OUT, LOW);
}

int read_uss_echo() {
    analogRead(ULTRASCHALL_SENSOR_PIN_ANA_IN);
}

int uss_lookup() {
    trigger_uss_lookup();
    read_uss_echo();
}