#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

//brain
brain  Brain;
//controller
controller Controller = controller(primary);
//motors
motor FLWheel = motor(PORT1, ratio18_1, true);
motor FRWheel = motor(PORT19, ratio18_1, false);
motor BLWheel = motor(PORT2, ratio18_1, true);
motor BRWheel = motor(PORT20, ratio18_1, false);
motor Tilter = motor(PORT18, ratio36_1, true);
motor Arm = motor(PORT3, ratio36_1, false);
motor RIntake = motor(PORT10, ratio36_1, true);
motor LIntake = motor(PORT5, ratio36_1, false);
//sensors
inertial Inertia = inertial(PORT21);
limit TrayLimit = limit(Brain.ThreeWirePort.H);
limit ArmLimit = limit(Brain.ThreeWirePort.G);

void vexcodeInit( void ) {
}