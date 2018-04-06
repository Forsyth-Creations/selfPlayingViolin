//--------- Stepper Motor Stuff --------
#include <Stepper.h>
#define stepperPin1 25
#define stepperPin2 26
#define stepperPin3 27
#define stepperPin4 28
const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution for your motor
const int speedOfStepperMotor = 60; //Value is represented in rpm, or revolutions per minute
Stepper bowStepper(stepsPerRevolution, stepperPin1, stepperPin2, stepperPin3, stepperPin4);
//use  myStepper.step((-)stepsPerRevolution); to control motor
// ^ Positive values are clockwise, whereas negative are counterclockwise

//--------- Rotary Encoder Stuff ---------------
#include <Encoder.h>
#define rotaryPin1 A1
#define rotaryPin2 A2
Encoder myEnc(rotaryPin1, rotaryPin2);
#define buttonPinForRotar A0

//------------Screen Stuff -------------
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//------------Servo Stuff--------------
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
//-----------Hardware Definitions-------
#define servoPin1 7
#define servoPin2 6
#define servoPin3 5
#define servoPin4 4


#define mainMenuLength 4
char* mainMenu[mainMenuLength] =
{
  "Play a Scale       ",
  "Play from Phone    ",
  "Demo Mode          ",
  "More Info          ",
};
//------------Special Characters-------
byte miniNote[8] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B01101,
  B11111,
  B11111,
  B01100,
};
byte stem1[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};
byte pointer[8] = {
  B00000,
  B11000,
  B11100,
  B11111,
  B11111,
  B11100,
  B11000,
  B00000,
};
byte note1[8] = {
  B00011,
  B00111,
  B01111,
  B11111,
  B11111,
  B01111,
  B00111,
  B00011,
};
byte note2[8] = {
  B11100,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100,
  B11000,
};
byte stem2[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
};
//------- Important Variables ---------------

long rotarRead = 0;
int whereInMenu = 0;
const int upServo1 = 70;
const int upServo2 = 0;
const int upServo3 = 180;
const int upServo4 = 150;

//---------- Scale Arrays  -- (1 is flat, 2 is natural, 3 is sharp)
int gScaleStrings[] = {4, };
char gScaleNotes[] =   {'G', };
int gScaleAccident[] = { 2 , };

//-------- Set-Up --------------
void setup() {
  bowStepper.setSpeed(speedOfStepperMotor);
  lcd.createChar(1, stem1);
  lcd.createChar(2, note1);
  lcd.createChar(3, note2);
  lcd.createChar(4, stem2);
  lcd.createChar(5, pointer);
  lcd.createChar(0, miniNote);
  lcd.createChar(6, pointer);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  Serial.begin(9600);
  lcd.begin(20, 4);
  initialize(0, 4, 3000);
}

//---------- Loop --------------
void loop() {
  printMainMenu();
  rotarRead = readRotar();
  //readRotar();
  //Serial.println(whereInMenu);
  if (buttonPressed()) {
    Serial.println("BUTTON PRESSED");
    switch (whereInMenu) {
      case 0:
        Serial.println(mainMenu[0]);
        subMenuA();
        break;
      case 1:
        Serial.println(mainMenu[1]);
        subMenuB();
        break;
      case 2:
        Serial.println(mainMenu[2]);
        subMenuC();
        break;
      case 3:
        Serial.println(mainMenu[3]);
        subMenuD();
        break;
      default:
        Serial.println("No menu selected from main screen");
    }
  }
}

//---------Initiatilize Sequence For Screen ---------
void initialize(int startingPointForMusicNote, int startingPointForText, int delayTime) { //All values refer to x
  writeMusicNote(startingPointForMusicNote);
  lcd.setCursor(startingPointForText , 1);
  lcd.write("  Self-Playing");
  lcd.setCursor(startingPointForText , 2);
  lcd.write("     Violin  ");
  initializeAllHardware();
  delay(delayTime);
}

//--------- Initialize All Components -----------
void initializeAllHardware() {
  allUp();
  resetStepperMotors();
}

//------- Resets Position of Stepper Motors ----------
void resetStepperMotors() {




}

//------- Write Big Music Note ----------------
void writeMusicNote(int xPos) {
  lcd.setCursor(xPos + 2 , 0);
  lcd.write(byte(1));
  lcd.setCursor(xPos + 2 , 1);
  lcd.write(byte(1));
  lcd.setCursor(xPos + 2 , 2);
  lcd.write(byte(1));
  lcd.setCursor(xPos + 2 , 3);
  lcd.write(byte(4));
  lcd.setCursor(xPos , 3);
  lcd.write(byte(2));
  lcd.setCursor(xPos + 1 , 3);
  lcd.write(byte(3));
}

//--------- Rotar Below -------------------
long oldPosition  = -999;
int readRotar() {
  long newPosition = myEnc.read() / 4;
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    lcd.clear();
  }
  if (buttonPressed()) {
    newPosition = 0;
  }
  return newPosition;  //Should I make this a void and just put the value into rotar?
}

//-------- Main Menu Print ----------------
void printMainMenu() {
  lcd.setCursor(0, 0);
  lcd.print("->");
  for (int i = 0; i <= 3; i++) {
    int x = ((rotarRead + i) % mainMenuLength);
    Serial.println(x);
    lcd.setCursor(2, i);
    lcd.print(mainMenu[x]);
  }
  whereInMenu = ((rotarRead) % mainMenuLength);
}

//-------- Button Pressed -----------------
boolean buttonPressed() {
  boolean b  = !digitalRead(buttonPinForRotar);
  while (digitalRead(buttonPinForRotar) == 0) {}
  if (digitalRead(buttonPinForRotar) == 0) {
    lcd.clear();
  }
  return b;
}

//-------- One Step in: Sub Menu A "PLAY A SCALE"--------
void subMenuA() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("In sub menu A");
  while (!buttonPressed()) {
    //Do stuff here
  }
  lcd.clear();
}

//-------- One Step in: Sub Menu B "PLAY FROM PHONE"--------
void subMenuB() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("In sub menu B");
  while (!buttonPressed()) {
    //Do stuff here
  }
  lcd.clear();
}

//-------- One Step in: Sub Menu C "DEMO MODE"--------
void subMenuC() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("In sub menu C");
  while (!buttonPressed()) {
    //Do stuff here
  }
  lcd.clear();
}

//-------- One Step in: Sub Menu D "MORE INFO"--------
void subMenuD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("In sub menu D");
  while (!buttonPressed()) {
    lcd.setCursor(0, 0);
    lcd.print("  This device was  ");
    lcd.setCursor(0, 1);
    lcd.print(" designed to teach.");
    lcd.setCursor(0, 2);
    lcd.print("  Plain and simple ");
    lcd.setCursor(0, 3);
    lcd.print("   -Forsyth/Lee  ");
  }
  lcd.clear();
}

//----- SERVO STUFF SHOULD ALL BE BELOW THIS LINE. ALL MENUS SHOULD BE ABOVE-------
void allUp() {
  servo1.write(upServo1);
  servo2.write(upServo2);
  servo3.write(upServo3);
  servo4.write(upServo4);
}

//--------Untested Method. Meant to play whatever scale is specified-----------
void playScale(int stringNumber[], char notes[], int accidentals[], int howManyOctaves, int delayTime) {
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

//---- Custom Delay To Avoid Code Pause -----------
void customDelay(int delayTimeMls) {
  int x = millis();
  while (x > (millis() + delayTimeMls)) {
    //potentially readRotar() here? I want to exit the program if something happens
  }
}
