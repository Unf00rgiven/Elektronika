char string[25];

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  Serial.setTimeout(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ret = 0;
  int duzina;
  
  Serial.println("Unesite string:");
  
  while(!Serial.available()); 
  delay(100);
  duzina = Serial.available();

  Serial.readBytes(string, duzina);
  string[duzina] = 0;

  ret = palindrom(string, duzina);

  if(ret == 0){
    Serial.print(string);
    Serial.print("jeste palindrom.\n");
  }else{
    Serial.print(string);
    Serial.print("nije palindrom.\n");
  }
}

int palindrom(char* string, int duzina){
  int a = 0;
  int b = duzina - 2;

  while(a < b){
    if(string[a] != string[b])
    {
      return 1;
    }
    else{
      a++;
      b--;
    }
  }

return 0;
}
