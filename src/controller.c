#include "controller.h"
void initialize_pad() {
    PadInit(0);
}

void pad_reset(void) {
    SysPad = 0;
    SysPadT = 0;
}

void pad_update(void){
    int	pad = PadRead(0);
    SysPadT = pad & (pad ^ SysPad);
    SysPad = pad;
}