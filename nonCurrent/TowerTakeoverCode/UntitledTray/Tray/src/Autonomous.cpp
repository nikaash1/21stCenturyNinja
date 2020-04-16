#include "vex.h"
using namespace vex;

//just deploy auto
void deploy(){
  intakeBrake();
  armControlled(UP, 100, 120);
  goP(FORWARD, 100, 100, 14, 0, 11.5, 100, false);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  intakeControlled(OUT, 100, 15);
}


//main 6 auton
void redSmallPlace(){

  //deploy
  intakeBrake();
  goP(FORWARD, 90, 90, 11, 1, 6, 110, true);
  wait(400, msec);
  driveTime(BACKWARD, 40, 700);
  setDrive(-40, -40);
  armEncoder(UP, 100, 140);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1800, msec);
  tray(UNTILT, 15);

  //cubes 1-5
  intake(IN, 100);
  goP(FORWARD, 60, 50, 36, 10, 21, 160, true);
  wait(100, msec);

  //cube 6
  turnP(LEFT, 80, 80, 25, 5, 20, 100, true);
  wait(200, msec);
  goP(FORWARD, 100, 100, 11, 1, 4, 110, true);
  wait(200, msec);

  //back up and align with zone
  turnP(RIGHT, 100, 100, 28, 5, 20, 100, true);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 40, 8, 32, 100, true);
  //intakeBrake();
  wait(100, msec);
  intakeControlled(OUT, 50, 100);
  turnP(RIGHT, 100, 100, 120, 10, 70, 120, true);

  //tilt
  trayControlled(TILT, 100, 200);
  driveTime(FORWARD, 40, 700);
  armGo(DOWN, 10);
  intake(OUT, 20);
  trayEncoder(TILT, 60, 300);
  trayEncoder(TILT, 40, 150);
  armBrake();
  wait(100, msec);
  
  //back out
  intake(OUT, 100);
  goP(BACKWARD, 80, 80, 7, 0, 0, 100, false);
  trayTime(UNTILT, 30, 500);
}

void blueSmallPlace(){
  //deploy
  intakeBrake();
  goP(FORWARD, 90, 90, 11, 1, 6, 110, true);
  wait(400, msec);
  driveTime(BACKWARD, 40, 700);
  setDrive(-40, -40);
  armEncoder(UP, 100, 140);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1800, msec);
  tray(UNTILT, 15);

  //cubes 1-5
  intake(IN, 100);
  goP(FORWARD, 60, 50, 36, 10, 21, 160, true);
  wait(100, msec);

  //cube 6
  turnP(RIGHT, 80, 80, 25, 5, 20, 100, true);
  wait(200, msec);
  goP(FORWARD, 100, 100, 11, 1, 4, 110, true);
  wait(200, msec);

  //back up and align with zone
  turnP(LEFT, 100, 100, 28, 5, 20, 100, true);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 40, 8, 32, 100, true);
  //intakeBrake();
  wait(100, msec);
  intakeControlled(OUT, 50, 100);
  turnP(LEFT, 100, 100, 107, 10, 80, 100, false);

  //tilt
  trayControlled(TILT, 100, 200);
  driveTime(FORWARD, 40, 700);
  armGo(DOWN, 10);
  intake(OUT, 20);
  trayEncoder(TILT, 60, 300);
  trayEncoder(TILT, 40, 150);
  armBrake();
  wait(100, msec);
  
  //back out
  intake(OUT, 100);
  goP(BACKWARD, 80, 80, 7, 0, 0, 100, false);
  trayTime(UNTILT, 30, 500);
  /*//deploy
  intakeBrake();
  goP(FORWARD, 90, 90, 11, 1, 6, 110, true);
  wait(400, msec);
  driveTime(BACKWARD, 40, 700);
  setDrive(-40, -40);
  armEncoder(UP, 100, 140);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1800, msec);
  tray(UNTILT, 15);

  //cubes 1-5
  intake(IN, 100);
  goP(FORWARD, 60, 50, 36, 10, 21, 160, true);
  wait(100, msec);

  //cube 6
  turnP(RIGHT, 80, 80, 34, 5, 20, 100, true);
  wait(200, msec);
  goP(FORWARD, 100, 100, 11, 1, 4, 110, true);
  wait(200, msec);

  //back up and align with zone
  turnP(LEFT, 100, 100, 31, 5, 20, 100, true);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 40, 8, 32, 100, true);
  //intakeBrake();
  wait(100, msec);
  intakeControlled(OUT, 50, 100);
  turnP(LEFT, 100, 100, 110, 10, 70, 120, true);

  //tilt
  trayControlled(TILT, 100, 200);
  driveTime(FORWARD, 40, 800);
  armGo(DOWN, 10);
  intake(OUT, 20);
  trayEncoder(TILT, 60, 300);
  trayEncoder(TILT, 40, 150);
  armBrake();
  wait(100, msec);
  
  //back out
  intake(OUT, 100);
  goP(BACKWARD, 80, 80, 7, 0, 0, 100, false);
  trayTime(UNTILT, 30, 500);*/
}


//collect auton
void red9Collect(){

  //deploy
  intakeBrake();
  goP(FORWARD, 100, 100, 4, 0, 0, 100, false);
  driveTime(BACKWARD, 50, 200);
  armControlled(UP, 100, 120);
  goP(FORWARD, 100, 100, 14, 0, 11.5, 100, false);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1200, msec);
  tray(UNTILT, 15);

  //cube 1-3
  intake(IN, 100);
  goP(FORWARD, 100, 45, 18, 5, 13, 100, false);
  trayControlled(TILT, 30, 150);

  //cubes 4-5
  armEncoder(UP, 100, 70);
  goP(FORWARD, 60, 55, 8, 0, 4, 100, false);
  armGo(DOWN, 100);
  goP(FORWARD, 100, 90, 8, 0, 2, 100, false);
  armBrake();
  tray(UNTILT, 15);

  //back up
  wait(100, msec);
  goP(BACKWARD, 100, 100, 3, 0, 2, 100, false);
  wait(100, msec);
  turnP(LEFT, 100, 80, 50, 0, 38, 100, false);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 41, 12, 30, 100, false);
  armGo(DOWN, 70);

  //align with cubes 6-9
  wait(100, msec);
  turnP(RIGHT, 100, 70, 45, 10, 40, 100, false);
  wait(100, msec);
  intake(IN, 100);

  //cubes 6-9
  goP(FORWARD, 70, 50, 10, 0, 6, 100, false);
  turnP(LEFT, 100, 100, 15, 0, 0, 100, false);
  goP(FORWARD, 70, 60, 31, 7, 19, 100, false);

  //align with zone
  armGo(DOWN, 40);
  goP(BACKWARD, 100, 100, 30, 0, 0, 100, false);
  wait(100, msec);
  turnP(RIGHT, 60, 60, 100, 0, 80, 100, false);
  intakeBrake();
}

void blue9Collect(){

  //deploy
  intakeBrake();
  goP(FORWARD, 100, 100, 3, 0, 0, 100, false);
  driveTime(BACKWARD, 30, 400);
  wait(300, msec);
  armControlled(UP, 100, 120);
  goP(FORWARD, 100, 100, 14, 0, 11.5, 100, false);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1200, msec);
  tray(UNTILT, 15);

  //cube 1-3
  intake(IN, 100);
  goP(FORWARD, 100, 45, 17, 5, 13, 100, false);
  trayControlled(TILT, 30, 150);

  //cubes 4-5
  armEncoder(UP, 100, 70);
  goP(FORWARD, 60, 55, 8, 0, 4, 100, false);
  armGo(DOWN, 100);
  goP(FORWARD, 100, 90, 8, 0, 2, 100, false);
  armBrake();
  tray(UNTILT, 15);

  //back up
  wait(100, msec);
  goP(BACKWARD, 100, 100, 3, 0, 2, 100, false);
  wait(100, msec);
  turnP(RIGHT, 100, 80, 50, 0, 38, 100, false);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 41, 12, 30, 100, false);
  armGo(DOWN, 70);

  //align with cubes 6-9
  wait(100, msec);
  turnP(LEFT, 100, 70, 45, 10, 40, 100, false);
  wait(100, msec);
  intake(IN, 100);

  //cubes 6-9
  goP(FORWARD, 70, 50, 10, 0, 6, 100, false);
  turnP(LEFT, 100, 100, 15, 0, 0, 100, false);
  goP(FORWARD, 70, 60, 31, 7, 19, 100, false);

  //align with zone
  armGo(DOWN, 40);
  goP(BACKWARD, 100, 100, 30, 0, 0, 100, false);
  wait(100, msec);
  turnP(LEFT, 60, 60, 100, 0, 80, 100, false);
  intakeBrake();
}

//skills auton
void skills(){
  //deploy
  intakeBrake();
  goP(FORWARD, 60, 60, 11, 0, 6, 100, false);
  wait(700, msec);
  driveTime(BACKWARD, 20, 1500);
  setDrive(-40, -40);
  armEncoder(UP, 100, 140);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(2500, msec);
  tray(UNTILT, 15);

  //align with first tower
  intake(IN, 100);
  goP(FORWARD, 60, 60, 6, 0, 2, 100, false);
  wait(200, msec);
  intakeControlled(OUT, 50, 120);
  wait(500, msec);
  turnP(RIGHT, 60, 60, 50, 0, 35, 100, false);
  wait(700, msec);

  //tower 1
  trayEncoder(TILT, 90, 30);
  armControlled(UP, 60, 275);
  goP(FORWARD, 50, 50, 16, 0, 10, 100, false);
  wait(500, msec);
  intake(OUT, 40);
  wait(1200, msec);

  //align with cubes 1-9
  goP(BACKWARD, 50, 50, 12, 0, 8, 100, false);
  wait(500, msec);
  intakeBrake();
  
  turnP(LEFT, 60, 60, 50, 0, 40, 100, false);
  wait(700, msec);
  //goP(BACKWARD, 60, 60, 18, 0, 12, 100, false);
  intake(IN, 100);
  
  wait(500, msec);
  driveTime(BACKWARD, 30, 700);
  driveTime(BACKWARD, 100, 200);
  wait(100, msec);
  armControlled(DOWN, 60, 275);
  tray(UNTILT, 100);
  armGo(DOWN, 60);
  wait(1500, msec);
  

  //cubes 1-9
  goP(FORWARD, 40, 30, 45, 20, 30, 100, true);
  wait(100, msec);
  turnP(RIGHT, 40, 30, 5, 1, 2, 100, true);
  wait(100, msec);
  goP(FORWARD, 50, 50, 30, 1, 17, 100, false);
  //wait(100, msec);
  //turnP(LEFT, 40, 30, 10, 1, 2, 100, true);
  wait(100, msec);
  goP(FORWARD, 40, 30, 35, 25, 30, 100, true);
  wait(500, msec);

  //align with zone
  turnP(RIGHT, 60, 60, 38, 0, 29, 100, false);
  wait(700, msec);
  intakeControlled(OUT, 30, 80);
  goP(FORWARD, 60, 60, 10, 0, 8, 100, false);
  //wait(5000, msec);

  //tilt
  driveTime(FORWARD, 40, 600);
  
  //intake(OUT, 10);
  armGo(DOWN, 100);
  //trayEncoder(TILT, 75, 150);
  trayEncoder(TILT, 100, 300);
  intakeCoast();
  trayEncoder(TILT, 70, 100);
  intake(OUT, 10);
  trayEncoder(TILT, 45, 200);
  intake(OUT, 30);
  //trayEncoder(TILT, 40, 125);
  trayControlled(TILT, 20, 200);
  wait(1000, msec);

  //back out
  intake(OUT, 60);
  goP(BACKWARD, 30, 30, 33, 4, 8, 100, false);
  trayControlled(UNTILT, 60, 800);
  wait(500, msec);

  //collect tower 2 cube
  turnP(RIGHT, 60, 60, 144, 0, 60, 100, false);
  driveTime(BACKWARD, 30, 3400);
  intake(IN, 100);
  goP(FORWARD, 50, 30, 48, 30, 38, 150, true);
  wait(500, msec);
  intakeBrake();
  wait(500, msec);
  
  //tower2
  intakeControlled(OUT, 50, 120);
  goP(BACKWARD, 30, 30, 11, 0, 5, 100, false);
  trayEncoder(TILT, 90, 30);
  armControlled(UP, 60, 275);
  goP(FORWARD, 30, 30, 11, 0, 6, 100, false);
  wait(500, msec);
  intake(OUT, 40);
  wait(1200, msec);
   goP(BACKWARD, 30, 30, 11, 0, 5, 100, false);

}
void redlarge(){
  //deploy
  intakeBrake();
  goP(FORWARD, 50, 50, 11, 0, 6, 100, false);
  wait(300, msec);
  driveTime(BACKWARD, 60, 700);
  setDrive(-40, -40);
  armEncoder(UP, 100, 140);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1900, msec);
  tray(UNTILT, 15);

  //cube 2
  intake(IN, 100);
  goP(FORWARD, 60, 60, 16, 0, 6, 100, false);
  wait(200, msec);

  //cube 3 
  turnP(RIGHT, 50, 50, 90, 0, 20, 100, false);
  wait(200, msec);
  goP(FORWARD, 60, 60, 8, 0, 2, 100, false);
  wait(200, msec);
  goP(BACKWARD, 60, 60, 8, 0, 12, 100, false);
  //cube 4
  turnP(LEFT, 50, 50, 165, 0, 60, 100, false);
  wait(100, msec);
  goP(FORWARD, 60, 60, 16, 0, 8, 100, false);
  wait(200, msec);
  
  //score
  turnP(LEFT, 60, 60, 44, 0, 10, 100, false);
  intakeBrake();
  wait(300, msec);
  intakeControlled(OUT, 100, 60);
  goP(FORWARD, 60, 60, 5, 0, 0, 100, false);
  driveTime(FORWARD, 40, 500);
  trayControlled(TILT, 100, 200);
  //intake(OUT, 20);
  trayEncoder(TILT, 70, 400);
  trayEncoder(TILT, 50, 150);
  wait(100, msec);
  intake(OUT, 100);
  goP(BACKWARD, 80, 80, 7, 0, 0, 100, false);
  trayTime(UNTILT, 30, 500);

}
void bluelarge(){
 //deploy
  intakeBrake();
  goP(FORWARD, 50, 50, 11, 0, 6, 100, false);
  wait(300, msec);
  driveTime(BACKWARD, 60, 700);
  setDrive(-40, -40);
  armEncoder(UP, 100, 140);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1900, msec);
  tray(UNTILT, 15);

  //cube 2
  intake(IN, 100);
  goP(FORWARD, 60, 60, 16, 0, 6, 100, false);
  wait(200, msec);

  //cube 3 
  turnP(LEFT, 50, 50, 90, 0, 20, 100, false);
  wait(200, msec);
  goP(FORWARD, 60, 60, 8, 0, 2, 100, false);
  wait(200, msec);
  goP(BACKWARD, 60, 60, 8, 0, 12, 100, false);
  //cube 4
  turnP(RIGHT, 50, 50, 175, 0, 60, 100, false);
  wait(100, msec);
  goP(FORWARD, 60, 60, 16, 0, 8, 100, false);
  wait(200, msec);
  
  //score
  turnP(RIGHT, 60, 60, 35, 7, 40, 100, true);
  intakeBrake();
  wait(300, msec);
  intakeControlled(OUT, 100, 60);
  goP(FORWARD, 60, 60, 5, 0, 0, 100, false);
  driveTime(FORWARD, 40, 500);
  trayControlled(TILT, 100, 200);
  //intake(OUT, 20);
  trayEncoder(TILT, 70, 400);
  trayEncoder(TILT, 50, 150);
  wait(100, msec);
  intake(OUT, 100);
  goP(BACKWARD, 80, 80, 7, 0, 0, 100, false);
  trayTime(UNTILT, 30, 500);
}
void runAuto(int autoNumber){
  if (autoNumber == 0){
    deploy();
  }  
  else if (autoNumber == 1){
    redSmallPlace();
  }
  else if (autoNumber == 2){
    blueSmallPlace();
  }
  else if (autoNumber == 3){
    red9Collect();
  }
  else if (autoNumber == 4){
    blue9Collect();
  }
  else if (autoNumber == 5){
    skills();
  }
  else if (autoNumber == 7){
    redlarge();
  }
  else if (autoNumber == 8){
    bluelarge();
  }
}