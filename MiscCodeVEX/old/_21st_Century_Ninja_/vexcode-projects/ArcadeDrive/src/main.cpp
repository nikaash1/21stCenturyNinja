//Test code for arcade drive controls and some tests with VexCode (not VCS)


#include "robot-config.h"
#include <string>
#include <cmath>


vex::competition    Competition;
using namespace std;



float stickdead = 6;
int brakeVar = 0;

#define FORWARD 1
#define BACKWARD -1
#define REVERSE -1
#define FAST 200
#define MEDIUM 100
#define SLOW 50
#define OLDVEX 127
#define LEFT 1
#define RIGHT -1
#define RIGHT_AXIS_Y 2
#define LEFT_AXIS_Y 3
#define RIGHT_AXIS_X 1
#define LEFT_AXIS_X 4




int getAxisValue(int axis){
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
    return 0;
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

void basebrake (int time){
    vex::task::sleep(time);
    Lwheel.stop(vex::brakeType::hold);
    Lwheel2.stop(vex::brakeType::hold);
    Rwheel.stop(vex::brakeType::hold);
    Rwheel2.stop(vex::brakeType::hold);
}

void baseunbrake (int time){
    vex::task::sleep(time);
    Lwheel.stop(vex::brakeType::coast);
    Lwheel2.stop(vex::brakeType::coast);
    Rwheel.stop(vex::brakeType::coast);
    Rwheel2.stop(vex::brakeType::coast);
}



/*void flywheelpid (int direction, int speed, int degrees){
    int rotations = (360*degrees)/15;
    
}
*/

void govolt(float direction, float speed, float time){
    
    LB.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);  
    LF.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    RB.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);  
    RF.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    wait(time);
    
}


void setDriveRight(float speed){
    
    RB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
    RF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);

    
}

void setDriveLeft(float speed){
    
    LB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
    LF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);
   
    
}

void setDriveStraight(float speed){

  RB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
  RF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);
  LB.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);  
  LF.spin(vex::directionType::fwd, 0.12*speed, vex::voltageUnits::volt);

}




void pre_auton( void ) {
  
}


void autonomous( void ) {
}


void usercontrol( void ) {
  // User control code here, inside the loop
      

    while (1){
     
         setDriveLeft(getAxisValue(RIGHT_AXIS_Y));
         setDriveRight(getAxisValue(RIGHT_AXIS_Y));
         setDriveLeft(getAxisValue(-1*LEFT_AXIS_X));
         setDriveRight(getAxisValue(LEFT_AXIS_X));


        //brake
      if ((Controller1.ButtonY.pressing())&&(brakeVar == 0)){
         brakeVar = 1;
          
          
        Lwheel.stop(vex::brakeType::hold);
        Rwheel.stop(vex::brakeType::hold);
        Lwheel2.stop(vex::brakeType::hold);
        Rwheel2.stop(vex::brakeType::hold);
        vex::task::sleep(300);
         
          
       
       
       
      }
      
    
      
      if ((Controller1.ButtonY.pressing())&&(brakeVar == 1)){
          Lwheel.stop(vex::brakeType::coast);
          Rwheel.stop(vex::brakeType::coast);
          Lwheel2.stop(vex::brakeType::coast);
          Rwheel2.stop(vex::brakeType::coast);
          vex::task::sleep(300);
         
          brakeVar = 0;
          

        
        
      
}     
   
      
      
      
 
    vex::task::sleep(15); //Sleep the task for a short amount of time to prevent wasted resources. 
  
}
}



int main() {

    pre_auton();
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
            while (true){
              if (RF.temperature(vex::percentUnits::pct) >= 40){
                  Controller1.rumble("-");
              }
              if (RB.temperature(vex::percentUnits::pct) >= 40){
                  Controller1.rumble("-");
              }
              if (LF.temperature(vex::percentUnits::pct) >= 40){
                  Controller1.rumble("-");
              }
              if (LB.temperature(vex::percentUnits::pct) >= 40){
                  Controller1.rumble("-");
              }
        }

}
