
#include "Wire.h"
#define DS1307_ADDRESS 0x68

byte zero = 0x00; 
unsigned int tempoConvertido[5];
unsigned int dataConvertida[5];
unsigned int dataPrincipal[7];
unsigned int horaPrincipal[7];
unsigned int segundo[2];
unsigned int minuto[2];
unsigned int hora[2];
unsigned int dia[2];
unsigned int mes[2];
unsigned int ano[2];
unsigned int semana;
void setup(){
  //Pinos ligados aos pinos 1, 2, 3 e 4 do teclado - Linhas
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
   
  //Pinos ligados aos pinos 5, 6, 7 e 8 do teclado - Colunas
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);

  Wire.begin();
  Serial.begin(9600);
  SelecionaDataeHoradefault();
  Serial.println("Aguardando acionamento das teclas...");
  Serial.println();
}

void loop(){
  char escolha = verificaTecla();
  if(escolha == '*'){
    Serial.println("grava do RTC...");
    delay(10);
    Date();
    delay(10);
    Timeclock();
    delay(10);
    SelecionaDataeHora();
    Serial.println("Gravado");
    Serial.println();
  }
  if(escolha == '#'){
    Serial.println("Mostrando tempo");
    Mostrarelogio();
    delay(10);
    Serial.println(" ");
    Serial.println();
  }

  
  delay(10);
}

 










