// S0-3 - 4-7, выход сенсора (out) - 8
// S0 и S1 - контакты масштабирования частоты
#define S0 4
#define S1 5
// S2 и S3 - контакты выбора массива цвета
#define S2 6
#define S3 7
#define out 8

int fr = 0; // переменная для частоты

void setup()
{
  // пины S0-3 выставляем на OUTPUT
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  // пин выхода сенсора выставляем на INPUT
  pinMode(out, INPUT);

  // выставляем масштабирование частоты в 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop()
{
  // считываем красный цвет
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  fr = pulseIn(out, LOW); 
  //fr = map(fr, 100, 1000, 0, 255);
  Serial.print("Red = ");
  Serial.print(fr);
  Serial.print("  ");
  delay(100);

  // считываем зеленый цвет
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  fr = pulseIn(out, LOW); 
  //fr = map(fr, 100, 1000, 0, 255);
  Serial.print("Green = ");
  Serial.print(fr);
  Serial.print("  ");
  delay(100);

  // считываем синий цвет
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  fr = pulseIn(out, LOW); 
  //fr = map(fr, 100, 1000, 0, 255);
  Serial.print("Blue = ");
  Serial.print(fr);
  Serial.println();
  delay(100);
}
