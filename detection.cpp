#include "detection.h"
#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>

#define ROBOT_NUM 16
robot_link rlink;

int LDR_one;
int LDR_two;
int pic_byte;
int param;
int parcel_type;

void reset_leds(void){ 						// sets all LEDs off
	pic_byte = rlink.request(READ_PORT_4);
	param = pic_byte bitor 0x70; 		// 0111 0000 binary
	rlink.command(WRITE_PORT_4,param);
}
	
void detected_red(void){
	pic_byte = rlink.request(READ_PORT_4);
	param = pic_byte bitor 0x60; 		// 0110 0000
	param = param bitand 0xEF;			// 1110 1111
	rlink.command(WRITE_PORT_4,param);
	parcel_type = 1;
}

void detected_green(void){
	pic_byte = rlink.request(READ_PORT_4);
	param = pic_byte bitor 0x50; 		// 0101 0000
	param = param bitand 0xDF;			// 1101 1111
	rlink.command(WRITE_PORT_4,param);
	parcel_type= 2;
}

void detected_white(void){
	pic_byte = rlink.request(READ_PORT_4);
	param = pic_byte bitor 0x40; 		// 0100 0000
	param = param bitand 0xCF;			// 1100 1111
	rlink.command(WRITE_PORT_4,param);	
	parcel_type = 3;
	}

void detected_ply(void){
	pic_byte = rlink.request(READ_PORT_4);
	param = pic_byte bitor 0x30; 		// 0011 0000
	param = param bitand 0xBF;			// 1011 1111
	rlink.command(WRITE_PORT_4,param);	
	parcel_type = 4;
}

void detected_clear(void){
	pic_byte = rlink.request(READ_PORT_4);
	param = pic_byte bitor 0x20; 		// 0010 0000
	param = param bitand 0xAF;			// 1010 1111
	rlink.command(WRITE_PORT_4,param);	
	parcel_type = 5;
}

void detection_failed(void){
	pic_byte = rlink.request(READ_PORT_4);
	param = param bitand 0x8F;			// 1000 1111
	rlink.command(WRITE_PORT_4,param);
	parcel_type = 6;
}



void detect_parcel(void){
	/*LDR_one = rlink.request(ADC5);
	LDR_two = rlink.request(ADC6); 				// reads analogue to digital voltages for ldrs
	  
	if (LDR_one > 0 and LDR_one <= 50 and LDR_two > 0 and LDR_two <=50){   // test voltages for each box
	detected_red();
	}
		
	if (LDR_one > 0 and LDR_one <= 50 and LDR_two > 0 and LDR_two <=50){   // test voltages for each box
	detected_green();
	}
	
	if (LDR_one > 0 and LDR_one <= 50 and LDR_two > 0 and LDR_two <=50){   // test voltages for each box
	detected_white();
	}
	
	if (LDR_one > 0 and LDR_one <= 50 and LDR_two > 0 and LDR_two <=50){   // test voltages for each box
	detected_ply();
	}
	
	if (LDR_one > 0 and LDR_one <= 50 and LDR_two > 0 and LDR_two <=50){   // test voltages for each box
	detected_clear();
	}
	
	else{   																// test voltages for each box
	detection_failed();
	}*/
	
	cout << rlink.request(READ_PORT_4) << endl;
	
	reset_leds();
	delay(2000);
	detected_red();
	delay(2000);
	detected_green();
	delay(2000);
	detected_white();
	delay(2000);
	detected_ply();
	delay(2000);	
	detected_clear();
	delay(2000);
	detection_failed();
	delay(2000);
	
	
}

