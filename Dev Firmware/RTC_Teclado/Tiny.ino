int doisInts(int a , int b){
  a = a * 10;
  int resposta = a + b;
  return resposta;
}


void doisVetores(){
  for(int i=0;i<=5;i++){tempoConvertido[i] = 0;}
  tempoConvertido[0] = doisInts(hora[0] , hora[1]);
  tempoConvertido[1] = doisInts(minuto[0] , minuto[1]);
  tempoConvertido[2] = doisInts(segundo[0] , segundo[1]);
  for(int i=0;i<=5;i++){dataConvertida[i] = 0;}
  
  dataConvertida[0] =  doisInts(dia[0] , dia[1]);
  dataConvertida[1] =  doisInts(mes[0] , mes[1]);
  dataConvertida[2] =  doisInts(ano[0] , ano[1]);
}

void SelecionaDataeHora(){   //Seta a data e a hora do DS1307
  doisVetores();
  byte horas = doisInts(hora[0] , hora[1]); //Valores de 0 a 23
  byte minutos = doisInts(minuto[0] , minuto[1]); //Valores de 0 a 59
  byte segundos = doisInts(segundo[0] , segundo[1]); //Valores de 0 a 59
  byte diadomes = dataConvertida[0]; //Valores de 1 a 31
  byte mes = dataConvertida[1]; //Valores de 1 a 12
  byte ano = dataConvertida[2]; //Valores de 0 a 99
  byte diadasemana = semana; //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); //Stop no CI para que o mesmo possa receber os dados
  
  //As linhas abaixo escrevem no CI os valores de 
  //data e hora que foram colocados nas variaveis acima
  Wire.write(ConverteParaBCD(segundos));
  Wire.write(ConverteParaBCD(minutos));
  Wire.write(ConverteParaBCD(horas));
  Wire.write(ConverteParaBCD(diadasemana));
  Wire.write(ConverteParaBCD(diadomes));
  Wire.write(ConverteParaBCD(mes));
  Wire.write(ConverteParaBCD(ano));
  Wire.write(zero); //Start no CI
  Wire.endTransmission();   
}

void Mostrarelogio()
{
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  int segundos = ConverteparaDecimal(Wire.read());
  int minutos = ConverteparaDecimal(Wire.read());
  int horas = ConverteparaDecimal(Wire.read() & 0b111111); 
  int diadasemana = ConverteparaDecimal(Wire.read()); 
  int diadomes = ConverteparaDecimal(Wire.read());
  int mes = ConverteparaDecimal(Wire.read());
  int ano = ConverteparaDecimal(Wire.read());
  //Mostra a data no Serial Monitor
  Serial.print("Data: ");
  Serial.print(diadomes);
  Serial.print("/");
  Serial.print(mes);
  Serial.print("/");
  Serial.print(ano);
  Serial.print(" ");
  Serial.print("Hora : ");
  Serial.print(horas);
  Serial.print(":");
  Serial.print(minutos);
  Serial.print(":");
  Serial.print(segundos);
  switch(diadasemana)
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


void SelecionaDataeHoradefault()   //Seta a data e a hora do DS1307
{
  byte segundos = 40; //Valores de 0 a 59
  byte minutos = 59; //Valores de 0 a 59
  byte horas = 23; //Valores de 0 a 23
  byte diadasemana = 1; //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
  byte diadomes = 17; //Valores de 1 a 31
  byte mes = 4; //Valores de 1 a 12
  byte ano = 13; //Valores de 0 a 99
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); //Stop no CI para que o mesmo possa receber os dados

  //As linhas abaixo escrevem no CI os valores de 
  //data e hora que foram colocados nas variaveis acima
  Wire.write(ConverteParaBCD(segundos));
  Wire.write(ConverteParaBCD(minutos));
  Wire.write(ConverteParaBCD(horas));
  Wire.write(ConverteParaBCD(diadasemana));
  Wire.write(ConverteParaBCD(diadomes));
  Wire.write(ConverteParaBCD(mes));
  Wire.write(ConverteParaBCD(ano));
  Wire.write(zero); //Start no CI
  Wire.endTransmission(); 
}


/*
 * 
void doisVetores(){

  for(int i=0;i<=5;i++){Serial.print(horaPrincipal[i]);}
  Serial.println();
  Serial.print("A de amore");
  Serial.println();
  for(int i=0;i<7;i++){Serial.print(dataPrincipal[i]);}
  Serial.println("B de Baixino");
  for(int i=0;i<=5;i++){tempoConvertido[i] = 0;}
  tempoConvertido[0] = doisInts(horaPrincipal[0] , horaPrincipal[1]);
  tempoConvertido[1] = doisInts(horaPrincipal[2] , horaPrincipal[3]);
  tempoConvertido[2] = doisInts(horaPrincipal[4] , horaPrincipal[5]);
  for(int i=0;i<=5;i++){dataConvertida[i] = 0;}
  dataConvertida[0] =  doisInts(horaPrincipal[0] , horaPrincipal[1]);
  dataConvertida[1] =  doisInts(horaPrincipal[2] , horaPrincipal[3]);
  dataConvertida[2] =  doisInts(dataPrincipal[4] , dataPrincipal[5]);
  dataConvertida[4] =  dataPrincipal[6];
  for(int i=0;i<=3;i++){Serial.println(tempoConvertido[i]);}
  Serial.println();
  Serial.print("C de coracao");
  Serial.println();
  for(int i=0;i<3;i++){Serial.println(dataConvertida[i]);}
  Serial.println("D de Deu bom");
  Serial.print(dataPrincipal[6]);
}*/
