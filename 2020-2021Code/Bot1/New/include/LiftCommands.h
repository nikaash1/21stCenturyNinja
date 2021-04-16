double getLift();
void setLift(int dir, double speed);
int liftEncoder(int dir, double speed, double height);
int liftControlled(int dir, double speed, double height);
void liftBrake();
void liftCoast();
int getLiftLimit();