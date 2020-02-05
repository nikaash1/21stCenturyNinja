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
    /*if (getArmLimit()){ //reset switch
      wait(200, msec);
      Arm.resetRotation();
    }*/
    if (getController(BTNL1)){
      armGo(UP, 5);
    }
    else if (getController(BTNL2)){
      armGo(DOWN, 100);
    }
    else if (getController(BTNA)){
      while (getController(BTNA)){
        wait(1, msec);
      }
      armEncoder(UP, 100, 150);
      armGo(DOWN, 100);
      tray(UNTILT, 15);
    }
    else if (getController(BTNB)){ //down on tilt
      armGo(DOWN, 30);
    }
    else{
      armBrake();
    }
  }
  return 0;
}