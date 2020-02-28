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
  wait(300, msec);
  driveTime(BACKWARD, 40, 700);
  setDrive(-40, -40);
  armEncoder(UP, 100, 140);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(2000, msec);
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

  //back up and align with zone
  turnP(RIGHT, 100, 100, 30, 5, 20, 100, true);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 38, 8, 32, 100, true);
  intakeBrake();
  wait(100, msec);
  intakeControlled(OUT, 50, 100);
  turnP(RIGHT, 100, 100, 114, 10, 70, 120, true);

  //tilt
  trayControlled(TILT, 100, 200);
  driveTime(FORWARD, 40, 600);
  intake(OUT, 20);
  trayEncoder(TILT, 60, 300);
  trayEncoder(TILT, 40, 150);
  wait(100, msec);
  
  //back out
  intake(OUT, 100);
  goP(BACKWARD, 100, 100, 7, 0, 0, 100, false);
  trayTime(UNTILT, 30, 500);
}

void blueSmallPlace(){

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
  goP(FORWARD, 60, 60, 18, 0, 12, 100, false);
  intakeControlled(OUT, 50, 120);
  wait(500, msec);
  turnP(RIGHT, 60, 60, 90, 0, 60, 100, false);
  wait(700, msec);

  //tower 1
  armControlled(UP, 60, 200);
  goP(FORWARD, 50, 50, 13, 0, 7, 100, false);
  wait(500, msec);
  intake(OUT, 30);
  wait(1200, msec);

  //align with cubes 1-9
  goP(BACKWARD, 50, 50, 13, 0, 7, 100, false);
  wait(500, msec);
  intakeBrake();
  armControlled(DOWN, 60, 200);
  turnP(LEFT, 60, 60, 90, 0, 60, 100, false);
  wait(700, msec);
  goP(BACKWARD, 60, 60, 18, 0, 12, 100, false);
  intake(IN, 100);
  armGo(DOWN, 60);
  wait(500, msec);
  driveTime(BACKWARD, 30, 700);
  wait(500, msec);

  //cubes 1-9
  goP(FORWARD, 50, 50, 110, 80, 90, 150, true);
  wait(500, msec);

  //align with zone
  turnP(RIGHT, 60, 60, 90, 0, 60, 100, false);
  wait(700, msec);
  intakeControlled(OUT, 30, 100);
  goP(FORWARD, 60, 60, 18, 0, 12, 100, false);
  wait(500, msec);

  //tilt
  intake(OUT, 10);
  armGo(DOWN, 100);
  trayEncoder(TILT, 50, 150);
  trayEncoder(TILT, 40, 150);
  trayEncoder(TILT, 30, 175);
  intake(OUT, 30);
  trayEncoder(TILT, 20, 125);
  trayControlled(TILT, 25, 150);

  //back out
  intake(OUT, 60);
  goP(BACKWARD, 30, 30, 18, 0, 6, 100, false);
  trayControlled(UNTILT, 60, 600);
  wait(500, msec);

  //collect tower 2 cube
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
}