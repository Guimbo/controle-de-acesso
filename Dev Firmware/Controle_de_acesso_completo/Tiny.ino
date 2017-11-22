void setDateTime(){   //Seta a data e a hour do DS1307
    unsigned int week_day = 1;
    unsigned int dayv[2];
    unsigned int monthv[2];
    unsigned int yearv[2];
    unsigned int secondv[2];
    unsigned int minutev[2];
    unsigned int hourv[2];
    
    Serial.println("Enter date in the format 00/00/00 ");
    char local_array[8];
    Serial.flush();
    int i = 0;
    for (i = 0; i<7 ;i++) {
      while (Serial.available() == 0) {}
      local_array[i] = Serial.read();
    }
    dayv[0] = local_array[0]- 48;
    dayv[1] = local_array[1]- 48;
    monthv[0] = local_array[2]- 48;
    monthv[1] = local_array[3]- 48;
    yearv[0] = local_array[4]- 48;
    yearv[1] = local_array[5]- 48;
    week_day = local_array[6]- 48;
    delay(10);

    Serial.println("Enter time in the format 00:00:00 ");
    Serial.flush();
    i = 0;
    for (i = 0; i < 6;i++) {
      while (Serial.available() == 0) {}
      local_array[i] = Serial.read();
    }
    hourv[0] = local_array[0]- 48;
    hourv[1] = local_array[1]- 48;
    minutev[0] = local_array[2]- 48;
    minutev[1] = local_array[3]- 48;
    secondv[0] = local_array[4]- 48;
    secondv[1] = local_array[5]- 48;
    delay(10);
    byte zero = 0x00; 
    byte hours = concatInt(hourv[0], hourv[1]); //Valores de 0 a 23
    byte minutes = concatInt(minutev[0], minutev[1]); //Valores de 0 a 59
    byte seconds = concatInt(secondv[0], secondv[1]); //Valores de 0 a 59
    byte month_day = concatInt(dayv[0], dayv[1]); //Valores de 1 a 31
    byte month = concatInt(monthv[0], monthv[1]); //Valores de 1 a 12
    byte year = concatInt(yearv[0] , yearv[1]); //Valores de 0 a 99
    byte day_in_week = week_day; //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.write(zero); //Stop no CI para que o monthmo possa receber os dados
    
    //As linhas abaixo escrevem no CI os valores de 
    //data e hour que foram colocados nas variaveis acima
    Wire.write(byteToBCD(seconds));
    Wire.write(byteToBCD(minutes));
    Wire.write(byteToBCD(hours));
    Wire.write(byteToBCD(day_in_week));
    Wire.write(byteToBCD(month_day));
    Wire.write(byteToBCD(month));
    Wire.write(byteToBCD(year));
    Wire.write(zero); //Start no CI
    Wire.endTransmission();   
 }

void showTime(){
  byte zero = 0x00;
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  int seconds = byteToInt(Wire.read());
  int minutes = byteToInt(Wire.read());
  int hours = byteToInt(Wire.read() & 0b111111); 
  int day_in_week = byteToInt(Wire.read()); 
  int month_day = byteToInt(Wire.read());
  int month = byteToInt(Wire.read());
  int year = byteToInt(Wire.read());
  //Mostra a data no Serial Monitor
  Serial.print("Data: ");
  Serial.print(month_day);
  Serial.print("/");
  Serial.print(month);
  Serial.print("/");
  Serial.print(year);
  Serial.print(" ");
  Serial.print("Hora : ");
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.print(seconds);
  switch(day_in_week)
    {
      case 0:Serial.println(", Domingo");
      break;
      case 1:Serial.println(", Segunda");
      break;
      case 2:Serial.println(", Terca");
      break;
      case 3:Serial.println(", Quarta");
      break;
      case 4:Serial.println(", Quinta");
      break;
      case 5:Serial.println(", Sexta");
      break;
      case 6:Serial.println(", Sabado");
    }
}


void selectDateTimeDefault()   //Seta a data e a hora do DS1307
{
  byte zero = 0x00;
  Serial.println("Recording default");
  byte seconds = 40; //Valores de 0 a 59
  byte minutes = 59; //Valores de 0 a 59
  byte hours = 23; //Valores de 0 a 23
  byte day_in_week = 1; //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
  byte month_day = 17; //Valores de 1 a 31
  byte month = 4; //Valores de 1 a 12
  byte year = 13; //Valores de 0 a 99
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); //Stop no CI para que o monthmo possa receber os dados

  //As linhas abaixo escrevem no CI os valores de 
  //data e hora que foram colocados nas variaveis acima
  Wire.write(byteToBCD(seconds));
  Wire.write(byteToBCD(minutes));
  Wire.write(byteToBCD(hours));
  Wire.write(byteToBCD(day_in_week));
  Wire.write(byteToBCD(month_day));
  Wire.write(byteToBCD(month));
  Wire.write(byteToBCD(year));
  Wire.write(zero); //Start no CI
  Wire.endTransmission(); 
  delay(10);
  Serial.println("Default in System");
}
