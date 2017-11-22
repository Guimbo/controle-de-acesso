void recordAccess(String user){
  byte zero = 0x00; 
	if (!SD.begin(4)) {
		Serial.println("initialization failed!");
		return;
	}
	Serial.println("initialization done.");
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
	//Grava data e hora no cart�o SD
	String fileName = returnNameOfMonth(month);
	fileName = String(fileName + int(year));
	logFile = SD.open(fileName, FILE_WRITE);
	String to_whrite = String(user + " ativou em ");
	logFile.print(to_whrite);
	logFile.print("Data: ");
	logFile.print(month_day);
	logFile.print("/");
	logFile.print(month);
	logFile.print("/");
	logFile.print(year);
	logFile.print(" ");
	logFile.print("Hora : ");
	logFile.print(hours);
	logFile.print(":");
	logFile.print(minutes);
	logFile.print(":");
	logFile.print(seconds);
	switch (day_in_week){
	case 0:logFile.println(", Domingo");
		break;
	case 1:logFile.println(", Segunda");
		break;
	case 2:logFile.println(", Terca");
		break;
	case 3:logFile.println(", Quarta");
		break;
	case 4:logFile.println(", Quinta");
		break;
	case 5:logFile.println(", Sexta");
		break;
	case 6:logFile.println(", Sabado");
	}
 logFile.close();
}



int recordNotAccess(String user) {
  byte zero = 0x00; 
	if (!SD.begin(4)) {
		Serial.println("initialization failed!");
		return 2;
	}
	Serial.println("initialization done.");
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
	//Contador zerado e nenhuma tentativa
	if ((global_week_day == 0) && (global_hour == 0) && (global_minute == 0) && (global_second == 0) && (trys = 0)) {
		global_week_day = day_in_week;
		global_hour = hours;
		global_minute = minutes;
		global_second = seconds;
		trys = 1;
		//Grava data e hora no cart�o SD
		String fileName = returnNameOfMonth(month);
		fileName = String(fileName + int(year));
		logFile = SD.open(fileName, FILE_WRITE);
		String to_whrite = String("!ERROR! :" + user + " tentou ativar em ");
		logFile.print(to_whrite);
		logFile.print("Data: ");
		logFile.print(month_day);
		logFile.print("/");
		logFile.print(month);
		logFile.print("/");
		logFile.print(year);
		logFile.print(" ");
		logFile.print("Hora : ");
		logFile.print(hours);
		logFile.print(":");
		logFile.print(minutes);
		logFile.print(":");
		logFile.print(seconds);
		switch (day_in_week) {
		case 0:logFile.println(", Domingo");
			break;
		case 1:logFile.println(", Segunda");
			break;
		case 2:logFile.println(", Terca");
			break;
		case 3:logFile.println(", Quarta");
			break;
		case 4:logFile.println(", Quinta");
			break;
		case 5:logFile.println(", Sexta");
			break;
		case 6:logFile.println(", Sabado");
		}
    logFile.close();
		return 1;
	}
	//Dentro do contador e com alguma tentaiva
	if ((day_in_week - global_week_day == 0) && (hours - global_hour <= 1) && (minutes - global_minute <= 1)) {
		if (((hours - global_hour == 1) && (((minutes + 60) - global_minute) <= 1)) || (hours - global_hour == 0)) {
			global_week_day = day_in_week;
			global_hour = hours;
			global_minute = minutes;
			global_second = seconds;
			//grava��o em SD card
			String fileName = returnNameOfMonth(month);
			fileName = String(fileName + int(year));
			logFile = SD.open(fileName, FILE_WRITE);
			String to_whrite = String("!ERROR! :" + user + " tentou ativar em ");
			logFile.print(to_whrite);
			logFile.print("Data: ");
			logFile.print(month_day);
			logFile.print("/");
			logFile.print(month);
			logFile.print("/");
			logFile.print(year);
			logFile.print(" ");
			logFile.print("Hora : ");
			logFile.print(hours);
			logFile.print(":");
			logFile.print(minutes);
			logFile.print(":");
			logFile.print(seconds);
			switch (day_in_week) {
			case 0:logFile.println(", Domingo");
				break;
			case 1:logFile.println(", Segunda");
				break;
			case 2:logFile.println(", Terca");
				break;
			case 3:logFile.println(", Quarta");
				break;
			case 4:logFile.println(", Quinta");
				break;
			case 5:logFile.println(", Sexta");
				break;
			case 6:logFile.println(", Sabado");
			}
			if (trys == 1) {
				trys = 2;
        logFile.close();
				return 1;
			}
			//Trava sistema
			if (trys == 2) {
				global_week_day = 0;
				global_hour = 0;
				global_minute = 0;
				global_second = 0;
				trys = 0;
				String fileName = returnNameOfMonth(month);
				fileName = String(fileName + int(year));
				logFile = SD.open(fileName, FILE_WRITE);
				String to_whrite = String("!ALERT! : FORCE BRUTE REGISTER! System lock in:");
				logFile.print(to_whrite);
				logFile.print("Data: ");
				logFile.print(month_day);
				logFile.print("/");
				logFile.print(month);
				logFile.print("/");
				logFile.print(year);
				logFile.print(" ");
				logFile.print("Hora : ");
				logFile.print(hours);
				logFile.print(":");
				logFile.print(minutes);
				logFile.print(":");
				logFile.print(seconds);
				switch (day_in_week) {
				case 0:logFile.println(", Domingo");
					break;
				case 1:logFile.println(", Segunda");
					break;
				case 2:logFile.println(", Terca");
					break;
				case 3:logFile.println(", Quarta");
					break;
				case 4:logFile.println(", Quinta");
					break;
				case 5:logFile.println(", Sexta");
					break;
				case 6:logFile.println(", Sabado");
				}
				return 0;
        logFile.close();
			}
		}
	}
	//Fora do contador com alguma tentativa	
	else {
		global_week_day = day_in_week;
		global_hour = hours;
		global_minute = minutes;
		global_second = seconds;
		trys = 1;
		//Grava data e hora no cartao SD
		String fileName = returnNameOfMonth(month);
		fileName = String(fileName + int(year));
		logFile = SD.open(fileName, FILE_WRITE);
		String to_whrite = String("!ERROR :" + user + " tentou ativar em ");
		logFile.print(to_whrite);
		logFile.print("Data: ");
		logFile.print(month_day);
		logFile.print("/");
		logFile.print(month);
		logFile.print("/");
		logFile.print(year);
		logFile.print(" ");
		logFile.print("Hora : ");
		logFile.print(hours);
		logFile.print(":");
		logFile.print(minutes);
		logFile.print(":");
		logFile.print(seconds);
		switch (day_in_week) {
		case 0:logFile.println(", Domingo");
			break;
		case 1:logFile.println(", Segunda");
			break;
		case 2:logFile.println(", Terca");
			break;
		case 3:logFile.println(", Quarta");
			break;
		case 4:logFile.println(", Quinta");
			break;
		case 5:logFile.println(", Sexta");
			break;
		case 6:logFile.println(", Sabado");
		}
    logFile.close();
		return 1;
	}
}

//void readAllLog(){}
//void recordLockSystem(){}
//void recordActiveSystem(){}
//fixShow users
