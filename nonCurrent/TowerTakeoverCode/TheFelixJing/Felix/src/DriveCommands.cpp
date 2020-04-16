#include "vex.h"
using namespace vex;

//get drive encoders
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
  FRWheel.spin(fwd, 0.12*rSpeed, volt);
  BRWheel.spin(fwd, 0.12*rSpeed, volt);
}

//set each drive motor (voltage)
void setDriveFull(double flSpeed, double blSpeed, double frSpeed, double brSpeed){
  FLWheel.spin(fwd, 0.12*flSpeed, volt);
  BLWheel.spin(fwd, 0.12*blSpeed, volt);
  FRWheel.spin(fwd, 0.12*frSpeed, volt);
  BRWheel.spin(fwd, 0.12*brSpeed, volt);
}

int driveEncoder(int dir, double speed, double dist){
  double inches = dist*20.34;
  FLWheel.startRotateFor(inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  FRWheel.startRotateFor(inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  BLWheel.startRotateFor(inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  BRWheel.startRotateFor(inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  return 0;
}

int turnEncoder(int dir, double speed, double dist){
  double deg = dist*3.75;
  FLWheel.startRotateFor(-1*deg*dir, rotationUnits::deg, -1*speed*dir, velocityUnits::pct);
  FRWheel.startRotateFor(deg*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  BLWheel.startRotateFor(-1*deg*dir, rotationUnits::deg, -1*speed*dir, velocityUnits::pct);
  BRWheel.startRotateFor(deg*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  return 0;
}

int strafeEncoder(int dir, double speed, double dist){
  double inches = dist*20.34;
  FLWheel.startRotateFor(-1*inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  FRWheel.startRotateFor(inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  BLWheel.startRotateFor(inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  BRWheel.startRotateFor(-1*inches*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  return 0;
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

//drive encoder commands
void driveStraight(int dir, double speed, double dist){
  while (abs(getDrive()) < dist){
    setDrive(speed, speed);
  }
}
void driveTurn(int dir, double speed, double dist){
  while (abs(getDrive()) < dist){
    setDrive(-1*speed, speed);
  }
}
void driveStrafe(int dir, double speed, double dist){
  while (abs(getDrive()) < dist){
    
  }
}