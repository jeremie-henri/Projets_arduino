#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);

}

void loop() {
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
