#include "vex.h"
using namespace vex;

int liftControls(){
  while(1){
    if ((getController(BTNL1)) == 1){
      upGo(UP, 100);
    }
    else if ((getController(BTNL2)) == 1){
      upGo(DOWN, 100);
    }
    else{
      upBrake();
    }
  }
  return 0;
}