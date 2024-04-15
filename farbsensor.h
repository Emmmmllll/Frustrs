/*
    Farbsensor für Frust-RS
*/
#ifndef FARBSENSOR_H
#define FARBSENSOR_H

enum FarbsensorIndex {
    SensorLinks,
    SensorRechts,
};

void farbsensor_setup();

int farbsensor_lookup(enum FarbsensorIndex idx);

#endif