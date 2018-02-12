void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Signal 1");
Serial.println(analogRead(A0));
  Serial.print("Signal 2");
Serial.println(analogRead(A1));
delay(250);
}
