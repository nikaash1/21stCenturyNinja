#include "vex.h"
using namespace vex;
int alignerToggle = 0;
void alignerButton(){

}
int alignerControls(){
  while(1){
    if ((getController(BTNRIGHT)) == 1){
      if (alignerToggle == 0){
        alignerToggle = 1;
        align(ALIGN, 100);
        alignBrake();
      }
      else{
        alignerToggle = 0;
        align(RETRACT, 100);
        alignCoast();
      }
    }
  }
  return 0;
}