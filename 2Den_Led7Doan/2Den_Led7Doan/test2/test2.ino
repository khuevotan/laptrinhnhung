int dayden0[] = {7, 6, 5, 4, 3, 2, 1, A2};
int dayden1[] = {7, 6, 5, 4, 3, 2, 1, A2};
int dayden2[] = {A1, A0, 13, 12, 11, 10, 9, 8};

int matran0[10][8]  = {
  {1, 1, 1, 1, 1, 1, 0, 0},     // hiển thị số 0
  {0, 1, 1, 0, 0, 0, 0, 0},     // số 1
  {1, 1, 0, 1, 1, 0, 1, 0},     // số 2
  {1, 1, 1, 1, 0, 0, 1, 0},     // số 3
  {0, 1, 1, 0, 0, 1, 1, 0},     // số 4
  {1, 0, 1, 1, 0, 1, 1, 0},     // số 5
  {1, 0, 1, 1, 1, 1, 1, 0},     // số 6
  {1, 1, 1, 0, 0, 0, 0, 0},     // số 7
  {1, 1, 1, 1, 1, 1, 1, 0},     // số 8
  {1, 1, 1, 1, 0, 1, 1, 0}      // số 9
};

int matran[10][8]  = {
  {1, 1, 1, 1, 1, 1, 0, 1},     // số 0
  {0, 1, 1, 0, 0, 0, 0, 1},     // số 1
  {1, 1, 0, 1, 1, 0, 1, 1},     // số 2
  {1, 1, 1, 1, 0, 0, 1, 1},     // số 3
  {0, 1, 1, 0, 0, 1, 1, 1},     // số 4
  {1, 0, 1, 1, 0, 1, 1, 1},     // số 5
  {1, 0, 1, 1, 1, 1, 1, 1},     // số 6
  {1, 1, 1, 0, 0, 0, 0, 1},     // số 7
  {1, 1, 1, 1, 1, 1, 1, 1},     // số 8
  {1, 1, 1, 1, 0, 1, 1, 1}      // số 9
};
const byte dot = A2;
const int showTime = 200;

void setup() {
  pinMode(dot, OUTPUT);
  for(byte i = 0; i < 9; i++){
    pinMode(dayden0[i], OUTPUT);
    pinMode(dayden1[i], OUTPUT);
    pinMode(dayden2[i], OUTPUT);
  }
}
void displayNum(int dayden[], int matran[]) {
  for(byte i = 0; i < 8; i++)
    digitalWrite(dayden[i], num[i]);
}
void loop() {
  for(byte i = 0; i < 10; i++) {
    displayNum(dayden0, matran0[i]);
    delay(showTime);
  }
  
  for(byte i = 0; i < 10; i++) {
      displayNum(dayden1, matran[i]);
      for(byte j = 0; j < 10; j++) {
          displayNum(dayden2, matran[j]);
          delay(showTime);
      }
 }
}
