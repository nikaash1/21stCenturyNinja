#include "vex.h"
using namespace vex;

//get lift encoder
double getLift(){
  double armVal = Lift.rotation(deg);
  return armVal;
}

//set power to lift
void setLift(int dir, double speed){
  Lift.spin(fwd, dir*speed*0.12, volt);
}

//spin lift for number of degrees and wait for finish
int liftEncoder(int dir, double speed, double height){
  Lift.startRotateFor(height*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  while (Lift.isSpinning()){
    wait(1, msec);
  }
  return 0;
}
//spin lift for number of degrees and dont wait for finish
int liftControlled(int dir, double speed, double height){
  Lift.startRotateFor(height*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  return 0;
}

//lift stop commands
void liftBrake(){
  Lift.stop(hold);
}
void liftCoast(){
  Lift.stop(coast);
}

//get lift limit value
int getLiftLimit(){
  if (LiftLimit.pressing()){
    return 1;
  }
  else{
    return 0;
  }
}