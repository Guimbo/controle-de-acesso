
void getDate(){

  Serial.println("Enter date in the format 00/00/00 ");
  char local_array[8];
  Serial.flush();
  int i = 0;
  for (i = 0; i<7 ;i++) {
	  while (Serial.available() == 0) {}
	  local_array[i] = Serial.read();
  }
  day[0] = local_array[0]- 48;
  day[1] = local_array[1]- 48;
  month[0] = local_array[2]- 48;
  month[1] = local_array[3]- 48;
  year[0] = local_array[4]- 48;
  year[1] = local_array[5]- 48;
  week_day = local_array[6]- 48;
  delay(10);
}


void getTime(){
  Serial.println("Enter time in the format 00:00:00 ");
  char local_array[6];
  Serial.flush();
  int i = 0;
  for (i = 0; i < 6;i++) {
	  while (Serial.available() == 0) {}
	  local_array[i] = Serial.read();
  }
  hour[0] = local_array[0]- 48;
  hour[1] = local_array[1]- 48;
  minute[0] = local_array[2]- 48;
  minute[1] = local_array[3]- 48;
  second[0] = local_array[4]- 48;
  second[1] = local_array[5]- 48;
  delay(10);
}


