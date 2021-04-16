#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

//brain
brain  Brain;
//controller
controller Controller = controller(primary);
//motors
motor FLWheel = motor(PORT6, ratio6_1, false);
motor FRWheel = motor(PORT3, ratio6_1, true);
motor BLWheel = motor(PORT13, ratio6_1, true);
motor BRWheel = motor(PORT19, ratio6_1, false);
motor MLWheel = motor(PORT17, ratio6_1, true);
motor MRWheel = motor(PORT5, ratio6_1, false);
motor Intake = motor(PORT15, ratio6_1, true);
motor Lift = motor(PORT11, ratio18_1, false);
//sensors
inertial Inertia = inertial(PORT1);
bumper LiftLimit = bumper(Brain.ThreeWirePort.G);

void vexcodeInit( void ) {
}