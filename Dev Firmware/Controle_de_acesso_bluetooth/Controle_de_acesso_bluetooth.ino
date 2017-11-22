#include "Wire.h"
#include <string.h>
#include <Streaming.h>
#define DS1307_ADDRESS 0x68


byte zero = 0x00; 
unsigned int time_complete[5];
unsigned int date_complete[5];
unsigned int second[2];
unsigned int minute[2];
unsigned int hour[2];
unsigned int day[2];
unsigned int month[2];
unsigned int year[2];
unsigned int week_day = 1;

void setup(){
  Serial.begin(9600);
  pinMode(17, OUTPUT);
  Wire.begin();
  selectDateTimeDefault();
  delay(100);
  Serial.println();
}

void loop(){
  if(Serial.available() >0){
    char command = serialReadChar();
    delay(100);
    Serial.println(command);
    if(command == 'a'){
		getPassword();
      delay(10);
    }
    if(command == 'b'){
      Serial.println("Configure Date and Time");
      delay(10);
      getDate();
      delay(10);
      getTime();
      delay(10);
      setDateTime();
      Serial.println("Recorded");
    }
    if(command == 'c'){
      Serial.println("Showing Time");
      showTime();
      delay(10);
      Serial.println(" ");
      Serial.println();
    }
	if (command == 'd') {
		getUserName();
		delay(10);
		Serial.println(" ");
		Serial.println();
	}
  }
}  
