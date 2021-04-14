#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static int state_count = 0;

 
  if(++blink_count == 125){
    //change_states(); //all the leds are turned off and nothing happens when buttons are pressed.
    //state_advance(); //blinks constantly
    //switch_state_adv();
    blink_count = 0;
 }//end if







  
  //turns off all the leds and doesn't do anything else (tried to manually access the states by using the blink counts)
 
  /* if((++blink_count == 80) &&(switch_state_changed == 1)) {
    toggle_red_on();
    toggle_green_on();
    blink_count = 0;
  }//end 1st if
  
  if((++blink_count == 100) && (switch_state_changed == 2)){
    toggle_red_off();
    blink_count= 0;
  }//end 2nd if
  
  if((++blink_count == 120) && (switch_state_changed ==3)){
    toggle_red_on();
    blink_count = 0;
  }//end 3rd if
  
  if((++blink_count == 140) && (switch_state_changed == 4)){
    toggle_green_off();
    blink_count = 0;
  }//end 4th if 
  */
}//end wdt

