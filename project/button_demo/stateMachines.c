#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

//static char bright_state = 0;

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

void toggle_red_on(){
  red_on =1;

  led_changed = 1;
  led_update();

}//end

void toggle_red_off(){
  red_on = 0;
  
  led_changed = 1;
  led_update();
}//end


char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void toggle_green_on(){
  green_on = 1;

  led_changed = 1;
  led_update();
}


void toggle_green_off(){
  green_on = 0;

  led_changed = 1;
  led_update();

}

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}

//red 75 brightness
void red_dim(){
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 1;
    state = 2;
    break;
  case 2:
    red_on = 0;
    state = 0;
    break;
  }//end switch

  led_changed = 1;
  led_update();
}//end red_dim

//green 75 brightness
  void green_dim(){
    static char state = 0;

    switch(state){
    case 0:
      green_on = 1;
      state = 1;
      break;
    case 1:
      green_on = 1;
      state = 2;
      break;
    case 2:
      green_on = 0;
      state = 0;
      break;

    }//end switch   
  led_changed = 1;
  led_update();
}//end green_dim

//25 red brightness
void red_dim_25(){
  static char state =0;

  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 2;
    break;
  case 2:
    red_on = 0;
    state = 3;
    break;
  case 3:
    red_on = 0;
    state = 0;
    break;
  }//end switch
  led_changed = 1;
  led_update();
}//end red_dim_25


//25 green brightness
void green_dim_25(){
  static char state = 0;

  switch(state){
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 2;
    break;
  case 2:
    green_on = 0;
    state = 3;
    break;
  case 3:
    green_on = 0;
    state = 0;
    break;
  }//end switch
  led_changed = 1;
  led_update();
}//end green_dim_25

//assign instructions for what happens in each state
void state_dimming(){
  //static char state = 0;

  switch(bright_state){
  case 0:
    toggle_red_on();
    toggle_green_on();
    //state = 1;
    break;
  case 1:
    red_dim();
    green_dim();
    //state = 2;
    break;
  case 2:
    red_dim_25();
    green_dim_25();
    //state = 0;
    break;
  case 3:
    toggle_red_off();
    toggle_green_on();
    break;
  }//end switch
  led_changed = 1;
  led_update();
}//end state_dimming

//access the states from the method above each time we move states.
void change_states(){
  switch(bright_state){
  case 0:
    bright_state = 1;
    break;
  case 1:
    bright_state = 2;
    break;
  case 2:
    bright_state = 3;
    break;
  case 3:
    bright_state = 0;
    break;
  }//end switch
  led_update();
}//end change_states

