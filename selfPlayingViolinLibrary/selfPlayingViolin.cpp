/*
 * the selfPlayingViolin Library was
 * developed by Henry Forsyth
 * on March 20, 2018, for a group
 * science fair project. All rights to the 
 * library's use go to Mr.Forsyth, but it
 * should be used freely for the betterment 
 * of any musician.
 * Releaseed into the Public Domain
 */

#include "Arduino.h"
#include "selfPlayingViolin.h"

selfPlayingViolin::selfPlayingViolin(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void selfPlayingViolin::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void selfPlayingViolin::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}
