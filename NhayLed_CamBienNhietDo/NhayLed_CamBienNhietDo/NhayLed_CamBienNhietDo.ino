void setup()
{
  pinMode(9,OUTPUT);
}

void loop()
{
  int giaTri = analogRead(A0);
  int nhietDo = map (giaTri, 20,358,-40,125);

  if(nhietDo > 25){
    digitalWrite(9,HIGH);
  }
  else {
    digitalWrite(9,LOW);
  }
  delay(1000); 
}
