#include "vex.h"
using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void autonomous(void) {
  runAuto(RED);
}

void usercontrol(void) {
  runDriverTasks();
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    if(getLiftLimit()){
      Brain.Screen.setFillColor(yellow);
      Brain.Screen.drawRectangle(0, 0, 1000, 1000);
    }
    else{
      Brain.Screen.setFillColor(purple);
      Brain.Screen.drawRectangle(0, 0, 1000, 1000);
    }
    wait(100, msec);
  }
}