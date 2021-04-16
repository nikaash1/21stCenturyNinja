#include "vex.h"
using namespace vex;

//setup auto
void idle(){
}

//red auton
void redAuto(){
  wait(100, msec);
  setIntake(INTAKE, 40);
  wait(100, msec);
  setLift(UP, 100);
  wait(100, msec);
  setLift(DOWN, 100);
  wait(150, msec);
  setLift(UP, 100);
  wait(100, msec);
  while(Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  setLift(UP, 30);
  wait(500, msec);
  goP(FORWARD, 30, 30, 40, 5, 20, 100, true);
  setIntake(OUTTAKE, 100);
  wait(700, msec);
  liftCoast();
}

//blue auton
void blueAuto(){
}

//skills auton
void skills(){
  goP(FORWARD, 100, 100, 30, 5, 3, 100, true);
}

void runAuto(int autoNumber){
  if (autoNumber == 0){
    idle();
  }  
  else if (autoNumber == 1){
    redAuto();
  }
  else if (autoNumber == 2){
    blueAuto();
  }
  else if (autoNumber == 3){
  }
  else if (autoNumber == 4){
  }
  else if (autoNumber == 5){
    skills();
  }
  else if (autoNumber == 7){
  }
  else if (autoNumber == 8){
  }
}