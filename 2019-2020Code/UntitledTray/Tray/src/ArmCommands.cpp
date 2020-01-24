#include "vex.h"
using namespace vex;

void armGo(int dir, double speed){
  Arm.spin(fwd, dir*speed*0.12, volt);
}

void armBrake(){
  Arm.stop(hold);
}

void armCoast(){
  Arm.stop(coast);
}

int armEncoder(int dir, double speed, double height){
  Arm.startRotateFor(height*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  while (Arm.isSpinning()){
    wait(1, msec);
  }
  return 0;
}
