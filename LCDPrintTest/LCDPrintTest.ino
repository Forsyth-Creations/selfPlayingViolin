#include <LiquidCrystal.h>
#include <Encoder.h>
#define sizeOfMenu1 4
int whichSelectionInMenu = 0;
int whichMenu = 0;
int selectedMenu = 0;

char* menu1[sizeOfMenu1] {
  "Play a Scale       ",
  "Play from Phone    ",
  "Demo Mode          ",
  "More Info          ",
};
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

#define rotaryPin1 A1
#define rotaryPin2 A2
Encoder myEnc(rotaryPin1, rotaryPin2);
#define buttonPinForRotar A0
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.createChar(1, stem1);
  lcd.createChar(2, note1);
  lcd.createChar(3, note2);
  lcd.createChar(4, stem2);
  lcd.createChar(5, pointer);
  lcd.createChar(0, miniNote);
  lcd.createChar(6, pointer);
  initialize(0, 5, 1000);
  delay(500);
  lcd.clear();
  printMenu(menu1, 0, 100, sizeOfMenu1);
  delay(500);
}
void loop() {
  beginSelfPlayingViolin();
}
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
void initialize(int startingPointForMusicNote, int startingPointForText, int delayTime) { //All values refer to x
  writeMusicNote(startingPointForMusicNote);
  lcd.setCursor(startingPointForText , 1);
  lcd.write(" Self-Playing");
  lcd.setCursor(startingPointForText , 2);
  lcd.write("   Violin  ");
  delay(delayTime);
}
void printMenu(char* inputArray[], int topTerm, int loadingDelay, int menuLength) {
  //lcd.clear();
  topTerm = abs(topTerm);
  lcd.setCursor(0 , 0);
  lcd.write(byte(6));
  char* printValue;
  for (int i = 0; i <= 3; i++) {
    lcd.setCursor(1 , i);
    printValue = inputArray[(i - (topTerm * -1)) % menuLength];
    lcd.write(printValue);
    delay(loadingDelay);
  }
  whichSelectionInMenu = topTerm % menuLength;
  //Serial.print("Menu #: ");
  //Serial.println(whichSelectionInMenu);
}
void beginSelfPlayingViolin() {
  char x = readRotar();
  int i;
  if (x == 'U') {
    i = 1;
  }
  else if (x == 'D') {
    i = -1;
  }
  else if (x == 'N') {
    i = 0;
  }
  int y = y + i;
  printMenu(menu1, y-1, 0, 4);
}

void menuManager(int whatMenuCurrently, int movingToWhatMenu) {
  String where = "UNKNOWN";
  String goingWhere = "UNKNOWN";

  while (digitalRead(buttonPinForRotar) == LOW) {
    delay(50);
  }

  switch (whatMenuCurrently) {
    case 0:
      switch (movingToWhatMenu) {
        case 0:
          Serial.println(menu1[0]);
          break;
        case 1:
          Serial.println(menu1[1]);
          break;
        case 2:
          Serial.println(menu1[2]);
          break;
        case 3:
          Serial.println(menu1[3]);
          break;

      }
      break;

    case 2:
      //thing
      break;
  }
}

long oldPosition  = -999;
char readRotar() {
  char returnValue;
  long absNumber;
  long testNumber;
  long newPosition = myEnc.read() / 4;
  if (newPosition != oldPosition) {
    absNumber = abs(oldPosition - newPosition);
    testNumber = oldPosition - newPosition;
    if (absNumber == testNumber)
    {
      //negativeTrend
      returnValue = 'D';
    }
    else {
      //positiveTrend
      returnValue = 'U';
    }
    oldPosition = newPosition;
    Serial.println(returnValue);
  }

  // Serial.println(newPosition/4);

  return returnValue;
}




