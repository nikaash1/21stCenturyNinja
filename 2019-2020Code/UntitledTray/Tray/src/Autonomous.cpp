#include "vex.h"
using namespace vex;

void runAutoTester(){

  //deploy
  intakeBrake();
  goP(FORWARD, 100, 100, 4, 0, 0);
  driveTime(BACKWARD, 50, 200);
  armControlled(UP, 100, 120);
  goP(FORWARD, 100, 100, 14, 0, 11.5);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1200, msec);
  tray(UNTILT, 15);

  //cube 1-3
  intake(IN, 100);
  goP(FORWARD, 100, 45, 18, 5, 13);
  trayControlled(TILT, 30, 150);

  //cubes 4-5
  armEncoder(UP, 100, 70);
  goP(FORWARD, 60, 55, 8, 0, 4);
  armGo(DOWN, 100);
  goP(FORWARD, 100, 90, 8, 0, 2);
  armBrake();
  tray(UNTILT, 15);

  //back up
  wait(100, msec);
  goP(BACKWARD, 100, 100, 3, 0, 2);
  wait(100, msec);
  turnP(LEFT, 100, 80, 50, 0, 38);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 41, 12, 30);
  armGo(DOWN, 70);

  //align with cubes 6-9
  wait(100, msec);
  turnP(RIGHT, 100, 70, 45, 10, 40);
  wait(100, msec);
  intake(IN, 100);

  //cubes 6-9
  //goPWithArms(FORWARD, 70, 50, 47, 10, 36, 33, UP, 100, 80);
  goP(FORWARD, 70, 50, 10, 0, 6);
  //turnP(LEFT, 100, 100, 15, 0, 0);
  goP(FORWARD, 70, 60, 31, 7, 19);

  //align with zone
  armGo(DOWN, 40);
  goP(BACKWARD, 100, 100, 30, 0, 0);
  wait(100, msec);
  turnP(RIGHT, 60, 60, 100, 0, 80);
  intakeBrake();
}

void runAutoTesterBlue(){

  //deploy
  intakeBrake();
  goP(FORWARD, 100, 100, 3, 0, 0);
  driveTime(BACKWARD, 30, 400);
  wait(300, msec);
  armControlled(UP, 100, 120);
  goP(FORWARD, 100, 100, 14, 0, 11.5);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  wait(1200, msec);
  tray(UNTILT, 15);

  //cube 1-3
  intake(IN, 100);
  goP(FORWARD, 100, 45, 17, 5, 13);
  trayControlled(TILT, 30, 150);

  //cubes 4-5
  armEncoder(UP, 100, 70);
  goP(FORWARD, 60, 55, 8, 0, 4);
  armGo(DOWN, 100);
  goP(FORWARD, 100, 90, 8, 0, 2);
  armBrake();
  tray(UNTILT, 15);

  //back up
  wait(100, msec);
  goP(BACKWARD, 100, 100, 3, 0, 2);
  wait(100, msec);
  turnP(RIGHT, 100, 80, 50, 0, 38);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 41, 12, 30);
  armGo(DOWN, 70);

  //align with cubes 6-9
  wait(100, msec);
  turnP(LEFT, 100, 70, 45, 10, 40);
  wait(100, msec);
  intake(IN, 100);

  //cubes 6-9
  //goPWithArms(FORWARD, 70, 50, 47, 10, 36, 33, UP, 100, 80);
  goP(FORWARD, 70, 50, 10, 0, 6);
  //turnP(LEFT, 100, 100, 15, 0, 0);
  goP(FORWARD, 70, 60, 31, 7, 19);

  //align with zone
  armGo(DOWN, 40);
  goP(BACKWARD, 100, 100, 30, 0, 0);
  wait(100, msec);
  turnP(LEFT, 60, 60, 100, 0, 80);
  intakeBrake();
}











































































void runAutoPlace(){

  //deploy
  intakeBrake();
  goP(FORWARD, 100, 100, 3, 0, 0);
  driveTime(BACKWARD, 40, 500);
  wait(300, msec);
  armControlled(UP, 100, 120);
  goP(FORWARD, 100, 100, 14, 0, 11.5);
  intakeDeploy(OUT, 50, 70);
  armGo(DOWN, 100);
  tray(UNTILT, 100);
  intakeControlled(OUT, 100, 15);
  wait(1200, msec);
  tray(UNTILT, 15);

  //cube 1-3
  intake(IN, 100);
  goP(FORWARD, 100, 50, 18, 5, 13);
  trayControlled(TILT, 30, 150);

  //cubes 4-5
  armEncoder(UP, 100, 70);
  goP(FORWARD, 60, 55, 8, 0, 4);
  armGo(DOWN, 100);
  goP(FORWARD, 100, 100, 8, 0, 0);
  armBrake();
  tray(UNTILT, 15);

  //back up
  wait(100, msec);
  goP(BACKWARD, 100, 100, 3, 0, 2);
  wait(100, msec);
  turnP(LEFT, 100, 90, 50, 0, 44);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 40.75, 17, 28);
  armGo(DOWN, 70);

  //align with cubes 6-9
  wait(100, msec);
  turnP(RIGHT, 100, 70, 45, 10, 40);
  wait(100, msec);
  intake(IN, 100);

  //cubes 6-9
  //goPWithArms(FORWARD, 70, 50, 47, 10, 36, 33, UP, 100, 80);
  goP(FORWARD, 90, 90, 20, 0, 14);

  //align with zone
  armGo(DOWN, 40);
  trayControlled(TILT, 40, 300);
  goP(BACKWARD, 100, 100, 16, 8, 10);
  wait(100, msec);
  turnP(RIGHT, 100, 100, 141, 0, 110);
  intakeBrake();

  //place stack
  intakeControlled(OUT, 100, 13);
  driveTime(FORWARD, 60, 130);
  setDrive(40, 40);
  intake(OUT, 12);
  trayP(130, 450, 550);
  intake(OUT, 100);
  goP(BACKWARD, 50, 25, 40, 0, 40);
}



























































void runNewAuto(){
  //deploy
  intakeBrake();
  setDrive(-100, -100);
  armEncoder(UP, 100, 120);
  trayEncoder(TILT, 100, 100);
  armGo(DOWN, 100);
  tray(UNTILT, 50);
  wait(100, msec);

  //cube 1-3
  goPWithIntake(FORWARD, 100, 100, 34, 5, 28, 10, IN, 100);
  trayControlled(TILT, 30, 150);

  //cubes 4-5
  armEncoder(UP, 100, 70);
  goP(FORWARD, 60, 55, 8, 0, 4);
  armGo(DOWN, 100);
  goP(FORWARD, 100, 100, 8, 0, 0);
  armBrake();
  tray(UNTILT, 15);

  //back up
  wait(100, msec);
  goP(BACKWARD, 100, 100, 3, 0, 2);
  wait(100, msec);
  turnP(LEFT, 100, 80, 50, 0, 38);
  wait(100, msec);
  goP(BACKWARD, 100, 100, 40.75, 17, 28);
  armGo(DOWN, 70);

  //align with cubes 6-9
  wait(100, msec);
  turnP(RIGHT, 100, 70, 45, 10, 40);
  wait(100, msec);
  intake(IN, 100);

  //cubes 6-9
  //goPWithArms(FORWARD, 70, 50, 47, 10, 36, 33, UP, 100, 80);
  goP(FORWARD, 75, 60, 10, 0, 5);
  armControlled(UP, 10, 30);
  //turnP(LEFT, 100, 100, 15, 0, 0);
  goPWithArms(FORWARD, 38, 48, 28, 7, 14, 20, UP, 100, 20);

  //align with zone
  armGo(DOWN, 40);
  trayControlled(TILT, 40, 300);
  goP(BACKWARD, 100, 100, 31, 0, 0);
  wait(100, msec);
  turnP(RIGHT, 100, 100, 140, 0, 110);
  intakeBrake();

  //place stack
  driveTime(FORWARD, 90, 130);
  setDrive(20, 20);
  intake(OUT, 20);
  trayP(100, 450, 820);
  intake(OUT, 100);
  goP(BACKWARD, 50, 25, 40, 0, 40);
}




void runAuto(int autoNumber){
  if (autoNumber == 0){
    intakeBrake();
    armControlled(UP, 100, 120);
    goP(FORWARD, 100, 100, 14, 0, 11.5);
    intakeDeploy(OUT, 50, 70);
    armGo(DOWN, 100);
    tray(UNTILT, 100);
    intakeControlled(OUT, 100, 15);
  }  
  else if (autoNumber == 1){
    runAutoTester();
  }
  else if (autoNumber == 2){
    runAutoPlace();
  }
  else if (autoNumber == 3){
    runNewAuto();
  }
  else if (autoNumber == 4){
    runAutoTesterBlue();
  }
}