void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   int granica = 20;
   int fibonaci[granica];
   fibonaci[0]=1;
   fibonaci[1]=1;

   Serial.print("IZLAZ: ");
   Serial.println(fibonaci[0]);
   delay(1000);
   Serial.println(fibonaci[1]);
   delay(1000);
  
   for(int i = 2 ; i <= granica ; i++)
   {
      fibonaci[i]=fibonaci[i-1]+fibonaci[i-2];
      Serial.println(fibonaci[i]);
      delay(1000);
   }

   Serial.end();
   exit(0);
  

}
