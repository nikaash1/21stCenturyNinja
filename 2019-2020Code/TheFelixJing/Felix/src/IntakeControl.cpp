#include "vex.h"
using namespace vex;

int intakeControls(){
  while(1){
    if ((getController(BTNR1)) == 1){
      intake(OPEN, 100);
    }
    else if ((getController(BTNR2)) == 1){
      intake(CLOSE, 100);
    }
    else{
      intakeBrake();
    }
    if ((getController(BTNY)) == 1){
      dropCube();
    }
  }
  return 0;
}
