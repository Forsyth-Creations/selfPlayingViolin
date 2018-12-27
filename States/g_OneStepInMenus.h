//-------- One Step in: Sub Menu A "PLAY A SCALE"--------
void subMenuA() {
  myEnc.write(0);
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
          playScale(gScaleStrings, gScaleNotes, gScaleAccident, 1, 1000);
          break;
        case 1:
          Serial.println(scaleMainMenu[1]);
          playScale(aScaleStrings, aScaleNotes, aScaleAccident, 1, 1000);
          break;
        case 2:
          Serial.println(scaleMainMenu[2]);
          playScale(bflatScaleStrings, bflatScaleNotes, bflatScaleAccident, 1, 1000);
          break;
        case 3:
          Serial.println(scaleMainMenu[3]);
          playScale(cScaleStrings, cScaleNotes, cScaleAccident, 1, 1000);
          break;
        case 4:
          Serial.println(scaleMainMenu[3]);
          playScale(dScaleStrings, dScaleNotes, dScaleAccident, 1, 1000);
          break;
        case 5:
          Serial.println(scaleMainMenu[3]);
          playScale(eflatScaleStrings, eflatScaleNotes, eflatScaleAccident, 1, 1000);
          break;
        case 6:
          Serial.println(scaleMainMenu[3]);
          playScale(fScaleStrings, fScaleNotes, fScaleAccident, 1, 1000);
          break;
        default:
          Serial.println("No menu selected from main screen");
      }
    }
  }//
  lcd.clear();
  delay(100);
}

//-------- One Step in: Sub Menu B "PLAY FROM PHONE"--------
void subMenuB() {
  myEnc.write(0);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    LISTENING...   ");
  lcd.setCursor(0, 1);
  lcd.print("   No Audio Source");
  lcd.setCursor(0, 2);
  lcd.print("     Detected     ");

  while (!buttonPressed()) {
    delay(50);
  }
  lcd.clear();
  delay(100);
}

//-------- One Step in: Sub Menu C "DEMO MODE"--------
void subMenuC() {
  myEnc.write(0);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Beginning Demo");
  lcd.setCursor(0, 2);
  lcd.print("Hold Button to Abort");
  while (!buttonPressed()) {
    servo1.write(random(50, 140));
    servo2.write(random(50, 140));
    servo3.write(random(50, 140));
    servo4.write(random(50, 140));
    delay(1000);
  }
  lcd.clear();
  delay(100);
  allUp();
}

//-------- One Step in: Sub Menu D "MORE INFO"--------
void subMenuD() {
  myEnc.write(0);
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
  lcd.print("   -The Creators  ");
  while (!buttonPressed()) {
    delay(50);
  }
  lcd.clear();
  delay(100);
}

void subMenuE() {
  myEnc.write(0);
  myEnc.write(0);
  lcd.clear();
  lcd.setCursor(0, 0);

  //lcd.print("TroubleShooting Tab");

  int back = whereIsBackOption(troubleshootMenu, troubleshootMenuLength);
  while (!buttonPressed() || whereInMenu != back) {
    rotarRead = readRotar();
    printMenu(troubleshootMenu, troubleshootMenuLength);

    if (whereInMenu == back && buttonPressed() == true) {
      break;
    }
    else if (buttonPressed()) {
      Serial.println("BUTTON PRESSED");
      switch (whereInMenu) {
        case 0:
          Serial.println(troubleshootMenu[0]);
          fullyUpServos();
          break;
        case 1:
          Serial.println(troubleshootMenu[1]);
          stepperMotorTest();
          break;
        case 2:
          Serial.println(troubleshootMenu[2]);
          servoTest();
          break;
        case 3:
          Serial.println(troubleshootMenu[3]);
          resetStepperMotors();
          break;
        default:
          Serial.println("No menu selected from main screen");
      }
    }
  }
  lcd.clear();
  delay(100);
}

void subMenuF() { //HERE
  myEnc.write(0);
  myEnc.write(0);
  lcd.clear();
  lcd.setCursor(0, 0);

  //lcd.print("Song Tab");

  int back = whereIsBackOption(songSamples , songSampleMenuLength);
  while (!buttonPressed() || whereInMenu != back) {
    rotarRead = readRotar();
    printMenu(songSamples, songSampleMenuLength);

    if (whereInMenu == back && buttonPressed() == true) {
      break;
    }
    else if (buttonPressed()) {
      Serial.println("BUTTON PRESSED");
      switch (whereInMenu) {
        case 0:
          Serial.println(songSamples[0]);
          //JingleBells();
          break;
        default:
          Serial.println("No menu selected from main screen");
      }
    }
  }
  lcd.clear();
  delay(100);
}


