#include "vex.h"
using namespace vex;


void resetAngle(){
  Inertia.resetRotation();
  Inertia.resetHeading();
}

void calibrateInertia(){
  Inertia.calibrate();
}

double getRobotAngle(int axis){
  if (axis == 1){
    return Inertia.yaw();
  }
  else if(axis == 2){
    return Inertia.roll();
  }
  else if(axis == 3){
    return Inertia.pitch();
  }
  else{
    return 0;
  }
}
