#pragma once

static const char NO_KEY = '\0';

class MyKeypad {
public:
  MyKeypad(byte rows, byte cols, byte* rowPins, byte* colPins, char* custom_km) : numRows(rows), numCols(cols), rowPins(rowPins), colPins(colPins) {
    keypadState = new bool[numRows * numCols]();
    keymap = new char[numRows * numCols];
    setKeymap(custom_km);
  }

  void begin() {
    pinMode(rowPins[0], INPUT_PULLUP);
    pinMode(rowPins[1], INPUT_PULLUP);
    pinMode(rowPins[2], INPUT_PULLUP);
    pinMode(rowPins[3], INPUT_PULLUP);

    pinMode(colPins[0], OUTPUT);
    pinMode(colPins[1], OUTPUT);
    pinMode(colPins[2], OUTPUT);
    pinMode(colPins[3], OUTPUT);
  }

  char getKey() {
    char key = NO_KEY;

    for (byte col = 0; col < numCols; col++) {
        digitalWrite(colPins[col], LOW);
        for (byte row = 0; row < numRows; row++) {
            if (digitalRead(rowPins[row]) == LOW && !keypadState[row * numCols + col]) {
                key = keymap[row * numCols + col];
                keypadState[row * numCols + col] = true; // Устанавливаем флаг, что клавиша была считана
            } else if (digitalRead(rowPins[row]) == HIGH) {
                keypadState[row * numCols + col] = false; // Сбрасываем флаг при отпускании клавиши
            }
        }
        digitalWrite(colPins[col], HIGH);
    }

    return key;
}

  void setKeymap(char *custom_km) {
    for (byte i = 0; i < numRows * numCols; i++) {
      keymap[i] = custom_km[i];
    }
  }

  void clearKeymap() {
    for (byte i = 0; i < numRows * numCols; i++) {
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

