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
}


void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  counter=counter+1;
  Serial.print(cm);
  Serial.print("cm;    ");
  Serial.print(counter);
  Serial.print("count");
  Serial.println();
  delay(100);

  if(cm<=400){
    spcount=spcount+1;
    if(spcount>=6){
          if((cm>200)&&(cm<=400)){
            leddelay=100;
          }else if((cm>0)&&(cm<=200)){
            leddelay=10;
          }
      myservo.write(servpos);
      digitalWrite(clockpin1,HIGH);
      digitalWrite(clockpin2,HIGH);
      digitalWrite(clockpin1, LOW);
      digitalWrite(clockpin2, LOW);
      delay(leddelay);
    }
  }else if(cm>400){
    spcount=0;
    servpos=0;
  }
}//end loop
