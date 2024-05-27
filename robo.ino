#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
    lcd.begin(16, 2);
    Serial.begin(115200);
}
int counter = 0;
void loop()
{
    if (Serial.available() > 0)
    {

        counter = (counter +1)%8;
        char receivedChar = Serial.read();
        int row = counter / 4;   // Determine the row based on the counter
        int col = counter % 4;   // Determine the column based on the counter
        lcd.print(counter);
        lcd.setCursor(col,row);
    }
}
void createCustomChar() {
  byte customChar[8] = {
    0b11111,
    0b00000,
    0b11111,
    0b00000,
    0b11111,
    0b00000,
    0b11111,
    0b00000
  };
  
  lcd.createChar(counter, customChar);
}