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

void setup() {
  Serial.begin (9600);
  myservo.attach(2);
  pinMode(clockpin1, OUTPUT);
  pinMode(clockpin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(clockReset, OUTPUT);
}


void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  noTone(piezo1);
  tone(piezo3, 400,500);

  for (servpos = 0; servpos <= 30; servpos += 1) {
    myservo.write(servpos);
    delay(15);
  }

  noTone(piezo3);
  tone(piezo2, 200,500);
  digitalWrite(clockpin1,HIGH);
  digitalWrite(clockpin2, LOW);
  delay(100);
  noTone(piezo2);                       
  
  for (servpos = 30; servpos >= 0; servpos -= 1) {
    myservo.write(servpos);
    delay(15); 
  }

  tone(piezo1, 100,500);
  digitalWrite(clockpin1, LOW);
  digitalWrite(clockpin2,HIGH);
  delay(10);

  
  
}
