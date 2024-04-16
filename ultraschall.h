/*
    Ultraschall Sensor für Frust-RS
*/
#ifndef ULTRASCHALL_H
#define ULTRASCHALL_H

void uss_setup();

void trigger_uss_lookup();

int read_uss_echo();

int uss_lookup();

#endif 