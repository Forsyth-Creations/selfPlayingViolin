void stepperMotorTest() {
  bowStepper.setSpeed(40);
  // step one revolution  in one direction:
  Serial.println("clockwise");
  bowStepper.step(-stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  bowStepper.step(stepsPerRevolution);
  delay(500);
}

//------- Resets Position of Stepper Motors ----------
void resetStepperMotors() {
  bowStepper.setSpeed(70);
  Serial.println("initializing steppper");
  long timeCheck = millis();
  while ((digitalRead(stepperMotorButtonPin) == 0 && (timeCheck + 10000) > millis()) && buttonPressed() == false) {
    Serial.println(digitalRead(-stepperMotorButtonPin));
    bowStepper.step(-50);
    delay(20);
  }
  delay(1000);
  if (digitalRead(stepperMotorButtonPin) == 1) {
    Serial.println("Stepper Motor for Bow Calibrated");
    bowStepper.step(150);
  }
  else {
    Serial.println("Calibration Failed. Check hardware, then restart program");
  }
}

char currentPosition = 'D';
void moveBow(int speedInRPM) {
  bowStepper.setSpeed(speedInRPM);
  if (currentPosition == 'D') {
    Serial.println("UP");
    bowStepper.step(stepsPerRevolution * 2);
    currentPosition = 'U';
  }
  else if (currentPosition == 'U') {
    Serial.println("DOWN");
    bowStepper.step(-stepsPerRevolution * 2);
    currentPosition = 'D';
  }
}

