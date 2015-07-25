#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

//Pan motor is connected to DC motor port M1 on shield
//Tilt motor is connected to DC motor port M2 on shield
//Pan potentiometer is connected to analog input 0
//Tilt potentiometer is connected to analog input 1
int panPin = 0;
int tiltPin = 1;
int panValue = 0;
int tiltValue = 0;

int panUpper = 0;
int panLower = 0;
int tiltUpper = 0;
int tiltLower = 0;

int tiltMotorSpeed = 100; //speed default
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
  if 

}
