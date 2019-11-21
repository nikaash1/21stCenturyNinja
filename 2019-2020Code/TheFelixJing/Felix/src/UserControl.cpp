#include "vex.h"
using namespace vex;

void runDriverTasks(){
  vex::task driveControlTask(driveFelix);
  vex::task brakeTask(brakeControls);
  vex::task driveBackTask(driveBackControl);
  vex::task liftTask(liftControls);
  vex::task intakeTask(intakeControls);
  vex::task alignerTask(alignerControls);
}