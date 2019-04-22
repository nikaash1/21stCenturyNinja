//Test code for arcade drive controls and some tests with VexCode (not VCS)


//#include "robot-config.h"
//#include "Autonomous.cpp"
//#include "PID.cpp"
#include "Commands.cpp"
#include <string>
#include <cmath>

vex::competition    Competition;
using namespace std;

//variables
/*float stickDead = 6;
int brakeVar = 0;
double turnSpeed = 1;
double straightSpeed = 0.92;*/


#define FORWARD 1
#define BACKWARD -1
#define REVERSE -1
#define FAST 200
#define MEDIUM 100
#define SLOW 50
#define OLDVEX 127
#define LEFT 1
#define RIGHT -1
#define RED 0
#define BLUE 1
#define RIGHT_AXIS_Y 2
#define LEFT_AXIS_Y 3
#define RIGHT_AXIS_X 1
#define LEFT_AXIS_X 4


void pre_auton( void ) {

  autoColorSelect();
  
}


void autonomous( void ) {

  //runAuto(autoSide, autoColor);

  runAuto(autoColorReturn(),autoPositionReturn(),true);

  //straightPID(1, 200, 24);



  driveStraightEncoders(1, PLoop(200, 200, 200, 200), 600);
  Brain.Screen.print(PLoop(200, 200, 200, 200));
 

}


void usercontrol( void ) {

  while (1){

    //tank drive
    if (brakeVar == 0){
      setDriveRight(getAnalog(RIGHT_AXIS_Y));
      setDriveLeft(getAnalog(LEFT_AXIS_Y));
    }

    //arcade drive
    if (brakeVar == 1){
      setDriveLeft(straightSpeed*(getAnalog(LEFT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X)*-1)*turnSpeed);
      setDriveRight(straightSpeed*(getAnalog(LEFT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X)*turnSpeed));
    }

    //brake
    if ((Controller1.ButtonY.pressing())&&(brakeVar == 0)){
      brakeVar = 1;
      baseBrakeHold(0);
      vex::task::sleep(300);
    }

    if ((Controller1.ButtonY.pressing())&&(brakeVar == 1)){
      brakeVar = 0;
      baseBrakeCoast(0);
      vex::task::sleep(300);
    }

    vex::task::sleep(15);
  }
}

int main() {
  pre_auton();
  Competition.autonomous( autonomous );
  Competition.drivercontrol( usercontrol );
  while (true){
    //vibrate when base motors are hot
    if (RF.temperature(vex::percentUnits::pct) >= 60){
      Controller1.rumble("-");
    }
    if (RB.temperature(vex::percentUnits::pct) >= 60){
      Controller1.rumble("-");
    }
    if (LF.temperature(vex::percentUnits::pct) >= 60){
      Controller1.rumble("-");
    }
    if (LB.temperature(vex::percentUnits::pct) >= 60){
      Controller1.rumble("-");
    }
  }
}
