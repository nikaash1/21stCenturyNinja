#include "vex.h"
using namespace vex;

void tray(int dir, double speed){
  Tilter.spin(fwd, dir*speed*0.12, volt);
}

void trayControlled(int dir, double speed, double dist){
  Tilter.startRotateFor(dist*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
}

double getTilter(){
  return Tilter.rotation(rotationUnits::deg);
}

void trayCoast(){
  Tilter.stop(coast);
}

void trayBrake(){
  Tilter.stop(hold);
}

void trayEncoder(int dir, double speed, double dist){
  Tilter.resetRotation();
  while (abs(Tilter.rotation(rotationUnits::deg)) < dist){
    Tilter.spin(fwd, dir*speed*0.12, volt);
  }
  Tilter.stop();
}

int trayP(int speed, double dist, double targetDist){
  Tilter.resetRotation();
  while (abs(getTilter()) < dist){
    double error = targetDist - Tilter.rotation(rotationUnits::deg);
    double traySpeed = 0.0011*error;
    tray(TILT, traySpeed*speed);
  }
  trayBrake();
  return 0;
}

void trayTime(int dir, int speed,  double waitTime){
  tray(dir, speed);
  wait(waitTime, msec);
  trayBrake();
}

int getTrayLimit(){
  if (TrayLimit.pressing()){
    return 1;
  }
  else{
    return 0;
  }
}