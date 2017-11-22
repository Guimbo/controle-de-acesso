// The under functions not count the user admin(the first space in memory)
void setUserAdmin() {
  mem.writeLong(0, 0x12345678);
  char msg_char[9];
  String msg = "zxjwfirs";
  msg.toCharArray(msg_char, 9);
  mem.writeChars(4, msg_char, sizeof(msg_char));
  unsigned long dado = mem.readLong(0);
  Serial.println(dado, HEX);
  Serial.println();
  char msgchar2[9];
  mem.readChars(4, msgchar2, sizeof(msgchar2));
  Serial.print("... read: ");
  Serial.println(msgchar2);

}
void rebootMemoryofUsers() {
	int i = 13;
	char msg_char[9];
	String msg = "00000000";
	while (i < 4095) {
		// clean memory of passwords
		mem.writeLong(i, 0x0000000f);
		// clean memory of usernames
		msg.toCharArray(msg_char, 9);
		mem.writeChars(i + 4, msg_char, sizeof(msg_char));
		i = i + 13;
	}
}


int seachMemoryFree() {
	int i = 13;
	for (i = 13; i < 4095;i = i + 13) {
		unsigned long data = mem.readLong(i);
		if (data == 0x0000000f) { return i; }
	}
	return 5000;
}

int memoOfUser(String usertoChange){
  int i = 0;
  char char_user[9];
  char char_from_search[9];
  int count = 0;
  int j = 0;
  usertoChange.toCharArray(char_user, 9);
  mem.readChars(4, char_from_search, sizeof(char_from_search));
  i=4;
  while(i<4096) { 
    count = 0;
    mem.readChars(i, char_from_search, sizeof(char_from_search));
     for(j=0;j <=9;j++){if(char_user[j] == char_from_search[j]){count++;}}
    if(count ==9){return i-4;}
    i = i+13;
  }
  return 5000;
}


int listAllUsers() {
	int count = 0;
	int i = 13;
	int j = 0;
	char user_char[9];
	String normal_name;
	for (i = 13; i < 4095; i = i + 13) {
		unsigned long data = mem.readLong(i);
		if (data == 0x0000000f) { continue; }
		mem.readChars(i + 4, user_char, sizeof(user_char));
		for (j = 0; j < 8; j++) {
			user_char[j] = int(user_char[j]) - 5;
			delay(10);
		}
		for (j = 0; j <= 8; j++) {
			normal_name = String(normal_name + char(user_char[j]));
		}
		delay(10);
		count++;
		Serial.println(normal_name);
	}
	return count;
}


void addUser() {
	String new_user = getUserName();
	unsigned long new_pass = getEncryptedPassword();
	int space = seachMemoryFree();
	Serial.print(space);
	if (space == 5000) { Serial.print("No space!"); }
	else {
		char char_user[9];
		mem.writeLong(space, new_pass);
		new_user.toCharArray(char_user, 9);
		mem.writeChars(space + 4, char_user, sizeof(char_user));
		Serial.print("Added");
	}
}

void deleteUser() {
	String end_user = getUserName();
	int memo_user = memoOfUser(end_user);
	if (memo_user == 5000) { Serial.print("User not finded"); }
	else {
		char char_user[9];
		mem.writeLong(memo_user, 0x0000000f);
		end_user = "00000000";
		end_user.toCharArray(char_user, 9);
		mem.writeChars(memo_user + 4, char_user, sizeof(char_user));
		Serial.print("Deleted");
	}
}

int authenticateUser() {
	String find_user = getUserName();
	Serial.println("username pego");
	Serial.println(find_user);
	unsigned long passoword_typed = getEncryptedPassword();
	Serial.println("password pego");
	Serial.println(passoword_typed);
	int memo_user = memoOfUser(find_user);
	Serial.println("memoria localizada");
	Serial.println(memo_user);
	unsigned long password_in_system;
	if (memo_user == 5000) {
		Serial.print("User not finded");
    if(recordNotAccess(find_user) == 0 ){
        //blockSystem();
    }
    return 0;
	}
	else {
		password_in_system = mem.readLong(memo_user);
		if ((memo_user == 0) && (passoword_typed == password_in_system)) { return 1; }
		if (passoword_typed == password_in_system) {
			access();
      recordAccess(find_user);
			return 2;
		}
		else {
			if(recordNotAccess(find_user) == 0 ){
        //blockSystem();
      }
			return 0;
	  }
  }
}

void menuadmin(){
	if (authenticateUser() ==1){configMenu();}
  }
