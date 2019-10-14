#include "robot-config.h"

#include <string>
#include <cmath>

using namespace std;


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