#include <Servo.h>
Servo myservo;
int servpos = 0;
int clockpin1 = 9;
int clockpin2 = 8;
int trigPin = 11;
int echoPin = 12;
int clockReset = 13;
int piezo1 = 3;
int piezo2 = 4;
int piezo3 = 5;
long duration, cm, inches;
int counter;
int toner;

void setup() {
  Serial.begin (9600);
  myservo.attach(2);
  pinMode(clockpin1, OUTPUT);
  pinMode(clockpin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(clockReset, OUTPUT);
  counter=0;
  toner=400;
}

void loop() {
  counter=counter+1;
  
  digitalWrite(clockpin1,HIGH);
  digitalWrite(clockpin1,LOW);
  digitalWrite(clockpin2,HIGH);
  digitalWrite(clockpin2,LOW);
  Serial.println(counter);
  
  if (counter<10){
        toner=toner-25;
      tone(piezo1,toner);
      for (servpos = 0; servpos <= 30; servpos += 1) {
       myservo.write(servpos);
       delay(20);
      }
     for (servpos = 30; servpos >= 0; servpos -= 1) {
       myservo.write(servpos);
       delay(20); 
      }
  }else if (counter>=10){
    servpos=0;
    myservo.write(0);
    noTone(piezo1);
    noTone(piezo2);
    noTone(piezo3);
    digitalWrite(clockReset,HIGH);
    digitalWrite(clockReset,LOW);
  }
  
}
