#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int upServo1 = 70;
int upServo2 = 0;
int upServo3 = 180;
int upServo4 = 150;

void setup() {
  servo1.attach(7);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(4);
  allUp();
  delay(500);
}

void loop() {

  moveServo(4, true);
  delay(600);
  moveServo(3, true);
  delay(600);
  moveServo(2, true);
  delay(600);
  moveServo(1, true);
  delay(600);
  allUp();
  delay(2000);


}

void moveServo(int whatServo, boolean upOrDown) {
  //true means down
  switch (whatServo) {
      int i;
    case 1:
      i = whichWay(upOrDown);
      servo1.write(upServo1 + (50 * i * -1));
      break;
    case 2:
      i = whichWay(upOrDown);
      servo2.write(upServo2 + (90 * i * -1 ));
      break;
    case 3:
      i = whichWay(upOrDown);
      servo3.write(upServo3 + (100 * i));
      break;
    case 4:
      i = whichWay(upOrDown);
      servo4.write(upServo4 + (50 * i));
      break;
    default:
      allUp();
  }
}

void allUp() {
  servo1.write(70);
  servo2.write(0);
  servo3.write(180);
  servo4.write(150);
}

int whichWay(boolean doYouKnowDaWay) {
  int x;
  if (doYouKnowDaWay == 1) {
    x = -1;
  }
  else {
    x = 1;
  }
  return x;
}

