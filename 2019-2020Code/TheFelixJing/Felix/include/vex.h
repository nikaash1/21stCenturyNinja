/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
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
#include "UserControl.h"
#include "AlignerControl.h"
#include "AlignerCommands.h"
#include "LiftCommands.h"
#include "LiftControl.h"
#include "IntakeCommands.h"
#include "IntakeControl.h"
#include "Autonomous.h"

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
//aligner
#define ALIGN 1
#define RETRACT -1
//lift
#define UP 1
#define DOWN -1
//intake
#define CLOSE 1
#define OPEN -1
//drive
#define LEFT 1
#define RIGHT -1
#define FORWARD 1
#define BACKWARD -1
#define REVERSE -1