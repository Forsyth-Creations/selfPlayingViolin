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

#ifndef selfPlayingViolin_h
#define selfPlayingViolin_h

#include "Arduino.h"

class selfPlayingViolin
{
  public:
    selfPlayingViolin(int pin);
    void dot();
    void dash();
  private:
    int _pin;

};

#endif
