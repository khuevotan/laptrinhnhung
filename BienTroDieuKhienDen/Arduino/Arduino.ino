int x = 0;
void setup() {
  pinMode(9,OUTPUT);
  pinMode(A0,INPUT);
}

void loop() {
  x = analogRead(A0);
  serial.print(x);
  serial.print('\n');
  delay(1000);
}
