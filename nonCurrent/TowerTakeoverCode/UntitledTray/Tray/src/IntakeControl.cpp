#include "vex.h"
using namespace vex;

int intakeControls(){
  double intakeSpeed = 1; //actual intake speed to slow down with toggle
  double intakeSpeed2 = 1; //for outtake during arm macro
  double intakeSpeed3 = 1; //speed of intake when arms are up
  double intakeSpeed4 = 1; //speed of intake when arms are up and toggle has occured
  double intakeTiltSpeed = 0.1; //speed of intake during tilt
  int intakeToggle = 0;
  int coastToggle = 0;
  int coastTiltToggle = 0;
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

    if (getController(BTNX)){
      while (getController(BTNX)){
        wait(1, msec);
      }
      if (coastToggle == 0){
        coastToggle = 1;
      }
      else if (coastToggle == 1){
        coastToggle = 0;
      }
    }
    //outake when arms are past 70
    if (getArm() <= 70){
      intakeSpeed2 = 1;
    }
    else{
      intakeSpeed2 = 0;
    }
    if (getArm() >= 100){
      intakeSpeed3 = 0.6;
      intakeSpeed4 = 1/(intakeSpeed*intakeSpeed);
    }
    else{
      intakeSpeed3 = 1;
      intakeSpeed4 = 1;
    }
    /*if (getTilter() >= 250){
      coastTiltToggle = 1;
    }
    else{
      coastTiltToggle = 0;
    }*/
    if (getController(BTNR1)){
      intake(OUT, 100*intakeSpeed*intakeSpeed3*intakeSpeed4);
    }
    else if (getController(BTNR2)){
      intake(IN, 100*intakeSpeed*intakeSpeed3*intakeSpeed4);
    }
    else if (getController(BTNA)){
      intake(OUT, (getJoystick(RIGHT_AXIS_Y) + getJoystick(LEFT_AXIS_Y))/2);
    }
    else if (getController(BTNL1)){ //outtake with arms
      intake(OUT, 65*intakeSpeed2);
    }
    else{
      if(coastToggle == 1){
        intakeCoast();
      }
      else{
        intakeBrake();
      }
    }
    wait(10, msec);
  }
  return 0;
}