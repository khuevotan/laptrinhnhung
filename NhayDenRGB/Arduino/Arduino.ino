int denDo = 9;
int denXanh = 10;
int denXanhLa = 11;
void setup() {
  pinMode(denDo, OUTPUT); 
  pinMode(denXanh, OUTPUT); 
  pinMode(denXanhLa, OUTPUT); 
}


void loop() {
  analogWrite(denDo, 0);
  analogWrite(denXanh, 255);
  analogWrite(denXanhLa, 0);
  
  delay(500);   
  analogWrite(denDo, 255);
  analogWrite(denXanh, 0);
  analogWrite(denXanhLa, 0);

  delay(500); 
  analogWrite(denDo, 0);
  analogWrite(denXanh, 0);
  analogWrite(denXanhLa, 255)                   ;
  delay(500);
}
