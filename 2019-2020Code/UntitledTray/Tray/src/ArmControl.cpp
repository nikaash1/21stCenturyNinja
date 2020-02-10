#include "vex.h"
using namespace vex;

int towerMode(){
  while(1){
    if (getController(BTNLEFT)){ //reset button
      while (getController(BTNLEFT)){
        wait(1, msec);
      }
      Arm.resetRotation();
    }
    if (getArmLimit()){ //reset switch
      Arm.resetRotation();
    }
    if (getController(BTNL1)){
      armGo(UP, 100);
    }
    else if (getController(BTNL2)){
      armGo(DOWN, 100);
    }
    else if (getController(BTNB)){ //down on tilt
      armGo(DOWN, 100);
    }
    else{
      armBrake();
    }
  }
  return 0;
}