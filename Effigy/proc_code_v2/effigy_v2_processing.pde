//Holly Adams March 2018
//Effigy v 1.2

import processing.sound.*;
import processing.serial.*;
import shapes3d.*;
import shapes3d.animation.*;
import shapes3d.utils.*;
      Ellipsoid body;
      Ellipsoid head;
      Ellipsoid eye;
      Ellipsoid nose;
      Tube arms;
      Ellipsoid hand;
      Tube leg;
      Ellipsoid foot;
model effigy= new model();
soundcontrol sounds= new soundcontrol();
Serial myPort;
int serialval,sceneval;//incoming data from the port
int inputcount, bMode, zmvar, counter, ramp, themecounter, titlecounter;
SoundFile themesong;
float themeamp, zmovement, xval, yval, zval, boxX, boxY, boxZ;
PShader edges;
boolean onchange, startsound;
      SoundFile[] booboos= new SoundFile[6];
      SoundFile[] crys= new SoundFile[4];
      SoundFile[] louds= new SoundFile[2];
      SoundFile[] sads= new SoundFile[4];
      SoundFile[] screams= new SoundFile[5];


void setup(){
    fullScreen(P3D);
    //size(300,300,P3D);
    printArray(Serial.list());
    String portName=Serial.list()[1];
    myPort=new Serial(this, portName, 9600);
    background(0);
    onchange= false;
    startsound=false;
    themesong= new SoundFile(this, "themeedit_02.aif");
    themeamp=1;
    themecounter=0;
    titlecounter=2500;
    themesong.loop(); 
    themesong.amp(themeamp);
    for(int i=0;i<6;i++){
         booboos[i]=new SoundFile(this,"booboo"+i+".aif");
    }for(int i=0;i<6;i++){
         booboos[i].amp(0);
    }for(int i=0;i<3;i++){
         crys[i]=new SoundFile(this,"cry"+i+".aif");
    }for(int i=0;i<3;i++){
         crys[i].amp(0);
    }for(int i=0;i<2;i++){
         louds[i]=new SoundFile(this,"loud"+i+".aif");
    }for(int i=0;i<2;i++){
         louds[i].amp(0);
    }for(int i=0;i<4;i++){
         sads[i]=new SoundFile(this,"sad"+i+".aif");
    }for(int i=0;i<4;i++){
         sads[i].amp(0);
    }for(int i=0;i<5;i++){
         screams[i]=new SoundFile(this,"scream"+i+".aif");
    }for(int i=0;i<5;i++){
         screams[i].amp(0);
    }
    boxX=4;
    boxY=2;
    boxZ=5;
    serialval=6;
    sceneval=6;
    inputcount=0; counter=0; ramp=0;
       body= new Ellipsoid(this,30,30);
       head= new Ellipsoid(this,30,30);
       eye= new Ellipsoid(this,30,30);
       nose= new Ellipsoid(this,30,30);
       arms= new Tube(this,30,30);
       hand= new Ellipsoid(this,30,30);
       leg= new Tube(this,30,30);
       foot= new Ellipsoid(this,30,30);
       smooth();
    bMode=BLEND;
    xval=0;yval=0;zval=0;
    zmovement=0.1;
    zmvar=-1;
    edges= loadShader("edgevert.glsl");
}


void draw(){
    if(myPort.available()>0){
      serialval=myPort.read();
    }
  
    themecounter=themecounter+1;
    println(themecounter);
    if(themecounter==3350){
     themesong.jump(0);
     themecounter=0;
    }
    
    titlecounter=titlecounter+1;
    if(titlecounter>=2000){
      effigy.texttitle();
      titlecounter=0;
    }
    
    ambientLight(50,50,50);
    directionalLight(200,200,200,0,0.5,0.75);
    camera();
    
    if(serialval!=6){
      onchange=true;
      sceneval=serialval;
      println(sceneval);
      startsound=true;
    }else if(serialval==6){
      inputcount=inputcount+1; 
    }
    if((inputcount>70)&&(serialval==6)){
     onchange=false; 
    }

    //making elmo happen:
    zmovement=zmovement+(zmvar*0.001);
      if((zmovement<0)||(zmovement>0.3)){
        zmvar=zmvar*-1;
    }
     pushMatrix();
     blendMode(bMode);
     translate(width/2, height/2,height*zmovement);
     shapeMode(CENTER);
     rotateX(radians(xval));//making the elmo and rotating him
     rotateY(radians(yval));
     rotateZ(radians(zval));
     effigy.texture1();
     effigy.build_him();
     popMatrix();
     
    if(onchange){
      counter=counter+1;
      fill(200,200,200,ramp);
      ramp=ramp+3;
      stroke(255,0,0,50);
      strokeWeight(2);
      pushMatrix();
         translate(width/2,height/2,0);
         sphere(4*ramp);
       popMatrix();
       if(sceneval==1){
         if((startsound==true)&&(counter==5)){
           sounds.sound1();
         }
         xval=xval+1.8;
         yval=yval+1.5;
         zval=zval-1;
             for(int i=-100;i<height;i=i+50){
              strokeWeight(20);
              stroke(75,150,150);
              line(0,i,width,i);
             }
         filter(INVERT);
         bMode=BLEND;
       }else if(sceneval==2){
         if((startsound==true)&&(counter==5)){
           sounds.sound2();
         }
         xval=xval+0.1;
         yval=yval+29;
         zval=zval-0.07;
         filter(POSTERIZE,5);
         bMode=BLEND;
       }else if(sceneval==3){
         if((startsound==true)&&(counter==5)){
           sounds.sound3();
         }
         xval=xval+0;
         yval=yval+0;
         zval=zval+2;
         filter(edges);
       }else if(sceneval==4){
         if((startsound==true)&&(counter==5)){
           sounds.sound4();
         }
         xval=xval+1;
         bMode=ADD;
         yval=yval-0.6;
         zval=zval+.8;
         filter(edges);
         //bMode=SUBTRACT;
       }else if(sceneval==5){
         if((startsound==true)&&(counter==5)){
           sounds.sound5();
         }
         xval=xval+0.01;
         yval=yval+0.1;
         zval=zval+0.3;
         pushMatrix();
           for(int i=-40;i<400;i=i+50){
             translate((width/2)+i,(height/2)+i);
             boxX=boxX+0.4;
             boxY=boxY-.9;
             boxZ=boxZ+1;
             rotateX(boxX);
             rotateY(boxY);
             rotateZ(boxZ);
             noFill();
             stroke(255,100);
             strokeWeight(2);
             box(i,i,i);
           }
         popMatrix();
       }
       if(counter>=200){
        bMode=ADD; 
       }
    }else if(!onchange){
          counter=0;
          ramp=0;
          inputcount=0;
          xval=xval-0.3;
          yval=yval+0.4;
          zval=zval+0.2;
          bMode=BLEND;
          sceneval=6;
          startsound=false;
    }
      
      
}