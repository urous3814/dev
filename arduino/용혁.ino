#include <Wire.h>  //i2c연결 보조용 라이브러리
#include<LiquidCrystal_I2C.h>. //모듈 불러오기

LiquidCrystal_I2C lcd(0x27,16,2);  //0x27번 주소로 i2c접속 (16*2칸짜리)

int Sensor_pin = 1;    //센서에선 A1핀 사용
int LED_R = 3;   //빨간 led는 3번핀 사용
int LED_G = 4;  //초록 led는 4번핀 사용

void setup()
{
    Serial.begin(9600);   //시리얼 보더레이트: 9600
    lcd.init();     //lcd 초기화
    lcd.backlight();   //lcd 백라이트 활성화

    pinMode(LED_R,OUTPUT);   //3번핀을 출력으로 설정
    pinMode(LED_G,OUTPUT);   //4번핀을 출력으로 설정
   
}

void loop()
{
  Serial.println(analogRead(Sensor_pin));   //A1핀 아날로그값을 받아와서 시리얼모니터로 출력
  delay(100);  

  if(analogRead(Sensor_pin) < 400){    //센서에서 받아온 값이 400이하라면
    lcd.clear();   //lcd지우기
    digitalWrite(LED_R,HIGH);  //빨간불 들어오게
    digitalWrite(LED_G,LOW);  //초록불 꺼지게
    lcd.setCursor(0,0);  //lcd의 커서를 0, 설정
    lcd.print("Water, Please");  //lcd로 Water, Please 라고 출력
  }
  else{   //센서에서 받아온 값이 400이상이면? 
    lcd.clear();  //lcd 지우기
    digitalWrite(LED_R,LOW);  //빨간불 꺼지게
    digitalWrite(LED_G,HIGH);  //초록불 들어오게
    lcd.setCursor(0,1);  //커서를 0, 1로 설정
    lcd.print("Enough");  //lcd로 Enough라고 출력
  }
}

