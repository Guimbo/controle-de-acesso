/*
*
* Read and write demo of the AT24CX library
* Written by Christian Paul, 2014-11-24
* 
* 
*/

// include libraries
#include <Wire.h>
#include <AT24CX.h>
#include <String.h>

// EEPROM object
AT24CX mem;

// setup
void setup() {
  // serial init
  Serial.begin(9600);
  Serial.println("AT24CX read/write test");
  Serial.println("----------------------");
}

// main loop
void loop() {
  int i = 0;
  int count = 0;
  for(i = 0; i <= 4095;i=i+13){
    Serial.print(i);
    // read and write long
    Serial.print("Write 0x0123456d in memo ");
    Serial.println(count);
    delay(10);
    mem.writeLong(i, 0x0123456d);
    delay(10);
    // read and write char
    Serial.print("Write String in memo ");
    Serial.println(count);
    delay(10);
   
    String msgs = "username";
    char msgchar[9];
    msgs.toCharArray(msgchar, 9);
    mem.writeChars(i+4, msgchar, sizeof(msgchar));
    count = count +13;
  }

  delay(10);
  count = 0;
  int count2 = 0;
  i = 0;
  for(i = 0; i <= 4095;i=i+13){
    unsigned long dado = mem.readLong(i);
    Serial.print("... read from : ");
    Serial.println(count);
    delay(10);
    Serial.println(dado, HEX);
    Serial.println();
    Serial.print("Read String from address ");
    Serial.println(count);
    delay(10);
    char msgchar2[9];
    mem.readChars(i+4, msgchar2, sizeof(msgchar2));
    Serial.print("... read: ");
    Serial.println(msgchar2);
    delay(10);
    Serial.println("--------------------");
    Serial.println();
    count = count +13;
    count2++;
 }
 Serial.println(count2);
  // stop
  while (1==1) {}
}
