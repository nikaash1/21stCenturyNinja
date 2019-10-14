/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Mon Mar 25 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// Potentiometer Display
// This program displays the potentiometer values to the Brain and Controller's Screen.
// There is a two second pause at the beginning of the program.
//
// Robot Configuration: 
// [Remote Controller]  [Name]
// Primary Controller   Controller1
//
// [Three Wire Port]    [Name]        
// Potentiometer        Pot1          
//
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
vex::pot        Potentiometer1 = vex::pot( Brain.ThreeWirePort.A );
vex::controller Controller1    = vex::controller();

int main() {
    // Wait 2 seconds or 2000 milliseconds before starting the program.
    vex::task::sleep( 2000 );
    // Print to the screen that the program has started.
    Brain.Screen.print("User Program has Started.");
    
    // Clear the controller's screen.
    // 
    Controller1.Screen.clearScreen();
    
    // Start an infinite loop to continuously get readings.
    // The program will not end until it is manually ended by the user.
    while(1) {        
        // Manually turn the shaft connected to the potentiometer. This will cause the values to change.
        // Print the value of the potentiometer in degrees to the Screen.
        Brain.Screen.printAt(1, 40, "The value of the potentiometer is %5f", Potentiometer1.value(vex::rotationUnits::deg));
        
        // use line 3, the bottom line, on the controller
        Controller1.Screen.setCursor(3,1);
        // Print the value of the Potentiometer sensor on the controllers screen.
        Controller1.Screen.print("Pot1 = %5f", Potentiometer1.value(vex::rotationUnits::deg));
        
        vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }
    
    // Prevent main from exiting with an infinite loop.                        
    while(1) {
      // Sleep the task for a short amount of time to prevent wasted resources.
      vex::task::sleep(100);
    }
}
