int x =0;
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  x = analogRead(A0);
  //chuyen sang do sang
  int doSang = map(x,0,1023,0,255);
  analogWrite(9,doSang);
}
