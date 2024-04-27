#include <DS3231.h>
#include "motor.h"

DS3231 rtc(SDA,SCL);
Time t;
int jam, menit, detik, steps, lp, i;
int sw1 = 30, sw2 = 36;
int sw3 = 33, sw4 = 35, sw5 = 37, sw6 = 39; 
int val = 0;

int buttonState = 0;
unsigned long previousMillisTimer = 0;
unsigned long CurrentMillisTimer;
const unsigned long timer = 300;                  
int buttonStatePrevious = LOW;                      
unsigned long minButtonLongPressDuration = 1000;   
unsigned long buttonLongPressMillis;               
bool buttonStateLongPress = false;                  
const int intervalButton = 100;                      
unsigned long previousButtonMillis;                 
unsigned long buttonPressDuration;                  
unsigned long currentMillis;

int buttonState1 = 0;
int buttonStatePrevious1 = LOW;                      
unsigned long minButtonLongPressDuration1 = 1000;   
unsigned long buttonLongPressMillis1;               
bool buttonStateLongPress1 = false;                  
const int intervalButton1 = 100;                      
unsigned long previousButtonMillis1;                 
unsigned long buttonPressDuration1;                  
unsigned long currentMillis1;

 void setup(){
  Serial.begin(9600);
  rtc.begin();
  
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);
  pinMode(sw6, INPUT);
  
  pinMode(R_EN1, OUTPUT);
  pinMode(L_EN1, OUTPUT);
  pinMode(R_PWM1, OUTPUT);
  pinMode(L_PWM1, OUTPUT);
  
  pinMode(R_EN2, OUTPUT);
  pinMode(L_EN2, OUTPUT);
  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);

//  rtc.setTime(18,39,00);
  Serial.println("Memulai Program");
}

void loop() {
   posN2 = rte2.read();
    if (posN2 != pos2){
      pos2 = posN2;
      Serial.print("  en2=");
      Serial.println(posN2);
      }
    posN1 = rte1.read();
    if (posN1 != pos1){
      pos1 = posN1;
      Serial.print("  en1=");
      Serial.println(posN2);
      } 
      main1();

}

  
void main1(){
  currentMillis = millis(); 
  if(currentMillis - previousButtonMillis > intervalButton) {
    buttonState = digitalRead(sw1);    
    if (buttonState == HIGH && buttonStatePrevious == LOW && !buttonStateLongPress) {
      buttonLongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
    }

    buttonPressDuration = currentMillis - buttonLongPressMillis;
    if (buttonState == HIGH && !buttonStateLongPress && buttonPressDuration >= minButtonLongPressDuration) {
      buttonStateLongPress = true;
      steps = 22;
      Serial.println("Button long press -- start program");
    }
      
    if (buttonState == LOW && buttonStatePrevious == HIGH) {
      buttonStatePrevious = LOW;
      buttonStateLongPress = false;

      if (buttonPressDuration < minButtonLongPressDuration) {
        steps = 20;
        Serial.println("Button short press -- kalibrasi timur");
      }
    }
    previousButtonMillis = currentMillis;

  }

  currentMillis1 = millis(); 
  if(currentMillis1 - previousButtonMillis1 > intervalButton1) {
    buttonState1 = digitalRead(sw2);    
    if (buttonState1 == HIGH && buttonStatePrevious1 == LOW && !buttonStateLongPress1) {
      buttonLongPressMillis1 = currentMillis1;
      buttonStatePrevious1 = HIGH;
    }

    buttonPressDuration1 = currentMillis1 - buttonLongPressMillis1;
    if (buttonState1 == HIGH && !buttonStateLongPress1 && buttonPressDuration1 >= minButtonLongPressDuration1) {
      buttonStateLongPress1 = true;
      steps = 30;
      Serial.println("Button long press -- Manual Move");
    }
    if (buttonState1 == LOW && buttonStatePrevious1 == HIGH) {
      buttonStatePrevious1 = LOW;
      buttonStateLongPress1 = false;
      if (buttonPressDuration1 < minButtonLongPressDuration1) {
        steps = 25;
        Serial.println("Button short press ");
      }
    }
    previousButtonMillis1 = currentMillis1;
  }

  if(steps == 30){
    int buttonState3 = digitalRead(sw3);
    int buttonState4 = digitalRead(sw4);
    int buttonState5 = digitalRead(sw5);
    int buttonState6 = digitalRead(sw6);
    if(buttonState5 == HIGH){ 
      cw2(240);
    }else if(buttonState6 == HIGH){
      ccw2(240);
    }else if(buttonState3 == 1){
      cw1(240);
    }else if(buttonState4 == 1){
      ccw1(240);
    }else{Stop();}
}

  CurrentMillisTimer = millis();
  if(CurrentMillisTimer - previousMillisTimer >= timer ){
    t=rtc.getTime();
    int jam  = t.hour;
    int menit = t.min;
    int detik = t.sec; 
  
        
//-------PROGRAM 1-------//
    if(steps == 25){
       if(lp == 1){
        PID1(0);
        if(posN1<=15){PID2(0);}
       }
       if(lp == 2){
        PID1(0);
        if(posN1<=15){PID2(0);}
        }
       if(lp == 3){
        PID1(0);
        if(posN1<=15){PID2(0);}
       }
    }


//--------KALIBRASI--------//
    if(steps == 20){
      lp = 1;
      PID2(315);
      if(posN2>=290){PID1(300);} 
    }
        
//---------PROGRAM 2-------//
  if(steps == 22){
    if(jam == 7){
      if(menit >= 0){
        if(detik >= 0){
          lp = 1;
          PID1(300);
          if(posN1>=285){PID2(300);}
        }
      }
    }

    if(jam == 8){
      if(menit >= 0){
        if(detik >= 0){
          lp = 1;
          PID1(300);
          if(posN1<=300){PID2(140);}
          
        }
      }
    }

    if(jam == 9){
      if(menit >= 0){
        if(detik >= 0){
          lp = 1;
          PID1(280);
          if(posN1<=295){PID2(80);}
          PID2(80);
        }
      }
    }

    if(jam == 10){
      if(menit >= 0){
        if(detik >= 0){
          lp = 1;
          PID1(220);
          if(posN1<=235){PID2(20);}
          
        }
      }
    }

    if(jam == 11){
      if(menit >= 0){
        if(detik >= 0){
          PID1(160);
          if(posN1<=175){PID2(-40);}
          lp = 2;
        }
      }
    }

    if(jam == 12){
      if(menit >= 0){
        if(detik >= 0){
          PID1(100);
          if(posN1<=115){PID2(-100);}
          lp = 2;
        }
      }
    }

    if(jam == 13){
      if(menit >= 0){
        if(detik >= 0){
          PID1(40);
          if(posN1<=55){PID2(-160);}
          
          lp = 2;
        }
      }
    }

    if(jam == 14){
      if(menit >= 0){
        if(detik >= 0){
          lp = 3;
          PID1(-20);
          if(posN1<=-5){PID2(-200);}
        }
      }
    }

    if(jam == 15){
      if(menit >= 0){
        if(detik >= 0){
          lp = 3;
          PID1(-80);
          if(posN1<=-65){PID2(-280);}
         
        }
      }
    }

    if(jam == 16){
      if(menit >= 0){
        if(detik >= 0){
          lp = 3;
          PID1(-160);
          if(posN1<=-145){PID2(-300);}
        }
      }
    }

    if(jam == 17){
      if(menit >= 0){
        if(detik >= 0){
          lp = 3;
          PID1(-300);
          if(posN1<=-285){PID2(-300);}
        }
      }
    }

    if(jam == 17){
      if(menit >= 30){
        if(detik >= 0){
         PID1(0);
          if(posN1<=-15){PID2(0);}
        }
      }
    }
   }
  

    previousMillisTimer = millis(); 
//    Serial.print("Time = ");
//    Serial.println(rtc.getTimeStr());
  }
}
