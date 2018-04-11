#include "d_scales.h"
#include "a_MenuArrays.h"
#include "b_Global.h"
#include "c_SpecChars.h"
#include "e_LCD.h"
#include "f_rotar.h"
#include "g_OneStepInMenus.h"

//------- Setup ----------------------
void setup() {
  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin3, OUTPUT);
  pinMode(servoPin4, OUTPUT);
  pinMode(lcdPin1, OUTPUT);
  pinMode(lcdPin2, OUTPUT);
  pinMode(lcdPin3, OUTPUT);
  pinMode(lcdPin4, OUTPUT);
  pinMode(lcdPin5, OUTPUT);
  pinMode(lcdPin6, OUTPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  bowStepper.setSpeed(120);
  lcd.begin(20, 4);
  lcd.createChar(1, stem1);
  lcd.createChar(2, note1);
  lcd.createChar(3, note2);
  lcd.createChar(4, stem2);
  lcd.createChar(5, pointer);
  lcd.createChar(0, miniNote);
  lcd.createChar(6, pointer);
  Serial.begin(9600);
  initialize(0, 5, 3000);
  lcd.clear();
}
void loop() {
  printMainMenu();
  rotarRead = readRotar();
  //Serial.println(whereInMenu);
  if (buttonPressed()) {
    Serial.println("BUTTON PRESSED");
    switch (whereInMenu) {
      case 0:
        Serial.println(mainMenu[0]);
        subMenuA();
        myEnc.write(0);
        break;
      case 1:
        Serial.println(mainMenu[1]);
        subMenuB();
        myEnc.write(0);
        break;
      case 2:
        Serial.println(mainMenu[2]);
        subMenuC();
        myEnc.write(0);
        break;
      case 3:
        Serial.println(mainMenu[3]);
        subMenuD();
        myEnc.write(0);
        break;
      case 4:
        Serial.println(mainMenu[4]);
        subMenuE();
        myEnc.write(0);
        break;
      default:
        Serial.println("No menu selected from main screen");
    }
  }
}


//------- All motors/Hardware BELOW ------

void stepperMotorTest() {
    bowStepper.setSpeed(40);
  // step one revolution  in one direction:
  Serial.println("clockwise");
  bowStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  bowStepper.step(-stepsPerRevolution);
  delay(500);
}


//--------- Initialize All Components -----------
void initializeAllHardware() {
  allUp();
  Serial.println("All Servos Up and Ready");
  resetStepperMotors();
}

//------- Resets Position of Stepper Motors ----------
void resetStepperMotors() {
  Serial.println("initializing steppper");
  long timeCheck = millis();
  while (digitalRead(stepperMotorButtonPin) == 0 && (timeCheck + 10000) > millis()) {
    bowStepper.step(15);
    Serial.println(digitalRead(stepperMotorButtonPin));
    //      ();
  }
  delay(400);
  if (digitalRead(stepperMotorButtonPin) == 1) {
    Serial.println("Stepper Motor for Bow Calibrated");
    bowStepper.step(60);
  }
  else {
    Serial.println("Calibration Failed. Check hardware, then restart program");
  }
}

//----- SERVO STUFF SHOULD ALL BE BELOW THIS LINE. ALL MENUS SHOULD BE ABOVE-------
void allUp() {
  servo1.write(upServo1);
  servo2.write(upServo2);
  servo3.write(upServo3);
  servo4.write(upServo4);
}

//------- Back Finder-------------

int whereIsBackOption(char* menuTesting[], int menuLength) {
  int returnInt;
  for (int i; i <= menuLength; i++) {
    if ((menuTesting[i] == "Back") || (menuTesting[i] == "Go Back") || (menuTesting[i] == "BACK") || (menuTesting[i] == "GO BACK")) {
      returnInt = i;
      Serial.print("Back foudn in menu! It is this line in the array:");
      Serial.println(returnInt);
      break;
    }
  }
  return returnInt;
}

//-------- Misc Servo Stuff ------------

//-----Controls Servos. Moves all to up position except one specified -------------
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

//--------Untested Method. Meant to play whatever scale is specified-----------
void playScale(int stringNumber[], char* notes[], int accidentals[], int howManyOctaves, int delayTime) {
  howManyOctaves  = howManyOctaves * 8;
  for ( int i; i < howManyOctaves; i++) {
    playNote(stringNumber[i], notes[i], accidentals[i]);
    delay(delayTime);
  }
}

//----- Important Method. Plays whatever note specified ----------
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

//--------- Moves a Servo Up or Down ------------------
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
  delay(160);
  allUpExcept(whatServo);
}

//----Helps with servo orientation, to know which way is up, which way is down----
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
