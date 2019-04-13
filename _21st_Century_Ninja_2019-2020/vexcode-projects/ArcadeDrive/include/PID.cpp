//#include "robot-config.h"
#include "Commands.cpp"
#include <string>
#include <cmath>

using namespace std;

double error;
double desiredValue;
double pVal;
double iVal;
double dVal;
double sensorPosition;
double sensorVelocity;



double getSensorPos(){
  return (RF.rotation(rotationUnits::deg)+RB.rotation(rotationUnits::deg)+LF.rotation(rotationUnits::deg)+LB.rotation(rotationUnits::deg))/4;
}

double getSensorVelocity(){
  return (RF.velocity(velocityUnits::dps)+RB.velocity(velocityUnits::dps)+LF.velocity(velocityUnits::dps)+LB.velocity(velocityUnits::dps))/4;
}

void calculatePID(double kP, double kI, double kD, double minErrorI, double maxErrorI, double maxPowerI, double acceptableError, double acceptableVelocity){

  error = 0;
  desiredValue = 0;
  pVal = 0;
  iVal = 0;
  dVal = 0;

  //calculate PID values
  sensorPosition = getSensorPos();
  sensorVelocity = getSensorVelocity();
  error = desiredValue - sensorPosition;

  //calculate P
  pVal = error;

  //add newest I value
  if((abs(error)>=minErrorI)&&(abs(error)<=maxErrorI)){
    iVal += error;
  }

  else if (abs(error)<=minErrorI){
    iVal = 0;
  }

  //calculate D
  dVal = sensorVelocity;

}

void turnPID(){

}

void straightPID(){

}