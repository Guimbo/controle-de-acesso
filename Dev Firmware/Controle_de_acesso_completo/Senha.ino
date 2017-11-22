unsigned long getEncryptedPassword(){
  int digit;
  unsigned long password = 0;
  Serial.println("password: ");
  for(digit=0; digit < 8 ;digit++){
    password = password << 4;
    password += charToHex(serialReadChar());
  }
  return password;
}

String getUserName() {
  String username;
	Serial.println("username:");
	unsigned int array_user[8];
	int i = 0;
	for (i = 0; i < 8; i++) {
		array_user[i] = serialReadChar();
		array_user[i] = int(array_user[i]) + 5;
		delay(10);
	}
	for (i = 0; i <= 8; i++) {
		username = String( username + char(array_user[i]));
	}
	return username;
}
