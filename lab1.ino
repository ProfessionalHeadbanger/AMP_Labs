//AMP Lab1 3 4 3

#include <TM1637Display.h>

#define CLK 2
#define DIO 3

#define DELAY1 200
#define DELAY2 500
#define DELAY3 600

#define A SEG_E | SEG_F | SEG_A | SEG_B | SEG_C | SEG_G
#define B SEG_F | SEG_E | SEG_D | SEG_C | SEG_G
#define C SEG_D | SEG_E | SEG_F | SEG_A
#define D SEG_G | SEG_E | SEG_D | SEG_C | SEG_B
#define E SEG_A | SEG_F | SEG_G | SEG_E | SEG_D
#define F SEG_A | SEG_F | SEG_G | SEG_E
#define G SEG_A | SEG_F | SEG_E | SEG_D | SEG_C
#define H SEG_F | SEG_G | SEG_E | SEG_C
#define I SEG_F | SEG_E
#define J SEG_D | SEG_C | SEG_B
#define K SEG_F | SEG_G | SEG_B | SEG_E | SEG_C
#define L SEG_F | SEG_E | SEG_D
#define N SEG_E | SEG_G | SEG_C
#define O SEG_E | SEG_F | SEG_C | SEG_D | SEG_A | SEG_B
#define P SEG_E | SEG_F | SEG_A | SEG_B | SEG_G
#define Q SEG_F | SEG_A | SEG_B | SEG_G | SEG_C
#define R SEG_E | SEG_G
#define T SEG_F | SEG_G | SEG_E | SEG_D
#define U SEG_F | SEG_E | SEG_D | SEG_C | SEG_B
#define Y SEG_F | SEG_G | SEG_B | SEG_C | SEG_D
#define SPACE 0
#define MINUS SEG_G

TM1637Display display(CLK, DIO);

void setup() 
{
  display.setBrightness(7);
}

void loop() 
{
  //task1();
  //task2();
  task3();
}

void task1()
{
  const uint8_t minus[] = { MINUS };
  display.clear();
  for (int i = 100; i >= -100; i-=2)
  {
    display.showNumberDec(i, false, 3, 1);
    if (i == -100)
    {
      display.setSegments(minus, 1);
    }
    delay(DELAY1);
  }
}

void task2()
{
  display.clear();
  const uint8_t minus[] = { MINUS };
    for (int i = 300; i >= -300; i -= 30)
    {
        display.clear();
        display.showNumberDecEx(abs(i), 0b01000000, true, 3, 1);
        if (i < 0)
        {
          display.setSegments(minus, 1);
        }
        delay(DELAY2);
    }
    delay(DELAY2);
}

void task3()
{
  display.clear();
  const uint8_t text[] = { L, O, C, K, SPACE, O, P, E, N, SPACE};
  int size_text = sizeof(text)/sizeof(text[0])-4;
  int i = 0;
  while(1)
  {
    display.setSegments(text+i);
    i = (i+1)%size_text;
    delay(DELAY3);
  }
}
