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
const int stepsPerRevolution = 400 ; // change this to fit the number of steps per revolution for your motor
const int speedOfStepperMotor = 30; //Value is represented in rpm, or revolutions per minute
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
//------ Critical Variables------------------
long rotarRead = 0;
int whereInMenu = 0;
const int upServo1 = 70;
const int upServo2 = 0;
const int upServo3 = 180;
const int upServo4 = 150;

//-----  Function/Method Declarations ------
void initializeAllHardware();
void writeMusicNote();
void initialize();
long readRotar();
void printMainMenu();
void printMenu();
boolean buttonPressed();
void subMenuA();
void subMenuB();
void subMenuC();
void subMenuD();
void subMenuE();
int whereIsBackOption(char* menuTesting[], int menuLength);
void allUp();
int whichWay();
void moveServo();
void playNote(int stringNumber, char note, int accidental);
void playScale(int stringNumber[], char* notes[], int accidentals[], int howManyOctaves, int delayTime);
void allUpExcept(int servoNumber);
void resetStepperMotors();
void initializeAllHardware();
void stepperMotorTest();
