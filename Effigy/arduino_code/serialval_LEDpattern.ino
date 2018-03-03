const int BUTTONa=2;
const int BUTTONb=3;
const int BUTTONc=4;
const int BUTTONd=5;
const int BUTTONe=6;
const int LEDa=8;
const int LEDb=9;
const int LEDc=10;
const int LEDd=11;
const int LEDe=12;
int aval=0;
int bval=0;
int cval=0;
int dval=0;
int eval=0;
int serialval=0;
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
  pinMode(LEDe,OUTPUT);
}

void loop() {

  //button reading and setting the serial value to be sent to processing
  aval= digitalRead(BUTTONa);
  bval= digitalRead(BUTTONb);
  cval= digitalRead(BUTTONc);
  dval= digitalRead(BUTTONd);
  eval= digitalRead(BUTTONe);
  if(aval==HIGH){
    serialval=1;
  }else if(bval==HIGH){
    serialval=2;
  }else if(cval==HIGH){
    serialval=3;
  }else if(dval==HIGH){
    serialval=4;
  }else if(eval==HIGH){
    serialval=5;
  }else if((aval==LOW)&&(bval==LOW)&&(cval==LOW)&&(dval==LOW)&&(eval==LOW)){
    serialval=6;
  }
  Serial.write(serialval);
  delay(100);
//coding the LED arrays
  
  if(serialval==6){
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,LOW);
  //Serial.write(6);
    
  }else if(serialval==1){
    digitalWrite(LEDa,HIGH);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,HIGH);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,HIGH);
    delay(100);
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,HIGH);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,HIGH);
    digitalWrite(LEDe,LOW);
    delay(100);
  //Serial.write(1);
    
  }else if(serialval==2){
    digitalWrite(LEDa,HIGH);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,LOW);
    delay(80);
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,HIGH);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,LOW);
    delay(80);
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,HIGH);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,LOW);
    delay(80);
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,HIGH);
    digitalWrite(LEDe,LOW);
    delay(80);
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,HIGH);
    delay(80);
  //Serial.write(2);
    
  }else if(serialval==3){
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,LOW);
    delay(50);
    digitalWrite(LEDa,HIGH);
    digitalWrite(LEDb,HIGH);
    digitalWrite(LEDc,HIGH);
    digitalWrite(LEDd,HIGH);
    digitalWrite(LEDe,HIGH);
    delay(50);
  // Serial.write(3);
    
  }else if(serialval==4){
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,HIGH);
    digitalWrite(LEDd,HIGH);
    digitalWrite(LEDe,LOW);
    delay(150);
    digitalWrite(LEDa,HIGH);
    digitalWrite(LEDb,HIGH);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,HIGH);
    delay(150);
 // Serial.write(4);
    
  }else if(serialval==5){
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,LOW);
    delay(50);
    digitalWrite(LEDa,HIGH);
    digitalWrite(LEDb,HIGH);
    digitalWrite(LEDc,HIGH);
    digitalWrite(LEDd,HIGH);
    digitalWrite(LEDe,HIGH);
    delay(150);
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,LOW);
    delay(50);
    digitalWrite(LEDa,HIGH);
    digitalWrite(LEDb,HIGH);
    digitalWrite(LEDc,HIGH);
    digitalWrite(LEDd,HIGH);
    digitalWrite(LEDe,HIGH);
    delay(150);
 // Serial.write(5);
    
  }else if(serialval==7){
    digitalWrite(LEDa,HIGH);
    digitalWrite(LEDb,HIGH);
    digitalWrite(LEDc,HIGH);
    digitalWrite(LEDd,HIGH);
    digitalWrite(LEDe,HIGH);
    delay(50);
    digitalWrite(LEDa,LOW);
    digitalWrite(LEDb,LOW);
    digitalWrite(LEDc,LOW);
    digitalWrite(LEDd,LOW);
    digitalWrite(LEDe,LOW);
    delay(5);
 // Serial.write(7);
    
  }

  }


