#include "vex.h"
using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void autonomous(void) {
  runAuto(RED_LARGE);
}

void usercontrol(void) {
  runDriverTasks();
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
