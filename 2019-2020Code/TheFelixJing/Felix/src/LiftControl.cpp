#include "vex.h"
using namespace vex;

int liftControls(){
  while(1){
    if ((getController(BTNL1)) == 1){
      upGo(UP, 70);
    }
    else if ((getController(BTNL2)) == 1){
      upGo(DOWN, 70);
    }
    else{
      upBrake();
    }
  }
  return 0;
}