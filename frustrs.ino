#define LED_PIN 13
#include "ultraschall.h"
#include "farbsensor.h"
#include "motor.h"
#include "util.h"
#include "maxim.h"

void setup() {
    Serial.begin(9600);

    uss_setup();
    farbsensor_setup();
    motor_setup();

    wait_for_serial("Start");

    Serial.println("Starting...");
}

void loop() {
    // Volle farht vorraus
    set_motor(MotorIndex::MotorLinks, MotorDirection::Forward, 255);
    set_motor(MotorIndex::MotorRechts, MotorDirection::Forward, 255);
    while (1) {
        exit_if_USS_detect ();
    }
    exit();
}

