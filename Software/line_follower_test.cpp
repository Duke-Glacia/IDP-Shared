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
	    
int main()
{
	bool moving = true;
	
	    
	int right_1=254;
	int right_2=252;
	int left_1=251;
	int left_2=249;
	int mid=250;
	int line_int;
	cout << line_int << endl;
	while (moving == true){
	line_int = line_sensor();
	while(line_int == mid){
	rlink.command(BOTH_MOTORS_GO_SAME,100);
	cout << line_int << endl;
	line_int = line_sensor();
	if (line_int != mid) {
		break;
	}
	}
	
	if(line_sensor() == right_1){
	rlink.command(MOTOR_1_GO,100);
	rlink.command(MOTOR_2_GO,120);
	delay(1000);
	//rlink.command(BOTH_MOTOR_GO_SAME_SPEED,100);
	
	
	
	while ( line_sensor() != mid){
	line_sensor();
	rlink.command(BOTH_MOTORS_GO_SAME,100);
	}
	
	rlink.command(MOTOR_1_GO,120);
	rlink.command(MOTOR_2_GO,100);
	delay(1000);
	}
	
}
}
	
	
