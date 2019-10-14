#include "robot-config.cpp"
#include <string>
#include <cmath>
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
vex::competition    Competition;
using namespace std;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Function                          */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/



int fly = 0;
int y = 0;
int z = 0;
int act = 0;
int breaker = 0;
int autof = 0;
int autoff = 0;
int auto_shot = 0;
int PID = 0;
float temp = 0;
int driver_start = 0;
float backshot = 0;
int shotTimer = 0;
float indexvar = 500;
float indexvar2 = 200;
float stickdead = 6;
#define FORWARD 1
#define BACKWARD -1
#define REVERSE -1
#define FAST 200
#define MEDIUM 100
#define SLOW 50
#define OLDVEX 127
#define LEFT 1
#define RIGHT -1
#define FLYSPEED 10.6
#define PI 3.14159265358979323846264338327950288419716939937510



void wait (int time){
    vex::task::sleep(time);
}


void movebase(int speed){
    Lwheel.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    Lwheel2.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    Rwheel2.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    Rwheel.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);


}

void turnbase(int speed, int direction){
    Lwheel.spin(vex::directionType::fwd,speed*-1*direction,vex::velocityUnits::rpm);
    Lwheel2.spin(vex::directionType::fwd,speed*-1*direction,vex::velocityUnits::rpm);
    Rwheel2.spin(vex::directionType::fwd,speed*1*direction,vex::velocityUnits::rpm);
    Rwheel.spin(vex::directionType::fwd,speed*1*direction,vex::velocityUnits::rpm);


}

void goo(int direction, int speed, float inches, int degrees2, int time){

    float degrees = 28.5*inches;
    Lwheel.startRotateFor(direction*degrees, vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    Rwheel.startRotateFor(direction*degrees, vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    Lwheel2.startRotateFor(direction*degrees, vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    Rwheel2.startRotateFor(direction*degrees, vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    while (((Lwheel.rotation(vex::rotationUnits::deg)) < abs(degrees2))&&((Lwheel2.rotation(vex::rotationUnits::deg)) < abs(degrees2))&&((Rwheel.rotation(vex::rotationUnits::deg)) < abs(degrees2))&&((Rwheel2.rotation(vex::rotationUnits::deg)) < abs(degrees2))){
    vex::task::sleep(1);
    }

    Lwheel.resetRotation();
    Lwheel2.resetRotation();
    Rwheel.resetRotation();
    Rwheel2.resetRotation();

    //task::sleep(time);
    //Lwheel.stop();
    //Rwheel.stop();
    //Lwheel2.stop();
    //Rwheel2.stop();
}



void turn(float direction, float degrees, float speed, float wait){

    float deg = abs(degrees*2*3.5);
    float Kp = 0.2;
    float Ki = 0.000005;
    float Kd = 0.84;
    int error;
    float proportion;
    int iraw;
    float integral;
    int finalerror;
    float derivative;
    const float iactivezone = 43;
    int FinalPower;
    bool TimerBool = true;
    if (wait < .25){
        wait = .25;
    }
    Lwheel.resetRotation();
    Rwheel.resetRotation();


    Brain.resetTimer();
     while(Brain.timer(vex::timeUnits::sec) < wait){
        error = deg - (Lwheel.rotation(vex::rotationUnits::deg)*-1*direction + Rwheel.rotation(vex::rotationUnits::deg)*1*direction);
	if ((error < iactivezone) && (error != 0)){
	    iraw = iraw + error;
	}
	else{
	    iraw = 0;
	}
        proportion = Kp * error;
        iraw = iraw + error;
        integral = Ki*iraw;
	    derivative = Kd*(error - finalerror);
    	finalerror = error;
        if (error == 0){
            derivative = 0;
    	}
        FinalPower = (proportion + integral+derivative)*speed; //proportion + integral + derivative

        turnbase(FinalPower, direction);


        if (abs(error) < 10){
            TimerBool = false;
        }
        if (TimerBool){
            Brain.resetTimer();

        }
    }
    Lwheel.stop(vex::brakeType::brake);
    Rwheel.stop(vex::brakeType::brake);
    Rwheel2.stop(vex::brakeType::brake);
    Lwheel2.stop(vex::brakeType::brake);
    vex::task::sleep(500);
    Lwheel.stop(vex::brakeType::coast);
    Rwheel.stop(vex::brakeType::coast);
    Rwheel2.stop(vex::brakeType::coast);
    Lwheel2.stop(vex::brakeType::coast);





}


void turnsmall(float direction, float degrees, float speed, float wait){
    float deg = abs(degrees*2*3.5);
    float Kp = 0.2;
    float Ki = 0.000005;
    float Kd = 0.84;
    int error;
    float proportion;
    int iraw;
    float integral;
    int finalerror;
    float derivative;
    const float iactivezone = 43;
    int FinalPower;
    bool TimerBool = true;
    if (wait < .25){
        wait = .25;
    }
    Lwheel.resetRotation();
    Rwheel.resetRotation();


    Brain.resetTimer();
     while(Brain.timer(vex::timeUnits::sec) < wait){
        error = deg - (Lwheel.rotation(vex::rotationUnits::deg)*-1*direction + Rwheel.rotation(vex::rotationUnits::deg)*1*direction);
	if ((error < iactivezone) && (error != 0)){
	    iraw = iraw + error;
	}
	else{
	    iraw = 0;
	}
        proportion = Kp * error;
        iraw = iraw + error;
        integral = Ki*iraw;
	    derivative = Kd*(error - finalerror);
    	finalerror = error;
        if (error == 0){
            derivative = 0;
    	}
        FinalPower = (proportion + integral+derivative)*speed; //proportion + integral + derivative

        turnbase(FinalPower, direction);


        if (abs(error) < 10){
            TimerBool = false;
        }
        if (TimerBool){
            Brain.resetTimer();

        }
    }
    Lwheel.stop(vex::brakeType::brake);
    Rwheel.stop(vex::brakeType::brake);
    Rwheel2.stop(vex::brakeType::brake);
    Lwheel2.stop(vex::brakeType::brake);
    vex::task::sleep(500);
    Lwheel.stop(vex::brakeType::coast);
    Rwheel.stop(vex::brakeType::coast);
    Rwheel2.stop(vex::brakeType::coast);
    Lwheel2.stop(vex::brakeType::coast);





}


void go (float degrees, float speed, float wait){
    float deg = abs(degrees*57);
    float Kp = 0.2;
    float Ki = 0.000005;
    float Kd = 0.84;
    int error;
    float proportion;
    int iraw;
    float integral;
    int finalerror;
    float derivative;
    const float iactivezone = 43;
    int FinalPower;

   int direction;
   if (degrees > 0){
       direction = 1;
   }
    else{
        direction = -1;
    }
    bool TimerBool = true;
    if (wait < .25){
        wait = .25;
    }
    Lwheel.resetRotation();
    Rwheel.resetRotation();


    Brain.resetTimer();
     while(Brain.timer(vex::timeUnits::sec) < wait){
        error = deg - abs((Lwheel.rotation(vex::rotationUnits::deg) + Rwheel.rotation(vex::rotationUnits::deg)));
	if ((error < iactivezone) && (error != 0)){
	    iraw = iraw + error;
	}
	else{
	    iraw = 0;
	}
        proportion = Kp * error;
        iraw = iraw + error;
        integral = Ki*iraw;
	    derivative = Kd*(error - finalerror);
    	finalerror = error;
        if (error == 0){
            derivative = 0;
    	}
        FinalPower = (proportion + integral+derivative)*speed*direction; //proportion + integral + derivative

        movebase(FinalPower);


        if (abs(error) < 40){
            TimerBool = false;
        }
        if (TimerBool){
            Brain.resetTimer();

        }
    }
    Lwheel.stop(vex::brakeType::brake);
    Rwheel.stop(vex::brakeType::brake);
    Rwheel2.stop(vex::brakeType::brake);
    Lwheel2.stop(vex::brakeType::brake);
    vex::task::sleep(50);
    Lwheel.stop(vex::brakeType::coast);
    Rwheel.stop(vex::brakeType::coast);
    Rwheel2.stop(vex::brakeType::coast);
    Lwheel2.stop(vex::brakeType::coast);
}







void movebasetime(int direction, int speed, int time){
    Lwheel.spin(vex::directionType::fwd,speed*direction,vex::velocityUnits::rpm);
    Lwheel2.spin(vex::directionType::fwd,speed*direction,vex::velocityUnits::rpm);
    Rwheel2.spin(vex::directionType::fwd,speed*direction,vex::velocityUnits::rpm);
    Rwheel.spin(vex::directionType::fwd,speed*direction,vex::velocityUnits::rpm);
    vex::task::sleep(time);
    Lwheel.stop();
    Lwheel2.stop();
    Rwheel.stop();
    Rwheel2.stop();


}

void turnbasetime(int direction, int speed, int time){
    Lwheel.spin(vex::directionType::fwd,-1*speed*direction,vex::velocityUnits::rpm);
    Lwheel2.spin(vex::directionType::fwd,-1*speed*direction,vex::velocityUnits::rpm);
    Rwheel2.spin(vex::directionType::fwd,speed*direction,vex::velocityUnits::rpm);
    Rwheel.spin(vex::directionType::fwd,speed*direction,vex::velocityUnits::rpm);
    vex::task::sleep(time);
    Lwheel.stop();
    Lwheel2.stop();
    Rwheel.stop();
    Rwheel2.stop();


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void basereset(){
    Lwheel.resetRotation();
    Lwheel2.resetRotation();
    Rwheel.resetRotation();
    Rwheel2.resetRotation();
}

void flywheelwstop (int direction, int speed, int time){
    Flywheel.spin(vex::directionType::fwd,direction*speed,vex::velocityUnits::rpm);
    vex::task::sleep(time);
    Flywheel.stop();
}

void flywheel (int direction, int speed, int time){
    Motor1.spin(vex::directionType::fwd,direction*speed,vex::voltageUnits::volt);
    Motor2.spin(vex::directionType::fwd,direction*speed,vex::voltageUnits::volt);
    vex::task::sleep(time);

}

void flywheelstop (int direction, int speed, int time){
    Motor1.stop();
    Motor2.stop();
    vex::task::sleep(time);

}

void intake (int direction, int speed, int time){
    Intake.spin(vex::directionType::fwd,direction*speed,vex::velocityUnits::rpm);
    vex::task::sleep(time);
    Intake.stop();
}

void intakenostop (int direction, int speed){
    Intake.spin(vex::directionType::fwd,direction*speed,vex::velocityUnits::rpm);
}


void actuator (int direction, int speed, int degrees){
    Actuator.startRotateFor(degrees,vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);

}

/*void go2 (int direction, float speed, float deg){
    float degrees = deg*57;


    if ((Lwheel.rotation(rotationUnits::deg)<abs(degrees*direction)&&(Rwheel.rotation(rotationUnits::deg)<abs(degrees*direction)))){
        Lwheel.spin(directionType::fwd,direction*speed,velocityUnits::rpm);
        Lwheel2.spin(directionType::fwd,direction*speed,velocityUnits::rpm);
        Rwheel.spin(directionType::fwd,direction*speed,velocityUnits::rpm);
        Rwheel2.spin(directionType::fwd,direction*speed,velocityUnits::rpm);
        Lwheel.resetRotation();
        Lwheel2.resetRotation();
        Rwheel.resetRotation();
        Rwheel2.resetRotation();
    }

    else{

    Lwheel.stop(brakeType::brake);
    Lwheel2.stop(brakeType::brake);
    Rwheel.stop(brakeType::brake);
    Rwheel2.stop(brakeType::brake);
    task::sleep(10);
    Lwheel.stop(brakeType::coast);
    Lwheel2.stop(brakeType::coast);
    Rwheel.stop(brakeType::coast);
    Rwheel2.stop(brakeType::coast);

    }
}

void turn2 (int direction, float speed, float deg){
    float degrees = deg*3.5;


    if ((Lwheel.rotation(rotationUnits::deg)<-1*degrees*direction)&&(Rwheel.rotation(rotationUnits::deg)<degrees*direction)){
        Lwheel.spin(directionType::fwd,-1*direction*speed,velocityUnits::rpm);
        Lwheel2.spin(directionType::fwd,-1*direction*speed,velocityUnits::rpm);
        Rwheel.spin(directionType::fwd,direction*speed,velocityUnits::rpm);
        Rwheel2.spin(directionType::fwd,direction*speed,velocityUnits::rpm);

    }

    else{

    Lwheel.stop();
    Rwheel.stop();
    Lwheel2.stop();
    Rwheel2.stop();

    }
    //task::sleep(time);

}*/

void turn1 (int direction, float speed, float deg){
    float degrees = deg*3.5;
    Lwheel.startRotateFor(-1*direction*degrees,vex::rotationUnits::deg,-1*direction*speed,vex::velocityUnits::rpm);
    Lwheel2.startRotateFor(-1*direction*degrees,vex::rotationUnits::deg,-1*direction*speed,vex::velocityUnits::rpm);
    Rwheel.startRotateFor(direction*degrees,vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    Rwheel2.startRotateFor(direction*degrees,vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);

    while ((Lwheel.isSpinning())&&(Rwheel.isSpinning)()){
          vex::task::sleep(1);
    }

    Lwheel.stop(vex::brakeType::brake);
    Rwheel.stop(vex::brakeType::brake);
    Rwheel2.stop(vex::brakeType::brake);
    Lwheel2.stop(vex::brakeType::brake);
    //task::sleep(time);

}

void go1 (int direction, float speed, float thing){
    float degrees = thing*28.5;
    Lwheel.startRotateFor(direction*degrees, vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    Lwheel2.startRotateFor(direction*degrees, vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    Rwheel.startRotateFor(direction*degrees, vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    Rwheel2.startRotateFor(direction*degrees, vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    //task::sleep(10);

    while ((Lwheel.isSpinning())&&(Rwheel.isSpinning)()){
          vex::task::sleep(1);
    }


    //task::sleep(time);

}


void autonshot (int time){
    //Actuator.setTimeout(1,timeUnits::sec);
    vex::task::sleep(time);
    Intake.startRotateFor(500,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
    Actuator.startRotateFor(indexvar,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
    while (Actuator.isSpinning()){
        wait(1);
    }
}

void autonshot2(int time){
    vex::task::sleep(time);
    Actuator.startRotateFor(150, vex::rotationUnits::deg, 200, vex::velocityUnits::rpm);
          Flywheel.stop();
          Flywheel2.stop();
          while (Actuator.isSpinning()){
              vex::task::sleep(1);
          }
          Intake.startRotateFor(540,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Intake.isSpinning()){
              vex::task::sleep(1);
          }
          Motor1.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Actuator.startRotateFor(-150, vex::rotationUnits::deg, 200, vex::velocityUnits::rpm);
          vex::task::sleep(300);
}



void stopall(int time){
    vex::task::sleep(time);
    Lwheel.stop();
    Rwheel.stop();
    Lwheel2.stop();
    Rwheel2.stop();
    Intake.stop();
    Motor1.stop();
    Motor2.stop();
    Actuator.stop();
}

void stopall2(int time){
    vex::task::sleep(time);
    Lwheel.stop();
    Rwheel.stop();
    Lwheel2.stop();
    Rwheel2.stop();
    Intake.stop();
    //Flywheel.stop();

}

void stopintake(int time){
    vex::task::sleep(time);
    Intake.stop();
    //Flywheel.stop();

}

void stopflywheel(int time){
    vex::task::sleep(time);
    Flywheel.stop();
    //Flywheel.stop();

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

void driveRightEncoder(int direction, int speed, float distance, float time){
    float inches = distance*28.5;
    wait(time);
    Rwheel.startRotateFor(inches,vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    Rwheel2.startRotateFor(inches,vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    while (Rwheel.isSpinning()){
        wait(1);
    }

}

void driveLeftEncoder(int direction, int speed, float distance, float time){
    float inches = distance*28.5;
    wait(time);
    Lwheel.startRotateFor(inches,vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    Lwheel2.startRotateFor(inches,vex::rotationUnits::deg,direction*speed,vex::velocityUnits::rpm);
    while (Rwheel.isSpinning()){
        wait(1);
    }

}

void setDriveRight(float direction, float speed, float time){

    RB.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    RF.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    wait(time);

}

void setDriveLeft(float direction, float speed, float time){

    LB.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    LF.spin(vex::directionType::fwd, speed*direction, vex::voltageUnits::volt);
    wait(time);

}








void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/





void autonomous( void ) {



    //grab ball from under cap
    intakenostop(FORWARD, FAST);
    //wait(300);
    go(37.5, 1.5, 0);
    //flywheel(FORWARD, FLYSPEED, 0);
    //stopintake(0);
    wait(100);
    go(-40, 1.5, 0);

    //shoot top flag
    turn(LEFT, 80, 1.5, 0);
    go(4, 1.5, 0);
    wait(0);
    intake(FORWARD, FAST, 50);
    autonshot(10);

    //shoot middle flag
    goo(FORWARD, FAST, 26.5, 10, 1);
    intake(FORWARD, FAST, 100);
    autonshot(150);

    //hit bottom flag
    go(8, 1.5, 0);
    turn1(LEFT, FAST, 15);
    //wait(100);
    go(16, 1.5, 0);
    turn1(RIGHT, FAST, 12);


    //flip cap
    go1(BACKWARD, FAST, 22);
    turn1(RIGHT, FAST, 110);
    movebasetime(BACKWARD, FAST, 400);
    //wait(250);
    //go(12, 0.9, 0);
    intakenostop(BACKWARD, FAST);
    go1(FORWARD, 200, 14);
    go1(FORWARD, 110, 13);

    //stopintake(0);
    //go(16, 1.2, 0);

    //park
    turn1(RIGHT, FAST, 66);
    govolt(FORWARD, 12, 1450);
    basebrake(500);
    stopall(100);







  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                              User Control Task                             */
/*                                                                            */
/*  This task is used to control your robot during the user control phase of  */
/*  a VEX Competition.                                                        */
/*                                                                            */
/*  You must modify the code to add your own robot specific commands here.    */
/*----------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
    if (driver_start == 0){

        Lwheel.stop(vex::brakeType::coast);
        Lwheel2.stop(vex::brakeType::coast);
        Rwheel.stop(vex::brakeType::coast);
        Rwheel2.stop(vex::brakeType::coast);

        Motor1.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
        Motor2.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);

        driver_start = 1;
        fly  = 1;
    }
    //Drive
    while (1){
     //if (breaker == 0){

         if (abs(Controller1.Axis3.value()) > stickdead){
      //Base Joystick Control
        LB.spin(vex::directionType::fwd, 0.12*Controller1.Axis3.value(), vex::voltageUnits::volt);

        LF.spin(vex::directionType::fwd, 0.12*Controller1.Axis3.value(), vex::voltageUnits::volt);

         }

         else if (abs(Controller1.Axis3.value()) < stickdead){

            LB.spin(vex::directionType::fwd, 0, vex::voltageUnits::volt);

            LF.spin(vex::directionType::fwd, 0, vex::voltageUnits::volt);

         }

         if (abs(Controller1.Axis2.value()) > stickdead){


         RB.spin(vex::directionType::fwd, 0.12*Controller1.Axis2.value(), vex::voltageUnits::volt);

         RF.spin(vex::directionType::fwd, 0.12*Controller1.Axis2.value(), vex::voltageUnits::volt);
         }

         else if (abs(Controller1.Axis2.value()) < stickdead){

            RB.spin(vex::directionType::fwd, 0, vex::voltageUnits::volt);

            RF.spin(vex::directionType::fwd, 0, vex::voltageUnits::volt);

         }



     //}


       /* if (Actuator.temperature(percentUnits::pct)>=50){
            Controller1.rumble("-------....--------");
        }

        */
        //Intake

         if (Controller1.ButtonR2.pressing()){
             intakenostop(FORWARD, FAST);

          }

          else if (Controller1.ButtonR1.pressing()){
              intakenostop(BACKWARD, FAST);

          }

          else{
            Intake.stop();
          }



     // else{}

        //flywheel
      if ((Controller1.ButtonA.pressing())&&(fly == 0)){
          vex::task::sleep(300);
          Motor1.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          fly = 1;

      }

      else{}

      if ((Controller1.ButtonA.pressing())&&(fly == 1)){
          vex::task::sleep(300);
          Motor1.stop();
          Motor2.stop();
          fly = 0;

      }

      else{}


        //brake
      if ((Controller1.ButtonY.pressing())&&(breaker == 0)){
         breaker = 1;


        Lwheel.stop(vex::brakeType::hold);
        Rwheel.stop(vex::brakeType::hold);
        Lwheel2.stop(vex::brakeType::hold);
        Rwheel2.stop(vex::brakeType::hold);
        vex::task::sleep(300);





      }

      else{}

      if ((Controller1.ButtonY.pressing())&&(breaker == 1)){
          Lwheel.stop(vex::brakeType::coast);
          Rwheel.stop(vex::brakeType::coast);
          Lwheel2.stop(vex::brakeType::coast);
          Rwheel2.stop(vex::brakeType::coast);
          vex::task::sleep(300);

          breaker = 0;

        /*Lwheel.startRotateFor(1, rotationUnits::deg,1,velocityUnits::rpm);
        Rwheel.startRotateFor(-1, rotationUnits::deg,1,velocityUnits::rpm);
        Lwheel2.startRotateFor(1, rotationUnits::deg,1,velocityUnits::rpm);
        Rwheel2.startRotateFor(-1, rotationUnits::deg,1,velocityUnits::rpm);

      */

      }

      else{}


        //actuator
      if ((Controller1.ButtonRight.pressing())){
          Actuator.spin(vex::directionType::fwd,-200,vex::velocityUnits::rpm);

      }



      /*else if ((Controller1.ButtonLeft.pressing())){
          Actuator.spin(vex::directionType::fwd,200,vex::velocityUnits::rpm);

      }*/

      else{

          Actuator.stop();
      }

         //1 Ball
      if ((Controller1.ButtonL2.pressing())&&(fly == 0)){

          Lwheel.stop();
          Lwheel2.stop();
          Rwheel.stop();
          Rwheel2.stop();
          vex::task::sleep(50);
          //Actuator.setTimeout(2.7,timeUnits::sec);
          auto_shot = 1;
          fly = 1;
          Motor1.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          vex::task::sleep(2000);
          Intake.startRotateFor(500,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          Actuator.startRotateFor(indexvar,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Actuator.isSpinning()){
              wait(1);
          }
          Intake.startRotateFor(300,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Intake.isSpinning()){
              wait(1);
          }





      }

      else{}

      if ((Controller1.ButtonL2.pressing())&&(fly == 1)){
          Lwheel.stop();
          Lwheel2.stop();
          Rwheel.stop();
          Rwheel2.stop();
          vex::task::sleep(200);
          //Actuator.setTimeout(1,timeUnits::sec);
          auto_shot = 1;
          fly = 1;
          Motor1.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Intake.startRotateFor(500,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          Actuator.startRotateFor(indexvar,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Actuator.isSpinning()){
              wait(1);
          }
          Intake.startRotateFor(300,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Intake.isSpinning()){
              wait(1);
          }
          /*Flywheel2.stop();
          Flywheel.stop();
          */
          auto_shot = 0;




      }










       if ((Controller1.ButtonLeft.pressing())){
              backshot = 0;
              shotTimer = 170;
       }
       if ((Controller1.ButtonUp.pressing())){
              backshot = 9.6;
              shotTimer = 100;
          }
        if ((Controller1.ButtonB.pressing())){
          if (breaker == 0){
          Lwheel.stop();
          Lwheel2.stop();
          Rwheel.stop();
          Rwheel2.stop();
          }
          vex::task::sleep(100);
          //Actuator.setTimeout(1,timeUnits::sec);
          auto_shot = 1;
          fly = 1;
          Motor1.spin(vex::directionType::fwd,backshot,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,backshot,vex::voltageUnits::volt);
          wait(shotTimer);
          Intake.startRotateFor(500,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          Actuator.startRotateFor(indexvar,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Actuator.isSpinning()){
              wait(1);
          }
          /*Flywheel2.stop();
          Flywheel.stop();
          */
          auto_shot = 0;
          Motor1.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);

          //wait(300);
        }

      /*if ((Controller1.ButtonDown.pressing())){

          Motor1.spin(vex::directionType::fwd,10,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,10,vex::voltageUnits::volt);

          Intake.startRotateFor(500,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          Actuator.startRotateFor(indexvar2,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Actuator.isSpinning()){
              wait(1);
          }
          Intake.startRotateFor(280,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Intake.isSpinning()){
              wait(1);
          }

          wait(200);
          Intake.startRotateFor(580,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Intake.isSpinning()){
              wait(1);
          }
          Motor1.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Actuator.startRotateFor(-150,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          wait(200);
      }*/

        //front double shot
      if ((Controller1.ButtonL1.pressing())){
          /*Motor1.spin(vex::directionType::fwd,0.5,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,0.5,vex::voltageUnits::volt);
          wait(150);
          Motor1.spin(vex::directionType::fwd,6.7,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,6.7,vex::voltageUnits::volt);
          wait(75);*/
          Intake.startRotateFor(1000,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          Actuator.startRotateFor(4*indexvar,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Actuator.isSpinning()){
              wait(1);
          }

          /*Motor1.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          Motor2.spin(vex::directionType::fwd,FLYSPEED,vex::voltageUnits::volt);
          wait(200);
          Intake.startRotateFor(500,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          Actuator.startRotateFor(indexvar,vex::rotationUnits::deg,200,vex::velocityUnits::rpm);
          while (Actuator.isSpinning()){
              wait(1);
          }*/

      }




     if ((((Flywheel.velocity(vex::velocityUnits::rpm)) + (Flywheel2.velocity(vex::velocityUnits::rpm)))/2 >= 190) && (((Flywheel.velocity(vex::velocityUnits::rpm)) + (Flywheel2.velocity(vex::velocityUnits::rpm)))/2 <= 197)){
        //Brain.Screen.clearScreen(vex::color::black);
        Brain.Screen.drawRectangle(15,15,50,50,vex::color::yellow);
     }
     else{
         //Brain.Screen.clearScreen(vex::color::black);
         Brain.Screen.drawRectangle(15,15,50,50,vex::color::purple);
     }









}





    vex::task::sleep(15); //Sleep the task for a short amount of time to prevent wasted resources.

}

//
// Main will set up the competition functions and callbacks.
//
int main() {

    //Run the pre-autonomous function
    pre_auton();

    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
            while (true){
                if (Actuator.temperature(vex::percentUnits::pct) >= 40){
                    Controller1.rumble(".");

            }

                if (Intake.temperature(vex::percentUnits::pct) >= 40){
                    Controller1.rumble("-");

            }

                /*Brain.Screen.setPenColor(vex::color::purple);
                Brain.Screen.setFillColor(vex::color::purple);
                Brain.Screen.drawRectangle(15,15,50,50,vex::color::purple);*/


    //Prevent main from exiting with an infinite loop.

        }
}
