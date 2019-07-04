
#include "Commands.cpp"
#include <string>
#include <cmath>

vex::competition    Competition;
using namespace std;

#define FORWARD 1
#define BACKWARD -1
#define REVERSE -1
//#define UP
//#define DOWN
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
  
  runAuto(0, 1, true);

}


void usercontrol( void ) {
  while (1){
    //Drive
    //Tank Control
    setDriveLeft((getAnalog(LEFT_AXIS_Y)));
    setDriveRight((getAnalog(RIGHT_AXIS_Y)));
    //H-Drive Control
    setDriveH(hSpeed*(((getAnalog(LEFT_AXIS_X)))+((getAnalog(RIGHT_AXIS_X)))));

    //Intake Control
    if (Controller1.ButtonR1.pressing()){
      intakeBrakeVar = 0;
      intakeSpin(BACKWARD, FAST);
    }
    else if (Controller1.ButtonR2.pressing()){
      intakeBrakeVar = 1;
      intakeBrake();
      intakeSpin(FORWARD, FAST);
    }

    //Brake when open, release brake when closing
    else{
      if (intakeBrakeVar == 0){
        intakeCoast();
      }
      else if (intakeBrakeVar == 1){
        intakeBrake();
      }
      else{
        intakeCoast();
      }
    }

    //Up
    //Up Correction
    /*if (getRUp() < (getLUp() - 50)){
      LUpCorrection();
    }
    else if (getLUp() < (getRUp() - 50)){
      RUpCorrection();
    }*/
    //Up Control
    if (Controller1.ButtonL1.pressing()){
      up(FORWARD, 200);
    }
    else if (Controller1.ButtonL2.pressing()){
      up(BACKWARD, 200);
    }
    else{
      upBrake();
    }

    //Brake Toggle Control
    if ((Controller1.ButtonY.pressing())&&(brakeVar == 0)){
      brakeVar = 1;
      baseBrakeHold(0);
      hBrakeHold(0);
      vex::task::sleep(300);
    }
    if ((Controller1.ButtonY.pressing())&&(brakeVar == 1)){
      brakeVar = 0;
      baseBrakeCoast(0);
      hBrakeCoast(0);
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
    //vibrate when a motor is above 70% heat
    if (RF.temperature(vex::percentUnits::pct) >= 70){
      Controller1.rumble("-");
      Controller1.Screen.newLine();
      Controller1.Screen.print("RF Heat Above 70%");
    }
    if (RB.temperature(vex::percentUnits::pct) >= 70){
      Controller1.rumble("-");
      Controller1.Screen.newLine();
      Controller1.Screen.print("RB Heat Above 70%");
    }
    if (LF.temperature(vex::percentUnits::pct) >= 70){
      Controller1.rumble("-");
      Controller1.Screen.newLine();
      Controller1.Screen.print("LF Heat Above 70%");
    }
    if (LB.temperature(vex::percentUnits::pct) >= 70){
      Controller1.rumble("-");
      Controller1.Screen.newLine();
      Controller1.Screen.print("LB Heat Above 70%");
    }
    if (MH.temperature(vex::percentUnits::pct) >= 70){
      Controller1.rumble("-");
      Controller1.Screen.newLine();
      Controller1.Screen.print("MH Heat Above 70%");
    }
    if (LUp.temperature(vex::percentUnits::pct) >= 70){
      Controller1.rumble(".");
      Controller1.Screen.newLine();
      Controller1.Screen.print("LUp Heat Above 70%");
    }
    if (RUp.temperature(vex::percentUnits::pct) >= 70){
      Controller1.rumble(".");
      Controller1.Screen.newLine();
      Controller1.Screen.print("RUp Heat Above 70%");
    }
    if (Intake.temperature(vex::percentUnits::pct) >= 70){
      Controller1.rumble("-");
      Controller1.Screen.newLine();
      Controller1.Screen.print("Intake Heat Above 70%");
    }
  }
}
