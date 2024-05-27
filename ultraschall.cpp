#include <Arduino.h>
#include "ultraschall.h"

/*
    The logic of this file is based on this article:
    https://funduino.de/nr-10-entfernung-messen
*/

#define ULTRASCHALL_SENSOR_PIN_DIG_OUT 5
#define ULTRASCHALL_SENSOR_PIN_ANA_IN A4

void uss_setup() {
    pinMode(ULTRASCHALL_SENSOR_PIN_DIG_OUT, OUTPUT);
    pinMode(ULTRASCHALL_SENSOR_PIN_ANA_IN, INPUT);

    //disable trigger for a short period to prevent unpredictable behaviour
    digitalWrite(ULTRASCHALL_SENSOR_PIN_DIG_OUT, LOW);
    delay(5);
}


void trigger_uss_lookup() {
    digitalWrite(ULTRASCHALL_SENSOR_PIN_DIG_OUT, HIGH);
    delay(10);
    digitalWrite(ULTRASCHALL_SENSOR_PIN_DIG_OUT, LOW);
}

unsigned long read_uss_echo() {
    return pulseIn(ULTRASCHALL_SENSOR_PIN_ANA_IN, HIGH);
}

unsigned long uss_lookup_time() {
    trigger_uss_lookup();
    return read_uss_echo();
}

unsigned long uss_lookup() {
    long time = uss_lookup_time();
    long distance_centimeters = static_cast<long>((static_cast<float>(time / 2)) * 0.03432);
    return distance_centimeters;
}

