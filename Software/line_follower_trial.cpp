#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>

#define ROBOT_NUM 16
robot_link rlink;

unsigned int line_sensing(void){
	unsigned int sensor_byte;
	sensor_byte=rlink.request(READ_PORT_4);
	return sensor_byte;
}

int line_sensor_right(void){
	int right_1=254;
	int right_1_alt=246;
	int right_2=244;
	int left_1=241;
	int left_1_alt=251;
	int left_2=249;
	int mid=242;
	int mid_alt=250;
	int line_int;
	int line_adjuster_right;
	int line_adjuster_left;
	line_int=line_sensing();
	if (line_int==mid or line_int==mid_alt){
		line_adjuster_right=0;
		line_adjuster_left=0;
	}
	else if(line_int==right_1 or line_int==right_1_alt){
		line_adjuster_right=30;
		line_adjuster_left=-10;
	}
	else if(line_int==left_1 or line_int==left_1_alt){
		line_adjuster_right=-10;
		line_adjuster_left=30;
	}
	return line_adjuster_right;
}

int line_sensor_left(void){
	int right_1=254;
	int right_1_alt=246;
	int right_2=244;
	int left_1=241;
	int left_1_alt=251;
	int left_2=249;
	int mid=242;
	int mid_alt=250;
	int line_int;
	int line_adjuster_right;
	int line_adjuster_left;
	
	line_int=line_sensing();

	if (line_int==mid or line_int==mid_alt){
		line_adjuster_right=0;
		line_adjuster_left=0;
	}
	else if(line_int==left_1 or line_int==left_1_alt or line_int==252){
		line_adjuster_right=-10;
		line_adjuster_left=30;
	}
	else if(line_int==right_1 or line_int==right_1_alt){
		line_adjuster_right=30;
		line_adjuster_left=-10;
	}
	return line_adjuster_left;
}
 
int line_sensor(void){
		int sensor_byte;
		sensor_byte=rlink.request(READ_PORT_4);
	    return sensor_byte;}
	    
void go_straight(void){
	rlink.command(MOTOR_1_GO,100+line_sensor_right());
	rlink.command(MOTOR_2_GO,228+line_sensor_left());
}

void turn_right_corner(void){
	rlink.command(MOTOR_1_GO,100);
	rlink.command(MOTOR_2_GO, 100);
}
void turn_left_corner(void){
	rlink.command(MOTOR_1_GO,228);
	rlink.command(MOTOR_2_GO, 228);
}

int main()
{
	int sensor_values;
	sensor_values=line_sensing();
	int   val;                              // data from microprocessor
	if (!rlink.initialise (ROBOT_NUM)) {      // setup the link
	cout << "Cannot initialise link" << endl;
	rlink.print_errs("    ");
	return -1;
	}	

	val = rlink.request (TEST_INSTRUCTION);   // send test instruction
	if (val == TEST_INSTRUCTION_RESULT) {     // check result
	cout << "Test passed" << endl;	
	
	
	bool moving = true;
	cout << rlink.request(READ_PORT_4)<<endl;
	
	while (moving == true){
	cout << rlink.request(READ_PORT_4)<<endl;
	go_straight();
	
	
}
}
return 0;
}
	

	
