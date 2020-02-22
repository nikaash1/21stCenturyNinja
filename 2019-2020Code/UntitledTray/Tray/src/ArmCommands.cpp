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

double getArm(){
  double armVal = Arm.rotation(rotationUnits::deg);
  return armVal;
}

int armEncoder(int dir, double speed, double height){
  Arm.startRotateFor(height*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  while (Arm.isSpinning()){
    wait(1, msec);
  }
  return 0;
}

int armControlled(int dir, double speed, double height){
  Arm.startRotateFor(height*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  return 0;
}

int getArmLimit(){
  if (ArmLimit.pressing()){
    return 1;
  }
  else{
    return 0;
  }
}