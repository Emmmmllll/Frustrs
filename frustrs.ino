#define LED_PIN 13
#include "ultraschall.h"
#include "farbsensor.h"
#include "motor.h"
#include "util.h"
#include "maxim.h"
int m_power = 255;

void setup() {
    Serial.begin(9600);

    uss_setup();
    farbsensor_setup();
    motor_setup();

    // wait_for_serial("Start");

    Serial.println("Starting...");

    set_motor_power(MotorAll, 255);  
   
}
 void uss_test() {
    int dist = uss_lookup();
    Serial.print("Uss Entfernung: ");
    Serial.println(dist);
    delay(500);
}


  void loop() {
    // licht_sensor_test();
     uss_test();
    // motor_test();

    if (farbsensor_lookup(SensorLinks)) {
        set_motor_direction(MotorLinks, Stand);
        set_motor_direction(MotorRechts, Forward);
    } else if (farbsensor_lookup(SensorRechts)) {
        set_motor_direction(MotorRechts, Stand);
        set_motor_direction(MotorLinks, Forward);
    } else {
        set_motor_direction(MotorRechts, Forward);
        set_motor_direction(MotorLinks, Forward);
    }
}

 /*
 void loop() {
    while ((farbsensor_lookup(SensorLinks))&&(farbsensor_lookup(SensorRechts))) {
  set_motor_direction(MotorAll, Forward);
   }
  if (farbsensor_lookup(SensorLinks)) {}
  else {
      set_motor_direction(MotorLinks, Stand);
      set_motor_direction(MotorRechts, Forward);
        }  
  if (farbsensor_lookup(SensorRechts)) {}
              else {
                   set_motor_direction(MotorRechts, Stand);
                   set_motor_direction(MotorLinks, Forward);
       }

  }

  */
 


/*void motor_test() {
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
*/
/*
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
*/
