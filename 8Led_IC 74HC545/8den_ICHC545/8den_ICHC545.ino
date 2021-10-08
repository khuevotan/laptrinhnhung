#define _latch 6
#define _clock 7
#define _data 5

void setup()
{
  pinMode(_latch, OUTPUT);
  pinMode(_clock, OUTPUT);
  pinMode(_data, OUTPUT);
}

void loop()
{
  for (int i=0; i< 256;i++)
  {
    digitalWrite(_latch,LOW);
    shiftOut(_data, _clock,LSBFIRST, i);
    digitalWrite( _latch,HIGH);
    delay(500);
  }
}
