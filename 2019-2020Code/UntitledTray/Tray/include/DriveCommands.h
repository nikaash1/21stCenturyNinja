double getDriveFL();
double getDriveFR();
double getDriveBL();
double getDriveBR();
double getDriveR();
double getDriveL();
double getDriveF();
double getDriveB();
double getDrive();
void driveReset();
double getHeatFL();
double getHeatFR();
double getHeatBL();
double getHeatBR();
void setDrive(double lSpeed, double rSpeed);
void setDriveFull(double flSpeed, double blSpeed, double frSpeed, double brSpeed);
int driveEncoder(int dir, double speed, double dist);
int turnEncoder(int dir, double speed, double dist);
int strafeEncoder(int dir, double speed, double dist);
void swing(double speedL, double speedR, double distL, double distR);
void swingEncoder(double speedL, double speedR, double distL, double distR);
void setFL(double speed);
void setFR(double speed);
void setBL(double speed);
void setBR(double speed);
void driveBrake();
void driveCoast();
void driveTime(int dir, double speed, double timeVal);
void setDriveTime(double speedL, double speedR, double timeVal);
void driveStraight(int dir, double speed, double dist);
void driveTurn(int dir, double speed, double dist);
void driveStrafe(int dir, double speed, double dist);
int goP(int dir, double initSpeed, double speed, double dist, double speedStart, double speedCut, double slowFactor, bool smooth);
int turnP(int dir, double initSpeed, double speed, double dist, double speedStart, double speedCut, double slowFactor, bool smooth);
int swingP(double speedL, double speedR, double distL, double distR, double maxErrorL, double maxErrorR);
int correctP(double speed, double targetDifference);