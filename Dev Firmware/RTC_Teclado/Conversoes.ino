byte ConverteParaBCD(byte val){ //Converte o número de decimal para BCD
  return ( (val/10*16) + (val%10) );
}

byte ConverteparaDecimal(byte val)  { //Converte de BCD para decimal
  return ( (val/16*10) + (val%16) );
}

int ConverteCharparaInt(char valor){
    int convertido = valor - '0';
    return convertido;
}

uint8_t decToBcd(uint8_t val){
  return ( (val/10*16) + (val%10) );
}
