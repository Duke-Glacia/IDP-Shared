#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>

#define ROBOT_NUM 16
robot_link rlink;
 
unsigned int line_sensor(void){
		unsigned int sensor_byte;
		sensor_byte=rlink.request(READ_PORT_4);
	    return sensor_byte;}
	    
void go_straight(void){
	rlink.command(MOTOR_1_GO,148);
	rlink.command(MOTOR_2_GO,20);
}

void turn_left(void){
	rlink.command(MOTOR_1_GO,0);
	rlink.command(MOTOR_2_GO,20);
}

void turn_right(void){
	rlink.command(MOTOR_1_GO,148);
	rlink.command(MOTOR_2_GO, 0);
}
void turn_right_corner(void){
	rlink.command(MOTOR_1_GO,100);
	rlink.command(MOTOR_2_GO, 100);
}


int main()
{
	
	int   val;     
	bool moving = true;
	int right_1=254;
	int right_1_alt = 246;
	int right_2=244;
	int right_2_alt = 252;
	int left_1=241;
	int left_1_alt = 251;
	int left_2=249;
	int left_2_alt = 241;
	int mid=242;
	int mid_alt = 250;
	int line_int;                         // data from microprocessor
	if (!rlink.initialise (ROBOT_NUM)) {      // setup the link
	cout << "Cannot initialise link" << endl;
	rlink.print_errs("    ");
	return -1;
	}	

	val = rlink.request (TEST_INSTRUCTION);   // send test instruction
	if (val == TEST_INSTRUCTION_RESULT) {     // check result
	cout << "Test passed" << endl;	
	
	


	while (moving == true){
	line_int = line_sensor();
	if (line_int == mid or line_int == mid_alt){
	go_straight();
	line_int = line_sensor();
	cout << line_int << endl;
	}
	
	else if(line_int == right_1 or line_int == right_1_alt){
		turn_left();
		delay(1000);
		
		while ( line_int != mid){
		line_int = line_sensor();
		go_straight();
		}
	
		turn_right();
		delay(1000);
		go_straight();
		}
		
	else if(line_int == left_1 or line_int == left_1_alt){
		turn_right();
		delay(1000);
		
		while ( line_int != mid){
		line_int = line_sensor();
		go_straight();
		}
	
		turn_left();
		delay(1000);
		go_straight();
		}
		
	else if(line_int == right_2 or line_int == right_2_alt){
		turn_left();
		delay(1500);
		
		while ( line_int != mid){
		line_int = line_sensor();
		go_straight();
		}
	
		turn_right();
		delay(1500);
		go_straight();
		}	
		
	else if(line_int == left_2 or line_int == left_2_alt){
		turn_right();
		delay(1500);
		
		while ( line_int != mid){
		line_int = line_sensor();
		go_straight();
		}
	
		turn_left();
		delay(1500);
		go_straight();
		}		
		
		
		
		
		
		
		
		
		
		
			
		
	}
	
	return 0;                             // all OK, finish
	}

	else if (val == REQUEST_ERROR) {
	cout << "Fatal errors on link:" << endl;
	rlink.print_errs();
	}
	else{
	cout << "Test failed (bad value returned)" << endl;
	return -1;                                // error, finish
	}


}
	
	
