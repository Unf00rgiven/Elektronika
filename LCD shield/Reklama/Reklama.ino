#include <LiquidCrystal.h>
LiquidCrystal lcd{8,9,4,5,6,7};

#define UP 3
#define RIGHT 5 
#define DOWN 4
#define LEFT 2
#define SELECT 1
#define NONE 0

int x_pos = 0, y_pos = 0;
int sd = 0;
char karakter = 32;

void setup() {
  lcd.begin(16,2);
  lcd.cursor();
  lcd.setCursor(0,0);
}

void loop() {
  int taster = ocitajTaster();

  if(taster != 0 && sd == 0){
    sd = 1;
    delay(50);
    if(taster == RIGHT){
        if(x_pos < 16){
          x_pos++;
        }
        if(x_pos == 16 && y_pos == 0){
          x_pos = 0;
          y_pos = 1;
        }
        if(x_pos == 16 && y_pos == 1){
          x_pos = 0;
          y_pos = 0;  
        }
    }  
    else if(taster == LEFT){
        if(x_pos > -1)
          x_pos--;
        if(x_pos == -1 && y_pos == 1){
          x_pos = 15;
          y_pos = 0;  
        }
        if(x_pos == -1 && y_pos == 0){
          x_pos = 15;
          y_pos = 1;  
        }  
    }
    else if(taster == UP){
      karakter++;
      if(karakter == 33)
        karakter = 48;
      if(karakter == 58)
        karakter = 65;
      if(karakter == 91)
        karakter = 97;
      if(karakter == 123)
        karakter = 32;
    }
    else if(taster == DOWN){
      karakter--;
      if(karakter == 47)
        karakter = 32;
      if(karakter == 64)
        karakter = 57;
      if(karakter == 96)
        karakter = 90;
      if(karakter == 31)
        karakter = 122;
    }
    else if(taster == SELECT){
      lcd.noCursor();
      
      while(1){
      lcd.scrollDisplayLeft();
      delay(200);
      } 
    }
  }
  if(taster == 0)
    sd = 0;

  lcd.setCursor(x_pos, y_pos);
  lcd.print(karakter);
  delay(100);
  //lcd.clear();
}

int ocitajTaster(){
  int a_vr = analogRead(0);
  if(a_vr < 50)
    return RIGHT;
  else if(a_vr < 175)
    return UP;
  else if(a_vr < 325)
    return DOWN;
  else if(a_vr < 520)
    return LEFT;
  else if(a_vr < 800)
    return SELECT;
  else
    return NONE;  
}