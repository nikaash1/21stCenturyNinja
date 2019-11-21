#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller = controller(primary);
motor FLWheel = motor(PORT1, ratio18_1, false);
motor FRWheel = motor(PORT10, ratio18_1, true);
motor BLWheel = motor(PORT11, ratio18_1, false);
motor BRWheel = motor(PORT20, ratio18_1, true);
motor Aligner = motor(PORT16, ratio36_1, true);
motor RUp = motor(PORT14, ratio36_1, true);
motor LUp = motor(PORT13, ratio36_1, false);
motor Intake = motor(PORT15, ratio36_1, true);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}