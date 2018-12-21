#include "d_scales.h"
#include "a_MenuArrays.h"
#include "b_Global.h"
#include "c_SpecChars.h"
#include "e_LCD.h"
#include "f_rotar.h"
#include "g_OneStepInMenus.h"
#include "servo.h"
#include "stepperMotor.h"

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
//--------- Initialize All Components -----------
void initializeAllHardware() {
  Serial.println("Self Playing Violin Running Version 2.0");
  allUp();
  Serial.println("All Servos Up and Ready");
  delay(2000);
  resetStepperMotors();
}
//------- Back Finder-------------
int whereIsBackOption(char* menuTesting[], int menuLength) {
  int returnInt;
  for (int i = 0; i <= menuLength; i++) {
    if ((menuTesting[i] == "Back") || (menuTesting[i] == "Go Back") || (menuTesting[i] == "BACK") || (menuTesting[i] == "GO BACK")) {
      returnInt = i;
      Serial.print("Back found in menu! It is this index in the array:");
      Serial.println(returnInt);
      break;
    }
  }
  return returnInt;
}

