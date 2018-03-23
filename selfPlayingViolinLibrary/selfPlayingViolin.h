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

#ifndef selfPlayingViolin_h
#define selfPlayingViolin_h

#include <Servo.h>
#include "Arduino.h"

#define led1Pin A0
#define led2Pin A1
#define led3Pin A2
#define led4Pin A3

class selfPlayingViolin
{
  public:
    selfPlayingViolin(int servoPin1, int servoPin2, int servoPin3, int servoPin4);
    void testMethod();
    void allOffExcept(int ledNumber);
    void testMethodTwo();
  private:
    int _servoPin1;
    int _servoPin2;
    int _servoPin3;
    int _servoPin4;
    int _upServo1 = 70;
    int _upServo2 = 0;
    int _upServo3 = 180;
    int _upServo4 = 150;
};

#endif
