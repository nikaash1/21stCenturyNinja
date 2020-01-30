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
    if (getController(BTNL1)){
      armGo(UP, 120);
    }
    else if (getController(BTNL2)){
      armGo(DOWN, 120);
    }
    else if (getController(BTNX)){
      armGo(UP, 120);
    }
    else if (getController(BTNA)){
      armGo(DOWN, 120);
    }
    else{
      armBrake();
    }
  }
  return 0;
}