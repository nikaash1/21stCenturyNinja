#include "robot-config.h"
//#include "Commands.cpp"
#include <string>
#include <cmath>

using namespace std;




double error;
double desiredValue;
double pVal;
double iVal;
double dVal;
double driveSensorPosition;
double sensorVelocity;





double getSensorPos(){
  return (Rwheel.rotation(rotationUnits::deg)+Rwheel2.rotation(rotationUnits::deg)+Lwheel2.rotation(rotationUnits::deg)+Lwheel.rotation(rotationUnits::deg))/4;
}

double getSensorVelocity(){
  return (Rwheel.velocity(velocityUnits::dps)+Rwheel2.velocity(velocityUnits::dps)+Lwheel.velocity(velocityUnits::dps)+Lwheel2.velocity(velocityUnits::dps))/4;
}

double ILimit (double input1, double floor, double ceiling){
  if (input1<=floor)return floor;
  if (input1>=ceiling)return ceiling;
  else{return input1;}
}


 //calculate PID values
double calculatePID(double kP, double kI, double kD, double minErrorI, double maxErrorI, double maxPowerI, double desiredValue/*double acceptableError, double acceptableVelocity*/){

  double error = 0;
  //desiredValue = 0;
  double pVal;
  //double iVal = 0;
  //double dVal = 0;



  driveSensorPosition = getSensorPos();
  //double sensorVelocity = getSensorVelocity();
  error = desiredValue - driveSensorPosition;

  //calculate P
  pVal = 200; //pVal = error

  //add newest I value
  /*if((abs(error)>=minErrorI)&&(abs(error)<=maxErrorI)){
    iVal += error;
  }

  else if (abs(error)<=minErrorI){
    iVal = 0;
  }*/

  //calculate D


  //dVal = (abs(sensorPosition))/sensorPosition;

  long integral = ILimit(iVal*kI, -maxPowerI, maxPowerI);


  return (pVal*kP)+(integral)+(dVal*kD);

}

void incrementDesiredValue(double value){desiredValue += value;}
void setDesiredValue(double value){desiredValue = value;}
double getDesiredValue(){return desiredValue;}

/*double getMotorPower(){
    return calculatePID();
}*/
















































//THIRD ITERATION OF PID TO ADD LATER

/*void PID(double thiskP, double thiskI, double thiskD, double thisminErrorI, 
  double thismaxErrorI, double thismaxPowerI, double thisacceptableError, double thisacceptableVelocity){

  

  thiskP = kP;
  thiskI = kI;
  thiskD = kD;
  thisminErrorI = minErrorI;
  thismaxErrorI = maxErrorI;
  thismaxPowerI = maxPowerI;

  desiredValue = 0;
  double thispVal = pVal;
  double thisiVal = iVal;
  double thisdVal = dVal;
  double thiserror = error;
  



  

  

}

double calculateP(){

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

}*/
