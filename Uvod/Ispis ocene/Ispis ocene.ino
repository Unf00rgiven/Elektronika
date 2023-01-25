char string[2];
int broj_poena;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10000);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Unesite broj poena:");
  
  while(!Serial.available()) ; 
  delay(100);
 
  broj_poena = Serial.parseInt();
  
    if(broj_poena > 50 && broj_poena < 61){
      Serial.print("Uneli ste ");
      Serial.print(broj_poena);
      Serial.println(" poena => Dobili ste ocenu 6.");
    }
    else if(broj_poena > 60 && broj_poena < 71){
      Serial.print("Uneli ste ");
      Serial.print(broj_poena);
      Serial.println(" poena => Dobili ste ocenu 7.");
    }
    else if(broj_poena > 70 && broj_poena < 81){
      Serial.print("Uneli ste ");
      Serial.print(broj_poena);
      Serial.println(" poena => Dobili ste ocenu 8.");
    }
    else if(broj_poena > 80 && broj_poena < 91){
      Serial.print("Uneli ste ");
      Serial.print(broj_poena);
      Serial.println(" poena => Dobili ste ocenu 9.");
    }
    else if(broj_poena > 90 && broj_poena < 101){
      Serial.print("Uneli ste ");
      Serial.print(broj_poena);
      Serial.println(" poena => Dobili ste ocenu 10.");
    }
    else {
      Serial.println("Uneli ste pogresan broj, Unesite ponovo! Broj mora biti u opsegu od 51 do 100.");
    }
}
