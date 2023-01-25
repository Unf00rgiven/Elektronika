char string[2];
int broj_poena;
int teorija[2];
int zadaci[3];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10000);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Unesite broj poena iz teorije (1. deo) :");
  while(!Serial.available()) ; 
  delay(100);
  teorija[0] = Serial.parseInt();
  if(teorija[0] > 25){
    return;
  }

  Serial.println("Unesite broj poena iz teorije (2. deo) :");
  while(!Serial.available()) ; 
  delay(100);
  teorija[1] = Serial.parseInt();
  if(teorija[1] > 25){
    return;
  }

  Serial.println("Unesite broj poena iz zadataka (1. deo) :");
  while(!Serial.available()) ; 
  delay(100);
  zadaci[0] = Serial.parseInt();
  if(zadaci[0] > 20){
    return;
  }
  
  Serial.println("Unesite broj poena iz zadataka (2. deo) :");
  while(!Serial.available()) ; 
  delay(100);
  zadaci[1] = Serial.parseInt();
  if(zadaci[1] > 20){
    return;
  }

  Serial.println("Unesite broj poena iz zadataka (3. deo) :");
  while(!Serial.available()) ; 
  delay(100);
  zadaci[2] = Serial.parseInt();
  if(zadaci[2] > 20){
    return;
  }

  broj_poena = teorija[0] + teorija[1] + zadaci[0] + zadaci[1] + zadaci[2];
  ocena(broj_poena);
}

void ocena(int broj_poena){
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
    else if(broj_poena > 100){
      Serial.print("Uneli ste ");
      Serial.print(broj_poena);
      Serial.println(" poena, sto je vise od gornje granice => Vas broj poena je sada 100 => Dobili ste ocenu 10.");
    }
    else {
      Serial.println("Uneli ste pogresan broj, Unesite ponovo! Broj mora biti u opsegu od 51 do 100.");
    }
}
