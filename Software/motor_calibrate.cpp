#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#define ROBOT_NUM 16   // The id number (see below)
robot_link rlink;      // datatype for the robot link
#include <stopwatch.h>
int main ()
{
stopwatch watch;
watch.start();
double etime;
int val;                          // data from microprocessor
if (!rlink.initialise (ROBOT_NUM)) { // setup the link
  cout << "Cannot initialise link" << endl;
  rlink.print_errs("  ");
  return -1;
}
val = rlink.request (TEST_INSTRUCTION); // send test instruction
if (val == TEST_INSTRUCTION_RESULT) { 
	cout << "Test passed" << endl;  // check result
  stat=rlink.request(STATUS);
  //etime=watch.read();
  //cout<<etime<<endl;   
  cout<<stat<<endl;
	
}


  //rlink.command(RAMP_TIME,100); 
  return 0;                            // all OK, finish
}
else if (val == REQUEST_ERROR) {
  cout << "Fatal errors on link:" << endl;
  rlink.print_errs();
}
else
  cout << "Test failed (bad value returned)" << endl;
return -1;  


//etime=watch.stop();
//cout<<etime<<endl;                    // error, finish
}
