#include "vex.h"
using namespace vex;
double alignerVar = 10;

void alignerMove(int dir, double speed){
  Aligner.spin(fwd, 0.12*speed*dir, volt);
}

double getAligner(){
  return Aligner.rotation(rotationUnits::deg);
}
void resetAligner(){
  Aligner.resetRotation();
}

void alignEncoder(int dir, double speed, int dist){
  Aligner.startRotateFor(dist*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
}

void align(int dir, double speed){
  alignEncoder(dir, speed, alignerVar);
}

void alignBrake(){
  Aligner.stop(hold);
}

void alignCoast(){
  Aligner.stop(coast);
}