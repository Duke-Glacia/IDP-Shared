#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#define ROBOT_NUM 16   // The id number (see below)
robot_link rlink;      // datatype for the robot link
#include <stopwatch.h>
#include <delay.h>
int main (){
	rlink.command(MOTOR_1_GO,100);
	delay(10000);
	//rlink.command(MOTOR_2_GO,100);
	//delay(10000);
	//rlink.command(MOTOR_3_GO,100);
	//delay(10000);
	//rlink.command(MOTOR_4_GO,100);
	//delay(10000);
}
