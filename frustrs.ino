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

    // wait_for_serial("Start");

    Serial.println("Starting...");

    // pinMode(2, INPUT);

    // set_motor(MotorIndex::MotorLinks, MotorDirection::Forward, 255);
    // set_motor(MotorIndex::MotorRechts, MotorDirection::Forward, 255);

    
}

void loop() {
    // licht_sensor_test();
    // uss_test();
    motor_test();
}

void uss_test() {
    int dist = uss_lookup();
    Serial.print("Uss Entfernung: ");
    Serial.println(dist);
    delay(500);
}

int m_power = 255;

void motor_test() {
    if (m_power > 0) {
        set_motor_direction(MotorIndex::MotorLinks, MotorDirection::Forward);
        set_motor_direction(MotorIndex::MotorRechts, MotorDirection::Forward);
        set_motor_power(MotorIndex::MotorLinks, m_power);
        set_motor_power(MotorIndex::MotorRechts, m_power);
    } else {
        set_motor_direction(MotorIndex::MotorLinks, MotorDirection::Backward);
        set_motor_direction(MotorIndex::MotorRechts, MotorDirection::Backward);
        set_motor_power(MotorIndex::MotorLinks, -m_power);
        set_motor_power(MotorIndex::MotorRechts, -m_power);
    }
}

void licht_sensor_test() {
    Serial.print("Linie links: ");
    if (farbsensor_lookup(FarbsensorIndex::SensorLinks)) {
        Serial.println("erkannt");
    } else {
        Serial.println();
    }

    Serial.print("Linie rechts: ");
    if (farbsensor_lookup(FarbsensorIndex::SensorRechts)) {
        Serial.println("erkannt");
    } else {
        Serial.println();
    }
    delay(250);
}
