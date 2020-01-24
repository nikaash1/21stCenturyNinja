#include "vex.h"
using namespace vex;

int tilterControls(){
  double traySpeed = 1;
  double traySpeed2 = 1;
  double trayToggleSpeed = 1;
  int trayToggle = 0;
  while (1){
    if (getController(BTNRIGHT)){
      while (getController(BTNRIGHT)){
        wait(1, msec);
      }
      if (trayToggle == 0){
        trayToggleSpeed = 0.4;
        trayToggle = 1;
      }
      else if (trayToggle == 1){
        trayToggleSpeed = 1;
        trayToggle = 0;
      }
    }
    if (getController(BTNLEFT)){
      while (getController(BTNLEFT)){
        wait(1, msec);
      }
      Tilter.resetRotation();
    }
    if (Tilter.rotation(rotationUnits::deg) >= 70 ){
      double error = 650 - Tilter.rotation(rotationUnits::deg);
      traySpeed = 0.002*error;
    }
    else{
      traySpeed = 1;
    }
    if ((Tilter.rotation(rotationUnits::deg) >= 200)){
      traySpeed2 = 0.3;
    }
    else{
      traySpeed2 = 1;
    }
    if (getController(BTNB)){
      tray(TILT, 100*traySpeed*trayToggleSpeed);
    }
    else if (getController(BTNY)){
      tray(UNTILT, 100*trayToggleSpeed);
    }
    else if (getController(BTNL1)){
      tray(TILT, 35*traySpeed2);
    }
    else if (getController(BTNL2)){
      tray(UNTILT, 60*traySpeed2);
    }
    else{
      trayBrake();
    }
  }
  return 0;
}