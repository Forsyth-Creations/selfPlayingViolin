//#include "b_Global.h"

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

  howManyOctaves  = howManyOctaves * 7;
  for (int i = 0; i <= howManyOctaves; i++) {
    playNote(stringNumber[i], notes[i], accidentals[i]); //plays the note described by the index of the particular assigned array
    whatNotePlaying(notes, accidentals, i); //outputs to LCD what note is playing
    delay(100);
    moveBow(180);
    //moveBow(150);
    delay(100);
    //moveBow(30);
  }
  for (int j = howManyOctaves ; j >= 0; j--) {
    playNote(stringNumber[j], notes[j], accidentals[j]);
    whatNotePlaying(notes, accidentals, j);
    delay(100);
    moveBow(180);
    //moveBow(150);
    delay(100);
    Serial.println(j);
    //moveBow(30);
  }
  Serial.println("Ending Scale");
  fullyUpServos();
  lcd.clear();
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
  delay(300);
  servo2.write(upServo2);
  delay(300);
  servo3.write(upServo3);
  delay(300);
  servo4.write(upServo4);
  delay(300);
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
  delay(200);
  servo2.write(0);
  delay(200);
  servo3.write(180);
  delay(200);
  servo4.write(180);
  delay(200);
}

void whatNotePlaying(char notes[], int accident[], int test) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Currently Playing:");
  lcd.setCursor(0, 1);
  lcd.print(scaleMainMenu[whereInMenu]);
  lcd.setCursor(0, 3);
  //lcd.print("Enjoy!    ");

  char* symbol = "A";
  lcd.setCursor(0, 2);
  lcd.print("Playing:");
  lcd.setCursor(9, 2);
  lcd.print(notes[test]);
  lcd.setCursor(11, 2);
  if (accident[test] == 1) {
    symbol = "Flat";
  }
  else if (accident[test] == 2) {
    symbol = "Natural";
  }
  else if (accident[test] == 3) {
    symbol = "Sharp";
  }
  lcd.print(symbol);
  lcd.setCursor(0, 3);
  int amount = checkKeySignature(accident);
  if (amount != 0) {
    lcd.print(amount);
  }
  lcd.setCursor(2, 3);
  lcd.print(keySignatureType);
}

int checkKeySignature(int accident[]) {
  int counter = 0;
  keySignatureType = " ";

  for (int i = 0; i < 7; i++) {
    if (accident[i] == 1) {
      keySignatureType = "Flat";
      Serial.println("FLAT SIGNATURE");
      break;
    }
    else if (accident[i] == 3) {
      keySignatureType = "Sharp";
      Serial.println("SHARP SIGNATURE");
      break;
    }
  }
  if (keySignatureType == "Sharp") {
    for (int i = 0; i < 7; i++) {
      if (accident[i] == 3) {
        counter++;
        Serial.println("Sharp Found");
      }
    }
  }
  if (keySignatureType == "Flat") {
    for (int i = 0; i < 7; i++) {
      if (accident[i] == 1) {
        counter++;
        Serial.println("Flat Found");
      }
    }
  }

  return counter;
}

