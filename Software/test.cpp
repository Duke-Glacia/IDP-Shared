#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#define ROBOT_NUM  16                         // The id number (see below)
robot_link  rlink; 


unsigned int line_sensor(void){
		unsigned int sensor_byte;
		
		sensor_byte=rlink.request(READ_PORT_4);
	    return sensor_byte;}
	    
	                               // datatype for the robot link
int main ()
{
int   val;    
//int etime;
int simulator;
stopwatch watch;                            // data from microprocessor
if (!rlink.initialise (ROBOT_NUM)) {      // setup the link
cout << "Cannot initialise link" << endl;
rlink.print_errs("    ");
return -1;
}
val = rlink.request (TEST_INSTRUCTION);   // send test instruction
if (val == TEST_INSTRUCTION_RESULT) {     // check result
cout << "Test passed" << endl;
//simulator = rlink.request(READ_PORT_0);
cout << line_sensor() << endl;
//cout<<simulator<<endl;



//watch.start();
//while(etime < 10000){
//rlink.command(MOTOR_1_GO,228);
//rlink.command(MOTOR_2_GO,100);
//etime = watch.read();
//}

return 0;                             // all OK, finish
}
else if (val == REQUEST_ERROR) {
cout << "Fatal errors on link:" << endl;
rlink.print_errs();
}
else
cout << "Test failed (bad value returned)" << endl;
return -1;                                // error, finish
}
