/**
 *
 *****************************************************************
 * IOT Challenges - https://instagram.com/iotchallenges          *
 *****************************************************************
 * Evandro Fruhauf                                               *
 *  GitHub - https://github.com/evandrodp                        *
 *  LinkedIn - http://linkedin.com/in/evandrofruhauf             *
 *****************************************************************
 * This code can contain parts from other open-sources projects, *
 * whenever possible it will be quoted.                          *
 *****************************************************************
 *
 * RGB
 *
 * Challenge: Make the RGB works showing Red/Green/Blue and do the rainbow
 *
 * Code base: http://www.squids.com.br/arduino/index.php/projetos-arduino/projetos-basicos/95-projeto-23-usando-o-led-rgb
**/
#include <Arduino.h>

// set LED RGB pins
const int R = 10;
const int G = 11;
const int B = 9;

// define if you want to see the rainbow mode
const bool rainbowMode = true;

int RedValue = 255;
int GreenValue = 0;
int BlueValue = 0;
int delayms = 50;

void blink();
void rainbow();

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  if (rainbowMode) {
    analogWrite(R, RedValue);
    analogWrite(G, GreenValue);
    analogWrite(B, BlueValue);
  }
}

void loop() {
  if (rainbowMode) {
    rainbow();
  } else {
    blink();
  }
}

void blink() {
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
  delay(1000);
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(B, LOW);
  delay(1000);
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
  delay(1000);
}

void rainbow() {
  for (GreenValue = 0; GreenValue <255; GreenValue=GreenValue+5){
      analogWrite(G, GreenValue);
      delay(delayms);
  }
  for (RedValue = 255; RedValue > 0; RedValue=RedValue-5){
      analogWrite(R, RedValue);
      delay(delayms);
  }
  for (BlueValue = 0; BlueValue < 255; BlueValue=BlueValue+5){
      analogWrite(B, BlueValue);
      delay(delayms);
  }
  for (GreenValue = 255; GreenValue > 0; GreenValue=GreenValue-5){
      analogWrite(G, GreenValue);
      delay(delayms);
  }
  for (RedValue = 0; RedValue < 255; RedValue=RedValue+5){
      analogWrite(R, RedValue);
      delay(delayms);
  }
  for (BlueValue = 255; BlueValue > 0; BlueValue=BlueValue-5){
      analogWrite(B, BlueValue);
      delay(delayms);
  }
}
