#include "LedControl.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

LedControl lc=LedControl(6,4,5,1);


unsigned long delaytime1=50;
unsigned long delaytime2=25;
void setup() {
  lcd.begin(16, 2);
  
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,1);
  /* and clear the display */
  lc.clearDisplay(0);
}

void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110}; //B01111110,B10001000,B10001000,B10001000,B01111110
  byte r[5]={B00010000,B00100000,B00100000,B00010000,B00111110};
  byte d[5]={B11111110,B00010010,B00100010,B00100010,B00011100};
  byte u[5]={B00111110,B00000100,B00000010,B00000010,B00111100};
  byte i[5]={B00000000,B00000010,B10111110,B00100010,B00000000};
  byte n[5]={B00011110,B00100000,B00100000,B00010000,B00111110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};
  byte b[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  byte c[5]={B00000000,B00000000,B00100010,B00100010,B00111110};
  byte l[5]={B00000000,B00000100,B00000100,B01111100,B01000000};
  byte h[5]={B00000000,B00001110,B00001000,B01111110,B00000000};
  byte p[5]={B00000000,B00111000,B00101000,B00111110,B00000000};//B00111100,B00101000,B00111000
  byte e[5]={B00000000,B00101010,B00101010,B00111110,B00000000};
  /* now display them one by one with a small delay */
  
  lc.setRow(0,0,h[0]);
  lc.setRow(0,1,h[1]);
  lc.setRow(0,2,h[2]);
  lc.setRow(0,3,h[3]);
  lc.setRow(0,4,h[4]);
  delay(delaytime1);

    
  lc.setRow(0,0,e[0]);
  lc.setRow(0,1,e[1]);
  lc.setRow(0,2,e[2]);
  lc.setRow(0,3,e[3]);
  lc.setRow(0,4,e[4]);
  delay(delaytime1);

  lc.setRow(0,0,l[0]);
  lc.setRow(0,1,l[1]);
  lc.setRow(0,2,l[2]);
  lc.setRow(0,3,l[3]);
  lc.setRow(0,4,l[4]);
  delay(delaytime1);
    
  lc.setRow(0,0,p[0]);
  lc.setRow(0,1,p[1]);
  lc.setRow(0,2,p[2]);
  lc.setRow(0,3,p[3]);
  lc.setRow(0,4,p[4]);
  delay(delaytime1);
    
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime1);
  
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime2);
    lc.setRow(0,row,B10100000);
    delay(delaytime2);
    //lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime2);
      lc.setRow(0,row,B10100000);
      delay(delaytime2);
      //lc.setRow(0,row,(byte)0);
    }
  }
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime2);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime2);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime2);
      lc.setLed(0,row,col,true);
      delay(delaytime2);
      }
    }
  }


void single_2() {
  for(int col=0;col<8;col++) {
    for(int row=0;row<8;row++) {
      delay(delaytime2);
      lc.setLed(0,row,col,true);
      delay(delaytime2);
      }
    }
  }



void LCD() {
  lcd.print("Hello There! :)");
  for(int i = 0 ; i < 16; ++i){
    lcd.setCursor(i, 1);
    lcd.print(".");
    delay(100);
  }
  lcd.clear();

  lcd.print("General kenobi");
  for(int i = 0 ; i < 16; ++i){
    lcd.setCursor(i, 1);
    lcd.print("!");
    delay(100);
  }
  lcd.clear();      
  
}

void loop() { 
  writeArduinoOnMatrix();
  single();
  columns();
  single_2();
  columns();
  LCD();
}
