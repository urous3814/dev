#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2,3);
int F;    //
int T=13; //trig
int E=12; //echo
/*-----------거리함수--------------*/
int dis()
{
  float Time;
  int distance;
  digitalWrite(T,HIGH);
  delay(10);
  digitalWrite(T,LOW);
  Time=pulseIn(E,HIGH);
  distance=(int)(340*Time/20000);
  if(distance<100){
  Serial.println(distance);
  BTSerial.print(distance);
  return distance;
  }
  delay(490);
}
/*------------모터-----------------*/
#define LA 4 //왼쪽 바퀴 앞
#define LB 5 //왼쪽 바퀴 뒤
#define RA 6 //오른쪽 바퀴 앞
#define RB 7 //오른쪽 바퀴 뒤
/*------------이동-----------------*/
void Move(int port,int value){
  analogWrite(port,value);  
}
void forward(int a){
  Move(LA, a);
  Move(LB, 0);
  Move(RA, a);
  Move(RB, 0);
  delay(1000);
}
void backward(int a){
  Move(LA,0);
  Move(LB,a);
  Move(RA,0);
  Move(RB,a);
  delay(1000);
}
void left(int a){
  Move(LA, 0);
  Move(LB, a);
  Move(RA, a);
  Move(RB, 0);
  delay(1000);
}
void right(int a){
  Move(LA, a);
  Move(LB, 0);
  Move(RA, 0);
  Move(RB, a);
  delay(1000);
  
}
void Stop(){
  Move(LA, 0);
  Move(LB, 0);
  Move(RA, 0);
  Move(RB, 0);
  delay(1000);
}
/*---------------------------------*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode (13,OUTPUT);
  pinMode (12,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  F=dis();
  char* origin=BTSerial.read();
  String Origin=origin;  //if(Origin.indexOf("*")==10)왔을 때 자료를 구분하는데 쓰임
  int cut,a;
  String cuttext[5];
  /*---------------값 자르기-----------*/
    while(Origin.indexOf("*")!=0)
    {
        cut=Origin.indexOf("!");
         cuttext[a]=Origin.substring(0,cut-1);
        a=a+1;
    }
    a=0;
   float x,y;
   x= cuttext[3].toFloat();
   y= cuttext[4].toFloat();
  /*----------이동----------*/
  if(F>10)
  {
    Stop();
  }
  if(x>y)
  {
    if(x>0)
    {
      left(x);  
    }
    else if(x<0)
    {
      right(-x);
    }
  }
  else
  {
    if(y>0)
    {
      forward(y);
    }
    else
    {
      backward(-y);
    }
  } 
}
