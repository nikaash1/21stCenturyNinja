#include "RobotMap.h"
//#include "Commands.cpp"
#include <string>
#include <cmath>

using namespace std;




/*double error;
double desiredValue;
double pVal;
double iVal;
double dVal;
double driveSensorPosition;
double sensorVelocity;
*/

double globalDesiredValue;

double getLUp(){
  return (LUp.rotation(rotationUnits::deg));
}
double getRUp(){
  return (RUp.rotation(rotationUnits::deg));
}
double getUp(){
  return ((RUp.rotation(rotationUnits::deg))+(LUp.rotation(rotationUnits::deg)))/2;
}
double getIntake(){
  return (Intake.rotation(rotationUnits::deg));
}
void resetUp(){
  RUp.resetRotation();
  LUp.resetRotation();
}
void resetIntake(){
  Intake.resetRotation();
}


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
  globalDesiredValue = desiredValue;
  double pVal;
  double iVal;
  double dVal;



  double driveSensorPosition = getSensorPos();
  //double driveSensorVelocity = getSensorVelocity();
  error = desiredValue - driveSensorPosition;

  //calculate P
  pVal = error;
  //pVal = 200; //pVal = error

  //add newest I value
  iVal = 0;
  if((abs(error)>=minErrorI)&&(abs(error)<=maxErrorI)){
    iVal += error;
  }
  else if (abs(error)<=minErrorI){
    iVal = 0;
  }
  //calculate I
  double integral = ILimit(iVal*kI, -maxPowerI, maxPowerI);

  //calculate D
  dVal = (abs(driveSensorPosition))/driveSensorPosition;

  return (pVal*kP)+(integral)+(dVal*kD);

}

void incrementDesiredValue(double value){globalDesiredValue += value;}
void setDesiredValue(double value){globalDesiredValue = value;}
double getDesiredValue(){return globalDesiredValue;}

double getMotorPower(double kP, double kI, double kD, double minErrorI, double maxErrorI, double maxPowerI, double desiredValue){
    return calculatePID(kP, kI, kD, minErrorI, maxErrorI,maxPowerI,desiredValue);
}
















































//NEWER ITERATION OF PID TO ADD LATER

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

























