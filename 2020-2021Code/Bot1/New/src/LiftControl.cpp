#include "vex.h"
using namespace vex;

int liftJoystick(){
  while(1){
    int downLimit = 1;
    if(getLiftLimit()){
      downLimit = 0;
    }
    else{
      downLimit = 1;
    }

    if(getController(BTNL1)){
      setLift(UP, 100);
    }
    else if(getController(BTNL2)){
      setLift(DOWN, 100*downLimit);
    }
    else{
      if(getLiftLimit()){
        liftCoast();
      }
      else{
        liftBrake();
      }
    }
    wait(10, msec);
  }
  return 1;
}