#include "WProgram.h"

// byte cols[8] = {13, 3, 5, 10, 6, 11, 15, 16};
byte cols[8] = {13, 6, 5, 10, 3, 11, 15, 16};
//byte rows[8] = {9, 14, 8, 12, 1, 7, 2, 5};
byte rows[8] = {9, 14, 1, 12, 8, 2, 7, 4};
byte tran[16] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, A0, A1, A2, A3};

void setup () {
  for (int i = 0; i < 16; i++) {
    pinMode(tran[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    digitalWrite(tran[cols[i] - 1], LOW);
    digitalWrite(tran[rows[i] - 1], LOW);
  }
}

byte heart[8][8] = {{ 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 1, 1, 0, 1, 1, 0, 0 },
                    { 1, 1, 1, 1, 1, 1, 1, 0 },
                    { 1, 1, 1, 1, 1, 1, 1, 0 },
                    { 0, 1, 1, 1, 1, 1, 0, 0 },
                    { 0, 0, 1, 1, 1, 0, 0, 0 },
                    { 0, 0, 0, 1, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0 }};

void display (int duration) {
  for (int i = duration * 1000; i > 0; i -= 250) {
    for (int row = 0; row < 8; row++) {
      digitalWrite(tran[rows[row] - 1], HIGH);
      for (int col = 0; col < 8; col++) {
        digitalWrite(tran[cols[col] - 1], heart[row][col] == 1 ? LOW : HIGH);
        delayMicroseconds(250);
        digitalWrite(tran[cols[col] - 1], HIGH);
      }
      digitalWrite(tran[rows[row] - 1], LOW);
    }
  }
}
void loop () {
  display(2);
  delay(150);
  display(4);
  delay(500);
}
