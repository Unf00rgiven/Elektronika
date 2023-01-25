void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float x1, x2;
  float a, b, c;
  float koren, pom;

  Serial.println("Unesite a : " );
  while (Serial.available() == 0) {}
  a = Serial.parseFloat();
  Serial.println("Unesite b : " );
  while (Serial.available() == 0) {}
  b = Serial.parseFloat();
  Serial.println("Unesite c : " );
  while (Serial.available() == 0) {}
  c = Serial.parseFloat();

  if (pow(b, 2)-4*a*c < 0)
  {
    koren = sqrt(4*a*c - pow(b, 2))/2/a;
    pom = - b/2/a;
    
    Serial.print("x1 = ");
    Serial.print(pom);
    Serial.print(" + i * ");
    Serial.println(koren);
    
    Serial.print("x2 = ");
    Serial.print(pom);
    Serial.print(" - i * ");
    Serial.println(koren);
  }
  else
  {
    koren = sqrt(pow(b, 2) - 4*a*c )/2/a;
    x1 = -(b/2/a) + koren;
    x2 = -(b/2/a) - koren;
    Serial.print("x1 = ");
    Serial.println(x1);
    Serial.print("x2 = ");
    Serial.println(x2);
  }

  Serial.end();
}
