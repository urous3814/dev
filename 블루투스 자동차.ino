char A;
float a;
int b;
float tm;
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2,3);
int T=5; //trig
int E=4; //echo
/*-----------거리함수--------------*/
int dis()
{
  digitalWrite(T,HIGH);
  delay(10);
  digitalWrite(T,LOW);
  a=pulseIn(E,HIGH);
  b=(int)(340*a/20000);
  Serial.println(b);
  delay(90);
  //BTSerial.print(b);
}
/*------------모터-----------------*/
#define LA 10 //왼쪽 바퀴
#define LB 11 //왼쪽 바퀴
#define RA 12 //오른쪽 바퀴
#define RB 13 //오른쪽 바퀴
/*------------이동-----------------*/
void Move(int port,int value){
  digitalWrite(port,value);  
}
void forward(){
  Move(LA, HIGH);
  Move(LB, LOW);
  Move(RA, HIGH);
  Move(RB, LOW);
  delay(1000);
}
void backward(){
  Move(LA,LOW);
  Move(LB,HIGH);
  Move(RA,LOW);
  Move(RB,HIGH);
  delay(1000);
}
void left(){
  Move(LA, LOW);
  Move(LB, HIGH);
  Move(RA, HIGH);
  Move(RB, LOW);
  delay(1000);
}
void right(){
  Move(LA, HIGH);
  Move(LB, LOW);
  Move(RA, LOW);
  Move(RB, HIGH);
  delay(1000);
  
}
void stop(){
  Move(LA, LOW);
  Move(LB, LOW);
  Move(RA, LOW);
  Move(RB, LOW);
  delay(1000);
}
/*---------------------------------*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode (5,OUTPUT);
  pinMode (4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  dis();
  Move(7,HIGH);
}
