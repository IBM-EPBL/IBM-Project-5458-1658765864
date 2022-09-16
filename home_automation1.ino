

#include<Servo.h>
#define outsensor 2
#define innersensor 5
#define buzz 3
#define door 4
#define fan 9
#define tempsensor A0
#define LED 7

int trig=5;
int echo=6;
float duration_us, distance_cm;
Servo Myservo;
void setup()
{
  pinMode(outsensor, INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(innersensor, INPUT);
  Myservo.attach(4);
  pinMode(fan,OUTPUT);
  Serial.begin(9600);
   pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
}

void loop()
{
  
  //outer door
  if(digitalRead(outsensor)==0){
digitalWrite(buzz,0);  
  }else{
 digitalWrite(buzz,1);  
    delay(500);
   digitalWrite(buzz,0);  
  }
  //inner door
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration_us = pulseIn(echo, HIGH);
  distance_cm = 0.017 * duration_us;
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(1000);
  
   if(distance_cm>120){   
    Myservo.write(0); 
  }else{
    Myservo.write(90);            
  }
    int val = analogRead(tempsensor);
  val = map(val, 20,358, 0,1000);
  
  if(val<=100){
  analogWrite(fan ,0);
  }else if(val<=500){
 analogWrite(fan ,val);
  }else{
  analogWrite(fan ,0);
    digitalWrite(buzz,1);  
      delay(5000);
    digitalWrite(buzz,0); 
      delay(2000);
    digitalWrite(LED,HIGH);
    
    
    
  }
  
  Serial.println(val);
}





