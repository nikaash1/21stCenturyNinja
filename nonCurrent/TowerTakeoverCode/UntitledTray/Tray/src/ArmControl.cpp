#include "vex.h"
using namespace vex;

bool deployed = false;
int towerMode(){
  while(1){
    if (getController(BTNLEFT)){ //reset button
      while (getController(BTNLEFT)){
        wait(1, msec);
      }
      Arm.resetRotation();
    }
    if (getController(BTNA)){
      while(getController(BTNA)){
        wait(1, msec);
      }
      if (!(deployed)){
        armEncoder(UP, 100, 140);
        armEncoder(DOWN, 100, 110);
        deployed = true;
      }
      else{
        Controller.rumble(".");
      }
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
    wait(10, msec);
  }
  return 0;
}