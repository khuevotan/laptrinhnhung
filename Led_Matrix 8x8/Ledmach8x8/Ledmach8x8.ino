#define DS_cot 2
#define DS_hang 3

#define SH_CP_hang 5
#define SH_CP_cot 6

#define ST_CP 4
byte cot = 0b10000000;
void setup() {
  pinMode (ST_CP,OUTPUT); //RCLK

  pinMode (DS_hang,OUTPUT);
  pinMode (SH_CP_hang,OUTPUT);

  pinMode (SH_CP_cot,OUTPUT);
  pinMode (DS_cot,OUTPUT);
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);  //hang 8 - hang 1
  digitalWrite(ST_CP,HIGH);
  
}

void loop() {
  for(int i=0; i< 8;i++){
    digitalWrite(ST_CP,LOW);
    shiftOut(DS_cot,SH_CP_cot,LSBFIRST,cot >> i); //cot 8 - cot 1
    digitalWrite(ST_CP,HIGH);
    delay(1000);
  }

}
