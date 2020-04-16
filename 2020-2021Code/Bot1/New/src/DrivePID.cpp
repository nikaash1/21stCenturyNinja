#include "vex.h"
using namespace vex;
//conversions
double inchesConversion = 1;
double degConversion = 1;
//straight variables
int straightDir = 1;
double straightInitSpeed = 0;
double straightSpeed = 0;
double straightTarget = 0;
double straightSpeedStart = 0;
double straightSpeedCut = 0;
double straightSlowFactor = 0;
bool straightSmooth = false;
int isStraight = 0;
//turn variables
int turnDir = 1;
double turnInitSpeed = 0;
double turnSpeed = 0;
double turnTarget = 0;
double turnSpeedStart = 0;
double turnSpeedCut = 0;
double turnSlowFactor = 0;
bool turnSmooth = false;
int isTurning = 0;

//calculate PID
int calculatePID(){

  double straightKP = 100/straightTarget;
  double straightKP2 = 8;
  double straightKPSlow = straightSlowFactor/100;
  double straightError = 1;
  double driftError = 0;
  double straightPVal = straightInitSpeed;
  double straightFinalPower = straightSpeed;
  double straightSpeedSmooth;

  double turnKP = 100/turnTarget;
  double turnKP2 = 8;
  double turnKPSlow = turnSlowFactor/100;
  double turnError = 1;
  double turnPVal = turnInitSpeed;
  double turnFinalPower = turnSpeed;
  double turnSpeedSmooth;
  if (straightSmooth){
    straightSpeedSmooth = straightSpeedStart;
  }
  else{
    straightSpeedSmooth = 0;
  }
  while(1){
    driftError = (getDriveR() - getDriveL())*straightKP2*(straightFinalPower)/100;
    setDrive((straightFinalPower + driftError)*straightDir*isStraight + turnFinalPower*turnDir*isTurning*-1, (straightFinalPower - driftError)*straightDir*isStraight + turnFinalPower*turnDir*isTurning);
  }
  return 0;
}


int go(int dir, double initSpeed, double speed, double dist, double speedStart, double speedCut, double slowFactor, bool smooth){
  driveReset();
  straightDir = dir;
  straightInitSpeed = initSpeed;
  straightSpeed = speed;
  straightTarget = dist*inchesConversion;
  straightSpeedStart = speedStart*inchesConversion;
  straightSpeedCut = speedCut*inchesConversion;
  straightSlowFactor = slowFactor;
  straightSmooth = smooth;
  isTurning = 0;
  isStraight = 1;
  return 0;
}

int turn(int dir, double initSpeed, double speed, double dist, double speedStart, double speedCut, double slowFactor, bool smooth){
  turnDir = dir;
  turnInitSpeed = initSpeed;
  turnSpeed = speed;
  turnTarget = dist*inchesConversion;
  turnSpeedStart = speedStart*inchesConversion;
  turnSpeedCut = speedCut*inchesConversion;
  turnSlowFactor = slowFactor;
  turnSmooth = smooth;
  isStraight = 0;
  isTurning = 1;
  return 0;
}