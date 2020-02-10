#include "vex.h"
using namespace vex;

int intakeControls(){
  double intakeSpeed = 1;
  double intakeSpeed2 = 1;
  int intakeToggle = 0;
  while (1){
    if (getController(BTNLEFT)){ //reset button
      while (getController(BTNLEFT)){
        wait(1, msec);
      }
      RIntake.resetRotation();
      LIntake.resetRotation();
    }
    if (getController(BTNDOWN)){
      while (getController(BTNDOWN)){
        wait(1, msec);
      }
      if (intakeToggle == 0){
        intakeSpeed = 0.3;
        intakeToggle = 1;
      }
      else if (intakeToggle == 1){
        intakeSpeed = 1;
        intakeToggle = 0;
      }
    }
    if (Arm.rotation(rotationUnits::deg) <= 70){
      intakeSpeed2 = 1;
    }
    else{
      intakeSpeed2 = 0;
    }
    if (getController(BTNR1)){
      intake(OUT, 100*intakeSpeed);
    }
    else if (getController(BTNR2)){
      intake(IN, 100*intakeSpeed);
    }
    else if (getController(BTNA)){
      intake(OUT, (getJoystick(RIGHT_AXIS_Y) + getJoystick(LEFT_AXIS_Y))/2);
    }
    else if (getController(BTNL1)){ //outtake with arms
      intake(OUT, 65*intakeSpeed2);
    }
    else{
      intakeBrake();
    }
  }
  return 0;
}