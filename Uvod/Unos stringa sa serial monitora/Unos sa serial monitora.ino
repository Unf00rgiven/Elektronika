char string[20];

void setup() {
  Serial.begin(9600);           //bita po sekundi

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
  
}

  void serialEvent(){
    delay(100);  
    int br_bajtova = Serial.available();
    
    Serial.readBytes(string, br_bajtova);
    string[br_bajtova] = '\0';                                  //moze i nula obicna

    Serial.println(string);
  }
