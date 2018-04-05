#include <Encoder.h>
#define rotaryPin1 A1
#define rotaryPin2 A2
Encoder myEnc(rotaryPin1, rotaryPin2);
#define buttonPinForRotar A0

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
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

//-------------------------------------------

void setup() {
  lcd.createChar(1, stem1);
  lcd.createChar(2, note1);
  lcd.createChar(3, note2);
  lcd.createChar(4, stem2);
  lcd.createChar(5, pointer);
  lcd.createChar(0, miniNote);
  lcd.createChar(6, pointer);
  Serial.begin(9600);
  lcd.begin(20, 4);
  initialize(0, 4, 3000);
}

void loop() {
  printMainMenu();
  rotarRead = readRotar();
  //Serial.println(whereInMenu);
  if (buttonPressed()) {
    rotarRead = 0;
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
//---------Initiatilize Sequence ---------
void initialize(int startingPointForMusicNote, int startingPointForText, int delayTime) { //All values refer to x
  writeMusicNote(startingPointForMusicNote);
  lcd.setCursor(startingPointForText , 1);
  lcd.write("  Self-Playing");
  lcd.setCursor(startingPointForText , 2);
  lcd.write("     Violin  ");
  delay(delayTime);
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
long readRotar() {
  long newPosition = myEnc.read() / 4;
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    lcd.clear();
  }
  return newPosition;
}
//-------- Main Menu Print ----------------
void printMainMenu() {
  lcd.setCursor(0,0);
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
  if(digitalRead(buttonPinForRotar) == 0){
    lcd.clear();
  }
  return b;
}

//-------- One Step in: Sub Menu A "PLAY A SCALE"--------

void subMenuA(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("In sub menu A");
  while(!buttonPressed()){
//Do stuff here
  }
  lcd.clear();
}
//-------- One Step in: Sub Menu B "PLAY FROM PHONE"--------
void subMenuB(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("In sub menu B");
  while(!buttonPressed()){
//Do stuff here
  }
  lcd.clear();
}
//-------- One Step in: Sub Menu C "DEMO MODE"--------
void subMenuC(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("In sub menu C");
  while(!buttonPressed()){
//Do stuff here
  }
  lcd.clear();
}
//-------- One Step in: Sub Menu D "MORE INFO"--------
void subMenuD(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("In sub menu D");
  while(!buttonPressed()){
    lcd.setCursor(0,0);
    lcd.print("  This device was  ");
    lcd.setCursor(0,1);
    lcd.print(" designed to teach.");
    lcd.setCursor(0,2);
    lcd.print("  Plain and simple ");
    lcd.setCursor(0,3);
    lcd.print("   -Forsyth/Lee  ");
  }
  lcd.clear();
}

