#include <Arduino.h>

int latch_pin = 9;
int data_pin = 8;
int clock_pin = 7;
int reset_pin = 6;

void reset_SIPO_register();
void shift_SIPO(byte sequence);
void clear_zero_SIPO();

void setup() {
  // put your setup code here, to run once:
  pinMode(latch_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(reset_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:  
  reset_SIPO_register();
  for (int i = 1; i < 8; i++) {
    shift_SIPO(pow(2, i));
    delay(500);
  }
}

void reset_SIPO_register() {
  digitalWrite(reset_pin, LOW);
  digitalWrite(reset_pin, HIGH);
}

void shift_SIPO(byte sequence) {
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, sequence);
  digitalWrite(latch_pin, HIGH);
}

void clear_zero_SIPO() {
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, 0x00);
  digitalWrite(latch_pin, HIGH);
}

