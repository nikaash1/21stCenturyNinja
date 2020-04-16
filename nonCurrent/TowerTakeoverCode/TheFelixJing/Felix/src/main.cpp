#include "vex.h"
using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void autonomous(void) {
  runAuto();
}

void usercontrol(void) {
  runDriverTasks();
  while(1){
    driveControls(TANK, XDRIVE);
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
