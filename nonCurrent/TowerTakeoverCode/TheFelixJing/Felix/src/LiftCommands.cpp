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

int liftEncoder(int dir, double speed, double dist){
  double inches = dist*28.38;
  LUp.startRotateFor(inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  RUp.startRotateFor(inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  return 0;
}