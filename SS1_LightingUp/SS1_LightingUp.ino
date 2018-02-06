//Holly Adams
//Sketch with two pattern options within the circuit

const int yLED = 13; //input pin number for LED
const int r1LED= 12;
const int r2LED= 11;
const int r3LED= 10;
const int r4LED= 9;
const int r5LED= 8;//all the RED LEDs
const int aBUTTON = 3; //input pin number for pushbutton
const int bBUTTON = 2;
int dr;
int aBval = 0; //val is flexible integer to store state of input pin
int old_aBval= 0;
int aBstate= 0;//0 is LED off and 1 is on, flex int
int bBval = 0; //val is flexible integer to store state of input pin
int old_bBval= 0;
int bBstate= 0;//0 is LED off and 1 is on, flex int

void setup() {
  pinMode(yLED,OUTPUT);//telling the arduino where to look for
  pinMode(r1LED,OUTPUT);
  pinMode(r2LED,OUTPUT);
  pinMode(r3LED,OUTPUT);
  pinMode(r4LED,OUTPUT);
  pinMode(r5LED,OUTPUT);
  pinMode(aBUTTON,INPUT);//and send information/voltage
  pinMode(bBUTTON,INPUT);//and send information/voltage
  dr=200;
}

void loop() {
  aBval=digitalRead(aBUTTON);//read inut value and store it in the int
  bBval=digitalRead(bBUTTON);//read inut value and store it in the int
       
        //button press changes state only when transitioning from 
    if (aBval==HIGH){//not being pressed to being pressed
      aBstate=1;
      bBstate=0;
    }
    if (bBval==HIGH){//not being pressed to being pressed
      bBstate=1;
      aBstate=0;
    }

    if(aBstate==1){
      digitalWrite(yLED,HIGH);//if the button is pressed, 5 v in to
      //pin 7. if this happens, val=high. if this, LED pin=high
        digitalWrite(r1LED,LOW);
        digitalWrite(r2LED,LOW);
        digitalWrite(r3LED,LOW);//can i make these into an array?
        digitalWrite(r4LED,LOW);
        digitalWrite(r5LED,LOW);
      delay(1000);
      digitalWrite(yLED,LOW);
        digitalWrite(r1LED,HIGH);
        digitalWrite(r2LED,HIGH);
        digitalWrite(r3LED,HIGH);//can i make these into an array?
        digitalWrite(r4LED,HIGH);
        digitalWrite(r5LED,HIGH);
      delay(1000);
    }else if(bBstate==1){
      digitalWrite(yLED,LOW);
      digitalWrite(r1LED,HIGH);
      delay(dr);
      digitalWrite(r2LED,HIGH);
      delay(dr);
      digitalWrite(r3LED,HIGH);
      delay(dr);
      digitalWrite(r4LED,HIGH);
      digitalWrite(r1LED,LOW);
      delay(dr);
      digitalWrite(r5LED,HIGH);
      digitalWrite(r2LED,LOW);
      delay(dr);
      digitalWrite(r3LED,LOW);
      delay(dr);
      digitalWrite(r4LED,LOW);
      delay(dr);
        digitalWrite(r5LED,HIGH);
      delay(dr);
      digitalWrite(r4LED,HIGH);
      delay(dr);
      digitalWrite(r3LED,HIGH);
      delay(dr);
      digitalWrite(r2LED,HIGH);
      digitalWrite(r5LED,LOW);
      delay(dr);
      digitalWrite(r1LED,HIGH);
      digitalWrite(r4LED,LOW);
      delay(dr);
      digitalWrite(r3LED,LOW);
      delay(dr);
      digitalWrite(r2LED,LOW);
      delay(dr);
    }

}
