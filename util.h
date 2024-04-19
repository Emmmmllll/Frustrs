#ifndef FRUSTRSUTIL_H
#define FRUSTRSUTIL_H

void exit();

/*
    Wartet bist str durch den Serial port (z.B. von einem angeschlossenem Computer) empfangen wurde
*/
void wait_for_serial(const char * str);

/*
    Startet das gesamte Programm neu.

    Es wird eine Funktion zu der Adresse 0x00 aufgerufen,
    wo der Interrupt table eintrag für den Reset button liegt
    und da Programm nach dem Stromanschluss startet.
    Der Interrupt eintrag dient dem Reset Button/Pin auf dem 
    Arduino Board und dadurch kann durch den Sprung nach 0x00
    das gesamte Programm neu gestartet werden.
*/
inline void reset() {
    (*(void (*) (void)) 0)();
}

#endif