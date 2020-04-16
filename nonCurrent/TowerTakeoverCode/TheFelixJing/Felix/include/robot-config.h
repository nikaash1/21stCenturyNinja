using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller;
extern motor FLWheel;
extern motor FRWheel;
extern motor BLWheel;
extern motor BRWheel;
extern motor Aligner;
extern motor RUp;
extern motor LUp;
extern motor Intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );