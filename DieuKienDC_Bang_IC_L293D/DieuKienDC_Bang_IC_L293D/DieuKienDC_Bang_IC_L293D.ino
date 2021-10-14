// dong co 1
int tocdo = 9;
int inp1 = 11;
int inp2 = 10;
// dong co 2
int tocdo2 = 6;
int inp3 = 5;
int inp4 = 4;

void setup()
{
  pinMode(tocdo, OUTPUT);
  pinMode(inp1, OUTPUT);
  pinMode(inp2, OUTPUT);
  pinMode(tocdo2, OUTPUT);
  pinMode(inp3, OUTPUT);
  pinMode(inp4, OUTPUT);
  digitalWrite(2, HIGH);
  attachInterrupt(0, tatdongco, CHANGE);
  digitalWrite(3, HIGH);
  attachInterrupt(1,dieukientocdogiam, CHANGE);
  
  //tat dong co
  digitalWrite(inp1,LOW);
  digitalWrite(inp2,LOW);
  digitalWrite(inp3,LOW);
  digitalWrite(inp4,LOW);
}

void tatdongco()
{
  digitalWrite(inp1,LOW);
  digitalWrite(inp2,LOW);
  digitalWrite(inp3,LOW);
  digitalWrite(inp4,LOW);
}

void directionControl()
{
  // Cho động cơ quay với tốc độ tối đa
  // Giá trị của PWM thay đổi từ 0 đến 255
    analogWrite(tocdo, 255);
  analogWrite(tocdo2, 255);
    // Tắt động cơ A và B
  digitalWrite(inp1, HIGH);
  digitalWrite(inp2, LOW);
  digitalWrite(inp3, HIGH);
  digitalWrite(inp4, LOW);
  delay(2000);

  // Thay đổi chiều quay của động cơ
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, HIGH);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, HIGH);
  delay(2000);
  
  // Tắt tất cả các động cơ
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, LOW);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, LOW);
}

void speedControl()
{
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, HIGH);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, HIGH);
  
    for(int i=0; i<256 ;i++){
    analogWrite(tocdo,i);
    analogWrite(tocdo2,i);
    delay(10);
    }
  
    for(int i=255;i >= 0; --i){
    analogWrite(tocdo,i);
    analogWrite(tocdo2,i);
    delay(10);
  }
  //tat dong co
  digitalWrite(inp1,LOW);
  digitalWrite(inp2,LOW);
  digitalWrite(inp3,LOW);
  digitalWrite(inp4,LOW);   
}
void dieukientocdotang()
{
  //bat cac dong co
  digitalWrite(inp1,LOW);
  digitalWrite(inp2,HIGH);
  digitalWrite(inp3,LOW);
  digitalWrite(inp4,HIGH);
  
  //tang toc do den max
  for(int i=0; i<256 ;i++){
    analogWrite(tocdo,i);
    analogWrite(tocdo2,i);
    delay(10);
  }
}

void dieukientocdogiam()
{
  //bat cac dong co
  digitalWrite(inp1,LOW);
  digitalWrite(inp2,HIGH);
  digitalWrite(inp3,LOW);
  digitalWrite(inp4,HIGH);
  
    //giam toc do ve 0
  for(int i=255;i >= 0; --i){
    analogWrite(tocdo,i);
    analogWrite(tocdo2,i);
    delay(10);
  }
}

void loop()
{
  directionControl();
  delay(1000);
  speedControl();
  delay(1000);
}
