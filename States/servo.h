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

//--------- Moves a Servo Up or Down ------------------
void moveServo(int whatServo, boolean upOrDown) {
  //true means down
  //Serial.println("I made it here");
  if (upOrDown == true) {
    switch (whatServo) {
      //int i;
      case 4:
        //i = whichWay(upOrDown);
        servo1.write(downServo1);
        //Serial.println("Servo 1");
        whatServo = 1;
        break;
      case 3:
        //i = whichWay(upOrDown);
        servo2.write(downServo2);
        //Serial.println("Servo 2");
        whatServo = 2;
        break;
      case 2:
        //i = whichWay(upOrDown);
        servo3.write(downServo3);
        // Serial.println("Servo 3");
        whatServo = 3;
        break;
      case 1:
        //i = whichWay(upOrDown);
        servo4.write(downServo4);
        //Serial.println("Servo 4");
        whatServo = 4;
        break;
      default:
        allUp();
    }
  }
  delay(160);
  allUpExcept(whatServo);
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
        moveServo(0, true);
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
        moveServo(0, true);
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

//--------Untested Method. Meant to play whatever scale is specified-----------
void playScale(int stringNumber[], char notes[], int accidentals[], int howManyOctaves, int delayTime) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Currently Playing:");
  lcd.setCursor(0, 1);
  lcd.print(scaleMainMenu[whereInMenu]);
  lcd.setCursor(0, 3);
  lcd.print("      Enjoy!    ");
  
  howManyOctaves  = howManyOctaves * 8;
  for ( int i = 0; i <= howManyOctaves; i++) {
    playNote(stringNumber[i], notes[i], accidentals[i]);
    delay(delayTime);
    moveBow(90);
  }
  for ( int i = howManyOctaves * 8 ; i >= 0; i--) {
    playNote(stringNumber[i], notes[i], accidentals[i]);
    delay(delayTime);
    moveBow(90);
  }
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

//----- SERVO STUFF SHOULD ALL BE BELOW THIS LINE. ALL MENUS SHOULD BE ABOVE-------
void allUp() {
  servo1.write(upServo1);
  servo2.write(upServo2);
  servo3.write(upServo3);
  servo4.write(upServo4);
}

void servoTest() {
  lcd.clear();
  lcd.setCursor(8, 1);
  lcd.print("Servo:");
  //while (buttonPressed() == false) {}
  moveServo(1, true);
  lcd.setCursor(10, 2);
  lcd.print("1");
  while (buttonPressed() == false) {
    delay(10);
  }
  allUp();
  moveServo(2, true);
  lcd.setCursor(10, 2);
  lcd.print("2");
  while (buttonPressed() == false) {
    delay(10);
  }
  allUp();
  moveServo(3, true);
  lcd.setCursor(10, 2);
  lcd.print("3");
  while (buttonPressed() == false) {
    delay(10);
  }
  //delay(delayBetweenChecks);
  allUp();
  moveServo(4 , true);
  lcd.setCursor(10, 2);
  lcd.print("4");
  while (buttonPressed() == false) {
    delay(10);
  }
  //delay(delayBetweenChecks);
  allUp();
  lcd.clear();
}

void fullyUpServos() {
  servo1.write(0);
  servo2.write(0);
  servo3.write(180);
  servo4.write(180);
}

