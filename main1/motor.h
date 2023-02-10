#include <Encoder.h>

Encoder rte2(51, 49);
Encoder rte1(45, 43);
long pos1,posN1,pos2,posN2;

//motor 1
#define R_EN1     3
#define R_PWM1    2
#define L_EN1     6
#define L_PWM1    7
//motor 2
#define R_EN2     9 
#define R_PWM2    8
#define L_EN2     12
#define L_PWM2    13

//set value PID
float Kp1 = 5;
float Ki1 = 0;
float Kd1 = 0;
float integral1, derivative1;
float deltaTime1, prevTime1, currentTime1;
float prevError1, error1;
float control1;
float dt1;  
int motorDir1;
float velocity1;

//set value PID2
float Kp2 = 5;
float Ki2 = 0;
float Kd2 = 0;
float integral2, derivative2;
float deltaTime2, prevTime2, currentTime2;
float prevError2, error2;
float dt2;
int  motorDir2;
float control2; 
float velocity2;

//set value pid 3
float Kp3 = 5;
float Ki3 = 0;
float Kd3 = 0;
float integral3, derivative3;
float deltaTime3, prevTime3, currentTime3;
float prevError3, error3;
float dt3;
int  motorDir3;
float control3; 
float velocity3;

//set value pid 4
float Kp4 = 26;
float Ki4 = 0;
float Kd4 = 0.8;
float integral4, derivative4;
float deltaTime4, prevTime4, currentTime4;
float prevError4, error4;
float dt4;
int  motorDir4;
float control4; 
float velocity4;

void PID1(int targetPos1){
   currentTime1 = micros();
  dt1 = (currentTime1 - prevTime1)/1000000.0;
  prevTime1 = currentTime1;
  
  error1 = targetPos1 - posN1;
  integral1 += error1*dt1;
  derivative1 = (error1 - prevError1)/dt1;
  control1 = (Kp1*error1) + (Ki1*integral1) + (Kd1*derivative1);
  prevError1 = error1;
  
  //drive motor
  if(control1<0){
    motorDir1 = -1;
    }
  else if(control1>0){
    motorDir1 = 1;
    }
  else{motorDir1 = 0;}

  float velocity1 = (int)fabs(control1);
  if(velocity1 > 230){
    velocity1 = 230;
    }
  if(velocity1 < 110 && control1 !=0){
    velocity1 = 0;
    }  
  analogWrite(R_EN1, velocity1);
  analogWrite(L_EN1, velocity1);
  
   if(motorDir1 == -1)//ccw
    {
      digitalWrite(R_PWM1, 0);
      digitalWrite(L_PWM1, 1);
    }
    if(motorDir1 == 1)//cw
    {
      digitalWrite(R_PWM1, 1);
      digitalWrite(L_PWM1, 0);  
    }
    if(motorDir1 == 0)//stop
    {
      digitalWrite(R_PWM1, 0);
      digitalWrite(L_PWM1, 0);  
    }
}
void PID2(int targetPos2){
// pid motor 2    

  currentTime2 = micros();
  dt2 = (currentTime2 - prevTime2)/1000000.0;
  prevTime2 = currentTime2;
 
  error2 = targetPos2 - posN2;
  integral2 += error2*dt2;
  derivative2 = (error2 - prevError2)/dt2;
  float control2 = (Kp2*error2) + (Ki2*integral2) + (Kd2*derivative2);
  prevError2 = error2;

  //drive motor
  if(control2<0){
    motorDir2 = -1;
    }
  else if(control2>0){
    motorDir2 = 1;
    }
    

  float velocity2 = (int)fabs(control2);
  if(velocity2 > 230){
    velocity2 = 230;
    }
  if(velocity2 < 110 && control2 !=0){
    velocity2 = 0;
    }  
  analogWrite(R_EN2, velocity2);
  analogWrite(L_EN2, velocity2);
  
  if(motorDir2 == -1)//ccw
  {
    digitalWrite(R_PWM2, 0);
    digitalWrite(L_PWM2, 1);
  }
  if(motorDir2 == 1)//cw
  {
    digitalWrite(R_PWM2, 1);
    digitalWrite(L_PWM2, 0);  
  }
  if(motorDir2 == 0)//stop
  {
    digitalWrite(R_PWM2, 0);
    digitalWrite(L_PWM2, 0);  
  }
} 

void PID3(int targetPos3){
  currentTime3 = micros();
  dt3 = (currentTime3 - prevTime3)/1000000.0;
  prevTime3 = currentTime3;
  
  error3 = targetPos3 - posN1;
  integral3 += error3*dt3;
  derivative3 = (error3 - prevError3)/dt3;
  control3 = (Kp3*error3) + (Ki3*integral3) + (Kd3*derivative3);
  prevError3 = error3;
  
  //drive motor
  if(control3<0){
    motorDir3 = -1;
    }
  else if(control3>0){
    motorDir3 = 1;
    }
  else{motorDir3 = 0;}

  float velocity3 = (int)fabs(control3);
  if(velocity3 > 220){
    velocity3 = 220;
    }
    if(velocity3 < 25 && control3 !=0){
    velocity3 = 0;
    }  
    
  analogWrite(R_EN1, velocity3);
  analogWrite(L_EN1, velocity3);
  
   if(motorDir3 == -1)//ccw
    {
      digitalWrite(R_PWM1, 0);
      digitalWrite(L_PWM1, 1);
    }
    if(motorDir3 == 1)//cw
    {
      digitalWrite(R_PWM1, 1);
      digitalWrite(L_PWM1, 0);  
    }
    if(motorDir3 == 0)//stop
    {
      digitalWrite(R_PWM1, 0);
      digitalWrite(L_PWM1, 0);  
    }
}
void PID4(int targetPos4){
// pid motor 2    

  currentTime4 = micros();
  dt4 = (currentTime4 - prevTime4)/1000000.0;
  prevTime4 = currentTime4;
 
  error4 = targetPos4 - posN2;
  integral4 += error4*dt4;
  derivative4 = (error4 - prevError4)/dt4;
  float control4 = (Kp4*error4) + (Ki4*integral4) + (Kd4*derivative4);
  prevError4 = error4;

  //drive motor
  if(control4<0){
    motorDir4 = -1;
    }
  else if(control4>0){
    motorDir4 = 1;
    }
    

  float velocity4 = (int)fabs(control4);
  if(velocity4 > 220){
    velocity4 = 220;
    }
  if(velocity4 < 25 && control4 !=0){
    velocity4 = 0;
    }  
    
  analogWrite(R_EN2, velocity4);
  analogWrite(L_EN2, velocity4);
  
  if(motorDir4 == -1)//ccw
  {
    digitalWrite(R_PWM2, 0);
    digitalWrite(L_PWM2, 1);
  }
  if(motorDir4 == 1)//cw
  {
    digitalWrite(R_PWM2, 1);
    digitalWrite(L_PWM2, 0);  
  }
  if(motorDir4 == 0)//stop
  {
    digitalWrite(R_PWM2, 0);
    digitalWrite(L_PWM2, 0);  
  }
} 

void cw(int Speed){
  analogWrite(R_EN1, Speed);//cw
  analogWrite(L_EN1, Speed);
  digitalWrite(R_PWM1, 1);
  digitalWrite(L_PWM1, 0);  

  analogWrite(R_EN2, Speed);//cw
  analogWrite(L_EN2, Speed);
  digitalWrite(R_PWM2, 1);
  digitalWrite(L_PWM2, 0); 
  }
  
void ccw(int Speed){
  analogWrite(R_EN1, Speed);//cw
  analogWrite(L_EN1, Speed);
  digitalWrite(R_PWM1, 0);
  digitalWrite(L_PWM1, 1);

  analogWrite(R_EN2, Speed);//cw
  analogWrite(L_EN2, Speed);
  digitalWrite(R_PWM2, 0);
  digitalWrite(L_PWM2, 1);
  }
  
void cw1(int Speed){
  analogWrite(R_EN1, Speed);//cw
  analogWrite(L_EN1, Speed);
  digitalWrite(R_PWM1, 1);
  digitalWrite(L_PWM1, 0);  
  }

void ccw1(int Speed){
  analogWrite(R_EN1, Speed);//cw
  analogWrite(L_EN1, Speed);
  digitalWrite(R_PWM1, 0);
  digitalWrite(L_PWM1, 1);   
  }
  
void cw2(int Speed){
  analogWrite(R_EN2, Speed);//cw
  analogWrite(L_EN2, Speed);
  digitalWrite(R_PWM2, 1);
  digitalWrite(L_PWM2, 0);  
  }

void ccw2(int Speed){
  analogWrite(R_EN2, Speed);//cw
  analogWrite(L_EN2, Speed);
  digitalWrite(R_PWM2, 0);
  digitalWrite(L_PWM2, 1);   
  }

void Stop(){
  analogWrite(R_EN1, 0);
  analogWrite(L_EN1, 0);
  digitalWrite(R_PWM1, 0);
  digitalWrite(L_PWM1, 0);
  
  analogWrite(R_EN2, 0);
  analogWrite(L_EN2, 0);
  digitalWrite(R_PWM2, 0);
  digitalWrite(L_PWM2, 0); 
  }

void Stops1(){
  analogWrite(R_EN1, 0);
  analogWrite(L_EN1, 0);
  digitalWrite(R_PWM1, 0);
  digitalWrite(L_PWM1, 0);
  }
void Stops2(){
  analogWrite(R_EN2, 0);
  analogWrite(L_EN2, 0);
  digitalWrite(R_PWM2, 0);
  digitalWrite(L_PWM2, 0); 
   }

 
  
