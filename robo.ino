#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
    lcd.begin(16, 2);
    Serial.begin(125000);
}

void loop()     {
  if (Serial.available() > 0) {
        String data = Serial.readString();
        
        //foreach character 
        for (int i = 0; i < data.length() / 40; i++) {
            byte customChar[8] = {0};
            //foreach row in character
            for (int j = 0; j < 8; j++) {
                //foreach bit in row
                for (int k = 0; k < 5; k++) {
                    customChar[j] |= (data[i * 40 + j * 5 + k] == '1' ? 1 : 0) << (4 - k);
                }
            }
            lcd.createChar(i, customChar);
            lcd.setCursor(i % 2, i / 2);
            lcd.write(byte(i));
        }
    }
}