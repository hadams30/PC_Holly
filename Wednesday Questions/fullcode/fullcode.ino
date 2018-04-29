#include <Servo.h>
Servo myservo;
int servpos = 0;
int clockpin1 = 9;
int clockpin2 = 8;
int trigPin = 11;
int echoPin = 12;
int clockReset = 13;
int piezo1 = 5;
int piezo2 = 3;
int piezo3 = 4;
long duration, cm, inches;
int counter, spcount;
int leddelay = 100;
int scene;

void setup() {
  Serial.begin (9600);
  myservo.attach(2);
  pinMode(clockpin1, OUTPUT);
  pinMode(clockpin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(clockReset, OUTPUT);
  counter=0;
  spcount=0;
  scene=0;
}


void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
  
      if(cm<=400){
        spcount=spcount+1;
        if(spcount>=6){
           if((cm>300)&&(cm<=400)){
            scene=1;   
           }else if((cm>200)&&(cm<=300)){
            scene=2;   
           }else if((cm>100)&&(cm<=200)){
            scene=3;   
           }else if((cm>=00)&&(cm<=100)){
            scene=4;   
           }
        }
      }else if(cm>400){
        spcount=0;
        servpos=0;
        scene=0;
        noTone(piezo3);
      }
      
  if(scene==0){

  }else if(scene==1){
      noTone(piezo3);
      digitalWrite(clockpin1,HIGH);
      digitalWrite(clockpin2,HIGH);
      digitalWrite(clockpin1, LOW);
      digitalWrite(clockpin2, LOW);
      delay(200);
  }else if(scene==2){
      noTone(piezo3);
      digitalWrite(clockpin1,HIGH);
      digitalWrite(clockpin2,HIGH);
      digitalWrite(clockpin1, LOW);
      digitalWrite(clockpin2, LOW);
      delay(100);
  }else if(scene==3){
      noTone(piezo3);
      digitalWrite(clockpin1,HIGH);
      digitalWrite(clockpin2,HIGH);
      digitalWrite(clockpin1, LOW);
      digitalWrite(clockpin2, LOW);
      delay(50);
  }else if(scene==4){
      //tone(piezo3, 800, 100);
      digitalWrite(clockpin1,HIGH);
      digitalWrite(clockpin2,HIGH);
      digitalWrite(clockpin1, LOW);
      digitalWrite(clockpin2, LOW);
      delay(10);
  }
}//end loop
