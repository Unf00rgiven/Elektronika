char rec[10];
char slovo;
char kopija[10];
int duzina, kraj = 0, zivoti = 5;
void setup() {
  Serial.begin(9600);
}

void loop() {
  pocetak();
  while (kraj == 0) {
    unos();
    pretraga();
    provera();
  }
}

void pocetak() {
  do {
    Serial.println("Unesite rec koju treba pogoditi (maksimalno 10 slova): ");
    while (!Serial.available());
    delay(150);
    duzina = Serial.available();
    Serial.readBytes(rec, duzina);
    rec[duzina] = 0;
    if (duzina > 10) {
      Serial.println("Rec preduga, pokusaj ponovo!");
    }
  } while (duzina > 10);
  Serial.println("Vasa rec je prihvacena, mozete poceti igru.");
  for (int i = 0; i < duzina; i++) {
    kopija[i] = '_';
  }
  for (int i = 0; i < duzina; i++) {
    Serial.print(" __ ");
  }
  Serial.println();
  Serial.print("Rec ima ");
  Serial.print(duzina);
  Serial.println(" slova.");

}

void unos() {
  Serial.println("Unesite slovo:");
  while (!Serial.available());
  delay(50);
  slovo = Serial.read();
  Serial.print("Trazim slovo ");
  Serial.println(slovo);
}

void pretraga() {
  int pog = 0;
  for (int i; i < duzina; i++) {
    if (rec[i] == slovo) {
      pog++;
      kopija[i] = slovo;
    }
  }
  if (pog == 0) {
    zivoti--;
    Serial.println("Trazenog slova nema!");
    Serial.print("Preostalo vam je ");
    Serial.print(zivoti);
    Serial.println(" pokusaja.");
  }
  else {
    Serial.print("Trazeno slovo se ponavlja ");
    Serial.print(pog);
    Serial.println(" puta.");
    for (int i = 0; i < duzina; i++) {
      Serial.print(kopija[i]);
      Serial.print(" ");
    }
    Serial.println();
  }
}

void provera() {
  int pog = 0;
  if (zivoti == 0) {
    Serial.println("GAME OVER!");
    Serial.print("Trazena rec je bila: ");
    Serial.println(rec);
    Serial.println("");
    Serial.println("");
    kraj = 1;
  }
  for (int i = 0; i < duzina; i++) {
    if (kopija[i] == rec[i]) {
      pog++;
    }
  }
  if (pog == duzina) {
    Serial.println("Cestamo, pogodili ste trazenu rec!");
    kraj = 1;
    Serial.println("");
    Serial.println("");
    Serial.println("");

  }
}

