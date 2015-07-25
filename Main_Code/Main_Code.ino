#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

//Pan motor is connected to DC motor port M1 on shield
//Tilt motor is connected to DC motor port M2 on shield
//Pan potentiometer is connected to analog input 0
//Tilt potentiometer is connected to analog input 1

//potentiometers connected to analog pin 0 and analog pin 1.
//Center pin of the potentiometer goes to the analog pin.
//side pins of the potentiometer go to +5V and ground
 
 
int panPin = 0;
int tiltPin = 1;
int panValue = 0;
int tiltValue = 0;

int panUpper = 0; //lower and upper bounds on dead range in middle
int panLower = 0;
int tiltUpper = 0;
int tiltLower = 0;

int tiltMotorSpeed = 100; //speed default (between 0 and 255)
int panMotorSpeed = 100;  //speed default

//create motorshield object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

//Request two motors from motorshield
Adafruit_DCMotor *panMotor = AFMS.getMotor(1);
Adafruit_DCMotor *tiltMotor = AFMS.getMotor(2);

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  panMotor->setSpeed(panMotorSpeed)

}

void loop() {
  
  panValue = analogRead(panPin);
  tiltValue = analogRead(tiltPin);
  if (panValue < panLower) //Pan motor control
  {
    
    //panMotor->setSpeed(newPanSpeed) //between 0 and 255
    panMotor->run(REVERSE);
  }
  else if (panValue> panUpper)
  {
    panMotor->run(FORWARD);
  }
  else
  {
    panMotor->run(RELEASE);
  }
  
  if (tiltValue < tiltLower) //Tilt motor control
  {
    
    //tiltMotor->setSpeed(newTiltSpeed) //between 0 and 255
    ptiltMotor->run(REVERSE);
  }
  else if (tiltValue> tiltUpper)
  {
    tiltMotor->run(FORWARD);
  }
  else
  {
    tiltMotor->run(RELEASE);
  }
delay(1); //delay for stability
}
