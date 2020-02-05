#include "vex.h"
using namespace vex;

double inchesConversion = 20.34;
double degConversion = 2;

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
  while (FLWheel.isSpinning()){
    wait(1, msec);
  }
  driveBrake();
  return 0;
}

int turnEncoder(int dir, double speed, double dist){
  double deg = dist*degConversion;
  FLWheel.startRotateFor(-1*deg*dir, rotationUnits::deg, -1*speed*dir, velocityUnits::pct);
  FRWheel.startRotateFor(deg*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  BLWheel.startRotateFor(-1*deg*dir, rotationUnits::deg, -1*speed*dir, velocityUnits::pct);
  BRWheel.startRotateFor(deg*dir, rotationUnits::deg, speed*dir, velocityUnits::pct);
  while (FLWheel.isSpinning() || FRWheel.isSpinning()){
    wait(1, msec);
  }
  driveBrake();
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

//drive time
void driveTime(int dir, double speed, double timeVal){
  setDrive(speed*dir, speed*dir);
  wait(timeVal, msec);
  driveBrake();
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

void swing(double speedL, double speedR, double distL, double distR){
  while ((abs(getDriveL()) < distL) || (abs(getDriveR()) < distR)){
    setDrive(speedL, speedR);
  }
  driveBrake();
}

void swingEncoder(double speedL, double speedR, double distL, double distR){
  double inchesL = distL*inchesConversion;
  double inchesR = distL*inchesConversion;
  FLWheel.startRotateFor(inchesL, rotationUnits::deg, speedL, velocityUnits::pct);
  FRWheel.startRotateFor(inchesR, rotationUnits::deg, speedR, velocityUnits::pct);
  BLWheel.startRotateFor(inchesL, rotationUnits::deg, speedL, velocityUnits::pct);
  BRWheel.startRotateFor(inchesR, rotationUnits::deg, speedR, velocityUnits::pct);
  while ((FLWheel.isSpinning())||(FRWheel.isSpinning())){
    wait(1, msec);
  }
}

int goP(int dir, double speed, double dist, double speedCut){
  driveReset();
  double speedP = speed/100;
  double deg = dist*inchesConversion;
  double speedCutInches = speedCut*inchesConversion;
  double kP = 0.2;
  double error = 1;
  double pVal = speed;
  while (abs(getDrive()) < deg){
    if (abs(getDrive()) <= speedCutInches){
      error = deg - abs(getDrive());
      pVal = kP*error*speedP;
    }
    setDrive(pVal*dir, pVal*dir);
  }
  driveBrake();
  return 0;
}

int turnP(int dir, double speed, double dist, double speedCut){
  driveReset();
  double speedP = speed/100;
  double deg = dist*degConversion;
  double speedCutDeg = speedCut*degConversion;
  double kP = 1;
  double error = 1;
  double pVal = speed;
  while ((abs(getDriveL()) < deg) || (abs(getDriveR()) < deg)){
    if ((abs(getDriveL()) < speedCutDeg) || (abs(getDriveR()) < speedCutDeg)){
      error = ((deg - abs(getDriveL())) + (deg - abs(getDriveR())))/2;
      pVal = kP*error*speedP;
    }
    setDrive(-1*pVal*dir, pVal*dir);
  }
  driveBrake();
  return 0;
}

int swingP(double speedL, double speedR, double distL, double distR, double maxErrorL, double maxErrorR){
  driveReset();
  double speedPL = speedL/100;
  double speedPR = speedR/100;
  double degL = distL*inchesConversion;
  double degR = distR*inchesConversion;
  double maxErrorInchL = maxErrorL*inchesConversion;
  double maxErrorInchR = maxErrorR*inchesConversion;
  double kP = 0.2;
  while ((abs(getDriveL()) < degL - maxErrorInchL) || (abs(getDriveR()) < degR - maxErrorInchR)){
    double errorL = degL - abs(getDriveL());
    double errorR = degR - abs(getDriveR());
    double pValL = kP*errorL*speedPL;
    double pValR = kP*errorR*speedPR;
    setDrive(pValL, pValR);
  }
  driveBrake();
  return 0;
}

int goPStop(int dir, double speed, double dist, double maxError){
  driveReset();
  double speedP = speed/100;
  double deg = dist*inchesConversion;
  double maxErrorInch = maxError*inchesConversion;
  double kP = 0.2;
  while (abs(getDrive()) < deg - maxErrorInch){
    double error = deg - abs(getDrive());
    double pVal = kP*error*speedP;
    setDrive(pVal*dir, pVal*dir);
  }
  driveBrake();
  return 0;
}

int turnPStop(int dir, double speed, double dist, double maxError){
  driveReset();
  double speedP = speed/100;
  double deg = dist*degConversion;
  double maxErrorDeg = maxError*degConversion;
  double kP = 0.5;
  while ((abs(getDriveL()) < deg - maxErrorDeg) || (abs(getDriveR()) < deg - maxErrorDeg)){
    double error = ((deg - abs(getDriveL())) + (deg - abs(getDriveR())))/2;
    double pVal = kP*error*speedP;
    setDrive(-1*pVal*dir, pVal*dir);
  }
  driveBrake();
  return 0;
}