void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  int x = analogRead(A0);
  digitalWrite(9,HIGH);
  delay(x);
  digitalWrite(9,LOW);
  delay(x);
}
