import processing.serial.*;
Serial myPort;
int val;
int stage;
float count;

void setup(){
size(400,400,P3D);
smooth(6);
String portName=Serial.list()[5];
myPort=new Serial(this,portName,9600);
stage=0;
count=0;
}

void draw(){
  if(myPort.available()>0){
    val=myPort.read();
      println(val,count);
  }

  
  if(stage==0){
    directionalLight(200,200,200,0,0.5,-1);
    camera(0,0,10,val,10,0,0,1,0);
    background(255);
      for(int x=0; x<width; x=x+10){
        for(int y=0; y<width; y=y+10){
       pushMatrix();
          translate(x,y);
          stroke(0);
          noFill();
          box(100);
       popMatrix();
       count=count+0.1;
        }}
        if(val>200){
     background(255,0,0);
     if((mousePressed)&&(count>2000)){
       stage=1;
       count=0;
     }
     }
  }//end stage 0
  
   if(stage==1){
    directionalLight(200,200,200,0,0.5,-1);
    camera(0,0,10,10,val,0,0,1,0);
    background(0);
      for(int x=0; x<width; x=x+10){
        for(int y=0; y<width; y=y+10){
       pushMatrix();
          translate(x,y);
          noFill();
          stroke(255);
          box(100);
       popMatrix();
       count=count+0.1;
        }}
        if(val>200){
     background(255,0,0);
     if((mousePressed)&&(count>2000)){
       stage=0;
       count=0;
     }
     }
  }//end stage 1
   
   
}