#include "vex.h"
using namespace vex;

void runDriverTasks(){
  vex::task driveControlTask(driveJoystick);
  vex::task liftControlTask(liftJoystick);
  vex::task intakeControlTask(intakeJoystick);
}
/*void runAutoTasks(){
  vex::task autoSelectTask(autoSelector);
  vex::task autoIndicateTask(autoIndicator);
}
void runMiscTasks(){
}*/