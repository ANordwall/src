#include "elecanisms.h"
#include "millis.h"

#define p1  D0
#define l1  D1
#define start   D7
#define led D9
#define p2  D12
#define l2  D13

int statep1 = 0;
int statep2 = 0;
int laststatep1 = 0;
int laststatep2 = 0;


// generate a random number between 1 and 5
int random(void) { 
    int num; 
    num = (rand() %6000) +2000; 
    return num;  
} 
  
 
  
int16_t main(void) {
    uint32_t t0, t;

    init_elecanisms();
    init_millis();

    t0 = millis();
    
    int r = random();
    
    while (1) {
	    t = millis();
        if (start==0 && t>=t0+r) {
            led = ON;
            while (1){
                int t1=millis();
	            if (p1==0){
                    led=OFF;
                    l1=ON;
                    while (1){
                        t=millis();
                        if (t>=t1+3000){
                            l1=OFF;
                            main();
                        }
                    }
                }
	        	else if (p2==0){
                    led=OFF;
                    l2=ON;
                    while (1){
                        t=millis();
                        if (t>=t1+3000){
                            l2=OFF;
                            main();
                        }
                    }

		            //l1 = (p1 == 0) ? ON : OFF; 
		            //l2 = (p2 == 0) ? ON : OFF; 
	        	}
	        }
        }
    }    
}


