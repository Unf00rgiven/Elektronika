String  sentence = "";
int pal_check = 1;
void setup () {
	Serial.begin (9600) ;
}
void loop () {
  // podatak se ocitava tek kada je nesto primljeno:
  if ( Serial.available () > 0) {
    delay (50);
    // ocitavanje primljene recenica:
    sentence = Serial.readString();
    
    
    for (int i = 0; i < sentence.length(); i++)
      if (sentence[i] != sentence[sentence.length()-i-1])
      	pal_check = 0;
    
    if(pal_check)
    {
      Serial.println (" sentence is palindrom");      
    }
    else
    {
      Serial.println (" sentence is NOT a palindrom");
      pal_check=1;
    }
    
  }
}