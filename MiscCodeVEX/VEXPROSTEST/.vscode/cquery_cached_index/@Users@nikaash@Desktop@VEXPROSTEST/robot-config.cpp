#include "main.h"

//blown ports: 5, 7, 20

//motor definitions
Motor leftFrontDrive(1, false);
Motor leftBackDrive(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor rightFrontDrive(3, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor rightBackDrive(4, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor puncher (19, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Motor feeder(6, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
Motor angler(10, E_MOTOR_GEARSET_36, false, E_MOTOR_ENCODER_DEGREES);
Motor flipper(8, E_MOTOR_GEARSET_36, true, E_MOTOR_ENCODER_DEGREES);
Controller master (CONTROLLER_MASTER);

//controller globals
int r1;
int r2;
int l1;
int l2;
int x;
int a;
int b;
int y;
int up;
int down;
int left;
int right;
int leftXValue;
int leftYValue;
int rightXValue;
int rightYValue;

//other globals
int program = 1; //1 is red front, 2 is blue front, 3 is red back, 4 is blue back, 5 is prog skills, 6 is no auton
int maxValue = 6; //total number of autons
int shotsFired = 0; //robot has not fired any shots yet
bool isAuton = true;
bool shootingTaskStarted = false;
//bool far = false; //far indicates full field shots
int range = 1; //1 is close, 2 is behind platform, 3 is against back wall

void initialize() {
  leftFrontDrive.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  leftBackDrive.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  rightFrontDrive.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  rightBackDrive.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  /*leftFrontDrive.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  leftBackDrive.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  rightFrontDrive.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  rightBackDrive.set_brake_mode(E_MOTOR_BRAKE_BRAKE);*/
  lcd::initialize();
}

void increaseAuton(){
  if(program < maxValue){
    program ++;
    delay(500);
  }
  else{
    program = 1;
  }
}

void decreaseAuton(){
  if(program >= 1){
    program --;
    delay(500);
  }
  else{
    program = maxValue;
  }
}

void disabled(){
}

void competition_initialize(){
  while(competition::is_disabled()){ //don't run if robot disconnects in auton or driver control

    lcd::register_btn2_cb(increaseAuton); //right button: go up
    lcd::register_btn0_cb(decreaseAuton); //left button: go down

    if(program == 1){
      lcd::set_text(1, "Red Front");
    }
    else if(program == 2){
      lcd::set_text(1, "Blue Front");
    }
    else if(program == 3){
      lcd::set_text(1, "Red Back");
    }
    else if(program == 4){
      lcd::set_text(1, "Blue Back");
    }
    else if(program == 5){
      lcd::set_text(1, "Prog Skills");
    }
    else if(program == 6){
      lcd::set_text(1, "No Auton");
    }
    delay(20);
  }
}

void resetBase(){
  leftBackDrive.tare_position(); //reset chassis encoders
  leftFrontDrive.tare_position();
  rightBackDrive.tare_position();
  rightFrontDrive.tare_position();
  delay(5);
}

void resetLaunch(){
  puncher.move(40); //ready to engage
  angler.move(-40); //lower angler to minimum possible height
  delay(800);
  puncher.tare_position(); //reset puncher encoder
  angler.tare_position(); //reset angler encoder
  delay(200);
  angler.move(0); //no stalling
  shotsFired = 0; //reset shots fired
}

void shootControlFn(void*){
  shootingTaskStarted = true; //only start this task once
  bool topPressed = false; //flag for top button
  bool bottomPressed = false; //flag for top button
  bool loaded = false;
  int targetPosition = 0; //keep track of target and error on puncher to better tell angler when to change angles
  int errorPosition = 0;
  resetLaunch(); //zero launcher and angler
  while(true){
    if(b == 1){ //close shots
      range = 1;
    }
    else if(a == 1){ //half court shots
      range = 2;
    }
    else if(x == 1){ //full court shots
      range = 3;
    }

    if(l1 == 1 && !topPressed){ //robot is ready to shoot top flag- only incriment once
      shotsFired ++;
      topPressed = true;
      loaded = false;
      if(range == 3 && !isAuton){ //far shot high flag
        angler.move_absolute(100, 100);
      }
      else if(range == 3 && isAuton){ //far shot high flag IN AUTON ONLY
        angler.move_absolute(108, 100);
      }
      else if(range == 2){ //mid shot high flag
        angler.move_absolute(125, 100);
      }
      else if(range == 1){ //close shot high flag
        angler.move_absolute(15, 100);
      }
    }
    else if(l1 == 0){
      topPressed = false;
    }

    if(l2 == 1 && !bottomPressed){ //identical logic but for bottom flag
      shotsFired ++;
      bottomPressed = true;
      loaded = false;
      if(errorPosition < 360){ //only change angle if the robot is ready to change angles
        if(range == 3 && !isAuton){ //far shot low flag
          angler.move_absolute(150, 100);
        }
        else if(range == 3 && isAuton){ //far shot low flag IN AUTON ONLY
          angler.move_absolute(160, 100);
        }
        else if(range == 2){ //mid shot low flag
          angler.move_absolute(175, 100);
        }
        else if(range == 1){ //close shot low flag
          angler.move_absolute(155, 100);
        }
      }
    }
    else if(l2 == 0){
      bottomPressed = false;
    }
    if(r1 == 1){
      angler.move_absolute(50, 100); //lower angle when loading- fixes ball dribble
    }
    targetPosition = 360 * shotsFired + 150; //target is 1 rotation for each new shot ready to fire: starts halfway back
    errorPosition = targetPosition - puncher.get_position(); //error is distance between target and actual

    if(errorPosition < 20){
      loaded = true; //puncher is pulled back- allows ratchet to kick in
    }

    if(errorPosition > 0 && !loaded){ //fire
      puncher.move(127);
    }
    else{ //puncher will hold position with ratchet- motors dont need to strain
      puncher.move(0);
    }
    delay(20);
  }
}

void doubleShot(){ //function only used in auton
  l1 = 1; //shoot top flag
  delay(100);
  l1 = 0;
  delay(900);
  l2 = 1; //shoot bottom flag
  delay(100);
  l2 = 0;
}

void drive(int left, int right, int max){
  leftFrontDrive.move_relative(left, max);
  leftBackDrive.move_relative(left, max);
  rightFrontDrive.move_relative(right, max);
  rightBackDrive.move_relative(right, max);
}

void autonomous(){
  isAuton = true;
  int max = 160;
  int turn = 100; //slower max speed for turning
  flipper.tare_position(); //reset the flipper
  if(!shootingTaskStarted){
    Task ShootControl(shootControlFn); //start shooting task if not already started
  }
  delay(10); //give everything time to start up
  if(program == 1){ //red front
    range = 1; //close shooting
    drive(850, 850, max); //get ball under cap
    feeder.move(127); //load
    delay(1100);
    drive(250, 250, 70); //inch forward to get ball under cap
    delay(800);
    drive(-1, 1, turn); //straighten out
    delay(100);
    drive(-450, -450, max); //come back halfway
    delay(600);
    feeder.move(0); //no stalling
    drive(480, -480, turn); //turn to face ground cap
    delay(900);
    flipper.move_absolute(-130, 100); //deploy flipper to flip cap
    delay(200);
    drive(-500, -500, max); //approach low cap
    delay(600);
    flipper.move_absolute(5, 80); //flip cap
    delay(600);
    drive(-450, 450, turn); //turn to line back of robot up with wall
    delay(1000);
    drive(-1000, -1000, max); //line up against side wall
    delay(1600);
    resetBase();
    delay(20);
    drive(200, 200, max); //inch away from wall
    delay(350);
    drive(-522, 522, turn); //turn to face low flag
    delay(1300);
    drive(1100, 1100, max); //score low flag
    delay(1500);
    resetBase(); //robot is now against wall
    delay(20);
    drive(-1440, -1500, max);
    delay(2500);
    doubleShot();
    delay(1500);
  }
  else if(program == 2){ //blue front
    range = 1; //close shooting
    drive(850, 870, max); //get ball under cap
    feeder.move(127); //load
    delay(1100);
    drive(250, 250, 70); //inch forward to get ball under cap
    delay(800);
    drive(-30, 30, turn); //straighten out
    delay(100);
    drive(-450, -450, max); //come back halfway
    delay(600);
    feeder.move(0); //no stalling
    drive(-480, 480, turn); //turn to face ground cap
    delay(900);
    flipper.move_absolute(-130, 100);
    delay(200);
    drive(-500, -500, max); //approach low cap
    delay(600);
    flipper.move_absolute(5, 80); //flip cap
    delay(600);
    drive(450, -450, turn); //turn to line back of robot up with wall
    delay(1000);
    drive(-1000, -1000, max); //line up against side wall
    delay(1600);
    resetBase();
    delay(20);
    drive(200, 200, max); //inch away from wall
    delay(350);
    drive(502, -502, turn); //turn to face low flag
    delay(1300);
    drive(1100, 1100, max); //score low flag
    delay(1500);
    resetBase(); //robot is now against wall
    delay(20);
    drive(-1530, -1500, max);
    delay(2500);
    doubleShot();
    delay(1500);
  }
  else if(program == 3){ //red back
    range = 3; //back shots
    drive(1100, 1100, 50); //go forward slowly to get ball under cap
    feeder.move(127); //intake
    delay(4500);
    drive(-200, -200, 60); //come back slightly
    delay(2000);
    drive(-416, 200, 70); //turn to face opponent's flags
    delay(4800);
    doubleShot();
    delay(800);
    drive(0, 400, 200); //turn to face parking platform
    delay(500);
    drive(1050, 1050, 200); //park
    delay(1300);
  }
  else if(program == 4){ //blue back
    range = 3; //back shots
    drive(1100, 1100, 50); //go forward slowly to get ball under cap
    feeder.move(127); //intake
    delay(4500);
    drive(-200, -200, 60); //come back slightly
    delay(2000);
    drive(200, -420, 70); //turn to face opponent's flags
    delay(4800);
    doubleShot();
    delay(800);
    drive(400, 0, 200); //turn to face parking platform
    delay(500);
    drive(1050, 1050, 200); //park
    delay(1300);
  }
  else if(program == 5){ //prog skill

    //FIRST POLE

    range = 1; //close shooting
    flipper.tare_position(); //reset flipper
    drive(1400, 1400, 180); //get ball under cap
    feeder.move(127); //load
    delay(2000);
    drive(-1440, -1440, 100); //come back to starting tile
    delay(3000);
    feeder.move(0); //no stalling
    drive(-497, 497, 70); //turn to face flags
    delay(1600);
    drive(1350, 1350, 100); //drive towards first flag pole
    delay(2500);
    drive(500, -500, 70); //turn to line up with wall
    delay(2000);
    drive(-600, -600, 50); //line up with wall
    delay(1300);
    resetBase(); //robot is against wall
    delay(20);
    drive(300, 300, 100); //inch away from wall
    delay(900);
    drive(-478, 478, 70); //turn to face flags
    delay(2000);
    drive(-50, -50, 100); //back up slightly
    delay(900);
    flipper.move_absolute(-130, 100); //deploy flipper
    doubleShot();
    delay(1000); //shoot 2 flags
    feeder.move(60); //recycle- low speed to guarentee we only get one ball
    drive(-32, 32, 70); //turn to face low flag
    delay(500);
    drive(1500, 1500, 100); //flip low flag
    delay(3100);
    resetBase(); //robot is now against wall
    delay(20);

    //SECOND POLE
    angler.move_absolute(20, 100); //ease of intaking later on
    drive(-500, -500, 100); //back away from wall
    delay(1200);
    feeder.move(-127); //spit out 2nd ball if the robot recycled both
    drive(-1000, 0, 70); //turn so wedges face ground cap
    delay(3000);
    drive(500, 500, 100); //line up against wall again
    feeder.move(0); //no stalling
    delay(1200);
    resetBase();
    delay(20);
    drive(-150, 0, 70); //angle to face low cap
    delay(500);
    drive(-600, -600, 100); //approach low cap
    delay(1500);
    flipper.move_absolute(-50, 80); //flip ground cap
    delay(1000);
    drive(0, 1825, 90); //swing robot to face next ground cap
    flipper.move_absolute(0, 80); //reset
    delay(4500);
    drive(900, 900, 100); //intake ball under cap and flip cap
    feeder.move(127); //intake
    delay(2500);
    drive(-400, -400, 100); //drive back, parallel to parking platform
    delay(1200);
    drive(-490, 490, 70); //turn to line back of robot up with parking platform
    delay(2000);
    drive(-650, -650, 50); //approach low platform extremely slowly
    delay(1200);
    resetBase(); //robot is now against low platform
    feeder.move(0);
    delay(20);
    drive(150, 150, 100); //drive forward to be correct distance from flags
    delay(600);
    drive(101, -101, 70); //angle towards middle row of flags
    delay(800);
    doubleShot(); //shoot flags
    delay(1500);

    //PARKING
    feeder.move(50); //clear balls
    drive(349, -349, 70); //turn parallel to parking platform
    delay(1200);
    drive(-800, -800, 100); //drive back towards first row of polls
    delay(1900);
    drive(-460, 460, 70); //turn perpendicular to parking platform
    delay(1800);
    drive(-620, -620, 100); //center of robot is now behind parking platform
    delay(1500);
    drive(500, -500, 70); //turn to face parking platform
    delay(2000);
    drive(2000, 2000, 200); //park
    delay(8000);
    feeder.move(0);
  }
  else if(program == 6){ //no auton
    delay(1);
  }
  isAuton = false; //stop drive PID
  delay(20);
  leftBackDrive.move(0); //stop driving
  leftFrontDrive.move(0);
  rightBackDrive.move(0);
  rightFrontDrive.move(0);
}

void readControllerFn(void*){ //stores remote values in globals for easy checking in other tasks
	while(true){
		r1 = master.get_digital(DIGITAL_R1);
		r2 = master.get_digital(DIGITAL_R2);
		l1 = master.get_digital(DIGITAL_L1);
		l2 = master.get_digital(DIGITAL_L2);
		x = master.get_digital(DIGITAL_X);
		y = master.get_digital(DIGITAL_Y);
		a = master.get_digital(DIGITAL_A);
		b = master.get_digital(DIGITAL_B);
		up = master.get_digital(DIGITAL_UP);
		down = master.get_digital(DIGITAL_DOWN);
		left = master.get_digital(DIGITAL_LEFT);
		right = master.get_digital(DIGITAL_RIGHT);
		leftXValue = master.get_analog(ANALOG_LEFT_X);
		leftYValue = master.get_analog(ANALOG_LEFT_Y);
		rightXValue = master.get_analog(ANALOG_RIGHT_X);
		rightYValue = master.get_analog(ANALOG_RIGHT_Y);
		delay(20);
	}
}

void opcontrol(){
  Task readController(readControllerFn); //store controller values in globals
  if(!shootingTaskStarted){
    Task ShootControl(shootControlFn); //start shooting task if not already started
  }
  int waitSpeed = 0;
  isAuton = false;
  int leftFront;
  int leftBack;
  int rightFront;
  int rightBack;
  int flipWait = 0;
  float tank = 1.3;
  float strafe = 0.7;
	while(true){
    //intended speeds for mecanum base
    leftFront = (rightYValue * tank) + leftXValue + (rightXValue * strafe);
    leftBack = (rightYValue * tank) + leftXValue - (rightXValue * strafe);
    rightFront = (rightYValue * tank) - leftXValue - (rightXValue * strafe);
    rightBack = (rightYValue * tank) - leftXValue + (rightXValue * strafe);

    if(abs(rightYValue) + abs(leftXValue) + abs(rightXValue) < 5){ //set motors to 0 velocity, not 0 voltage, for insane break mode
      leftFrontDrive.move_velocity(0);
      leftBackDrive.move_velocity(0);
      rightFrontDrive.move_velocity(0);
      rightBackDrive.move_velocity(0);
    }

    else{ //if the wheels are supposed to be moving, use voltage instead of built in pid
      leftFrontDrive.move(leftFront);
      leftBackDrive.move(leftBack);
      rightFrontDrive.move(rightFront);
      rightBackDrive.move(rightBack);
    }

    if(r1 == 1 && r2 == 0){ //load
      feeder.move(110);
    }
    else if(r2 == 1 && r1 == 0){ //spit out
      feeder.move(-127);
    }
    else{
      feeder.move(0);
    }

    if(up == 1){ //flip
      flipper.move(127);
      flipWait = 5;
    }
    else if(down == 1){ //go down
      flipper.move(-127);
      flipWait = -5;
    }
    else{ //if not loading or shooting, turn feeder off
      flipper.move(flipWait);
    }

		delay(20);
	}
}
