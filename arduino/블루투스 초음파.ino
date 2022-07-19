char A;
float a;
int b;
//#include <IRremote.h>
//decode_results results;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (5,OUTPUT);
  pinMode (4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,HIGH);
  delay (10);
  digitalWrite(5,LOW);
  a=pulseIn(4,HIGH);
  b=(int)(340*a/10000/2);
  Serial.println(b);
  delay(500);
}
