#include <cmath>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"


#include "robot-config.h"

#include "Joystick.h"
#include "DriveControl.h"
#include "DriveCommands.h"
#include "Tasks.h"
#include "Autonomous.h"
#include "InertiaCommands.h"
#include "DrivePID.h"

using namespace std;

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

//drive controls
#define TANK 1
#define ARCADE 2
#define STANDARD 1
#define XDRIVE 2
#define HDRIVE 3
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
//drive
#define LEFT 1
#define RIGHT -1
#define FORWARD 1
#define BACKWARD -1
#define REVERSE -1
//tilter
#define TILT 1
#define UNTILT -1
//auton
#define NONE 0
#define RED 1
#define BLUE 2
#define SKILLS 5
#define TOTAL_AUTONS 3
