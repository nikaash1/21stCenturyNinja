void tray(int dir, double speed);
void trayControlled(int dir, double speed, double deg);
double getTilter();
void trayCoast();
void trayBrake();
void trayEncoder(int dir, double speed, double deg);
int trayP(int speed, double dist, double targetDist);
void trayTime(int dir, int speed,  double waitTime);
int getTrayLimit();