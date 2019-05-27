
#include "Commands.cpp"
#include <string>
#include <cmath>

vex::competition    Competition;
using namespace std;

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
}


void autonomous( void ) {
  straightPID(1, 200, 24);
}


void usercontrol( void ) {
  while (1){
    //tank drive
    if (brakeVar == 0){
      setDriveRight(getAnalog(RIGHT_AXIS_Y));
      setDriveLeft(getAnalog(LEFT_AXIS_Y));

      //H-Drive Tank (uncomment)
      //setDriveH(hSpeed*((0.5*(getAnalog(LEFT_AXIS_X)))+(0.5*(getAnalog(RIGHT_AXIS_X)))));
    }
    //arcade drive
    if (brakeVar == 1){
      setDriveLeft(straightSpeed*(getAnalog(LEFT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X)*-1*turnSpeed));
      setDriveRight(straightSpeed*(getAnalog(LEFT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X)*turnSpeed));

      //H-Drive Arcade (uncomment)
      //setDriveH(hSpeed*(getAnalog(LEFT_AXIS_X)));

      //Mechanum Arcade (uncomment)
      //strafeMech(mechSpeed*(getAnalog(LEFT_AXIS_X)));
    }

    //intake
    if (Controller1.ButtonR2.pressing()){
      intakeSpin(FORWARD, FAST);
    }

    if (Controller1.ButtonR1.pressing()){
      intakeSpin(BACKWARD, FAST);
    }

    else{
      intakeStop();
    }

    //brake and switch to arcade
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
    if (Brain.Screen.pressing()){
      autoColorSelect();
      wait(300);
    }
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
