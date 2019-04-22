//#include "robot-config.h"
#include "PID.cpp"
#include <string>
#include <cmath>

double speed1;

float stickDead = 6;
int brakeVar = 0;
double turnSpeed = 1;
double straightSpeed = 0.92;
double autoCol;
double autoPos;


#define FORWARD 1
#define BACKWARD -1
#define REVERSE -1
#define FAST 200
#define MEDIUM 100
#define SLOW 50
#define OLDVEX 127
#define LEFT 1
#define RIGHT -1
#define RED 0
#define BLUE 1
#define RIGHT_AXIS_Y 2
#define LEFT_AXIS_Y 3
#define RIGHT_AXIS_X 1
#define LEFT_AXIS_X 4
//int autoCol = 0;
//int autoNum = 0;

//functions

double getAnalog(int axis){
  if (axis  == 1){
    return Controller1.Axis1.value();
  }
  if (axis == 2){
    return Controller1.Axis2.value();
  }
  if (axis == 3){
    return Controller1.Axis3.value();
  }
  if (axis == 4){
    return Controller1.Axis4.value();
  }
  else{
    return 100;
  }

}

void wait (int time){
    vex::task::sleep(time);
}

void stopall(int time){
    vex::task::sleep(time);
    Lwheel.stop();
    Rwheel.stop();
    Lwheel2.stop();
    Rwheel2.stop();
    
}

void baseBrakeHold (int time){
    vex::task::sleep(time);
    Lwheel.stop(vex::brakeType::hold);
    Lwheel2.stop(vex::brakeType::hold);
    Rwheel.stop(vex::brakeType::hold);
    Rwheel2.stop(vex::brakeType::hold);
}

void baseBrakeCoast (int time){
    vex::task::sleep(time);
    Lwheel.stop(vex::brakeType::coast);
    Lwheel2.stop(vex::brakeType::coast);
    Rwheel.stop(vex::brakeType::coast);
    Rwheel2.stop(vex::brakeType::coast);
}


void govolt(float direction, float speed, float time){
    
    LB.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);  
    LF.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    RB.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);  
    RF.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    wait(time);
    
}


void setDriveRight(double speed){
    
    RB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
    RF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);

    
}

void setDriveLeft(double speed){
    
    LB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
    LF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);
   
    
}

void setDriveStraight(double speed){

  RB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
  RF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);
  LB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
  LF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);

}

void driveStraightEncoders(int direction, double speed, double degrees){

  Lwheel.startRotateFor(direction*degrees, rotationUnits::deg, direction*speed, velocityUnits::rpm);
  Lwheel2.startRotateFor(direction*degrees, rotationUnits::deg, direction*speed, velocityUnits::rpm);
  Rwheel.startRotateFor(direction*degrees, rotationUnits::deg, direction*speed, velocityUnits::rpm);
  Rwheel2.startRotateFor(direction*degrees, rotationUnits::deg, direction*speed, velocityUnits::rpm);

  /*Lwheel.stop();
  Lwheel2.stop();
  Rwheel.stop();
  Rwheel2.stop();*/

}

void stopDriveLeft(){

  //wait(time);
  LB.stop(brakeType::hold);
  LF.stop(brakeType::hold);

}

void stopDriveRight(){

  //wait(time);
  RB.stop(brakeType::hold);
  RF.stop(brakeType::hold);

}

void stopDrive(double time){

  wait(time);
  stopDriveLeft();
  stopDriveRight();

}


void spinEncoder(int direction, double speed, double degrees){


  
  while(getSensorPos()<degrees){
    RB.spin(vex::directionType::fwd, direction*0.12*speed, vex::voltageUnits::volt);  
    RF.spin(vex::directionType::fwd, direction*0.12*speed, vex::voltageUnits::volt);
    LB.spin(vex::directionType::fwd, direction*0.12*speed, vex::voltageUnits::volt);  
    LF.spin(vex::directionType::fwd, direction*0.12*speed, vex::voltageUnits::volt);
  }

  Lwheel.stop();
  Lwheel2.stop();
  Rwheel.stop();
  Rwheel2.stop();



}

void straightPID(int direction, double speed, double degrees){

  double inches = degrees*28.5;
  error = 1;
  while (abs(error) > 0){
  speed = calculatePID(2, 1, 0.01, 0.2*inches, 0.8*inches, 1, inches);
  setDriveStraight(direction*speed);

  while((Rwheel.isSpinning())||(Lwheel.isSpinning())){
    wait(1);
  }

  stopDrive(0);
  }
}

void turnPID(){



}

void yieldaction(int time){
  int i = 0;
  while (i < time){
    task::sleep(1);
    i++;
  }

  i = 0;
}


double PLoop(double d1, double d2, double d3, double speed){
  double sensorPos = getSensorPos();
  error = (d1+d2+d3) - sensorPos;
  //speed2 = speed1;
  if (sensorPos <= d1){
    double x = (sensorPos+10)/d1;
    double setspeed = speed*x;
    speed1 = setspeed;
    return setspeed;
  }

  if ((sensorPos > d1)&&(sensorPos <= d1+d2)){
    double setspeed = speed;
    speed1 = setspeed;
    return setspeed;
  }

  if ((sensorPos > d1+d2)){
    double y = 1 - (sensorPos-(d1+d2));
    double setspeed = speed*y;
    speed1 = setspeed;
    return setspeed;
  }

  else{
    return 200;
  }

/*else{
  return 0;
}*/
 

}

void runP(double d1, double d2, double d3, double speed){

  
  do{
    PLoop(d1, d2, d3, speed);
  }
  while (getSensorPos()< (d1+d2+d3));

}

void goP(){
  driveStraightEncoders(1, PLoop(200, 200, 200, 200), 600);
}

//this will be the input for color argument within runAuto function (this is probably a lie)
void autoColorSelect(){
  //int autoCol = 0;
    if (Brain.Screen.pressing()){
        if (autoCol == 0){
          autoCol = 1;
        }
        else if (autoCol == 1){
          autoCol = 0;
        }
      }
  //return autoCol;
}

//this will be the input for number argument within runAuto function (this is also probably not true)
void autoPositionSelect(){
  //double autoNum = 0;
  //return autoNum;

}


int autoColorReturn(){
  return autoCol;
}

int autoPositionReturn(){
  return autoPos;
}


//AUTONOMOUS COMMAND
void runAuto(int autoColor, int autoNumber, bool running){
  if (running){
  //red
    if (autoColor == 0){
      Brain.Screen.drawRectangle(15, 15, 50, 50, red);
      if (autoNumber == 1){

        straightPID(1, 1, 24);

      }
      if (autoNumber == 2){


      }
      if (autoNumber == 3){

      }
      if (autoNumber == 4){

      }
    }

    //blue
    if (autoColor == 1){
      Brain.Screen.drawRectangle(15, 15, 50, 50, blue);
      if (autoNumber == 1){

      }
      if (autoNumber == 2){

      }
      if (autoNumber == 3){

      }
      if (autoNumber == 4){

      }
    }

  }

  else{



  }


}



