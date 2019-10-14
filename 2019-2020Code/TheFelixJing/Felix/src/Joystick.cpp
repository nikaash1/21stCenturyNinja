#include "vex.h"
using namespace vex;

//get joystick values
double getJoystick(int axis){
  if (axis == 1){
    return Controller.Axis1.value();
  }
  else if (axis == 2){
    return Controller.Axis2.value();
  }
  else if (axis == 3){
    return Controller.Axis3.value();
  }
  else if (axis == 4){
    return Controller.Axis4.value();
  }
  else{
    return 0;
  }
}

