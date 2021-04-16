#include "vex.h"
using namespace vex;

double inchesConversion = 30*(7/3);
double degConversion = 3.5*(7/3);

//drive encoders
double getDriveFL(){
  return FLWheel.rotation(deg);
}
double getDriveFR(){
  return FRWheel.rotation(deg);
}
double getDriveBL(){
  return BLWheel.rotation(deg);
}
double getDriveBR(){
  return BRWheel.rotation(deg);
}
double getDriveR(){
  double rot = (getDriveFR() + getDriveBR())/2;
  return rot;
}
double getDriveL(){
  double rot = (getDriveFL() + getDriveBL())/2;
  return rot;
}
double getDriveF(){
  double rot = (getDriveFR() + getDriveFL())/2;
  return rot;
}
double getDriveB(){
  double rot = (getDriveBR() + getDriveBL())/2;
  return rot;
}
double getDrive(){
  double rot = (getDriveFL() + getDriveFR() + getDriveBL() + getDriveBR())/4;
  return rot;
}

void driveReset(){
  FLWheel.resetRotation();
  FRWheel.resetRotation();
  BLWheel.resetRotation();
  BRWheel.resetRotation();
}

//get heat of drive motors
double getHeatFL(){
  return FLWheel.temperature(pct);
}
double getHeatFR(){
  return FLWheel.temperature(pct);
}
double getHeatBL(){
  return FLWheel.temperature(pct);
}
double getHeatBR(){
  return FLWheel.temperature(pct);
}

//set each side of drive (voltage)
void setDrive(double lSpeed, double rSpeed){
  FLWheel.spin(fwd, 0.12*lSpeed, volt);
  BLWheel.spin(fwd, 0.12*lSpeed, volt);
  MLWheel.spin(fwd, 0.12*lSpeed, volt);
  FRWheel.spin(fwd, 0.12*rSpeed, volt);
  BRWheel.spin(fwd, 0.12*rSpeed, volt);
  MRWheel.spin(fwd, 0.12*rSpeed, volt);
}

//set each drive motor (voltage)
void setDriveFull(double flSpeed, double blSpeed, double frSpeed, double brSpeed){
  FLWheel.spin(fwd, 0.12*flSpeed, volt);
  BLWheel.spin(fwd, 0.12*blSpeed, volt);
  FRWheel.spin(fwd, 0.12*frSpeed, volt);
  BRWheel.spin(fwd, 0.12*brSpeed, volt);
}

//individual motor speeds (voltage)
void setFL(double speed){
  FLWheel.spin(fwd, 0.12*speed, volt);
}
void setFR(double speed){
  FRWheel.spin(fwd, 0.12*speed, volt);
}
void setBL(double speed){
  BLWheel.spin(fwd, 0.12*speed, volt);
}
void setBR(double speed){
  BRWheel.spin(fwd, 0.12*speed, volt);
}

//drive stop commands
void driveBrake(){
  FLWheel.stop(hold);
  BLWheel.stop(hold);
  FRWheel.stop(hold);
  BRWheel.stop(hold);
}
void driveCoast(){
  FLWheel.stop(coast);
  BLWheel.stop(coast);
  FRWheel.stop(coast);
  BRWheel.stop(coast);
}

//drive time
void driveTime(int dir, double speed, double timeVal){
  setDrive(speed*dir, speed*dir);
  wait(timeVal, msec);
  driveBrake();
}
void setDriveTime(double speedL, double speedR, double timeVal){
  setDrive(speedL, speedR);
  wait(timeVal, msec);
  driveBrake();
}

//P+ Loops
int goP(int dir, double initSpeed, double speed, double dist, double speedStart, double speedCut, double slowFactor, bool smooth){
  driveReset();
  double speedP = speed/100;
  double targetVal = dist*inchesConversion;
  double speedStartInches = speedStart*inchesConversion;
  double speedCutInches = speedCut*inchesConversion;
  double kP = 100/targetVal;
  double kP2 = 3;
  double kPSlow = slowFactor/100;
  double error = 1;
  double driftError = 0;
  double pVal = initSpeed;
  double finalPower = speed;
  double speedSmooth;
  if (smooth){
    speedSmooth = speedStartInches;
  }
  else{
    speedSmooth = 0;
  }
  while (abs(getDrive()) < targetVal){
    if ((abs(getDrive()) <= speedCutInches) && (abs(getDrive()) > speedStartInches)){
      error = (targetVal + speedSmooth) - (abs(getDrive())*kPSlow);
      pVal = kP*error*speedP;
    }
    finalPower = pVal*dir;
    driftError = (getDriveR() - getDriveL())*kP2*(finalPower)/100;
    setDrive((pVal + driftError)*dir, (pVal - driftError)*dir);
  }
  driveBrake();
  return 0;
}

int turnP(int dir, double initSpeed, double speed, double dist, double speedStart, double speedCut, double slowFactor, bool smooth){
  driveReset();
  double speedP = speed/100;
  double targetVal = dist*degConversion;
  double speedStartDeg = speedStart*degConversion;
  double speedCutDeg = speedCut*degConversion;
  double kP = 100/targetVal;
  double kPSlow = slowFactor/100;
  double error = 1;
  double pVal = initSpeed;
  double speedSmooth;
  if (smooth){
    speedSmooth = speedStartDeg;
  }
  else{
    speedSmooth = 0;
  }
  while ((abs(getDriveL()) < targetVal) && (abs(getDriveR()) < targetVal)){
    if (((abs(getDriveL()) <= speedCutDeg) || (abs(getDriveR()) <= speedCutDeg)) && ((abs(getDriveL()) > speedStartDeg) || (abs(getDriveR()) > speedStartDeg))){
      error = (((targetVal + speedSmooth) - (abs(getDriveL())*kPSlow)) + ((targetVal + speedSmooth) - (abs(getDriveR())*kPSlow)))/2;
      pVal = kP*error*speedP;
    }
    setDrive(-1*pVal*dir, pVal*dir);
  }
  driveBrake();
  return 0;
}
