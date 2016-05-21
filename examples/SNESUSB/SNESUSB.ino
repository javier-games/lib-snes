#include <NES.h>

NES pad = NES(4,3,2,100);
int i=0;
void setup() {
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  pad.update();
  
  if(pad.Select_changed()){
       if( pad.Select() )
      Keyboard.press(32);
    else
      Keyboard.release(32);
  }
  if(pad.Start_changed()){
       if( pad.Start() )
      Keyboard.press(13);
    else
      Keyboard.release(13);
  }
        
  if( pad.A_changed() ){
    if( pad.A() )
      Keyboard.press(65);
    else
      Keyboard.release(65);
  }
  
  if( pad.B_changed() ){
    if( pad.B() )
      Keyboard.press(66);
    else
      Keyboard.release(66);
  }
  
  if( pad.Up_changed() ){
    if( pad.Up() )
      Keyboard.press(218);
    else
      Keyboard.release(218);
  }
  
  if( pad.Down_changed() ){
    if( pad.Down() )
      Keyboard.press(217);
    else
      Keyboard.release(217);
  }
  
  if( pad.Left_changed() ){
    if( pad.Left() )
      Keyboard.press(216);
    else
      Keyboard.release(216);
  }
  
  if( pad.Right_changed() ){
    if( pad.Right() )
      Keyboard.press(215);
    else
      Keyboard.release(215);
  }
}   




