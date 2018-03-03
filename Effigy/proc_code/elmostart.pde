//Holly Adams Feb 2018
//in progress sketch for EFFIGY 

boolean onchange;//turned on when any button being pressed
int counter;//used to track how long button pressed
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

void setup(){
 size(1000,1000,P3D);
 background(0);
 elmo=loadShape("elmo.obj");
 xval=0;
 yval=0;
 zval=0;
 ramp=0;
 counter=0;
 serialval=6;//state when no buttons pressed
 onchange=false;//"
 printArray(Serial.list());//remember to see what port arduino is
 String portName=Serial.list()[2];
 myPort=new Serial(this, portName, 9600);
 bMode=BLEND;//set default blend mode
 edges= loadShader("edgevert.glsl");
 //sort= loadShader("vhs.glsl");
}

void draw(){
     if(myPort.available()>0){//getting button info from arduino serial connection
       serialval=myPort.read();
     }
      
      directionalLight(200,200,200,0,0.5,-1);
      camera();
      println(serialval);//monitor the information from the serial port 
      
    if((serialval!=6)||(mousePressed)){//is a button being pressed
      onchange=true;//or mouse being clicked? (for testing)
    }else{
      onchange=false;
    }
    
     pushMatrix();
     blendMode(bMode);
     translate(width/2, height/2,690);
     shapeMode(CENTER);
     rotateX(radians(xval));//making the elmo and rotating him
     rotateY(radians(yval));
     rotateZ(radians(zval));
     shape (elmo, 00,0);
     popMatrix();
       
   if(onchange){//if any button being pressed
       counter=counter+1;//counter created in order to add an effect once the button is held down for 8 seconds?
       fill(0,ramp);
       stroke(255,0,0,50);
       strokeWeight(2);
       ramp=ramp+1;
       pushMatrix();
         translate(500,500,0);
         sphere(3*ramp);//this is the background sphere 
       popMatrix();
      if(serialval==1){//BUTTON 1
         xval=xval+0.8;
         yval=yval+0.5;
         zval=zval-1;
         filter(INVERT);
         bMode=BLEND;
      }else if(serialval==2){//BUTTON 2
         xval=xval+0.1;
         yval=yval+0.08;
         zval=zval-0.07;
         filter(POSTERIZE,5);
         bMode=BLEND;
       }else if(serialval==3){//BUTTON 3
         xval=xval+0;
         yval=yval+0;
         zval=zval+2;
         filter(edges);
       }else if(serialval==4){//BUTTON 4
         xval=xval+1;
         yval=yval-0.6;
         zval=zval+.8;
         filter(DILATE);
         bMode=BLEND;
       }else if(serialval==5){//BUTTON 5
         xval=xval+3;
         yval=yval+1;
         zval=zval+0;
         //filter(sort);
         bMode=SCREEN;
       }
       if(counter>=350){//if button held enough time.. what happens?
         //filter(INVERT);do something! not invert because...
       }
       
       
   }else if(!onchange){//buttons released, things reset!!
       counter=0;
       ramp=0;
       xval=xval-0.3;
       yval=yval+0.4;
       zval=zval+0.2;
       bMode=BLEND;
     }
     
     
    
}//END DRAW LOOP