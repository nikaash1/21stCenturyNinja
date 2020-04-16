#include "vex.h"
using namespace vex;

void runDriverTasks(){
  vex::task driveControlTask(driveJoystick);
}
/*void runAutoTasks(){
  vex::task autoSelectTask(autoSelector);
  vex::task autoIndicateTask(autoIndicator);
}
void runMiscTasks(){
}*/