/*---------------------------------------------------------------------------------
    _____ ___________________  
  /  _  \\______   \_   ___ \ 
 /  /_\  \|       _/    \  \/ 
/    |    \    |   \     \____
\____|__  /____|_  /\______  /
        \/       \/        \/ 
  An OpenSource Pythagorean based 2D plotter
      By: Glenn Lopez

Github page: https://github.com/glennlopez/Arc/tree/master
  (visit the link above for the latest version history & revision)    
---------------------------------------------------------------------------------*/

#ifndef _AFMotor_h_
#define _AFMotor_h_
#include <inttypes.h>
#include <avr/io.h>

//------------------------------------------------------------------------------

//#define MOTORDEBUG 1

#define MICROSTEPS 16  // 8 or 16

#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR4_A 0
#define MOTOR4_B 6
#define MOTOR3_A 5
#define MOTOR3_B 7

#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4

// Arduino pin names
#define MOTORLATCH 12
#define MOTORCLK 4
#define MOTORENABLE 7
#define MOTORDATA 8

//------------------------------------------------------------------------------

class AFMotorController 
 {
  public:
  AFMotorController();
  void enable();
  friend class AF_DCMotor;
  void latch_tx();
 };


class AF_Stepper {
public:
  AF_Stepper(uint16_t, uint8_t);
  void step(uint16_t steps, uint8_t dir);
  void setSpeed(uint16_t);
  uint8_t onestep(uint8_t dir);
  void release();
  uint16_t revsteps; // # steps per revolution
  uint8_t steppernum;
  uint32_t usperstep, steppingcounter;
private:
  uint8_t currentstep;
  uint8_t a, b, c, d;
};

//------------------------------------------------------------------------------
#endif