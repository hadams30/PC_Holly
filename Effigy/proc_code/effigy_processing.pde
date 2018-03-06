//Holly Adams Feb 2018
//sketch for EFFIGY 


boolean onchange;//turned on when any button being pressed
int counter, inputcount;//used to track how long button pressed
PShader edges, sort;
PShape elmo;//elmo obj
float xval;//following values in order to control rotation
float yval;
float zval;
int ramp;//ramping the opacity of the growing sphere
int bMode;//blendmode variables
import processing.serial.*;
Serial myPort;
int serialval;//incoming data from the port
int sceneval;
float scalelmo;
float boxX,boxY,boxZ;

void setup(){
    fullScreen(P3D);
       //size(1000,1000,P3D);
       background(0);
       elmo=loadShape("elmo.obj");
       xval=0;
       yval=0;
       zval=0;
       ramp=0;
       boxX=4;
       boxY=2;
       boxZ=5;
       counter=0;
       inputcount=0;
       serialval=6;//state when no buttons pressed
       sceneval=6;
       scalelmo=1;
       onchange=false;//"
       printArray(Serial.list());//remember to see what port arduino is
       String portName=Serial.list()[1];
       myPort=new Serial(this, portName, 9600);
       bMode=BLEND;//set default blend mode
       edges= loadShader("edgevert.glsl");
       //sort= loadShader("vhs.glsl");
}//END SETUP

void draw(){
     if(myPort.available()>0){//getting button info from arduino serial connection
       serialval=myPort.read();
     }
      
      directionalLight(200,200,200,0,0.5,-1);
      camera();
      println(serialval);//monitor the information from the serial port 
      
    if((serialval!=6)||(mousePressed)){//is a button being pressed
      onchange=true;//or mouse being clicked? (for testing)
      sceneval=serialval;
    }
    if((inputcount>70)&&(serialval==6)){
      onchange=false;
    }
    if(serialval==6){
     inputcount=inputcount+1; 
    }
    
     pushMatrix();
     blendMode(bMode);
     translate(width/2, height/2,height*0.7);
     shapeMode(CENTER);
     elmo.scale(scalelmo);
     rotateX(radians(xval));//making the elmo and rotating him
     rotateY(radians(yval));
     rotateZ(radians(zval));
     shape (elmo, 00,0);
     popMatrix();
       
   
   if(onchange){//if any button being pressed
       if(serialval==6){
        inputcount=inputcount+1; 
       }
      // println(inputcount);
       counter=counter+1;//counter created in order to add an effect once the button is held down for 8 seconds?
       fill(200,200,200,ramp);
       stroke(255,0,0,50);
       strokeWeight(2);
       ramp=ramp+3;
       pushMatrix();
         translate(width/2,height/2,0);
         sphere(4*ramp);//this is the background sphere 
       popMatrix();
      if(sceneval==1){//BUTTON 1
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
      }else if(sceneval==2){//BUTTON 2
         xval=xval+0.1;
         yval=yval+29;
         zval=zval-0.07;
         filter(POSTERIZE,5);
         bMode=BLEND;
       }else if(sceneval==3){//BUTTON 3
         xval=xval+0;
         yval=yval+0;
         zval=zval+2;
         filter(edges);
       }else if(sceneval==4){//BUTTON 4
         xval=xval+1;
         bMode=ADD;
         yval=yval-0.6;
         zval=zval+.8;
         filter(edges);
         bMode=SUBTRACT;
         //bMode=SUBTRACT;
       }else if(sceneval==5){//BUTTON 5
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
       
       if(counter>=200){//if button held enough time.. what happens?
         bMode=ADD;
       }
       
       
   }else if(!onchange){//buttons released, things reset!!
       counter=0;
       ramp=0;
       inputcount=0;
       xval=xval-0.3;
       yval=yval+0.4;
       zval=zval+0.2;
       bMode=BLEND;
       scalelmo=1;
       elmo.scale(scalelmo);
       sceneval=6;
     }
     
     
    
}