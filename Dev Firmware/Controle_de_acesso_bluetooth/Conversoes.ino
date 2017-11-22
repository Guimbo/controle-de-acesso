byte byteToBCD(byte val){
  return ( (val/10*16) + (val%10) );
}

byte byteToInt(byte val)  {
  return ( (val/16*10) + (val%16) );
}


int concatInt(int a , int b){
  a = a * 10;
  int answer = a + b;
  return answer;
}

int charToHex(char caractere){
  if(caractere == '0'){ return 0x0;}
  if(caractere == '1'){ return 0x1;}
  if(caractere == '2'){ return 0x2;}
  if(caractere == '3'){ return 0x3;}
  if(caractere == '4'){ return 0x4;}
  if(caractere == '5'){ return 0x5;}
  if(caractere == '6'){ return 0x6;}
  if(caractere == '7'){ return 0x7;}
  if(caractere == '8'){ return 0x8;}
  if(caractere == '9'){ return 0x9;}
  if(caractere == 'a'){ return 0xa;}
  if(caractere == 'b'){ return 0xb;}
  if(caractere == 'c'){ return 0xc;}
  if(caractere == 'd'){ return 0xd;}
  if(caractere == 'e'){ return 0xe;}
  if(caractere == 'f'){ return 0xf;}
  
}

enum DiaDaSemana {
	Domingo,
	Segunda,
	Terca,
	Quarta,
	Quinta,
	Sexta,
	Sabado
};