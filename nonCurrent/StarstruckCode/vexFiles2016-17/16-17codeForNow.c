#pragma config(Motor,  port1,           frwheel,       tmotorVex393HighSpeed_HBridge, openLoop, driveRight)
#pragma config(Motor,  port2,           flwheel,       tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           brwheel,       tmotorVex393HighSpeed_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           blwheel,       tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{



}



































//control with joystick
task usercontrol(){
	bLCDBacklight = true;
	string mainBattery, expBattery;
	while (true){//self explanatory but if you didnt get that it means nonstop