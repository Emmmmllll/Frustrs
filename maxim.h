#include "ultraschall.h"
void exit_if_USS_detect () {
  if (uss_lookup() < 100)
  {
    exit(0);
  }
}
