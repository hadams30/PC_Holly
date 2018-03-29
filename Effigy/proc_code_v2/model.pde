class model{
 model(){
 }
 
 void texttitle(){
   textSize(200);
   textAlign(CENTER,CENTER);
   fill(20,0,0);
   text("EFFIGY",width/2,height/5);
 }
 
 void texture1(){
        body.setTexture("original.jpg");
        body.drawMode(Shape3D.TEXTURE);
        head.setTexture("original.jpg");
        head.drawMode(Shape3D.TEXTURE);
        eye.setTexture("original.jpg");
        eye.drawMode(Shape3D.TEXTURE);
        nose.setTexture("original.jpg");
        nose.drawMode(Shape3D.TEXTURE);
        arms.setTexture("original.jpg");
        arms.drawMode(Shape3D.TEXTURE);
        hand.setTexture("original.jpg");
        hand.drawMode(Shape3D.TEXTURE);
        leg.setTexture("original.jpg");
        leg.drawMode(Shape3D.TEXTURE);
        foot.setTexture("original.jpg");
        foot.drawMode(Shape3D.TEXTURE);
 }
 void texture2(){
        body.setTexture("download.jpg");
        body.drawMode(Shape3D.TEXTURE);
        head.setTexture("download.jpg");
        head.drawMode(Shape3D.TEXTURE);
        eye.setTexture("download.jpg");
        eye.drawMode(Shape3D.TEXTURE);
        nose.setTexture("download.jpg");
        nose.drawMode(Shape3D.TEXTURE);
        arms.setTexture("download.jpg");
        arms.drawMode(Shape3D.TEXTURE);
        hand.setTexture("download.jpg");
        hand.drawMode(Shape3D.TEXTURE);
        leg.setTexture("download.jpg");
        leg.drawMode(Shape3D.TEXTURE);
        foot.setTexture("download.jpg");
        foot.drawMode(Shape3D.TEXTURE);
 }
 
 
 void build_him(){
    pushMatrix();
            body.setSize(50,80,30);
            body.draw();
               popMatrix();
               pushMatrix();
            translate(0,-100);
            head.setSize(60,60,30);
            head.draw();
               popMatrix();
               pushMatrix();
            translate(-20,-160);
            eye.setSize(25,25,25);
            eye.draw();
               popMatrix();
               pushMatrix();
            translate(20,-160);
            eye.draw();
               popMatrix();
               pushMatrix();
            translate(0,-140,15);
            nose.setSize(20,20,20);
            nose.draw();
               popMatrix(); 
               pushMatrix();
            translate(0,-35);
            rotateZ(PI/2);
            arms.setSize(20,20,20,20,300);
            arms.draw();
               popMatrix();
               pushMatrix();
            translate(-150,-35);
            hand.setSize(30,30,25);
            hand.draw();
               popMatrix();    
               pushMatrix();
            translate(150,-35);
            hand.draw();
               popMatrix();
               pushMatrix();
            translate(-25,75);
            rotateZ(0.2);
            leg.setSize(20,20,20,20,200);
            leg.draw();
               popMatrix();
               pushMatrix();
            translate(25,75);
            rotateZ(-0.2);
            leg.draw();
               popMatrix();
               pushMatrix();
            translate(-45,190,20);
            rotateX(0.8);
            foot.setSize(30,50,25);
            foot.draw();
               popMatrix();
               pushMatrix();
            translate(45,190,20);
            rotateX(0.8);
            foot.draw();
               popMatrix();
 }
 
  
  
  
  
  
}
