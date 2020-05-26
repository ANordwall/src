#include "elecanisms.h"
#include "millis.h"

#define p1  D0			// Player 1 button
#define l1  D1			// Player 1 LED
#define start   D7		// Start button
#define led D9			// main LED
#define p2  D12			// Player 2 button
#define l2  D13			// Player 2 LED


// generate a random number between 6000 and 2000
int random(void) { 
    int num; 
    num = (rand() %6000) +2000; 
    return num;  
} 
  
 
  
int16_t main(void) {
    uint32_t t0, t;

    init_elecanisms();
    init_millis();

    t0 = millis();                          //start time
    
    int r = random();                       //random delay length 
    
    while (1) {
	    t = millis();
        if (start==0 && t>=t0+r) {          // if start button is pressed and random time has elapsed
            led = ON;
            while (1){
                int t1=millis();
	            if (p1==0){                 // if player 1 hits their button
                    led=OFF;
                    l1=ON;
                    while (1){
                        t=millis();
                        if (t>=t1+2000){    //turn on P1 LED for 2 seconds to indicate win
                            l1=OFF;
                            main();         //repeat main function
                        }
                    }
                }
	        	else if (p2==0){            //if player 2 hits their button
                    led=OFF;
                    l2=ON;
                    while (1){
                        t=millis();
                        if (t>=t1+2000){    //turn on P1 LED for 2 seconds to indicate win
                            l2=OFF;
                            main();         //repeat main function
                        }
                    }
	        	}
	        }
        }
    }    
}


