#include "vex.h"
using namespace vex;

bool autoRunning = false;
int autoVar = 0;

int autoVarReturn(){
  return autoVar;
}

void deploy(){
  armEncoder(UP, 100, 100);
  armEncoder(DOWN, 100, 100);
}
int go1(){
  goP(FORWARD, 30, 38, 4);
  turnP(RIGHT, 100, 90, 5);
  goP(FORWARD, 100, 10, 1);
  turnP(RIGHT, 100, 90, 5);
  goP(FORWARD, 100, 50, 3);
  turnP(LEFT, 100, 30, 3);
  goP(FORWARD, 100, 15, 2);
  return 0;
}

void test(){
  trayTime(UNTILT, 100, 200);
  trayBrake();
  intake(IN, 100);
}
void runAutoTester(){
  deploy();
  armGo(DOWN, 30);
  intake(IN, 100);
  trayTime(UNTILT, 100, 200);
  trayBrake();
  goP(FORWARD, 35, 35, 8);
  trayTime(TILT, 30, 75);
  wait(500, msec);
  armEncoder(UP, 100, 80);
  goP(FORWARD, 35, 16, 10);
  armGo(DOWN, 20);
  goP(FORWARD, 40, 25, 10);
  armCoast();
  /*armEncoder(UP, 100, 40);
  turnP(RIGHT, 100, 90, 5);
  goP(FORWARD, 100, 10, 1);
  turnP(RIGHT, 100, 90, 5);
  goP(FORWARD, 100, 50, 3);
  turnP(LEFT, 100, 30, 3);
  goP(FORWARD, 100, 15, 2);
  intakeBrake();
  trayP(100, 600);*/

}

void runAuto10Small(){

}

void runAuto(int autoNumber){
  autoRunning = true;
  if (autoNumber == 0){
    deploy();
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

int autoSelector(){
  while (!(autoRunning)){
    if ((Brain.Screen.pressing()) && (autoVar < TOTAL_AUTONS)){
      autoVar++;
    }
    else if ((Brain.Screen.pressing()) && (autoVar >= TOTAL_AUTONS)){
      autoVar = 0;
    }
  }
  return 0;
}

int autoIndicator(){
  while (!(autoRunning)){
    if (autoVar == 0){
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(100, 100, 100, 100, purple);
      Brain.Screen.print("deploy");
    }
    else if (autoVar == 1){
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(100, 100, 100, 100, red);
      Brain.Screen.print("large zone");
    }
    else if (autoVar == 2){
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(100, 100, 100, 100, red);
      Brain.Screen.print("small zone");
    }
    else if (autoVar == 3){
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(100, 100, 100, 100, blue);
      Brain.Screen.print("large zone");
    }
    else if (autoVar == 4){
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(100, 100, 100, 100, blue);
      Brain.Screen.print("small zone");
    }
  }
  return 0;
}
