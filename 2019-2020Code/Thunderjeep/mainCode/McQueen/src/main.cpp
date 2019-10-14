// To complete the VEXcode V5 Text project upgrade process, please follow the
// steps below.
// 
// 1. You can use the Robot Configuration window to recreate your V5 devices
//   - including any motors, sensors, 3-wire devices, and controllers.
// 
// 2. All previous code located in main.cpp has now been commented out. You
//   will need to migrate this code to the new "int main" structure created
//   below and keep in mind any new device names you may have set from the
//   Robot Configuration window. 
// 
// If you would like to go back to your original project, a complete backup
// of your original (pre-upgraded) project was created in a backup folder
// inside of this project's folder.

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}

// // ---- START VEXCODE CONFIGURED DEVICES ----
// // Robot Configuration:
// // [Name]               [Type]        [Port(s)]
// // ---- END VEXCODE CONFIGURED DEVICES ----
// 
// #include "Commands.cpp"
// #include <string>
// #include <cmath>
// 
// vex::competition    Competition;
// using namespace std;
// 
// #define FORWARD 1
// #define BACKWARD -1
// #define REVERSE -1
// //#define UP
// //#define DOWN
// #define FAST 200
// #define MEDIUM 100
// #define SLOW 50
// #define OLDVEX 127
// #define LEFT 1
// #define RIGHT -1
// #define RED 0
// #define BLUE 1
// #define FRONT 1
// #define BACK 2
// #define SKILLS 3
// #define RIGHT_AXIS_Y 2
// #define LEFT_AXIS_Y 3
// #define RIGHT_AXIS_X 1
// #define LEFT_AXIS_X 4
// 
// void pre_auton( void ) {
// 
// 
// 
// }
// 
// 
// void autonomous( void ) {
//   runAuto(RED, FRONT, true);
//   //runSkillsAuto();
// }
// 
// 
// void usercontrol ( void ) {
//   /*intakeSpin(BACKWARD, 100);
//   wait(1000);
//   resetIntake();*/
//   while (1){
//     //Drive
//     //Tank Control
//     setDriveLeft((getAnalog(LEFT_AXIS_Y)));
//     setDriveRight((getAnalog(RIGHT_AXIS_Y)));
//     //H-Drive Control
//     setDriveH(hSpeed*(((getAnalog(LEFT_AXIS_X)))+((getAnalog(RIGHT_AXIS_X)))));
// 
//     //Intake Control
//     
//     if (Controller1.ButtonR1.pressing()){
//       intakeBrakeVar = 0;
//       intakeSpin(BACKWARD, FAST);
//       Controller1.Screen.print(getUp());
//     }
//     else if (Controller1.ButtonR2.pressing()){
//       intakeBrakeVar = 1;
//       intakeBrake();
//       intakeSpin(FORWARD, FAST);
//     }
//     /*else if (Controller1.ButtonB.pressing()){
//       intakeBrakeVar = 2;
//     }*/
// 
//     //Brake when closed, release brake when opening
//     else{
//       if (intakeBrakeVar == 0){
//         intakeCoast();
//       }
//       else if (intakeBrakeVar == 1){
//         intakeBrake();
//       }
//       else{
//         intakeBrake();
//       }
//     }
// 
//     /*if (Controller1.ButtonB.pressing()){
//       routineDriver();
//     }*/
// 
//     
// 
//     //Controller1.ButtonB.pressed(routineDriver);
//     //Controller1.ButtonA.pressed(wait1);
// 
// 
//     
// 
//     //Up
//       if (Controller1.ButtonL1.pressing()){
//         up(FORWARD, 200);
//       }
//       else if (Controller1.ButtonL2.pressing()){
//         up(BACKWARD, 200);
//       }
//       else{
//         upBrake();
//       }
// 
//     //Brake Toggle Control
//     if ((Controller1.ButtonY.pressing())&&(brakeVar == 0)){
//       brakeVar = 1;
//       baseBrakeHold(0);
//       hBrakeHold(0);
//       vex::task::sleep(300);
//     }
//     if ((Controller1.ButtonY.pressing())&&(brakeVar == 1)){
//       brakeVar = 0;
//       baseBrakeCoast(0);
//       hBrakeCoast(0);
//       vex::task::sleep(300);
//     }
//     vex::task::sleep(15);
//   }
// }
// 
// int main() {
//   pre_auton();
//   Competition.autonomous( autonomous );
//   Competition.drivercontrol( usercontrol );
//   while (true){
//     if (Brain.Screen.pressing()){
//       autoColorSelect();
//       wait(300);
//     }
// 
// 
//     //Controller1.Screen.clearLine();
//     Controller1.Screen.print(autoColorReturn());
//     //vibrate when a motor is too hot
//     if (RF.temperature(vex::percentUnits::pct) >= 70){
//       Controller1.rumble("-");
//       Controller1.Screen.newLine();
//       Controller1.Screen.print("RF Heat Above 70%");
//     }
//     if (RB.temperature(vex::percentUnits::pct) >= 70){
//       Controller1.rumble("-");
//       Controller1.Screen.newLine();
//       Controller1.Screen.print("RB Heat Above 70%");
//     }
//     if (LF.temperature(vex::percentUnits::pct) >= 70){
//       Controller1.rumble("-");
//       Controller1.Screen.newLine();
//       Controller1.Screen.print("LF Heat Above 70%");
//     }
//     if (LB.temperature(vex::percentUnits::pct) >= 70){
//       Controller1.rumble("-");
//       Controller1.Screen.newLine();
//       Controller1.Screen.print("LB Heat Above 70%");
//     }
//     if (MH.temperature(vex::percentUnits::pct) >= 70){
//       Controller1.rumble("-");
//       Controller1.Screen.newLine();
//       Controller1.Screen.print("MH Heat Above 70%");
//     }
//     if (LUp.temperature(vex::percentUnits::pct) >= 70){
//       Controller1.rumble(".");
//       Controller1.Screen.newLine();
//       Controller1.Screen.print("LUp Heat Above 70%");
//     }
//     if (RUp.temperature(vex::percentUnits::pct) >= 70){
//       Controller1.rumble(".");
//       Controller1.Screen.newLine();
//       Controller1.Screen.print("RUp Heat Above 70%");
//     }
//     if (Intake.temperature(vex::percentUnits::pct) >= 95){
//       Controller1.rumble("-");
//       Controller1.Screen.newLine();
//       Controller1.Screen.print("Intake Heat Above 95%");
//     }
//   }
// }
// 