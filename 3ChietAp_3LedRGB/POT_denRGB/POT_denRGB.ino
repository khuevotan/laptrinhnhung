int led1 = 9;
int led2 = 10;
int led3 = 11;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  int val1 = map(analogRead(A0),0,1023,0,255);
  int val2 = map(analogRead(A1),0,1023,0,255);
  int val3 = map(analogRead(A2),0,1023,0,255);
  analogWrite(led1,val1);
  analogWrite(led2,val2);
  analogWrite(led3,val3);
}
