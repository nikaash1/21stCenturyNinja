#include "vex.h"
using namespace vex;

bool autoRunning = false;
int autoVar = 0;

int autoVarReturn(){
  return autoVar;
}

void deploy(){
  armEncoder(UP, 100, 200);
  armEncoder(DOWN, 100, 200);
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
  //deploy
  driveEncoder(FORWARD, 100, 2);
  driveTime(BACKWARD, 60, 100);
  armEncoder(UP, 100, 150);
  armGo(DOWN, 100);
  tray(UNTILT, 15);
  intake(IN, 100);
  //wait(100, msec);
  //first 5 cubes
  goP(FORWARD, 60, 34, 20);
  armGo(DOWN, 20);
  wait(300, msec);
  trayTime(TILT, 30, 75);
  trayBrake();
  armEncoder(UP, 100, 90);
  goP(FORWARD, 150, 8, 3);
  armGo(DOWN, 100);
  goP(FORWARD, 120, 12, 6);
  armCoast();
  armBrake();
  //back up
  goP(BACKWARD, 150, 12, 7);
  turnP(LEFT, 80, 35, 20);
  goP(BACKWARD, 70, 27, 20);
  driveEncoder(BACKWARD, 70, 27);
  //align with cubes 6-9
  wait(200, msec);
  turnP(RIGHT, 100, 45, 37);
  turnEncoder(RIGHT, 100, 45);
  intake(IN, 100);
  //last 4 cubes
  goP(FORWARD, 45, 8, 4);
  turnP(LEFT, 100, 7, 3);
  goP(FORWARD, 25, 29, 23);
  //align with zone
  goP(BACKWARD, 100, 20, 13);
  wait(100, msec);
  turnP(RIGHT, 70, 120, 90);
  intakeBrake();
  //place stack
  goP(FORWARD, 100, 12, 7);
  armGo(DOWN, 40);
  wait(300, msec);
  intake(OUT, 20);
  trayP(60, 550);
  intake(OUT, 40);
  goP(BACKWARD, 25, 40, 40);
  driveEncoder(BACKWARD, 25, 40);
}










void runAutoTesterBlue(){
}




void runAutoPID(){
turnP(RIGHT, 130, 115, 40);
}
void runAutoEnc(){
turnEncoder(RIGHT, 70, 30);
}

void runAuto10Test(){

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
    runAutoTesterBlue();
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
