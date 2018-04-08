
//------ All Definitions -------------
#define stepperPin1 45
#define stepperPin2 43
#define stepperPin3 41
#define stepperPin4 39
#define rotaryPin1 A1
#define rotaryPin2 A2
#define stepperMotorButtonPin 28
#define buttonPinForRotar A0
#define servoPin1 53
#define servoPin2 51
#define servoPin3 49
#define servoPin4 47
#define lcdPin1 12
#define lcdPin2 11
#define lcdPin3 5
#define lcdPin4 4
#define lcdPin5 3
#define lcdPin6 2

//--------- Stepper Motor Stuff --------
#include <Stepper.h>
const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution for your motor
const int speedOfStepperMotor = 60; //Value is represented in rpm, or revolutions per minute
Stepper bowStepper(stepsPerRevolution, stepperPin1, stepperPin2, stepperPin3, stepperPin4);
//use bowStepper.step((-)stepsPerRevolution); to control motor
// ^ Positive values are clockwise, whereas negative are counterclockwise

//-----  All Encoder Stuff -----------
#include <Encoder.h>
Encoder myEnc(rotaryPin1, rotaryPin2);

//--------- LCD Stuff ----------------
#include <LiquidCrystal.h>
LiquidCrystal lcd(lcdPin1, lcdPin2, lcdPin3, lcdPin4, lcdPin5, lcdPin6);

//------------Servo Stuff--------------
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

//------ Menus ---------------
#define mainMenuLength 4
char* mainMenu[mainMenuLength] =
{
  "Play a Scale       ",
  "Play from Phone    ",
  "Demo Mode          ",
  "More Info          ",
};

#define scaleMainMenuLength 8
char* scaleMainMenu[scaleMainMenuLength] =
{
  "A Major,Two Octave",
  "B Major,Two Octave",
  "C Major,Two Octave",
  "D Major,Two Octave",
  "E Major,Two Octave",
  "F Major,Two Octave",
  "G Major,Two Octave",
  "Back",

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
//------ Critical Variables------------------
long rotarRead = 0;
int whereInMenu = 0;
const int upServo1 = 70;
const int upServo2 = 0;
const int upServo3 = 180;
const int upServo4 = 150;

//--------- Scales --------------------
int gScaleStrings[] = {4, };
char gScaleNotes[] =   {'G', };
int gScaleAccident[] = { 2 , };

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
      default:
        Serial.println("No menu selected from main screen");
    }
  }
}
//---------Initiatilize Sequence ---------
void initialize(int startingPointForMusicNote, int startingPointForText, int delayTime) { //All values refer to x
  writeMusicNote(startingPointForMusicNote);
  lcd.setCursor(startingPointForText , 1);
  lcd.write(" Self-Playing");
  lcd.setCursor(startingPointForText , 2);
  lcd.write("   Violin  ");
  initializeAllHardware();
  delay(delayTime);
}

//------- Write Music Note ----------------
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
long readRotar() {
  long newPosition = myEnc.read() / 4;
  if (newPosition < 0 || oldPosition < 0) {
    newPosition = 0;
    oldPosition = 0;
    delay(50);
  }
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    lcd.clear();
    Serial.println(newPosition);
  }
  return newPosition;
}
//-------- Main Menu Print ----------------
void printMainMenu() {
  lcd.setCursor(0, 0);
  lcd.print("->");
  for (int i = 0; i <= 3; i++) {
    int x = ((rotarRead + i) % mainMenuLength);
    lcd.setCursor(2, i);
    lcd.print(mainMenu[x]);
  }
  whereInMenu = ((rotarRead) % mainMenuLength);
}
//------ Print Menu. Any menu --------------
void printMenu(char* inputArray[], int menuLength) {
  lcd.setCursor(0, 0);
  lcd.print("->");
  for (int i = 0; i <= 3; i++) {
    int x = ((rotarRead + i) % menuLength);
    lcd.setCursor(2, i);
    lcd.print(inputArray[x]);
  }
  whereInMenu = ((rotarRead) % menuLength);
}
//-------- Button Pressed -----------------
boolean buttonPressed() {
  boolean b  = !digitalRead(buttonPinForRotar);
  while (digitalRead(buttonPinForRotar) == 0) {
   // lcd.clear();
  }
  return b;
}

//-------- One Step in: Sub Menu A "PLAY A SCALE"--------
void subMenuA() {
  lcd.clear();
  lcd.setCursor(0, 0);
  int back = whereIsBackOption(scaleMainMenu, scaleMainMenuLength);
  //lcd.print("SCALES HERE");
  while (!buttonPressed() || whereInMenu != back) {
    rotarRead = readRotar();
    printMenu(scaleMainMenu, scaleMainMenuLength);

    if (whereInMenu == back && buttonPressed() == true) {
      break;
    }
    else if (buttonPressed()) {
      Serial.println("BUTTON PRESSED");
      switch (whereInMenu) {
        case 0:
          Serial.println(scaleMainMenu[0]);
          //subMenuA();
          break;
        case 1:
          Serial.println(scaleMainMenu[1]);
          //subMenuB();
          break;
        case 2:
          Serial.println(scaleMainMenu[2]);
          //subMenuC();
          break;
        case 3:
          Serial.println(scaleMainMenu[3]);
          //subMenuD();
          break;
        default:
          Serial.println("No menu selected from main screen");
      }
    }
  }
  lcd.clear();
  delay(100);
}

//-------- One Step in: Sub Menu B "PLAY FROM PHONE"--------
void subMenuB() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Work in Progress");
  while (!buttonPressed()) {
    //Do stuff here
  }
  lcd.clear();
  delay(100);
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
  delay(100);
}

//-------- One Step in: Sub Menu D "MORE INFO"--------
void subMenuD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("In sub menu D");
  lcd.setCursor(0, 0);
  lcd.print("  This device was  ");
  lcd.setCursor(0, 1);
  lcd.print(" designed to teach.");
  lcd.setCursor(0, 2);
  lcd.print("  Plain and simple ");
  lcd.setCursor(0, 3);
  lcd.print("   -Forsyth/Lee  ");
  while (!buttonPressed()) {
  }
  lcd.clear();
  delay(100);
}

//------- All motors/Hardware BELOW ------




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
  while (digitalRead(stepperMotorButtonPin) == 0 && (timeCheck + 6000) > millis()) {
    bowStepper.step(-15);
    Serial.println(digitalRead(stepperMotorButtonPin));
    //delay(20);
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
