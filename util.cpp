#include <Arduino.h>
#include "util.h"

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

