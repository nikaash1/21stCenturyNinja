#include "vex.h"
using namespace vex;
//joystick axes
#define RIGHT_AXIS_X 1
#define RIGHT_AXIS_Y 2
#define LEFT_AXIS_Y 3
#define LEFT_AXIS_X 4
//button numbers
#define BTNR1 1
#define BTNR2 2
#define BTNL1 3
#define BTNL2 4
#define BTNA 5
#define BTNB 6
#define BTNY 7
#define BTNX 8
#define BTNUP 9
#define BTNDOWN 10
#define BTNLEFT 11
#define BTNRIGHT 12
//drive controls
#define TANK 1
#define ARCADE 2
#define STANDARD 1
#define XDRIVE 2

void driveControls(int style, int driveType){
  double getAnalogRArcade = getJoystick(LEFT_AXIS_Y) - getJoystick(RIGHT_AXIS_X);
  double getAnalogLArcade = getJoystick(LEFT_AXIS_Y) - ((getJoystick(RIGHT_AXIS_X))*-1);
  double getAnalogStrafe = getJoystick(LEFT_AXIS_X) + getJoystick(RIGHT_AXIS_X);
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