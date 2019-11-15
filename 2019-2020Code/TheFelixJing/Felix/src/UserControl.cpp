#include "vex.h"
using namespace vex;

void runDriverTasks(){
  vex::task brakeTask(brakeControls);
  vex::task liftTask(liftControls);
  vex::task intakeTask(intakeControls);
  vex::task alignerTask(alignerControls);
}