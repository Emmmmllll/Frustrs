#include <Arduino.h>
#include "motor.h"

//TODO: Richtige Pins verwenden
#define MOTOR_LINKS_POWER_PIN_ANA_OUT A0
#define MOTOR_RECHTS_POWER_PIN_ANA_OUT A1

#define MOTOR_LINKS_DIR_1_PIN_DIG_OUT 13 //(N3)HIGH
#define MOTOR_LINKS_DIR_2_PIN_DIG_OUT 12 //(N4)LOW == Vorwärts

#define MOTOR_RECHTS_DIR_1_PIN_DIG_OUT 10 //(N1)HIGH
#define MOTOR_RECHTS_DIR_2_PIN_DIG_OUT 11 //(N2)LOW  ==> Vorwärts

void set_motor_power_at_pin(uint8_t pin, int power);

void motor_setup() {
    pinMode(MOTOR_LINKS_POWER_PIN_ANA_OUT, OUTPUT);
    pinMode(MOTOR_RECHTS_POWER_PIN_ANA_OUT, OUTPUT);

    pinMode(MOTOR_LINKS_DIR_1_PIN_DIG_OUT, OUTPUT);
    pinMode(MOTOR_LINKS_DIR_2_PIN_DIG_OUT, OUTPUT);

    pinMode(MOTOR_RECHTS_DIR_1_PIN_DIG_OUT, OUTPUT);
    pinMode(MOTOR_RECHTS_DIR_2_PIN_DIG_OUT, OUTPUT);
}

void set_motor_power(enum MotorIndex idx, int power) {
    switch (idx) {
        case MotorIndex::MotorLinks:
        return set_motor_power_at_pin(MOTOR_LINKS_POWER_PIN_ANA_OUT, power);
        case MotorIndex::MotorRechts:
        return set_motor_power_at_pin(MOTOR_RECHTS_POWER_PIN_ANA_OUT, power);
        case MotorIndex::Both:
        set_motor_power_at_pin(MOTOR_LINKS_POWER_PIN_ANA_OUT, power);
        return set_motor_power_at_pin(MOTOR_RECHTS_POWER_PIN_ANA_OUT, power);
    }
    // Index ist invalide z.B. durch Casting: (enum MotorIndex) 3;
    Serial.println("Warning: Trying to set motor power of invalid index");
}

void set_motor_direction(enum MotorIndex idx, enum MotorDirection dir) {
    uint8_t pins[2];

    switch (idx) {
        case MotorIndex::MotorLinks:
        pins[0] = MOTOR_LINKS_DIR_1_PIN_DIG_OUT;
        pins[1] = MOTOR_LINKS_DIR_2_PIN_DIG_OUT;
        break;
        
        case MotorIndex::MotorRechts:
        pins[0] = MOTOR_RECHTS_DIR_1_PIN_DIG_OUT;
        pins[1] = MOTOR_RECHTS_DIR_2_PIN_DIG_OUT;
        break;

        default:
        // Index ist invalide z.B. durch Casting: (enum MotorIndex) 3;
        Serial.println("Warning: Trying to set motor direction of invalid index");
        return;
    }

    switch (dir) {
        case MotorDirection::Forward:
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[1], LOW);
        return;
        case MotorDirection::Backward:
        digitalWrite(pins[0], LOW);
        digitalWrite(pins[1], HIGH);
        return;
    }

    // Direction ist invalide z.B. durch Casting: (enum MotorDirection) 3;
    Serial.println("Warning: Trying to set invalid motor direction");
}

void set_motor_power_at_pin(uint8_t pin, int power) {
    // TODO: keine Ahnung, wie das bei den Motoren funkioniert
    analogWrite(pin, power);
}