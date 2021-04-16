#include "vex.h"
using namespace vex;

int intakeJoystick(){
  while(1){
    if(getController(BTNR2)){
      setIntake(INTAKE, 100);
    }
    else if(getController(BTNR1)){
      setIntake(OUTTAKE, 100);
    }
    else{
      setIntake(INTAKE, 40);
    }
    wait(10, msec);
  }
  return 1;
}