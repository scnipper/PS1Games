#include "core.h"


void setState(enum State state) {
    mainState = state;
    initFuncs[state]();
}