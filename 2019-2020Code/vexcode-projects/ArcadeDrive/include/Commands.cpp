//#include "robot-config.h"
#include "PID.cpp"
#include <string>
#include <cmath>

double speed1;

float stickDead = 6;
int brakeVar = 0;
double turnSpeed = 1;
double straightSpeed = 0.92;
double hSpeed = 1;
double mechSpeed = 1;
double inchConvertVal = 28.5;
double degreeConvertVal = 1;
double autoCol;
double autoPos;


#define FORWARD 1
#define BACKWARD -1
#define REVERSE -1
#define FAST 200
#define MEDIUM 100
#define SLOW 50
#define ROBOTCFAST 127
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

//get joystick values
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

//task sleep shortcut (wait1Msec())
void wait(int time){
    vex::task::sleep(time);
}

//artificial yield example
void yieldaction(int time){
  int i = 0;
  while (i < time){
    task::sleep(1);
    i++;
  }

  i = 0;
}


//DRIVE COMMANDS

//stops drive
void stopall(int time){
    vex::task::sleep(time);
    Lwheel.stop();
    Rwheel.stop();
    Lwheel2.stop();
    Rwheel2.stop();
    
}
//activates brake type hold
void baseBrakeHold (int time){
    vex::task::sleep(time);
    Lwheel.stop(vex::brakeType::hold);
    Lwheel2.stop(vex::brakeType::hold);
    Rwheel.stop(vex::brakeType::hold);
    Rwheel2.stop(vex::brakeType::hold);
}
//sets base motors to coast
void baseBrakeCoast (int time){
    vex::task::sleep(time);
    Lwheel.stop(vex::brakeType::coast);
    Lwheel2.stop(vex::brakeType::coast);
    Rwheel.stop(vex::brakeType::coast);
    Rwheel2.stop(vex::brakeType::coast);
}
//go straight using voltage (-12 to 12)
void govolt(float direction, float speed, float time){
    LB.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);  
    LF.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    RB.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);  
    RF.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    wait(time);
}

//USER CONTROL DRIVE COMMANDS
//right side of drive voltage (-100 to 100)
void setDriveRight(double speed){ 
    RB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
    RF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt); 
}
//left side of drive voltage (-100 to 100)
void setDriveLeft(double speed){
    LB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
    LF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);
}
//runs center H wheel with voltage assuming H-Drive (-100 to 100)
void setDriveH(double speed){
  MH.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);
}
//use with mechanum drive to strafe voltage (-100 to 100)
void strafeMech(double speed){
  LB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
  LF.spin(vex::directionType::fwd, -1*0.12*speed, vex::voltageUnits::volt);
  RB.spin(vex::directionType::fwd, -1*0.12*speed, vex::voltageUnits::volt);  
  RF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);
}
//drive straight voltage (-100 to 100)
void setDriveStraight(double speed){
  RB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
  RF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);
  LB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
  LF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);
}
//set each side of drive voltage (-100 to 100)
void setDrive(double leftspeed, double rightspeed){
  RB.spin(vex::directionType::fwd, 0.12*rightspeed, vex::voltageUnits::volt);  
  RF.spin(vex::directionType::fwd, 0.12*rightspeed, vex::voltageUnits::volt);
  LB.spin(vex::directionType::fwd, 0.12*leftspeed, vex::voltageUnits::volt);  
  LF.spin(vex::directionType::fwd, 0.12*leftspeed, vex::voltageUnits::volt);
}


//OTHER DRIVE COMMANDS
//this section needs to be cleaned up

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
  LB.stop(brakeType::hold);
  LF.stop(brakeType::hold);
}
void stopDriveRight(){
  RB.stop(brakeType::hold);
  RF.stop(brakeType::hold);
}
void stopDriveH(){
  MH.stop(brakeType::hold);
}
void stopDriveFull(double time){
  wait(time);
  stopDriveLeft();
  stopDriveRight();
  stopDriveH();
}
void stopDrive(int time){
  wait(time);
  stopDriveLeft();
  stopDriveRight();
}
void spinEncoder(int direction, double speed, double degrees){
  while(abs(getSensorPos())<abs(degrees)){
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


//PID COMMANDS
//go straight with PID
void straightPID(int direction, double speed, double degrees){
  double inches = degrees*inchConvertVal;
  double motorSpeed;
  while ((getSensorPos()) < abs(inches)){
    motorSpeed = calculatePID(2, 1, 0.01, 0.2*inches, 0.8*inches, 1, inches);
    setDriveStraight(direction*motorSpeed*speed);
  }
}
//turn with PID
void turnPID(int direction, double speed, double degrees){
  double turnDegrees = degrees*degreeConvertVal;
  double motorSpeed;
  while ((getSensorPos())<abs(turnDegrees)){
    motorSpeed = motorSpeed = calculatePID(2, 1, 0.01, 0.2*turnDegrees, 0.8*turnDegrees, 1, turnDegrees);
    setDrive(speed*direction*motorSpeed,speed*direction*motorSpeed*-1);
  }

}




//OTHER SUBSYSTEMS

void intakeSpin(double direction, double speed){
  Intake.spin(vex::directionType::fwd, direction*speed, vex::velocityUnits::rpm);
}

void intakeStop(){
  Intake.stop();
}


//AUTO INIT COMMANDS

//this will be the input for color argument within runAuto function (this is probably a lie)
void autoColorSelect(){
  //int autoCol = 0;
    //if (Brain.Screen.pressing()){
        if (autoCol == 0){
          wait(200);
          autoCol = 1;
          Brain.Screen.drawRectangle(15, 15, 50, 50, blue);
        }
        else if (autoCol == 1){
          wait(200);
          Brain.Screen.drawRectangle(15, 15, 50, 50, red);
          autoCol = 0;
        }
        
      //}
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


//auto selection
void runAuto(int autoColor, int autoNumber, bool running){
  if (running){
  //red
    if (autoColor == 0){
      
      if (autoNumber == 1){

        //straightPID(1, 1, 24);
        //goP();

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



