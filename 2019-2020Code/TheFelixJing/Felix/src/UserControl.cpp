#include "vex.h"
using namespace vex;

//joystick axes
#define RIGHT_AXIS_X 1
#define RIGHT_AXIS_Y 2
#define LEFT_AXIS_Y 3
#define LEFT_AXIS_X 4
//button numbers
#define BTNR1 1
#define BTNR2 2
#define BTNL1 3
#define BTNL2 4
#define BTNA 5
#define BTNB 6
#define BTNY 7
#define BTNX 8
#define BTNUP 9
#define BTNDOWN 10
#define BTNLEFT 11
#define BTNRIGHT 12
//drive controls
#define TANK 1
#define ARCADE 2
#define STANDARD 1
#define XDRIVE 2

void runDriver(int style, int driveType){
  driveControls(style, driveType);
}