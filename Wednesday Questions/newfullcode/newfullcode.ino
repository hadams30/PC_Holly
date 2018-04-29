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
  if(scene==0){
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
           if(cm>300){
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
        myservo.write(0);
        noTone(piezo3);
        noTone(piezo2);
        noTone(piezo1);
        digitalWrite(clockReset,HIGH);
        digitalWrite(clockReset,LOW);
        scene=0;
      }
      
  }else if(scene==1){
      for(int i = 10000; i>=10; i=i-5){
          digitalWrite(clockpin1,HIGH);
          digitalWrite(clockpin2,HIGH);
                    delay(i);
          digitalWrite(clockpin1, LOW);
          digitalWrite(clockpin2, LOW);
                    delay(i);
      }
          scene=0;
  }else if(scene==2){
      for(int i = 7000; i>=10; i=i-5){
          digitalWrite(clockpin1,HIGH);
          digitalWrite(clockpin2,HIGH);
          tone(piezo3, 7000-i , i);
                    delay(i+50);
          digitalWrite(clockpin1, LOW);
          digitalWrite(clockpin2, LOW);
          tone(piezo3, 9000-i , i);
                    delay(i+50);
      }
  }else if(scene==3){
      for(int i = 10000; i>=10; i=i-10){
               for (servpos = 0; servpos <= 20; servpos += 1) {
                    myservo.write(servpos);
                    tone(piezo2, 100*(servpos), 800);
                    delay(15);
                 }
          digitalWrite(clockpin1,HIGH);
          digitalWrite(clockpin2,HIGH);
          delay(i);
               for (servpos = 20; servpos >= 0; servpos -= 1) {
                    myservo.write(servpos);
                    delay(15); 
                }
          digitalWrite(clockpin1, LOW);
          digitalWrite(clockpin2, LOW);
          delay(i);
      }   
  }else if(scene==4){
          digitalWrite(clockpin1,HIGH);
          digitalWrite(clockpin2,HIGH);
          digitalWrite(clockpin1, LOW);
          digitalWrite(clockpin2, LOW);
          delay(100);
  }


  
}

