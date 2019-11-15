#include "vex.h"
using namespace vex;

void intake(int dir, int speed){
  Intake.spin(fwd, 0.12*speed, volt);
}

void intakeEncoderWait(int dir, int speed, int dist){
  Intake.startRotateFor(dist*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  while(Intake.isSpinning()){
    wait(1, msec);
  }
}

void intakeBrake(){
  Intake.stop(hold);
}
void intakeCoast(){
  Intake.stop(coast);
}

void dropCube(){
  intakeEncoderWait(OPEN, 100, 10);
  intakeEncoderWait(CLOSE, 100, 10);
}