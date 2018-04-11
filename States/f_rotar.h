//--------- Rotar Below -------------------
long oldPosition  = -999;
long readRotar() {
  long newPosition = myEnc.read() / 4;
  if (newPosition < 0 || oldPosition < 0) {
    newPosition = 0;
    oldPosition = 0;
    delay(50);
  }
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    lcd.clear();
    Serial.println(newPosition);
  }
  return newPosition;
}

//-------- Button Pressed -----------------
boolean buttonPressed() {
  boolean b  = !digitalRead(buttonPinForRotar);
  while (digitalRead(buttonPinForRotar) == 0) {
    // lcd.clear();
  }
  return b;
}
