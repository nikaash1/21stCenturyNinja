#include "vex.h"
using namespace vex;

void setIntake(int dir, double speed){
  Intake.spin(fwd, dir*speed*0.12, volt);
}