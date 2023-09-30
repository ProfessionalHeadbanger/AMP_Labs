//Lab2 1
//Выводить температуру в градусах цельсия и влажность с паузой 2 секунды (2 знака на значение, 2 знака пояснение)

#include <TM1637Display.h>
#include "DHT.h"

#define CLK 2
#define DIO 3
#define DHTPIN 4

#define DELAY1 2000

#define MINUS SEG_G
#define C SEG_D | SEG_E | SEG_F | SEG_A
#define o SEG_A | SEG_B | SEG_F | SEG_G
#define prleft SEG_A | SEG_B | SEG_F | SEG_G | SEG_D
#define prright SEG_A | SEG_G | SEG_D | SEG_C | SEG_E

TM1637Display display(CLK, DIO);
DHT dht(DHTPIN, DHT11);

void setup() {
  display.setBrightness(7);
  dht.begin();
}

void loop() {
  display.clear();
  task();
}

void task()
{
  const uint8_t temp[] = { o, C };
  const uint8_t humi[] = {prleft, prright};
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  display.showNumberDec(int(t), false, 2, 0);
  display.setSegments(temp, 2, 2);
  delay(DELAY1);

  display.showNumberDec(int(h), false, 2, 0);
  display.setSegments(humi, 2, 2);
  delay(DELAY1);
}
