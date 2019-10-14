/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Mon Mar 25 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// Screen Press
// This program instructs the robot to draw a circle on the brain whenever a user presses the screen.
//
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here

int main() {
    // Create an infinite loop to record data until the user manually ends the program.
    while(1) {         
      // Check to see if the brain has been pressed.
      if(Brain.Screen.pressing()) { //If the Brain is pressed...
        //...Clear the screen of any circles that were on the screen from a previous touch.
        Brain.Screen.clearScreen();            
        // Draw a circle with the origin being the user's touch locations.
        Brain.Screen.drawCircle(Brain.Screen.xPosition(), Brain.Screen.yPosition(), 50);
      }
    }
}
