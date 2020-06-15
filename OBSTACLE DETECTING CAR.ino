#include<Servo.h>
int pos=45;
Servo myservo;
#define m1a 2
#define m1b 3
#define m2a 4
#define m2b 5
#define echoPin1 10
#define trigPin1 11
#define echoPin2 7
#define trigPin2 8
void setup() 
{
  // put your setup code here, to run once:
myservo.attach(9);
myservo.write(45);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);
Serial.begin(9600);
}

void loop() {
  for(pos=45;pos<=120;pos=pos+5)
  {
   myservo.write(pos); 
   delay(100);
  }
   for(pos=120;pos>=45;pos=pos-5)
  {
   myservo.write(pos); 
   delay(100);
  }
  // put your main code here, to run repeatedly:
 int distance1,duration1;
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(2); 
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1,HIGH);
distance1 =duration1/58.2;
Serial.println("distance1");
Serial.println(distance1);
//====================
 int distance2,duration2;
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(2); 
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2,HIGH);
distance2 =duration2/58.2;
Serial.println("distance2");
Serial.println(distance2);


   if(50>distance1 && 50>distance2)
   {
     digitalWrite(m1a, HIGH);// right
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, LOW);
     digitalWrite(m2b, LOW);
   }
      if(distance1>50 && distance2>50)
   {
     digitalWrite(m1a, HIGH);// forward
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, HIGH);
     digitalWrite(m2b, LOW);
   }
      if(distance1<50 && distance2>50)
   {
     digitalWrite(m1a, HIGH);//Right
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, LOW);
     digitalWrite(m2b, LOW);
   }
      if(distance1>50 && distance2<50)
   {
     digitalWrite(m1a, LOW);//left
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, HIGH);
     digitalWrite(m2b, LOW);
   }

    if(distance1<0 || distance2<0)
   {
     digitalWrite(m1a, HIGH);//left
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, LOW);
     digitalWrite(m2b, LOW);
   }
 }
