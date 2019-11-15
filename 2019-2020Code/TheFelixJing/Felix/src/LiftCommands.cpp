#include "vex.h"
using namespace vex;

void upGo(int dir, double speed){
  RUp.spin(fwd, dir*speed*0.12, volt);
  LUp.spin(fwd, dir*speed*0.12, volt);
}

void upBrake(){
  RUp.stop(hold);
  LUp.stop(hold);
}

void upCoast(){
  RUp.stop(coast);
  LUp.stop(coast);
}