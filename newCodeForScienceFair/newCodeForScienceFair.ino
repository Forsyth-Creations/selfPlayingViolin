#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int upServo1 = 70;
int upServo2 = 0;
int upServo3 = 180;
int upServo4 = 150;

#define led1Pin A0
#define led2Pin A1
#define led3Pin A2
#define led4Pin A3
#define buttonPin 3
#define servoPin1 7
#define servoPin2 6
#define servoPin3 5
#define servoPin4 4


void setup() {
  Serial.begin(9600);
  servo1.attach(7);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(4);
  allUp();
  delay(500);
}

void loop() {
  oneOctaveGScale();
}

void moveServo(int whatServo, boolean upOrDown) {
  //true means down
  switch (whatServo) {
      int i;
    case 1:
      i = whichWay(upOrDown);
      servo1.write(upServo1 + (50 * i * -1));
      allOffExcept(whatServo);
      break;
    case 2:
      i = whichWay(upOrDown);
      servo2.write(upServo2 + (90 * i * -1 ));
      allOffExcept(whatServo);
      break;
    case 3:
      i = whichWay(upOrDown);
      servo3.write(upServo3 + (100 * i));
      allOffExcept(whatServo);
      break;
    case 4:
      i = whichWay(upOrDown);
      servo4.write(upServo4 + (50 * i));
      allOffExcept(whatServo);
      break;
    default:
      allUp();
  }
  delay(160);
  allUpExcept(whatServo);
}

void allUp() {
  servo1.write(upServo1);
  servo2.write(upServo2);
  servo3.write(upServo3);
  servo4.write(upServo4);
  analogWrite(led1Pin, 0);
  analogWrite(led2Pin, 0);
  analogWrite(led3Pin, 0);
  analogWrite(led4Pin, 0);
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

void allUpExcept(int servoNumber) {
  switch (servoNumber) {
    case 1:
      servo2.write(upServo2);
      servo3.write(upServo3);
      servo4.write(upServo4);
      break;
    case 2:
      servo1.write(upServo1);
      servo3.write(upServo3);
      servo4.write(upServo4);
      break;
    case 3:
      servo1.write(upServo1);
      servo2.write(upServo2);
      servo4.write(upServo4);
      break;
    case 4:
      servo1.write(upServo1);
      servo2.write(upServo2);
      servo3.write(upServo3);
      break;
    default:
      allUp();
  }

}

void playNote(int stringNumber, char note, int accidental) {
  //The violin strings are numbered left to right (G = 4, D = 3, A = 2, E = 1)
  //any input on the accidental should be either 1 (flat), 2 (Natural), or 3 (Sharp)
  switch (stringNumber) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      if (note == 'D' && accidental == 2) {
        moveServo(0, false);
        Serial.print("D string, note ");
        Serial.println(note);
      }
      if (note == 'E' && accidental == 2) {
        moveServo(1, true);
        Serial.print("D string, note ");
        Serial.println(note);
      }
      if (note == 'F' && accidental == 2) {
        moveServo(2, true);
        Serial.print("D string, note ");
        Serial.println(note);
      }
      if (note == 'F' && accidental == 3) {
        moveServo(3, true);
        Serial.print("D string, note ");
        Serial.println(note);
      }
      if (note == 'G' && accidental == 2) {
        moveServo(4, true);
        Serial.print("D string, note ");
        Serial.println(note);
      }

      break;
    case 4:
      if (note == 'G' && accidental == 2) {
        moveServo(0, false);
        Serial.print("G string, note ");
        Serial.println(note);
      }
      if (note == 'A' && accidental == 2) {
        moveServo(1, true);
        Serial.print("G string, note ");
        Serial.println(note);
      }
      if (note == 'B' && accidental == 2) {
        moveServo(3, true);
        Serial.print("G string, note ");
        Serial.println(note);
      }
      if (note == 'B' && accidental == 1) {
        moveServo(2, true);
        Serial.print("G string, note ");
        Serial.println(note);
      }
      if (note == 'C' && accidental == 2) {
        moveServo(4, true);
        Serial.print("G string, note ");
        Serial.println(note);
      }

      break;

  }
}

void oneOctaveGScale() {
  Serial.println("Starting Scale");
  playNote(4, 'G', 2);
  pauseFor(1000);
  playNote(4, 'A', 2);
  pauseFor(1000);
  playNote(4, 'B', 2);
  pauseFor(1000);
  playNote(4, 'C', 2);
  pauseFor(1000);
  playNote(3, 'D', 2);
  pauseFor(1000);
  playNote(3, 'E', 2);
  pauseFor(1000);
  playNote(3, 'F', 3);
  pauseFor(1000);
  playNote(3, 'G', 2);
  pauseFor(1000);
  //back down now
  playNote(3, 'G', 2);
  pauseFor(1000);
  playNote(3, 'F', 3);
  pauseFor(1000);
  playNote(3, 'E', 2);
  pauseFor(1000);
  playNote(3, 'D', 2);
  pauseFor(1000);
  playNote(4, 'C', 2);
  pauseFor(1000);
  playNote(4, 'B', 2);
  pauseFor(1000);
  playNote(4, 'A', 2);
  pauseFor(1000);
  playNote(4, 'G', 2);
  pauseFor(1000);
}

void setAllToNinety() {
  servo1.write(105);
  servo2.write(70);
  servo3.write(90);
  servo4.write(120);
}

void allOffExcept(int ledNumber) {
  switch (ledNumber) {
    case 1:
      analogWrite(led1Pin, 200);
      analogWrite(led2Pin, 0);
      analogWrite(led3Pin, 0);
      analogWrite(led4Pin, 0);
      break;
    case 2:
      analogWrite(led1Pin, 0);
      analogWrite(led2Pin, 200);
      analogWrite(led3Pin, 0);
      analogWrite(led4Pin, 0);
      break;
    case 3:
      analogWrite(led1Pin, 0);
      analogWrite(led2Pin, 0);
      analogWrite(led3Pin, 200);
      analogWrite(led4Pin, 0);
      break;
    case 4:
      analogWrite(led1Pin, 0);
      analogWrite(led2Pin, 0);
      analogWrite(led3Pin, 0);
      analogWrite(led4Pin, 200);
      break;
  }

}

void pauseFor(int delayTime) {

  for (int i = 0; i < delayTime/100; i++) {
    delay(100);
    if (digitalRead(buttonPin) == HIGH) {
      Serial.println("BUTON PRESSED");
      delay(100);
      do {
        delay(100);
      } while (digitalRead(buttonPin) == LOW);
     
    }

  }
return;

}
