void access(){
    Serial.println("Opened!");
    digitalWrite(17, HIGH);
    delay (3000);
    Serial.println();
    Serial.println("Closed!");
    digitalWrite(17, LOW);
    delay(100);
}

char serialReadChar(){
    char character;
    while(Serial.available() == 0){}
    character = Serial.read();
    delay(10);
    Serial.println(character);
    delay(10);
    return character;
}