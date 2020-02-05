#include "vex.h"
using namespace vex;

void intake(int dir, int speed){
  RIntake.spin(fwd, 0.12*speed*dir, volt);
  LIntake.spin(fwd, 0.12*speed*dir, volt);
}

void intakeBrake(){
  RIntake.stop(hold);
  LIntake.stop(hold);
}
void intakeCoast(){
  RIntake.stop(coast);
  LIntake.stop(coast);
}

void intakeControlled(int dir, double speed, double deg){
  RIntake.startRotateFor(deg*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  LIntake.startRotateFor(deg*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  while((RIntake.isSpinning())||(RIntake.isSpinning())){
    wait(1, msec);
  }
}

double getIntake(){
  double intakeVal = (RIntake.position(rotationUnits::deg)+RIntake.position(rotationUnits::deg))/2;
  return intakeVal;
}