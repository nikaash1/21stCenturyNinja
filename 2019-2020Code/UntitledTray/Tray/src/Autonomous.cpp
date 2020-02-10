#include "vex.h"
using namespace vex;

void runAutoTester(){

  //deploy
  driveEncoder(FORWARD, 100, 2);
  driveTime(BACKWARD, 40, 300);
  armEncoder(UP, 100, 150);
  armGo(DOWN, 100);
  tray(UNTILT, 15);
  intake(IN, 100);

  //cube 1-3
  goP(FORWARD, 80, 32, 7, 20);
  wait(200, msec);
  armGo(DOWN, 20);
  wait(200, msec);
  trayTime(TILT, 30, 75);
  trayBrake();

  //cubes 4-5
  armEncoder(UP, 100, 80);
  goP(FORWARD, 90, 8, 0, 4);
  armGo(DOWN, 100);
  goP(FORWARD, 90, 8, 0, 5);
  armCoast();
  armBrake();

  //back up
  goP(BACKWARD, 250, 15, 0, 11);
  wait(100, msec);
  turnP(LEFT, 130, 80, 5, 60);
  wait(100, msec);
  goP(BACKWARD, 180, 25, 5, 16);

  //align with cubes 6-9
  wait(200, msec);
  turnP(RIGHT, 100, 75, 10, 60);
  intake(IN, 100);
  wait(100, msec);

  //cubes 6-9
  //goP(FORWARD, 80, 44, 0, 30);
  goP(FORWARD, 100, 10, 0, 0);
  turnP(LEFT, 100, 7, 0, 0);
  goP(FORWARD, 80, 40, 0, 28);
  goP(BACKWARD, 100, 32, 0, 0);
  trayControlled(TILT, 40, 250);
  wait(100, msec);
  turnP(RIGHT, 100, 170, 0, 120);
  intakeBrake();

  //place stack
  goP(FORWARD, 100, 8, 0, 3);
  armGo(DOWN, 40);
  wait(300, msec);
  intake(OUT, 10);
  trayP(100, 600, 500);
  intake(OUT, 40);
  goP(BACKWARD, 25, 40, 0, 40);
}

void runAuto(int autoNumber){
  if (autoNumber == 0){
    goP(FORWARD, 100, 100, 0, 100);
  }  
  else if (autoNumber == 1){
    runAutoTester();
  }
  else if (autoNumber == 2){ 
  }
  else if (autoNumber == 3){
  }
  else if (autoNumber == 4){
  }
}