void setup(){
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
  unsigned long senha1 = formaSenhaHexa();
  Serial.print(senha1, HEX);
  Serial.println();
  delay(10);
}
