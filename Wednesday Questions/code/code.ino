#include <NewPing.h>//  HC-SR04-NewPing.ino
int trigPin = 11;   
int echoPin = 12; 
int piezo = 3;  
int clockpin1 = 9;
int clockpin2 = 8;
int clockReset = 13;
long duration, cm, inches;
#define TRIGGER_PIN  11
#define ECHO_PIN     12
#define MAX_DISTANCE 400
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float distance;
int s4counter=0;
#include <Servo.h>
Servo myservo;
int servpos = 0;
int s2counter = 0;
int pval1 = 2;// the val sent to pwm piezo
int pval2 = 1;//how many points the piezo shifts by 

void setup() {
  Serial.begin (9600);
  myservo.attach(2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(clockpin1, OUTPUT);
  pinMode(clockpin2, OUTPUT);
  pinMode(clockReset, OUTPUT);
  pinMode(piezo, OUTPUT);
}
 
void loop(){
    delay(10);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH,20000);
    if((duration==0)||(distance=155.91)){
                    pinMode(echoPin,OUTPUT);
                    digitalWrite(echoPin,LOW);
                    delayMicroseconds(200);
                    pinMode(echoPin,INPUT);
    }
    distance = (duration/2) / 29.1;
//  distance = sonar.ping_cm();
  Serial.print("Distance = ");
  if (distance >= 130 || distance <= 60) {
    Serial.println("Out of range");

  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    if(distance<=85){
                        for (servpos = 0; servpos <= 30; servpos += 1) {
                            myservo.write(servpos);
                            digitalWrite(clockpin1,HIGH);
                            digitalWrite(clockpin2,HIGH);
                            delay(8);
                            
                        }

                        for (servpos = 30; servpos >= 0; servpos -= 1) {
                            myservo.write(servpos);
                            digitalWrite(clockpin1, LOW);
                            digitalWrite(clockpin2, LOW);
                            delay(8); 
                        }
analogWrite(piezo,150);
delay(40);
analogWrite(piezo,0);
    }else if(distance<=95){
                  for(int i = 100; i>=50; i=i-26){
                      s2counter=s2counter+1;
                          if(s2counter>=5){
                            for (servpos = 0; servpos <= 20; servpos += 1) {
                              myservo.write(servpos);
                              delay(20);
                             }
                            for (servpos = 20; servpos >= 0; servpos -= 1) {
                              myservo.write(servpos);
                              delay(20); 
                             }
                          }
                      digitalWrite(clockpin1,HIGH);
                      digitalWrite(clockpin2,HIGH);
                         delay(i);
                      digitalWrite(clockpin1, LOW);
                      digitalWrite(clockpin2, LOW);
                         delay(i);
                  }for(int i = 100; i>=10; i=i-12){
                        s4counter=s4counter-i;
                      digitalWrite(clockpin1,HIGH);
                      digitalWrite(clockpin2,HIGH);
                      analogWrite(piezo,10);
                         delay(17);
                      analogWrite(piezo,0);
                      digitalWrite(clockpin1, LOW);
                      digitalWrite(clockpin2, LOW);
                         delay(17);
                  }

    }else if(distance<=110){
                  for(int i = 100; i>=10; i=i-7){
                     digitalWrite(clockpin1,HIGH);
                     digitalWrite(clockpin2,HIGH);
                          delay(i);
                     digitalWrite(clockpin1, LOW);
                     digitalWrite(clockpin2, LOW);
                          delay(i);
                  }

    }else if(distance<=129){
                  for(int i = 100; i>=10; i=i-3){
                    analogWrite(piezo,pval1);
                    pval1=pval1+pval2;
                    if(pval1<=0||pval1>=5){
                      pval2=-pval2;
                    }
                        myservo.write(0);
                     digitalWrite(clockpin1,HIGH);
                     digitalWrite(clockpin2,HIGH);
                        delay(i);
                        myservo.write(15);
                     digitalWrite(clockpin1, LOW);
                     digitalWrite(clockpin2, LOW);
                        delay(i);
                 }
           analogWrite(piezo,0);
                    pinMode(echoPin,OUTPUT);
                    digitalWrite(echoPin,LOW);
                    delayMicroseconds(200);
                    pinMode(echoPin,INPUT);
    }
  }//end scenes
  delay(500);
}//end void loop


