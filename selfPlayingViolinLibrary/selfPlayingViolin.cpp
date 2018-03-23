/*
   the selfPlayingViolin Library was
   developed by Henry Forsyth
   on March 20, 2018, for a group
   science fair project. All rights to the
   library's use go to Mr.Forsyth, but it
   should be used freely for the betterment
   of any musician.
   Releaseed into the Public Domain
*/

#include "Arduino.h"
#include <Servo.h>
#include "selfPlayingViolin.h"
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

selfPlayingViolin::selfPlayingViolin(int servoPin1, int servoPin2, int servoPin3, int servoPin4)
{
  _servoPin1 = servoPin1;
  _servoPin2 = servoPin2;
  _servoPin3 = servoPin3;
  _servoPin4 = servoPin4;
  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin3, OUTPUT);
  pinMode(servoPin4, OUTPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
}

void selfPlayingViolin::testMethod()
{

testMethodTwo();

}

void selfPlayingViolin::testMethodTwo()
{
  //test
}


