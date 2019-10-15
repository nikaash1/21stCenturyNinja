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

//get button values
int getController(int buttonNumber){
  if (buttonNumber == 1){
    if (Controller.ButtonR1.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 2){
    if (Controller.ButtonR2.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 3){
    if (Controller.ButtonL1.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 4){
    if (Controller.ButtonL2.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 5){
    if (Controller.ButtonA.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 6){
    if (Controller.ButtonB.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 7){
    if (Controller.ButtonY.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 8){
    if (Controller.ButtonX.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 9){
    if (Controller.ButtonUp.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 10){
    if (Controller.ButtonDown.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 11){
    if (Controller.ButtonLeft.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 12){
    if (Controller.ButtonRight.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
}