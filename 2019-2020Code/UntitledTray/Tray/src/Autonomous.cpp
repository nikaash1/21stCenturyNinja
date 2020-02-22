#include "vex.h"
using namespace vex;

void redSmallPlace(){
  //deploy
  intakeBrake();
  goP(FORWARD, 90, 90, 11, 1, 6, 110, true);
  wait(300, msec);
  driveTime(BACKWARD, 40, 700);
  setDrive(-40, -40);
  armEncoder(UP, 100, 140);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1500, msec);
  tray(UNTILT, 15);
  //cubes 1-5
  intake(IN, 100);
  goP(FORWARD, 60, 80, 40, 3, 20, 160, true);
  wait(100, msec);
  //cube 6
  turnP(LEFT, 100, 100, 30, 5, 20, 100, true);
  wait(200, msec);
  goP(FORWARD, 100, 100, 7, 1, 4, 110, true);
  wait(200, msec);
  //back out
  turnP(RIGHT, 100, 100, 30, 5, 20, 100, true);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 40, 8, 32, 100, true);
  intakeBrake();
  wait(100, msec);
  intakeControlled(OUT, 50, 120);
  turnP(RIGHT, 100, 100, 110, 10, 70, 120, true);
  trayControlled(TILT, 100, 200);
  driveTime(FORWARD, 40, 600);
  intake(OUT, 20);
  trayEncoder(TILT, 60, 300);
  trayEncoder(TILT, 40, 150);
  wait(100, msec);
  intake(OUT, 100);
  goP(BACKWARD, 100, 100, 7, 0, 0, 100, false);
  trayTime(UNTILT, 30, 500);
}

void redSmall7(){
  //deploy
  intakeBrake();
  goP(FORWARD, 90, 90, 11, 1, 6, 110, true);
  wait(300, msec);
  driveTime(BACKWARD, 40, 700);
  setDrive(-40, -40);
  armEncoder(UP, 100, 140);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1500, msec);
  tray(UNTILT, 15);
  //cubes 1-5
  intake(IN, 100);
  goP(FORWARD, 60, 80, 40, 3, 20, 160, true);
  wait(100, msec);
  //cube 6
  turnP(LEFT, 100, 100, 30, 5, 20, 100, true);
  wait(200, msec);
  goP(FORWARD, 100, 100, 7, 1, 4, 110, true);
  wait(200, msec);
  //cube 7
  turnP(RIGHT, 100, 100, 40, 5, 27, 100, true);
  wait(200, msec);
  goP(FORWARD, 100, 100, 11, 1, 6, 100, true);
  wait(200, msec);
  //back out
  goP(BACKWARD, 100, 100, 40, 8, 32, 100, true);
  intakeBrake();
  wait(100, msec);
  intakeControlled(OUT, 50, 120);
  turnP(RIGHT, 100, 100, 110, 10, 70, 120, true);
  trayControlled(TILT, 100, 200);
  driveTime(FORWARD, 40, 600);
  intake(OUT, 20);
  trayEncoder(TILT, 60, 400);
  trayEncoder(TILT, 40, 150);
  wait(100, msec);
  intake(OUT, 100);
  goP(BACKWARD, 100, 100, 7, 0, 0, 100, false);
  trayTime(UNTILT, 30, 500);
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
  //goPWithArms(FORWARD, 70, 50, 47, 10, 36, 33, UP, 100, 80);
  goP(FORWARD, 70, 50, 10, 0, 6, 100, false);
  //turnP(LEFT, 100, 100, 15, 0, 0);
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
  //goPWithArms(FORWARD, 70, 50, 47, 10, 36, 33, UP, 100, 80);
  goP(FORWARD, 70, 50, 10, 0, 6, 100, false);
  //turnP(LEFT, 100, 100, 15, 0, 0);
  goP(FORWARD, 70, 60, 31, 7, 19, 100, false);

  //align with zone
  armGo(DOWN, 40);
  goP(BACKWARD, 100, 100, 30, 0, 0, 100, false);
  wait(100, msec);
  turnP(LEFT, 60, 60, 100, 0, 80, 100, false);
  intakeBrake();
}

void runAuto(int autoNumber){
  if (autoNumber == 0){
    intakeBrake();
    armControlled(UP, 100, 120);
    goP(FORWARD, 100, 100, 14, 0, 11.5, 100, false);
    intakeDeploy(OUT, 50, 70);
    armGo(DOWN, 100);
    tray(UNTILT, 100);
    intakeControlled(OUT, 100, 15);
  }  
  else if (autoNumber == 1){
    red9Collect();
  }
  else if (autoNumber == 2){
    redSmallPlace();
  }
  else if (autoNumber == 3){
    redSmall7();
  }
  else if (autoNumber == 4){
    blue9Collect();
  }
}