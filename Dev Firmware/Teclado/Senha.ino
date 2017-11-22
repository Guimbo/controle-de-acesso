unsigned long formaSenhaHexa(){
  int digito;
  unsigned long senha = 0;
  for(digito=0; digito < 8 ;digito++){
    senha = senha << 4;
    senha += ConverteCharParaHex(verificaTecla("hexa"));
  }
  return senha;
}
