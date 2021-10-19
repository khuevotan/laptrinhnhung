int display0[] = {7, 6, 5, 4, 3, 2, 1, A2};
int display1[] = {7, 6, 5, 4, 3, 2, 1, A2};
int display2[] = {A1, A0, 13, 12, 11, 10, 9, 8};

int nums0[10][8]  = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}  // 9
};

int nums[10][8]  = {
  {1, 1, 1, 1, 1, 1, 0, 1}, // 0
  {0, 1, 1, 0, 0, 0, 0, 1}, // 1
  {1, 1, 0, 1, 1, 0, 1, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0, 1}, // 7
  {1, 1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1, 1}  // 9
};

const byte dot = A2;
const int showTime = 200;

void setup() {
  pinMode(dot, OUTPUT);
  for(byte i = 0; i < 9; i++){
    pinMode(display0[i], OUTPUT);
    pinMode(display1[i], OUTPUT);
    pinMode(display2[i], OUTPUT);
  }
}

void loop() {
  for(byte i = 0; i < 10; i++) {
    displayNum(display0, nums0[i]);
    delay(showTime);
  }
  
  for(byte i = 0; i < 10; i++) {
    displayNum(display1, nums[i]);
    
    for(byte j = 0; j < 10; j++) {
      displayNum(display2, nums[j]);
      delay(showTime);
    }
  }
}

void displayNum(int display[], int num[]) {
  for(byte i = 0; i < 8; i++)
    digitalWrite(display[i], num[i]);
}
