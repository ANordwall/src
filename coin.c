#include "elecanisms.h"

int16_t main(void) {
    init_elecanisms();


        LED1 = (D0 == 0) ? ON : OFF;   // turn LED1 on if SW2 is pressed 
        LED3 = (SW3 == 0) ? ON : OFF;   // turn LED3 on if SW3 is pressed
    
}

