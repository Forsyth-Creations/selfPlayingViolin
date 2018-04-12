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
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
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
  int flat = 1;
  int natural = 2;
  int sharp = 3;

  switch (stringNumber) {
    case 1: //E String
      break;
    case 2: //A String
      break;
    case 3: //D String
      if (note == 'D' && accidental == natural) {
        moveServo(0, false);
        Serial.print("D string, note ");
        Serial.println(note);
      }
      if (note == 'E' && accidental == natural) {
        moveServo(1, true);
        Serial.print("D string, note ");
        Serial.println(note);
      }
      if (note == 'F' && accidental == natural) {
        moveServo(2, true);
        Serial.print("D string, note ");
        Serial.println(note);
      }
      if (note == 'F' && accidental == sharp) {
        moveServo(3, true);
        Serial.print("D string, note ");
        Serial.println(note);
      }
      if (note == 'G' && accidental == natural) {
        moveServo(4, true);
        Serial.print("D string, note ");
        Serial.println(note);
      }

      break;
    case 4: //G String
      if (note == 'G' && accidental == natural) {
        moveServo(0, false);
        Serial.print("G string, note ");
        Serial.println(note);
      }
      if (note == 'A' && accidental == natural) {
        moveServo(1, true);
        Serial.print("G string, note ");
        Serial.println(note);
      }
      if (note == 'B' && accidental == natural) {
        moveServo(3, true);
        Serial.print("G string, note ");
        Serial.println(note);
      }
      if (note == 'B' && accidental == flat) {
        moveServo(2, true);
        Serial.print("G string, note ");
        Serial.println(note);
      }
      if (note == 'C' && accidental == natural) {
        moveServo(4, true);
        Serial.print("G string, note ");
        Serial.println(note);
      }
      break;
  }
}

void oneOctaveGScale() {
  int speedOfNotes = 50;
  Serial.println("Starting Scale");
  playNote(4, 'G', 2);
  pauseFor(speedOfNotes);
  playNote(4, 'A', 2);
  pauseFor(speedOfNotes);
  playNote(4, 'B', 2);
  pauseFor(speedOfNotes);
  playNote(4, 'C', 2);
  pauseFor(speedOfNotes);
  playNote(3, 'D', 2);
  pauseFor(speedOfNotes);
  playNote(3, 'E', 2);
  pauseFor(speedOfNotes);
  playNote(3, 'F', 3);
  pauseFor(speedOfNotes);
  playNote(3, 'G', 2);
  pauseFor(speedOfNotes);
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
  int brightness = 200;
  switch (ledNumber) {
    case 1:
      analogWrite(led1Pin, brightness);
      analogWrite(led2Pin, 0);
      analogWrite(led3Pin, 0);
      analogWrite(led4Pin, 0);
      break;
    case 2:
      analogWrite(led1Pin, 0);
      analogWrite(led2Pin, brightness);
      analogWrite(led3Pin, 0);
      analogWrite(led4Pin, 0);
      break;
    case 3:
      analogWrite(led1Pin, 0);
      analogWrite(led2Pin, 0);
      analogWrite(led3Pin, brightness);
      analogWrite(led4Pin, 0);
      break;
    case 4:
      analogWrite(led1Pin, 0);
      analogWrite(led2Pin, 0);
      analogWrite(led3Pin, 0);
      analogWrite(led4Pin, brightness);
      break;
  }
}

void pauseFor(int delayTime) {
  /*
  boolean stillPressed;
  int timeDelayStarted  = millis();
  while (timeDelayStarted + delayTime > millis()) {
    Serial.print("timeDelayStarted :");
    Serial.println(timeDelayStarted);
    Serial.print("millis :");
    Serial.println(millis());
    /*
    Serial.println("TEST 1");
    if (digitalRead(buttonPin) == HIGH) {
      Serial.println("BUTTON PRESSED");
      while ( digitalRead(buttonPin) == HIGH) {
        delay(50);
        Serial.println("I'm Here 1");
      }
      Serial.println("Going back to code");
      return;
    }
    */
  //  delay(1);
  //}
  
  
  delay(delayTime);
}


