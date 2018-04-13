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

//---------Initiatilize Sequence ---------
void initialize(int startingPointForMusicNote, int startingPointForText, int delayTime) { //All values refer to x
  writeMusicNote(startingPointForMusicNote);
  lcd.setCursor(startingPointForText , 1);
  lcd.write(" Self-Playing");
  lcd.setCursor(startingPointForText , 2);
  lcd.write("   Violin  ");
  initializeAllHardware();
 // delay(delayTime);
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

