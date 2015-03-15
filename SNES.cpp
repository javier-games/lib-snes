//
//  SNES.cpp
//  
//
//  Created by Francisco Javier García Gutiérrez on 22/12/14.
//
//

// For Arduino 1.0 and earlier
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <SNES.h>

SNES::SNES(int _Q5,int _PL,int _CP,int _tp):Q5(_Q5),PL(_PL),CP(_CP),tp(_tp){
    
    pinMode(CP,OUTPUT);
    pinMode(PL,OUTPUT);
    pinMode(Q5,INPUT );
    
    for( int i = 0 ; i < 16 ; i++ ){
        btn[i] = 0;
        btp[i] = 0;
    }
    current_time = 0;
    last_time = 0;
    latch = false;
    count = 0;
}

void SNES::update(){
    current_time = micros();
    
    if( current_time-last_time > tp/2 ){
        
        latch=!latch;
        
        if(latch){
            
            if( count++ >= 16 )
                count = 0;
            
            if( count != 0 ){
                btp[count-1] = btn[count-1];
                btn[count-1] = !digitalRead(Q5);
                digitalWrite(CP,HIGH);
            }
            else
                digitalWrite(PL,HIGH);
            
        }
        else{
            
            if( count == 0 )
                digitalWrite(PL,LOW);
            else
                digitalWrite(CP,LOW);
            
        }
        last_time = current_time;
    }
}


bool SNES::B(){
    return btn[0];
}
bool SNES::Y(){
    return btn[1];
}
bool SNES::Select(){
    return btn[2];
}
bool SNES::Start(){
    return btn[3];
}
bool SNES::Up(){
    return btn[4];
}
bool SNES::Down(){
    return btn[5];
}
bool SNES::Left(){
    return btn[6];
}
bool SNES::Right(){
    return btn[7];
}
bool SNES::A(){
    return btn[8];
}
bool SNES::X(){
    return btn[9];
}
bool SNES::L(){
    return btn[10];
}
bool SNES::R(){
    return btn[11];
}
bool SNES::Btn(int _btn){
    return btn[_btn];
}
bool SNES::B_changed(){
    return btn[0]^btp[0];
}
bool SNES::Y_changed(){
    return btn[1]^btp[1];
}
bool SNES::Select_changed(){
    return btn[2]^btp[2];
}
bool SNES::Start_changed(){
    return btn[3]^btp[3];
}
bool SNES::Up_changed(){
    return btn[4]^btp[4];
}
bool SNES::Down_changed(){
    return btn[5]^btp[5];
}
bool SNES::Left_changed(){
    return btn[6]^btp[6];
}
bool SNES::Right_changed(){
    return btn[7]^btp[7];
}
bool SNES::A_changed(){
    return btn[8]^btp[8];
}
bool SNES::X_changed(){
    return btn[9]^btp[9];
}
bool SNES::L_changed(){
    return btn[10]^btp[10];
}
bool SNES::R_changed(){
    return btn[11]^btp[11];
}

