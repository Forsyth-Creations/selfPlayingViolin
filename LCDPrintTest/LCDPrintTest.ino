#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
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

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  lcd.createChar(1, stem1);
  lcd.createChar(2, note1);
  lcd.createChar(3, note2);
  lcd.createChar(4, stem2);
  initialize(0, 5);
  delay(5000);
  lcd.clear();
}

void loop() {


  /*
    for(int i = 0; i < 4; i++){
       lcd.setCursor(0, i-1);
      lcd.write(" ");
     lcd.setCursor(0, i);
      lcd.write(byte(0));
      delay(500);
    }
  */
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

void initialize(int startingPointForMusicNote, int startingPointForText) { //All values refer to x
  writeMusicNote(startingPointForMusicNote);
  lcd.setCursor(startingPointForText , 0);
  lcd.write("Self-Playing");
  lcd.setCursor(startingPointForText , 1);
  lcd.write("   Violin  ");
  lcd.setCursor(startingPointForText , 2);
  lcd.write("By Mr.Forsyth");
  lcd.setCursor(startingPointForText , 3);
  lcd.write(" and Mr.Lee");

}


