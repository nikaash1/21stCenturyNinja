#include "vex.h"
using namespace vex;

int brakeVar = 0;

void driveControls(int style, int driveType){
  double getAnalogRArcade = getJoystick(LEFT_AXIS_Y) - getJoystick(RIGHT_AXIS_X);
  double getAnalogLArcade = getJoystick(LEFT_AXIS_Y) - ((getJoystick(RIGHT_AXIS_X))*-1);
  double getAnalogStrafe = (getJoystick(LEFT_AXIS_X) + getJoystick(RIGHT_AXIS_X));
  if (style == 1){
    if (driveType == 1){
      setDrive(getJoystick(LEFT_AXIS_Y), getJoystick(RIGHT_AXIS_Y));
    }
    else if (driveType == 2){
      setDriveFull(((getJoystick(LEFT_AXIS_Y)) - (getAnalogStrafe)*-1), ((getJoystick(LEFT_AXIS_Y)) - (getAnalogStrafe)), ((getJoystick(RIGHT_AXIS_Y)) - (getAnalogStrafe)), ((getJoystick(RIGHT_AXIS_Y)) - (getAnalogStrafe)*-1));
    }
    else{
      setDrive(getJoystick(LEFT_AXIS_Y), getJoystick(RIGHT_AXIS_Y));
    }
  }
  else if (style == 2){
    if (driveType == 1){
      setDrive(((getJoystick(LEFT_AXIS_Y))-(getJoystick(RIGHT_AXIS_X)*-1)), ((getJoystick(LEFT_AXIS_Y))-(getJoystick(RIGHT_AXIS_X))));
    }
    else if (driveType == 2){
      setDriveFull(((getAnalogLArcade)-(getJoystick(LEFT_AXIS_X))*-1), ((getAnalogLArcade)-(getJoystick(LEFT_AXIS_X))*1), ((getAnalogRArcade)-(getJoystick(LEFT_AXIS_X))*1), ((getAnalogRArcade)-(getJoystick(LEFT_AXIS_X))*-1));
    }
    else{
      setDrive(((getJoystick(LEFT_AXIS_Y))-(getJoystick(RIGHT_AXIS_X)*-1)), ((getJoystick(LEFT_AXIS_Y))-(getJoystick(RIGHT_AXIS_X))));
    }
  }
}

int driveFelix(){
  while ((getController(BTNB)) == 0){
    driveControls(XDRIVE, TANK);
  }
  return 0;
}

int brakeControls(){
  while (1){
    if ((getController(BTNY)) == 1){
      if (brakeVar == 0){
        wait(300, msec);
        driveBrake();
        brakeVar = 1;
      }
      else if (brakeVar == 1){
        wait(300, msec);
        driveCoast();
        brakeVar = 0;
      }
    }
  }
  return 0;
}

int driveBackControl(){
  while(1){
    if ((getController(BTNB)) == 1){
      driveEncoder(BACKWARD, 60, 10);
    }
  }
  return 0;
}