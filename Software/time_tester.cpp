#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>

#define ROBOT_NUM 16
robot_link rlink;
 
int line_sensor(void){
		int sensor_byte;
		sensor_byte=rlink.request(READ_PORT_3);
	    return sensor_byte;}
	    
void go_straight(void){
	rlink.command(MOTOR_1_GO,228);
	rlink.command(MOTOR_2_GO,100);
}

void turn_left(void){
	rlink.command(MOTOR_1_GO,228);
	rlink.command(MOTOR_2_GO,120);
}

void turn_right(void){
	rlink.command(MOTOR_1_GO,248);
	rlink.command(MOTOR_2_GO, 100);
}
void turn_left_corner(void){
	rlink.command(MOTOR_1_GO,100);
	rlink.command(MOTOR_2_GO, 100);
}
void turn_right_corner(void){
	rlink.command(MOTOR_1_GO,228);
	rlink.command(MOTOR_2_GO,228);
}

void back(void){
	rlink.command(MOTOR_1_GO,100);
	rlink.command(MOTOR_2_GO,228);
}
void stop(void){
	rlink.command(MOTOR_1_GO,0);
	rlink.command(MOTOR_2_GO,0);
	}
	

int main()
{
	
	int   val;                              // data from microprocessor
	if (!rlink.initialise (ROBOT_NUM)) {      // setup the link
	cout << "Cannot initialise link" << endl;
	rlink.print_errs("    ");
	return -1;
	}	

	val = rlink.request (TEST_INSTRUCTION);   // send test instruction
	if (val == TEST_INSTRUCTION_RESULT) {     // check result
	cout << "Test passed" << endl;
}	
	if(true){
		
	int right_1=3;
	int right_2=1;
	int left_1=6;
	int left_2=4;
	int mid=2;
	int line_int;
	line_int = line_sensor();
	cout << line_int << endl;
	cout << rlink.request(READ_PORT_3);
	
	//turn_left();
	//delay(1000);
	go_straight();
	delay(35000/14.1372);
	turn_right_corner();
	delay(1500);
	go_straight();
	delay(12000/14.1372);
	stop();
	delay(1000);
	back();
	delay(10000/14.1372);
	turn_left_corner();
	delay(1600);
	go_straight();
	delay(75000/14.1372);
	turn_left_corner();
	delay(1499);
	go_straight();
	delay(50000/14.1372);
	turn_left_corner();
	delay(1499);
	
	//turn_right_corner();
	//delay (1000);
	//go_straight();
	//delay(1000);
}
	/* while (moving == true){
	line_int = line_sensor();
	if(line_int == mid){
	go_straight();
	cout << line_int << endl;
	}
	
	else if(line_int == right_1){
		turn_left();
		delay(1000);
		
		while ( line_int != mid){
		line_int = line_sensor();
		go_straight();
		}
	
		turn_right();
		delay(1000);
		}
	
}*/
	
	
	
	
	
	
	
	
	
	return 0;                             // all OK, finish
	}

	
	
