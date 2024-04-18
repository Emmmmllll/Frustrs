#ifndef FRUSTRSUTIL_H
#define FRUSTRSUTIL_H

void exit();

/*
    Wartet bist str durch den Serial port (z.B. von einem angeschlossenem Computer) empfangen wurde
*/
void wait_for_serial(const char * str);

#endif