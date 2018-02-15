int y; 
int x;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  y = analogRead(A5);
  x = map(y, 0, 1023, 0, 200);
Serial.println(x);
}
