const int BUTTONa=2;
const int BUTTONb=3;
const int BUTTONc=4;
const int BUTTONd=5;
const int BUTTONe=6;
const int LEDa=8;
const int LEDb=9;
const int LEDc=10;
const int LEDd=11;
int aval=0;
int bval=0;
int cval=0;
int dval=0;
int eval=0;
int serialval=0;
int oldsval=6;
int striketotal=0;


void setup() {
  Serial.begin(9600);
  
  pinMode(BUTTONa,INPUT);
  pinMode(BUTTONb,INPUT);
  pinMode(BUTTONc,INPUT);
  pinMode(BUTTONd,INPUT);
  pinMode(BUTTONe,INPUT);

  pinMode(LEDa,OUTPUT);
  pinMode(LEDb,OUTPUT);
  pinMode(LEDc,OUTPUT);
  pinMode(LEDd,OUTPUT);
}

void loop() {

  //button reading and setting the serial value to be sent to processing
  aval= digitalRead(BUTTONa);
  bval= digitalRead(BUTTONb);
  cval= digitalRead(BUTTONc);
  dval= digitalRead(BUTTONd);
  eval= digitalRead(BUTTONe);
  if((aval==HIGH)&&(oldsval==6)){//oldsval employeed in order to ensure that the doll doesnt get stuck on any number other than 6
    serialval=1;
  }else if((bval==HIGH)&&(oldsval==6)){
    serialval=2;
  }else if((cval==HIGH)&&(oldsval==6)){
    serialval=3;
  }else if((dval==HIGH)&&(oldsval==6)){
    serialval=4;
  }else if((eval==HIGH)&&(oldsval==6)){
    serialval=5;
  }else{
    serialval=6;
  }

  oldsval=serialval;
  
  Serial.write(serialval);
  delay(100);
//coding the LED arrays
  
  if(serialval==6){
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,LOW);
    
  }else if(serialval==1){
        digitalWrite(LEDa,HIGH);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,HIGH);
        digitalWrite(LEDd,LOW);
     Serial.write(1);
        delay(100);
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,HIGH);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,HIGH);
        delay(100);
    
  }else if(serialval==2){
        digitalWrite(LEDa,HIGH);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,LOW);
        delay(80);
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,HIGH);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,LOW);
        delay(80);
     Serial.write(2);
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,HIGH);
        digitalWrite(LEDd,LOW);
        delay(80);
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,HIGH);
        delay(80);
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,LOW);
        delay(80);
    
  }else if(serialval==3){
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,LOW);
     Serial.write(3);
        delay(50);
        digitalWrite(LEDa,HIGH);
        digitalWrite(LEDb,HIGH);
        digitalWrite(LEDc,HIGH);
        digitalWrite(LEDd,HIGH);
        delay(50);
    
  }else if(serialval==4){
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,HIGH);
        digitalWrite(LEDd,HIGH);
     Serial.write(4);
        delay(150);
        digitalWrite(LEDa,HIGH);
        digitalWrite(LEDb,HIGH);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,LOW);
        delay(150);
    
  }else if(serialval==5){
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,LOW);
        delay(50);
        digitalWrite(LEDa,HIGH);
        digitalWrite(LEDb,HIGH);
        digitalWrite(LEDc,HIGH);
        digitalWrite(LEDd,HIGH);
     Serial.write(5);
        delay(150);
        digitalWrite(LEDa,LOW);
        digitalWrite(LEDb,LOW);
        digitalWrite(LEDc,LOW);
        digitalWrite(LEDd,LOW);
        delay(50);
        digitalWrite(LEDa,HIGH);
        digitalWrite(LEDb,HIGH);
        digitalWrite(LEDc,HIGH);
        digitalWrite(LEDd,HIGH);
     Serial.write(5);
        delay(150);
    serialval=6;
  }

  }


