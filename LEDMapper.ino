#include "Arduino.h"
#include <Adafruit_TinyUSB.h>
#include <Adafruit_NeoPixel.h>

#define PIN 5
#define LEDCOUNT 1093 

int corner[20];
int cornerNum = 0;
int LED = 0;
bool showWalls = false;
bool canProceed = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDCOUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.fill(strip.Color(0,0,0),0,LEDCOUNT);
  strip.show();
  Serial.begin(115200);
  delay(1000);
  Serial.println("LED Mapper");
  canProceed = true;
}

void loop() {
  if (showWalls == false){
  for (int i = 0; i<LEDCOUNT;i++){
      if (i == LED){
        strip.setPixelColor(i,strip.Color(255,0,0));
      } else{
        strip.setPixelColor(i,strip.Color(0,0,0));
      }
  }
  }
  strip.show();
if (canProceed){
  canProceed = false;
Serial.println("Align LED to corner "+ String(cornerNum) +" with +/- and then press 'e' to confirm or press 's' to end measurement");

}  
if (Serial.available()) {
  String input = Serial.readStringUntil('\n');
  if (input == "e") {
    corner[cornerNum] = LED;
      Serial.println("Stored Corner "+ String(cornerNum) +" as LED " + String(LED));
      cornerNum++;
      canProceed = true;
  }
else if (input == "s") {
    showWalls = true;
    int arraySize = sizeof(corner) / sizeof(corner[0]);
    Serial.println("-----------------------------------------");
    for (int i = 0; i < arraySize-1; i++){
      if (corner[i+1]-corner[i] > 0){
      Serial.println("Wall "+ String(i+1) +" First LED is "+ corner[i] +", Last LED is "+ String(corner[i+1]) +", and Length is "+ String(corner[i+1]-corner[i]));
      strip.fill(strip.Color(random(0,255),random(0,255),random(0,255)),corner[i]+1,corner[i+1]-1);
      strip.setPixelColor(corner[i],strip.Color(0,255,0));
      strip.show();
    }
    }
    if (cornerNum <= 1){
    Serial.println("Not Enough Corners Recorded!");
    }
}
  else if (input.charAt(0) == 'm' && input.length() > 1 && isDigit(input.charAt(1))
  ){
    showWalls = false;
    cornerNum = input.substring(1).toInt();
    LED = corner[cornerNum];
  }
  else if(input.charAt(0) == '+'){
    LED += input.su+218
    bstring(1).toInt();
  }
  else if(input.charAt(0) == '-'){
    LED -= input.substring(1).toInt();
  }
}
  delay(300);
}
