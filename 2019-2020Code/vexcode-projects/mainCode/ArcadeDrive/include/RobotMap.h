//configure brain/controller and motors

//#include "PID.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"


vex::brain Brain;
vex::controller Controller1 = vex::controller();
vex::timer TimerDrive = vex::timer();
vex::timer TimerUp = vex::timer();
vex::motor Lwheel2 = vex::motor(vex::PORT9);
vex::motor Lwheel = vex::motor(vex::PORT10);
vex::motor Rwheel2 = vex::motor(vex::PORT2,true)  ;
vex::motor Rwheel = vex::motor(vex::PORT3,true);
vex::motor Hwheel = vex::motor(vex::PORT7);
vex::motor Intake = vex::motor(vex::PORT18,true);
vex::motor LUp = vex::motor(vex::PORT13,true);
vex::motor RUp = vex::motor(vex::PORT16);


//class for running direct voltage
namespace vex {
  class motor_special : public motor {
    private:
      uint32_t  _local_index;

    public:
      motor_special(int32_t index) :  motor(index), _local_index(index) {};  
      ~motor_special() {};
      using motor::spin;
      void spin(directionType dir, double voltage, voltageUnits units) {
        int32_t voltage_mv = (units == voltageUnits::volt ? voltage * 1000.0 : voltage);
        voltage_mv = (dir == directionType::fwd ? voltage_mv : -(voltage_mv));
        if( voltage_mv == 0 ) {
          stop();
        } else {
          vexMotorVoltageSet(_local_index, voltage_mv);
        }
      }
  };
}

using namespace vex;


//motor configuration for the ones that should be able to run voltage
motor_special RF(vex::PORT2);
motor_special RB(vex::PORT3);
motor_special LF(vex::PORT10);
motor_special LB(vex::PORT9);
motor_special MH(vex::PORT7);


