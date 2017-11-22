void configMenu() {
    Serial.println("ADMIN MENU - select one option");
    Serial.println("Entrei, daqui ninguem me tira");
		char command = 'z';
		delay(100);
		Serial.println(command);
    while(command != 'h'){
      command = serialReadChar();
  		if (command == 'a') {
  			Serial.println("Configure Date and Time");
  			delay(10);
  			setDateTime();
  			Serial.println("Recorded");
        command='z';
        
  		}
  		if (command == 'b') {
  			Serial.println("Showing Time");
  			showTime();
  			delay(10);
  			Serial.println(" ");
  			Serial.println();
        command='z';
  		}
  		if (command == 'c'){
  		Serial.println("Carregando memoria...");
  		rebootMemoryofUsers();
  		Serial.println("Conclu�do.");
      command='z';
  		}
  		if (command == 'd') {
  			int numero = listAllUsers();
  			Serial.println("Numero de usu�rio no sistema:");
  			Serial.println(numero);
        command='z';
  		}
      if (command == 'e') {
        addUser();
        command='z';
      }
  		if (command == 'f') {
  			deleteUser();
        command='z';
  		}
	}
  Serial.println("saindo");
}
void resetProtocol() {
  Serial.println("Loading System");
  setUserAdmin();
  rebootMemoryofUsers();
  int number = listAllUsers();
  Serial.println(number);
  char char_from_search[9]; 
  mem.readChars(4, char_from_search, sizeof(char_from_search));
  Serial.print("debug");
  Serial.println(char_from_search);
  Serial.println("Loading memory");
  Serial.println("Done");
  number = listAllUsers();
  Serial.println(number);
  char_from_search[9];
 
  mem.readChars(4, char_from_search, sizeof(char_from_search));
  Serial.print("debug 2");
  Serial.println(char_from_search);
  menuadmin();
}

void activeProtocol(){
  menuadmin();
}

