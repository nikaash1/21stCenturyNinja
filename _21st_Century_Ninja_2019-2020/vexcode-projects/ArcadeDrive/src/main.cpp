//Test code for arcade drive controls and some tests with VexCode (not VCS)


//#include "robot-config.h"
#include "PID.cpp"
//#include "Commands.cpp"
#include <string>
#include <cmath>


vex::competition    Competition;
using namespace std;

//variables
float stickDead = 6;
int brakeVar = 0;
double turnSpeed = 1;
double straightSpeed = 0.92;

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


void pre_auton( void ) {
  
}


void autonomous( void ) {

}


void usercontrol( void ) {

    while (1){

      //arcade drive
      setDriveLeft(straightSpeed*(getAnalog(LEFT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X)*-1)*turnSpeed);
      setDriveRight(straightSpeed*(getAnalog(LEFT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X)*turnSpeed));

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
              if (RF.temperature(vex::percentUnits::pct) >= 80){
                  Controller1.rumble("-");
              }
              if (RB.temperature(vex::percentUnits::pct) >= 80){
                  Controller1.rumble("-");
              }
              if (LF.temperature(vex::percentUnits::pct) >= 80){
                  Controller1.rumble("-");
              }
              if (LB.temperature(vex::percentUnits::pct) >= 80){
                  Controller1.rumble("-");
              }
        }

}
