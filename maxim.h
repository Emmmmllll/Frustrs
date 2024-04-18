#include "ultraschall.h"
void exit_if_USS_detect () {
    // wenn ein Objekt näher als 1 Meter ist, beende das Programm
    if (uss_lookup() < 100)
    {
        exit(0);
    }
}
