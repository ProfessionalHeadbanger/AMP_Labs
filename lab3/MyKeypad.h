#pragma once

static const char NO_KEY = '\0';

class MyKeypad 
{
public:
  MyKeypad(byte rows, byte cols, byte* rowPins, byte* colPins, char* custom_km) : numRows(rows), numCols(cols), rowPins(rowPins), colPins(colPins) 
  {
    keypadState = new bool[numRows * numCols]();
    keymap = new char[numRows * numCols];
    setKeymap(custom_km);
  }

  void begin() 
  {
    for (int i = 0; i < numRows; i++)
    {
      pinMode(rowPins[i], INPUT_PULLUP);
    }

    for (int i = 0; i < numCols; i++)
    {
      pinMode(colPins[i], OUTPUT);
    }
  }

  char getKey(bool interrupted = false) 
  {
    char key = NO_KEY;

    for (byte col = 0; col < numCols; col++) 
    {
      digitalWrite(colPins[col], LOW);
      for (byte row = 0; row < numRows; row++) 
      {
        if (digitalRead(rowPins[row]) == LOW && !keypadState[row * numCols + col]) 
        {
          key = keymap[row * numCols + col];
          keypadState[row * numCols + col] = true; // Устанавливаем флаг, что клавиша была считана
        }
        else if (digitalRead(rowPins[row]) == HIGH) 
        {
          keypadState[row * numCols + col] = false; // Сбрасываем флаг при отпускании клавиши
        }
      }
      digitalWrite(colPins[col], HIGH);
    }
    if (interrupted)
    {
      for (int col = 0; col < numCols; col++)
      {
        digitalWrite(colPins[col], LOW);
      }
    }
    return key;
  }

  void setKeymap(char *custom_km) 
  {
    for (byte i = 0; i < numRows * numCols; i++) 
    {
      keymap[i] = custom_km[i];
    }
  }

  void clearKeymap() 
  {
    for (byte i = 0; i < numRows * numCols; i++) 
    {
      keymap[i] = NO_KEY;
    }
  }

private:
  byte numRows;
  byte numCols;
  bool *keypadState;
  char *keymap;
  byte* rowPins;
  byte* colPins;
};
