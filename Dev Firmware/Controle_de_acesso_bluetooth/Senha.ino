unsigned long getEncryptedPassword(){
  int digit;
  unsigned long password = 0;
  for(digit=0; digit < 8 ;digit++){
    password = password << 4;
    password += charToHex(serialReadChar());
  }
  return password;
}

void getPassword(){
  Serial.println("password:");
  unsigned long senha1 = getEncryptedPassword();
  unsigned long senha_default = 0x0123456d;

  if(senha1 == senha_default){access();}
  else{
    Serial.println("Accesses Denied");
  }
}


String getUserName() {
  String username;
	Serial.println("username:");
	unsigned int array_user[8];
	int i = 0;
	for (i = 0; i < 8; i++) {
		array_user[i] = serialReadChar();
		array_user[i] = array_user[i] << 2;
		array_user[i] = array_user[i] + 20;
		array_user[i] = array_user[i] >> 2;
		Serial.println(array_user[i]);
		Serial.println(char(array_user[i]));
		delay(10);
	}
	for (i = 0; i <= 8; i++) {
		username = String( username + char(array_user[i]));
	}
	Serial.println(username);
	return username;
}