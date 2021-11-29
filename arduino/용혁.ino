#include <Wire.h>
#include<LiquidCrystal_I2C.h>  //ㅁㅗㄷㅠㄹ ㅂㅜㄹㄹㅓㅇㅗㄱㅣ
LiquidCrystal_I2C lcd(0x3F,16,2);
int Sensor_pin = 1;
int LED_R = 3;
int LED_G = 4;
void setup()
{
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    pinMode(LED_R,OUTPUT);
    pinMode(LED_G,OUTPUT);
   
}
void loop()
{
  Serial.println(analogRead(Sensor_pin));
  delay(100);
  if(analogRead(Sensor_pin) > 400){
    lcd.clear();
    digitalWrite(LED_R,HIGH);
    digitalWrite(LED_G,LOW);
    lcd.setCursor(0,0);
    lcd.print("Water, Please");
  }
  else{
    lcd.clear();
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_G,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Enough");
  }
}
