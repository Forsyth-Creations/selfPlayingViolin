void moveAll() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoOne.write(pos);              // tell servo to go to position in variable 'pos'
    servoTwo.write(pos);              // tell servo to go to position in variable 'pos'
    servoThree.write(pos);              // tell servo to go to position in variable 'pos'

    delay(pace);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servoOne.write(pos);              // tell servo to go to position in variable 'pos'
    servoTwo.write(pos);              // tell servo to go to position in variable 'pos'
    servoThree.write(pos);              // tell servo to go to position in variable 'pos'
    delay(pace);                       // waits 15ms for the servo to reach the position
  }
}

void jingleBells() {
  int speedOfPlay = 125;
  int i;
  int previousi = 0;
  for (i = 0; i < sizeof(scale) / sizeof(i); i = i + 1) {
    Serial.println(scale[i]);
    if ( i == previousi) {
      delay(speedOfPlay);
    }
    else {
      switch (scale[i]) {
        case 1:
          servoOne.write(minServoPos);              // tell servo to go to position in variable 'pos'
          break;
        case 2:
          servoTwo.write(minServoPos);              // tell servo to go to position in variable 'pos'
          break;
        case 3:
          servoThree.write(minServoPos);              // tell servo to go to position in variable 'pos'
          break;
       default:
          allUp();
      }
      delay(speedOfPlay);
      allUp();
    }
    previousi = i;
  }
}

