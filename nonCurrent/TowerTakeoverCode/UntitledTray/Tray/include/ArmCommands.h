void armGo(int dir, double speed);
void armBrake();
void armCoast();
double getArm();
int armEncoder(int dir, double speed, double height);
int armControlled(int dir, double speed, double height);
int getArmLimit();