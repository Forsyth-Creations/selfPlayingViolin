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
int scale[] = {0,2,2,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,3,3,0,0,2,2,0,0,1,1,0,0,0,0,0};
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
  scaleOne();
}
void allUp() {
  servoOne.write(maxServoPos);              // tell servo to go to position in variable 'pos'
  servoTwo.write(maxServoPos);              // tell servo to go to position in variable 'pos'
  servoThree.write(maxServoPos);
}
void scaleOne() {
  int speedOfPlay = 125;
  int i;
  int previousi = 0;
  for (i = 0; i < sizeof(scale) / sizeof(i); i = i + 1) {
    Serial.println(scale[i]);
    if ( i == previousi) {
      delay(speedOfPlay);
    }
    else {
      switch (scale[i]) {
        case 1:
          servoOne.write(minServoPos);              // tell servo to go to position in variable 'pos'
          break;
        case 2:
          servoTwo.write(minServoPos);              // tell servo to go to position in variable 'pos'
          break;
        case 3:
          servoThree.write(minServoPos);              // tell servo to go to position in variable 'pos'
          break;
       default:
          allUp();
      }
      delay(speedOfPlay);
      allUp();
    }
    previousi = i;
  }
}
void moveAll() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoOne.write(pos);              // tell servo to go to position in variable 'pos'
    servoTwo.write(pos);              // tell servo to go to position in variable 'pos'
    servoThree.write(pos);              // tell servo to go to position in variable 'pos'

    delay(pace);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servoOne.write(pos);              // tell servo to go to position in variable 'pos'
    servoTwo.write(pos);              // tell servo to go to position in variable 'pos'
    servoThree.write(pos);              // tell servo to go to position in variable 'pos'
    delay(pace);                       // waits 15ms for the servo to reach the position
  }
}

