#include "vex.h"
using namespace vex;

void runDriverTasks(){
  vex::task driveControlTask(driveJoystick);
  vex::task towerModeTask(towerMode);
  vex::task intakeControlTask(intakeControls);
  vex::task tilterControlTask(tilterControls);
}
/*void runAutoTasks(){
  vex::task autoSelectTask(autoSelector);
  vex::task autoIndicateTask(autoIndicator);
}
void runMiscTasks(){
}*/