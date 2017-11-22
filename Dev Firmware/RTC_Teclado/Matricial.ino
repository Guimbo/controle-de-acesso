void imprimeTecla(int linha, int coluna){
  char tecla = formaTecla(linha, coluna);
  Serial.print(tecla);
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


void  Date(){

  Serial.println("Digite a data no formato 00/00/00 ");
  for(int i=0;i<7;i++){dataPrincipal[i] =0;}
  dataPrincipal[0] = 0;
  dia[0] = verificaTecla()- 48;
  dia[1] = verificaTecla()- 48;
  Serial.print("/");
  mes[0] = verificaTecla()- 48;
  mes[1] = verificaTecla()- 48;
  Serial.print("/");
  ano[0] = verificaTecla()- 48;
  ano[1] = verificaTecla()- 48;
  Serial.println(" Digite o dia da semana em numero:");
  semana = verificaTecla()- 48;
  Serial.println();
  delay(10);
}


void Timeclock(){
  Serial.println("Digite a hora no formato 00:00:00 ");
  for(int i=0;i<7;i++){horaPrincipal[i] =0;}
  hora[0] = verificaTecla() - 48;
  hora[1] = verificaTecla() - 48;
  Serial.print(":");
  minuto[0] = verificaTecla()- 48;
  minuto[1] = verificaTecla()- 48;
  Serial.print(":");
  segundo[0] = verificaTecla()- 48;
  segundo[1] = verificaTecla()- 48;
  delay(10);   
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


