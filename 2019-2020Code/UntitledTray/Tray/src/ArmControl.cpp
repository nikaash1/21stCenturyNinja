#include "vex.h"
using namespace vex;

int towerMode(){
  while(1){
    if (getController(BTNL1)){
      armGo(UP, 100);
    }
    else if (getController(BTNL2)){
      armGo(DOWN, 100);
    }
    /*else if (getController(BTNUP)){
      armGo(UP, 100);
    }
    else if (getController(BTNLEFT)){
      armGo(DOWN, 100);
    }*/
    else{
      armBrake();
    }
  }
  return 0;
}