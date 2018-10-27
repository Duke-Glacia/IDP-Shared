#include "actuator.h"
#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>

#define ROBOT_NUM 16
robot_link rlink;

int pic_current;							// variable for current bit value on chip
int param; 									// varaiable to write new value to chip 
const int bit_raise = 0x80;					// 1000 0000 in hex - to set bit7 high
const int bit_lower = 0x7F;					// 1011 1111 in hex - to set bit7 low




void raise_box(void){						// raises rack and pinion
  rlink.command(MOTOR_3_GO, 255);
  delay(1000);								// waits 2secs (ADJUST THIS TO GIVE FULL MOTION)
  rlink.command(MOTOR_3_GO, 0);
}

void lower_box(void){						// lowers rack and pinion
  rlink.command(MOTOR_3_GO, 127     ); 			// sets motor to down
  delay(1000);								// waits 2secs (ADJUST THIS TO GIVE FULL MOTION)
  rlink.command(MOTOR_3_GO, 0);				// Stops motor
} 

void extend_actuators(void){
	pic_current = rlink.request(READ_PORT_4);
	param = pic_current bitor bit_raise;	// ORs current bits with 1000 0000 ie sets bit7 high and leaves rest as they are
	rlink.command (WRITE_PORT_4, param);
}

void retract_actuators(void){
	pic_current = rlink.request(READ_PORT_4);
	param = pic_current bitand bit_lower;	// ANDs current bits with 0111 1111 ie sets bit7 low and leaves rest as they are
	rlink.command (WRITE_PORT_4, param);
}

void collect_parcel(void){					// box should start and finish in the down and retracted position (for now)
	raise_box();
	extend_actuators();
	delay(500);
	lower_box();
	delay(500);
	retract_actuators();
}

void drop_parcel(void){
	extend_actuators();
	delay(500);
	raise_box();
	retract_actuators();
	delay(500);
	lower_box();
}


