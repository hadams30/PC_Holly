class soundcontrol{
  soundcontrol(){
    
  }
  
  
  
  
  void sound1(){
    int selectsound;
    selectsound= int(random(0,5));
    booboos[selectsound].amp(1);
    booboos[selectsound].play();
  }
  
  void sound2(){
    int selectsound;
    selectsound= int(random(0,2));
    crys[selectsound].amp(1);
    crys[selectsound].play();
  }
  
  void sound3(){
    int selectsound;
    selectsound= int(random(0,1));
    louds[selectsound].amp(1);
    louds[selectsound].play();
  }
  
  void sound4(){
    int selectsound;
    selectsound= int(random(0,3));
    sads[selectsound].amp(1);
    sads[selectsound].play();
  }
  
  void sound5(){
    int selectsound;
    selectsound= int(random(0,4));
    screams[selectsound].amp(1);
    screams[selectsound].play();
  }
  
  
}
