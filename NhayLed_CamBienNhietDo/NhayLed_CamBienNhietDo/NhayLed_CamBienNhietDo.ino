void setup()
{
  Serial.begin(9600);
  pinMode(11,OUTPUT)
}

void loop()
{
  int giaTri = analogRead(A0);
  int nhietDo = map (giaTri, 20,358,-40,125);
  
  if(nhietDo >37){
    digitalWrite(9,HIGH);
  }
  else {
    digitalWrite(9,LOW);
  }
  delay(1000); 
}
