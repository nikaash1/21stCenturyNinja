#include "vex.h"
using namespace vex;

//setup auto
void idle(){
}

//red auton
void redAuto(){
}

//blue auton
void blueAuto(){
}

//skills auton
void skills(){
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