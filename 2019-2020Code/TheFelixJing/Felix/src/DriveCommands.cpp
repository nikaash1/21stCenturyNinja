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