void setup(){
  pinMode(2, OUTPUT);
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
  
  Serial.begin(9600);
  Serial.println("Controle de Acesso");
  Serial.println();
}

void loop(){
  char escolha = verificaTecla();
  if(escolha == 'A'){
    Serial.println("PASS!");
    digitalWrite(2, HIGH);
    delay (5000);
    Serial.println();
    Serial.println("Closing");
    digitalWrite(2, LOW);
    delay(500);
  }
  delay(100);
}

 
char formaTecla(int x, int y){
  if(x==1 && y ==1){return '1';}
  if(x==1 && y ==2){return '2';}
  if(x==1 && y ==3){return '3';}
  if(x==1 && y ==4){return 'A';}
  if(x==2 && y ==1){return '4';}
  if(x==2 && y ==2){return '5';}
  if(x==2 && y ==3){return '6';}
  if(x==2 && y ==4){return 'B';}
  if(x==3 && y ==1){return '7';}
  if(x==3 && y ==2){return '8';}
  if(x==3 && y ==3){return '9';}
  if(x==3 && y ==4){return 'C';}
  if(x==4 && y ==1){return '*';}
  if(x==4 && y ==2){return '0';}
  if(x==4 && y ==3){return '#';}
  if(x==4 && y ==4){return 'D';}
}

void imprimeTecla(int linha, int coluna){
  char tecla = formaTecla(linha, coluna);
  Serial.println(tecla);
  delay(10);
}

char verificaTecla(){
  char pressionada = 'n';
  while(pressionada == 'n'){
      for (int ti = 3; ti<7; ti++){
        //Alterna o estado dos pinos das linhas
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(ti, HIGH);
        //Verifica se alguma tecla da coluna 1 foi pressionada
        if (digitalRead(8) == HIGH){        
            imprimeTecla(ti-2, 1);
            while(digitalRead(8) == HIGH){}
            pressionada = formaTecla(ti-2, 1);
        }
        //Verifica se alguma tecla da coluna 2 foi pressionada    
        if (digitalRead(9) == HIGH){
            imprimeTecla(ti-2, 2);
            while(digitalRead(9) == HIGH){}
            pressionada = formaTecla(ti-2, 2);
        } 
        //Verifica se alguma tecla da coluna 3 foi pressionada
        if (digitalRead(10) == HIGH){
            imprimeTecla(ti-2, 3);
            while(digitalRead(10) == HIGH){}
            pressionada = formaTecla(ti-2, 3);
        }
        
        //Verifica se alguma tecla da coluna 4 foi pressionada
        if (digitalRead(11) == HIGH){
            imprimeTecla(ti-2, 4);
            while(digitalRead(11) == HIGH){}
            pressionada = formaTecla(ti-2, 4);
        }
      }
  }
  return pressionada;
}





