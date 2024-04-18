#define LED_PIN 13
#include "ultraschall.h"
#include "farbsensor.h"
#include "motor.h"
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

/*
    Wartet bist str durch den Serial port (z.B. von einem angeschlossenem Computer) empfangen wurde
*/
void wait_for_serial(const char * str) {
    String serial_in;

    Serial.print("Waiting for Serial Message '");
    Serial.print(str);
    Serial.println("' ...");

    while (serial_in != str) {
        // recieved something last cycle but did not match str
        if (serial_in.length() != 0) {
            Serial.print("Expected: '");
            Serial.print(str);
            Serial.print("' Got: '");
            Serial.print(serial_in);
            Serial.println("'");
        }

        serial_in = Serial.readString();

        // remove trailing new line character        
        if (serial_in.charAt(serial_in.length() - 1) == '\n') {
            serial_in = serial_in.substring(0, serial_in.length() - 1);
        }

        // delay for power efficiency
        // we are waiting anyways
        delay(100);
    }
}


void exit() {
    delay(1000);
    exit(0);
}

//moin
