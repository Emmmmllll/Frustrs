/*
    Motor für Frust-RS
*/
#ifndef MOTOR_H
#define MOTOR_H

enum MotorIndex {
    MotorLinks,
    MotorRechts,
    MotorAll,
};

enum MotorDirection {
    Forward,
    Stand,
    Backward,
};

/*
    Setzt pinMode() für die Motoren
*/
void motor_setup();


/*
    Setzt Motor-stärke
    ### Beispiel
    set_motor_power(MotorIndex::MotorLinks, 3);
*/
void set_motor_power(enum MotorIndex idx, int power);

/*
    Setzt Motor-richtung
    ### Beispiel
    set_motor_power(MotorIndex::MotorLinks, MotorDirection::Forward);
*/
void set_motor_direction(enum MotorIndex idx, enum MotorDirection dir);

/*
    Setzt Motor-stärke und -richtung
    ### Beispiel
    set_motor_power(MotorIndex::MotorLinks, MotorDirection::Forward, 3);
*/
inline void set_motor(enum MotorIndex idx, enum MotorDirection dir, int power) {
    set_motor_direction(idx, dir);
    set_motor_power(idx, power);
}

#endif