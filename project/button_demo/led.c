#include <msp430.h>
#include "led.h"
#include "switches.h"

//assigned new variables to be able to use the code from blink_demo
unsigned char green_on = 0, red_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED};
static char greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_changed = 1;
  led_update();
}//end led_init

void led_update(){
  char ledFlags = 0;

  //code from button_demo from led.c
  //only turns on the green
  
  /*if (switch_state_changed) {
  char ledFlags = 0; //by default, no LEDs on 

  ledFlags |= switch_state_down1 ? LED_GREEN : 0;
  ledFlags |= switch_state_down1 ? 0 : LED_RED;

  P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
  P1OUT |= ledFlags;         // set bits for on leds
  }//end if

  switch_state_changed = 0;
  */
  
  //code from the blink_demo led.c, all the leds are off
  if(led_changed){
     ledFlags = greenVal[green_on] | redVal[red_on];

    P1OUT &=(0Xff^LEDS) |ledFlags;
    P1OUT |= ledFlags;
    led_changed = 0;

    }//end 1st if


   
  // This code below is to s


   
  /*if(switch_state_down1 && switch_state_changed == 2){
    ledFlags |= switch_state_down2 ? LED_GREEN : 0;
    ledFlags |= switch_state_down2 ? 0 : LED_RED;

    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }//end 2nd if

  if(switch_state_down1 && switch_state_changed == 3){
    ledFlags |= switch_state_down3 ? 0: LED_GREEN;

    P1OUT &= (0xff^LEDS) |ledFlags;
    P1OUT |=ledFlags;
  }//end 3rd if
  //switch_state_changed = 0;
  */


   
}//end led_update

