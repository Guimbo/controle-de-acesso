void access(){
    Serial.print(2); //Envia 2 para o android
    digitalWrite(17, HIGH);
    delay (3000);
    Serial.print(4); // Envia 4 para o android
    digitalWrite(17, LOW);
    delay(10);
}

char serialReadChar(){
    char character;
    while(Serial.available() == 0){}
    character = Serial.read();
    delay(10);
    return character;
}
