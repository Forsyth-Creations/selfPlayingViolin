#include <Servo.h>
Servo servoOne;
Servo servoTwo;
Servo servoThree;


//Jingle Bells stuff
int jingleBells[] = {0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 3, 3, 0, 0, 2, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0};
int jbBowMovement[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int jbtempo = 100;

int minServoPos = 50;
int maxServoPos = 100;

void setup() {
  // put your setup code here, to run once:
  servoOne.attach(9);
  servoTwo.attach(8);
  servoThree.attach(7);
  Serial.begin(9600);
  allUp();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

  beginPlaying(jingleBells, jbBowMovement, jbtempo);
}

//this method works by taking a bow movement array, a song array, and a tempo int to run the song

void beginPlaying(int bowMove[], int notes[], int tempo) {

  int i;
  int previousi = 0;
  for (i = 0; i < sizeof(notes) / sizeof(i); i = i + 1) {
    Serial.println(notes[i]);
    if ( i == previousi) {
      delay(tempo);
    }
    else {
      switch (notes[i]) {
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
      delay(tempo);
      allUp();
    }
    previousi = i;
  }

}

void allUp() {
  servoOne.write(maxServoPos);              // tell servo to go to position in variable 'pos'
  servoTwo.write(maxServoPos);              // tell servo to go to position in variable 'pos'
  servoThree.write(maxServoPos);
}

