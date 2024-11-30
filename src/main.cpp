/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       tz2668                                                    */
/*    Created:      11/14/2024, 4:17:29 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

brain Brain;

// define your global instances of motors and other devices here

controller Controller1;
motor LeftMotorFront(PORT1, gearSetting::ratio6_1, false);
motor LeftMotorBack(PORT2, gearSetting::ratio6_1, true);
motor LeftMotorMid(PORT3, gearSetting::ratio6_1, false);
motor RightMotorFront(PORT4, gearSetting::ratio6_1, true);
motor RightMotorBack(PORT5, gearSetting::ratio6_1, false);
motor RightMotorMid(PORT6, gearSetting::ratio6_1, true);
motor motorpair_1(PORT7, gearSetting::ratio18_1, true);
motor motorpair_2(PORT8, gearSetting::ratio18_1, false);
motor motor2(PORT9, gearSetting::ratio18_1, true);

struct MotorSpeeds {
  int leftspeed;
  int rightspeed;
};

int t, A1, A2, A3, A4, L1, L2, R1, R2, X, Y, A, B, LEFT, RIGHT, UP, DOWN,
  last_L1, last_L2, last_R1, last_R2, 
  last_X, last_Y, last_A, last_B, last_LEFT, last_RIGHT, last_UP, last_DOWN;
    
void defineController(){
  last_L1 = L1;
  last_L2 = L2;
  last_R1 = R1;
  last_R2 = R2;
  last_X = X;
  last_Y = Y;
  last_A = A;
  last_B = B;
  last_LEFT = LEFT;
  last_RIGHT = RIGHT;
  last_UP = UP;
  last_DOWN = DOWN;
  t = Brain.timer(vex::timeUnits::msec);
  A1 = Controller1.Axis1.position(vex::percentUnits::pct);
  A2 = Controller1.Axis2.position(vex::percentUnits::pct);
  A3 = Controller1.Axis3.position(vex::percentUnits::pct);
  A4 = Controller1.Axis4.position(vex::percentUnits::pct);
  L1 = Controller1.ButtonL1.pressing();
  L2 = Controller1.ButtonL2.pressing();
  R1 = Controller1.ButtonR1.pressing();
  R2 = Controller1.ButtonR2.pressing();
  X = Controller1.ButtonX.pressing();
  Y = Controller1.ButtonY.pressing();
  A = Controller1.ButtonA.pressing();
  B = Controller1.ButtonB.pressing();
  LEFT = Controller1.ButtonLeft.pressing();
  RIGHT = Controller1.ButtonRight.pressing();
  UP = Controller1.ButtonUp.pressing();
  DOWN = Controller1.ButtonDown.pressing();
}

MotorSpeeds forward1() {
//   int speedx = A3;
//   int speedspin = A1 * 0.7;
//   if (!L2) {
//     speedx = speedx / 2;
//   }
//   if (speedx){
//     LeftMotorFront.spin(directionType::fwd, speedx, velocityUnits::pct);
//     LeftMotorBack.spin(directionType::fwd, speedx, velocityUnits::pct);
//     RightMotorFront.spin(directionType::fwd, speedx, velocityUnits::pct);
//     RightMotorBack.spin(directionType::fwd, speedx, velocityUnits::pct);
//   }else if (speedspin){
//     LeftMotorFront.spin(directionType::fwd, speedspin, velocityUnits::pct);
//     LeftMotorBack.spin(directionType::fwd, speedspin, velocityUnits::pct);
//     RightMotorFront.spin(directionType::rev, speedspin, velocityUnits::pct);
//     RightMotorBack.spin(directionType::rev, speedspin, velocityUnits::pct);
//   }else{
//     LeftMotorFront.stop();
//     LeftMotorBack.stop();
//     RightMotorFront.stop();
//     RightMotorBack.stop();
//   }
// }
  int speedx = A3;
  int speedspin = A1;
  if (!L2) {
    speedx = speedx * 0.6;
    speedspin = speedspin * 0.6;
  }
  int leftSpeed = speedx + speedspin;
  int rightSpeed = speedx - speedspin;
  MotorSpeeds speeds = {leftSpeed, rightSpeed};
  return speeds;
}


void motorpair1(){
  if (R1){
    motorpair_1.spin(directionType::fwd, 100, velocityUnits::pct);
    motorpair_2.spin(directionType::fwd, 100, velocityUnits::pct);
  }else if (R2){
    motorpair_1.spin(directionType::rev, 100, velocityUnits::pct);
    motorpair_2.spin(directionType::rev, 100, velocityUnits::pct);
  }else{
    motorpair_1.stop(vex::brakeType::hold);
    motorpair_2.stop(vex::brakeType::hold);
  }
}

void motor2_1(){
  if (X){
    motor2.spin(directionType::fwd, 100, velocityUnits::pct);
  }else if (Y){
    motor2.spin(directionType::rev, 100, velocityUnits::pct);
  }else{
    motor2.stop(vex::brakeType::hold);
  }
}


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................s

    // wait(20, msec); // Sleep the task for a short amount of time to
    //                 // prevent wasted resources.
    defineController();
    MotorSpeeds forwardSpeeds = forward1();

    if ((forwardSpeeds.leftspeed != 0 )|| (forwardSpeeds.rightspeed != 0)){
      LeftMotorFront.spin(directionType::fwd, forwardSpeeds.leftspeed, velocityUnits::pct);
      LeftMotorBack.spin(directionType::fwd, forwardSpeeds.leftspeed, velocityUnits::pct);
      LeftMotorMid.spin(directionType::fwd, forwardSpeeds.leftspeed, velocityUnits::pct);
      RightMotorFront.spin(directionType::fwd, forwardSpeeds.rightspeed, velocityUnits::pct);
      RightMotorBack.spin(directionType::fwd, forwardSpeeds.rightspeed, velocityUnits::pct);
      RightMotorMid.spin(directionType::fwd, forwardSpeeds.rightspeed, velocityUnits::pct);
    }else{
      LeftMotorFront.stop(vex::brakeType::hold);
      LeftMotorBack.stop(vex::brakeType::hold);
      LeftMotorMid.stop(vex::brakeType::hold);
      RightMotorFront.stop(vex::brakeType::hold);
      RightMotorBack.stop(vex::brakeType::hold);
      RightMotorMid.stop(vex::brakeType::hold);
    }
    // LeftMotorFront.spin(directionType::fwd, forwardSpeeds.leftspeed, velocityUnits::pct);
    // LeftMotorBack.spin(directionType::fwd, forwardSpeeds.leftspeed, velocityUnits::pct);
    // LeftMotorMid.spin(directionType::fwd, forwardSpeeds.leftspeed, velocityUnits::pct);
    // RightMotorFront.spin(directionType::fwd, forwardSpeeds.rightspeed, velocityUnits::pct);
    // RightMotorBack.spin(directionType::fwd, forwardSpeeds.rightspeed, velocityUnits::pct);
    // RightMotorMid.spin(directionType::fwd, forwardSpeeds.rightspeed, velocityUnits::pct);
    motorpair1();
    motor2_1();

    // spin1();
    // Example: Use joystick values to control the motors


    // Don't hog the CPU
    vex::task::sleep(20);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();


  // Prevent main from exiting with an infinite loop.
  while (true) {
    // wait(100, msec);
    vex::task::sleep(100);
  }
}
