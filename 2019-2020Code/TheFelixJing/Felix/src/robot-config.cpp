#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller = controller(primary);
motor FLWheel = motor(PORT1, ratio18_1, false);
motor FRWheel = motor(PORT2, ratio18_1, false);
motor BLWheel = motor(PORT3, ratio18_1, true);
motor BRWheel = motor(PORT4, ratio18_1, true);
motor Aligner = motor(PORT5, ratio6_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}