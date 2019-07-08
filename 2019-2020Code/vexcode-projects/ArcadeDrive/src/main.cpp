
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
  
  //runAuto(RED, 1, true);
<<<<<<< HEAD

  intakeMove(FORWARD, FAST, 420);
  intakeBrake();
  intakeSpin(FORWARD, 20);
  goOldPID(3.5, 1.5, 0);
  upMove(FORWARD, FAST, 400);
  goOldPID(5, 1.5, 0);
  wait(200);
  upMove(BACKWARD, FAST, 200);
  routine(FAST);
  intakeSpin(FORWARD, 20);
  wait(50);
  intakeBrake();
  goOldPID(19, 1.5, 0);
  upMove(FORWARD, FAST, 700);
  intakeMove(BACKWARD, FAST, 420);
  upMove(BACKWARD, FAST, 700);
  intakeMove(FORWARD, FAST, 420);
  upMove(FORWARD, MEDIUM, 200);
  turnOldPID(LEFT, 120, 1.1, 0);
  goOldPID(30, 1.2, 0);
  upMove(BACKWARD, MEDIUM, 600);
  intakeMove(BACKWARD, FAST, 420);
  goOldPID(-30, 1.4, 0);
=======
  //intakeMove(FORWARD, 200, 540);
  //wait(500);
  upGoUp(350, 1.5, 0);
  //goOldPID(50, 1.5, 0);
  //wait(500);
  //goOldPID(10, 1,0);
>>>>>>> b8616d10f61e4547aedac3056afd991f96edf3e5

}


void usercontrol ( void ) {

  /*do{
    upGoUp(100, 1.5, 0);
  }
  while (running);*/
  
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
      Controller1.Screen.print(getUp());
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

    if (Controller1.ButtonB.pressing()){
      routine(FAST);
    }


    

    //Up
      if (Controller1.ButtonL1.pressing()){
        up(FORWARD, 200);
      }
      else if (Controller1.ButtonL2.pressing()){
        up(BACKWARD, 150);
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
