/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

/* Other Mentions
  All other code written by Joseph Lee and Henry Forsyth
  https://github.com/HullabalooRobotics/selfPlayingViolin.git
*/

#include <Servo.h>

Servo servoOne;
Servo servoTwo;
Servo servoThree;
int pace = 8;
int scale[] = {0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 3, 3, 0, 0, 2, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0};
int minServoPos = 50;
int maxServoPos = 100;

int pos = 0;    // variable to store the servo position

void setup() {
  servoOne.attach(9);
  servoTwo.attach(8);
  servoThree.attach(7);
  Serial.begin(9600);
  allUp();
  delay(2000);
}

void loop() {
  //jingleBells();
  jingleBells();
}
void allUp() {
  servoOne.write(maxServoPos);              // tell servo to go to position in variable 'pos'
  servoTwo.write(maxServoPos);              // tell servo to go to position in variable 'pos'
  servoThree.write(maxServoPos);
}
