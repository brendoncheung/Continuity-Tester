#include <Arduino.h>

int data_pin = 8;
int latch_pin = 9;
int clock_pin = 10;
int reset_pin = 11;

void reset_SIPO_register();
void shift_SIPO(byte sequence);

void setup() {
  pinMode(latch_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(reset_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  reset_SIPO_register();
  int position = 1;

  for (int i = 0; i < 8; i++) {
    int into = position << i;
    shift_SIPO(into);
    Serial.println(into, BIN);
    delay(500);
  }
}

void reset_SIPO_register() {
  digitalWrite(reset_pin, LOW);
  digitalWrite(reset_pin, HIGH);
}

void shift_SIPO(byte sequence) {
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, sequence);
  digitalWrite(latch_pin, HIGH);
}




  // int position = 1;
  // for (int i = 0; i < 8; i++) {
  //   int into = position << i;
  //   shift_SIPO(0xFF);
  //   Serial.println(into);
  //   delay(500);
  // }