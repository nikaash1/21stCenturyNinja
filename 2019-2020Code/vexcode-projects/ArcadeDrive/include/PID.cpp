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

static double ILimit (double input1, double floor, double ceiling){
  if (input1<=floor)return floor;
  if (input1>=ceiling)return ceiling;
  return input1;
}


 //calculate PID values
double calculatePID(double kP, double kI, double kD, double minErrorI, double maxErrorI, double maxPowerI, double acceptableError, double acceptableVelocity){

  error = 0;
  desiredValue = 0;
  pVal = 0;
  iVal = 0;
  dVal = 0;



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

  return pVal*kP+ILimit(iVal*kI, -maxPowerI, maxPowerI)+dVal*kD;

}

void incrementDesiredValue(double value){desiredValue += value;}
void setDesiredValue(double value){desiredValue = value;}
double getDesiredValue(){return desiredValue;}

/*double getMotorPower(){
    return calculatePID();
}*/

void turnPID(){

}

void straightPID(){

}