int dem=0;
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  dem = dem + 1;
  delay(1000);
  if(dem == 65){
  dem=0;
  }
  if(dem<=25){
  digitalWrite(0, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);  
  }
 if(dem>25&&dem<35){
  digitalWrite(0, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);  
 }
   if(dem>=35){
   digitalWrite(0, LOW);
   digitalWrite(2, LOW);
   digitalWrite(4, HIGH); 
   }
   
 }
