void arrayConcat(){
  for(int i=0;i<=5;i++){ time_complete[i] = 0;}
  time_complete[0] = concatInt(hour[0] , hour[1]);
  time_complete[1] = concatInt(minute[0] , minute[1]);
  time_complete[2] = concatInt(second[0] , second[1]);
  for(int i=0;i<=5;i++){ date_complete[i] = 0;}
  date_complete[0] =  concatInt(day[0] , day[1]);
  date_complete[1] =  concatInt(month[0] , month[1]);
  date_complete[2] =  concatInt(year[0] , year[1]);
}

void setDateTime(){   //Seta a data e a hour do DS1307
  arrayConcat();
  byte hours = concatInt(hour[0] , hour[1]); //Valores de 0 a 23
  byte minutes = concatInt(minute[0] , minute[1]); //Valores de 0 a 59
  byte seconds = concatInt(second[0] , second[1]); //Valores de 0 a 59
  byte month_day = date_complete[0]; //Valores de 1 a 31
  byte month = date_complete[1]; //Valores de 1 a 12
  byte year = date_complete[2]; //Valores de 0 a 99
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

void showTime()
{
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
      case Domingo:Serial.println(", Domingo");
      break;
      case Segunda:Serial.println(", Segunda");
      break;
      case Terca:Serial.println(", Terca");
      break;
      case Quarta:Serial.println(", Quarta");
      break;
      case Quinta:Serial.println(", Quinta");
      break;
      case Sexta:Serial.println(", Sexta");
      break;
      case Sabado:Serial.println(", Sabado");
    }
}


void selectDateTimeDefault()   //Seta a data e a hora do DS1307
{
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
