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
  }//
  lcd.clear();
  delay(100);
}

//-------- One Step in: Sub Menu B "PLAY FROM PHONE"--------
void subMenuB() {
  myEnc.write(0);
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
  myEnc.write(0);
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
  lcd.print("   -Forsyth/Lee  ");
  while (!buttonPressed()) {
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
          allUp();
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
