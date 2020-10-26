#include <LiquidCrystal.h>

// lcd (register select, enable, db4, db5, db6, db7)
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  lcd.begin(16,2);
  lcd.print("IEEE is awesome.");
  lcd.setCursor(0,0);
  //lcd.print("hello");
}

void loop()
{
  //lcd.setCursor(column,row)
  lcd.setCursor(0,1);
  lcd.print(millis() / 1000);

}