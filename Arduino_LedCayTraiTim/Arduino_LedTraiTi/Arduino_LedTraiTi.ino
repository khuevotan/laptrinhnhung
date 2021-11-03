// Khai báo các chân sẽ sử dụng để giao tiếp IC HC595
int latchPin = 10;
int clockPin = 12;
int dataPin = 11;

// Khai báo mảng dùng điều khiển IC
byte ledStatus[3]= {};
byte SangHet=0b11111111;
byte TatHet=0b00000000;

// Khai báo các kiểu chạy
byte Chay1[9]= {0b00000000,0b10000000,0b11000000,0b11100000,0b11110000,0b11111000,0b11111100,0b11111110,0b11111111};
byte Chay2[9]= {0b11111111,0b01111111,0b00111111,0b00011111,0b00001111,0b00000111,0b00000011,0b00000001,0b00000000};

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

// Hàm shiftOut ra IC 595
// Ở đây bạn hoàn toàn có thể sử dụng vòng lặp cho code ngắn gọn và chuyên nghiệp hơn
// Nhưng tôi thích làm thế này nhìn cho dễ hiểu
void shiftOutHC595(int dataPin, int clockPin, byte ledStatus[]) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,ledStatus[0]);
  shiftOut(dataPin,clockPin,MSBFIRST,ledStatus[1]);
  shiftOut(dataPin,clockPin,MSBFIRST,ledStatus[2]);
  digitalWrite(latchPin, HIGH);
}

// Hàm chạy led kiểu 1
void Kieu1(int _delay)
{

   for (int i = 0;i<=8;i++)
   {
      ledStatus[0]=Chay1[i];
      ledStatus[1]=TatHet;
      ledStatus[2]=TatHet;
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(_delay);
   }

   for (int i = 0;i<=8;i++)
   {
      ledStatus[0]=SangHet;
      ledStatus[1]=Chay1[i];
      ledStatus[2]=TatHet;
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(_delay);
   }

   for (int i = 0;i<=8;i++)
   {
      ledStatus[0]=SangHet;
      ledStatus[1]=SangHet;
      ledStatus[2]=Chay1[i];
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(_delay);
   }
}

// Hàm chạy led kiểu 1
void Kieu2(int _delay)
{
   for (int i = 0;i<=8;i++)
   {
      ledStatus[0]=Chay2[i];
      ledStatus[1]=SangHet;
      ledStatus[2]=SangHet;
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(_delay);
   }

   for (int i = 0;i<=8;i++)
   {
      ledStatus[0]=TatHet;
      ledStatus[1]=Chay2[i];
      ledStatus[2]=SangHet;
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(_delay);
   }

   for (int i = 0;i<=8;i++)
   {
      ledStatus[0]=TatHet;
      ledStatus[1]=TatHet;
      ledStatus[2]=Chay2[i];
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(_delay);
   }

}

// Hàm chạy led kiểu 3
void Kieu3(int _delay, int SoLan)
{
for (int i = 0;i<=SoLan;i++) {
   ledStatus[0]=SangHet;
   ledStatus[1]=SangHet;
   ledStatus[2]=SangHet;
   shiftOutHC595(dataPin,clockPin,ledStatus);
   delay(_delay);
   ledStatus[0]=TatHet;
   ledStatus[1]=TatHet;
   ledStatus[2]=TatHet;
   shiftOutHC595(dataPin,clockPin,ledStatus);
   delay(_delay);
}
  
}

void loop() { 
// Gọi hàm chạy kiểu 1 thời gian delay 50
Kieu1(50);
// Gọi hàm chạy kiểu 2 thời gian delay 50
Kieu2(50);
// Gọi hàm chạy kiểu 3 thời gian delay 500 và vòng lặp chạy 5 lần
Kieu3(500,5);
}
