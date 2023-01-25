int a;
int b;
int c;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  a = 1;
  b = 1;
  Serial.println(a);
  Serial.println(b);
}

void loop() {
  // put your main code here, to run repeatedly:
  c = a + b;
  
  if(c < 0){
    while(true);
  }
  
  Serial.println(c);
  a = b;
  b = c;
  delay(1000);
}
