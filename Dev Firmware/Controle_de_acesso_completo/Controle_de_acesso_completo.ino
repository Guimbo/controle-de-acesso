#include <Wire.h>
#include <AT24CX.h>
#include <SPI.h>
#include <SD.h>
#define DS1307_ADDRESS 0x68
File logFile;
AT24CX mem;
int global_week_day = 0;
int global_hour = 0;
int global_minute = 0;
int global_second = 0;
unsigned int trys = 0;

void setup(){
  Serial.begin(9600);
  pinMode(17, OUTPUT);
  Wire.begin();
  selectDateTimeDefault();
  Serial.println("Loading System");
  delay(100);
  Serial.println();
}

void loop(){
  resetProtocol();
}  
