#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

//static char state = 0;
void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

//Didn't work!!
void buzzer_state(){
  static int state = 0;
  switch(state){
  case 0:
    buzzer_set_period(1000);
    break;
  case 1:
    buzzer_set_period(2000);
    break;
  case 2:
    buzzer_set_period(500);
    break;
  case 3:
    buzzer_set_period(20);
    break;
  }
}



//didn't stop!!
void buzzer_off(){

  CCR0 = 0;
  CCR1 = 0;

}//end buzzer_off


//Didn't work
void sounds(){
  static char state = 0;
  float first_sound = 1960;
  float second_sound = 2200;
  float third_sound = 730.42;

  switch(state){
  case 0:
    buzzer_set_period(first_sound);
    break;
  case 1:
    buzzer_set_period(second_sound);
    break;
  case 2:
    buzzer_set_period(third_sound);
    break;
  case 3:
    buzzer_set_period(0);
    break;
  }//end switch
}//end method

    
    
  

