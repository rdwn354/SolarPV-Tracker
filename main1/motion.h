//program cadangan 
  if(steps == 22){
    if(jam == 7){
      if(menit >= 0){
        if(detik >= 0){
          cw(140);
          lp = 1;
          if(posN1 >= 300){
            Stops1(); 
            }         
          if(posN2 >= 300){
            Stops2();
            }
        }
      }
    }

    if(jam == 8){
      if(menit >= 0){
        if(detik >= 0){
          ccw(240);
          lp = 1;
          if(posN1 <= 300){
            Stops1(); 
            }         
          if(posN2 <= 140){
            Stops2();
            }
        }
      }
    }

    if(jam == 9){
      if(menit >= 0){
        if(detik >= 0){
          ccw(240);
          lp = 1;
          if(posN1 <= 280){
            Stops1(); 
            }         
          if(posN2 <= 80){
            Stops2();
            }
        }
      }
    }

    if(jam == 10){
      if(menit >= 0){
        if(detik >= 0){
          ccw(240);
          lp = 1;
          if(posN1 <= 220){
            Stops1(); 
            }         
          if(posN2 <= 20){
            Stops2();
            }
        }
      }
    }

    if(jam == 11){
      if(menit >= 0){
        if(detik >= 0){
          ccw(240);
          lp = 2;
          if(posN1 <= 160){
            Stops1(); 
            }         
          if(posN2 <= -40){
            Stops2();
            }
        }
      }
    }

    if(jam == 12){
      if(menit >= 0){
        if(detik >= 0){
          ccw(240);
          lp = 2;
          if(posN1 <= 100){
            Stops1(); 
            }         
          if(posN2 <= -100){
            Stops2();
            }
        }
      }
    }

    if(jam == 13){
      if(menit >= 0){
        if(detik >= 0){
          ccw(135);
          lp = 2;
          if(posN1 <= 40){
            Stops1(); 
            }         
          if(posN2 <= -160){
            Stops2();
            }
        }
      }
    }

    if(jam == 14){
      if(menit >= 0){
        if(detik >= 0){
          ccw(135);
          lp = 3;
          if(posN1 <= -20){
            Stops1(); 
            }         
          if(posN2 <= -200){
            Stops2();
            }
        }
      }
    }

    if(jam == 15){
      if(menit >= 0){
        if(detik >= 0){
          ccw(135);
          lp = 3;
          if(posN1 <= -80){
            Stops1(); 
            }         
          if(posN2 <= -280){
            Stops2();
            }
        }
      }
    }

    if(jam == 16){
      if(menit >= 0){
        if(detik >= 0){
          ccw(135);
          lp = 3;
          if(posN1 <= -160){
            Stops1(); 
            }         
          if(posN2 <= -300){
            Stops2();
            }
        }
      }
    }

    if(jam == 17){
      if(menit >= 0){
        if(detik >= 0){
          ccw(135);
          lp = 3;
          if(posN1 <= -300){
            Stops1(); 
            }         
          if(posN2 <= -300){
            Stops2();
            }
        }
      }
    }

    if(jam == 18){
      if(menit >= 0){
        if(detik >= 0){
          cw(240);
           lp = 4;
          if(posN1 >= 0){
            Stops1(); 
            }         
          if(posN2 >= 0){
            Stops2();
            }
        }
      }
    }
   }
//kalibrasi
if(steps == 20){
      lp = 1;
      PID2(350);
      if(posN2>=335){PID1(300);} 
    }

//cadangan 
  if(steps == 22){
    if(jam == 7){
      if(menit >= 0){
        if(detik >= 0){
          lp = 1;
          PID1(350);
          if(posN1>=335){PID2(350);}
        }
      }
    }

    if(jam == 8){
      if(menit >= 0){
        if(detik >= 0){
          lp = 1;
          PID1(300);
          if(posN1<=315){PID2(140);}
          
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
          PID1(-350);
          if(posN1<=-335){PID2(-350);}
      
        }
      }
    }

    if(jam == 18){
      if(menit >= 0){
        if(detik >= 0){
          cw(240);
           lp = 4;
          if(posN1 >= 0){
            Stops1(); 
            }         
          if(posN2 >= 0){
            Stops2();
            }
        }
      }
    }
   }
//Program utama

    if(buttonVal1 == HIGH){
      steps = 20;
    }
    else if(buttonVal2 == HIGH){
      steps = 21;
      }
    else{}
//------------------------//

//-------PROGRAM 1-------//
    if(steps == 20){
       if(lp == 1){
         ccw();
         if(posN1<=0){
           Stops1();
           }
         if(posN2<=0){
           Stops2();
           }
       }
       
       if(lp == 2){
         ccw1();
         cw2();
         if(posN1<=0){
           Stops1();
           }
         if(posN2>=0){
           Stops2();
           }
        }
       if(lp == 4){
          Stop(); 
        }

       if(lp == 3){
         cw();
         if(posN1>=0){
           Stops1();
           }
         if(posN2>=0){
           Stops2();
           }
       }
    }
//--------------------------//

//---------PROGRAM 2-------//
  if(steps == 21){
    if(jam == 7){
      if(menit >= 0){
        if(detik >= 0){
          cw();
          lp = 1;
          if(posN1 >= 400){
            Stops1(); 
            }         
          if(posN2 >= 200){
            Stops2();
            }
        }
      }
    }

    if(jam == 8){
      if(menit >= 0){
        if(detik >= 0){
          ccw();
          lp = 1;
          if(posN1 <= 340){
            Stops1(); 
            }         
          if(posN2 <= 140){
            Stops2();
            }
        }
      }
    }

    if(jam == 9){
      if(menit >= 0){
        if(detik >= 0){
          ccw();
          lp = 1;
          if(posN1 <= 280){
            Stops1(); 
            }         
          if(posN2 <= 80){
            Stops2();
            }
        }
      }
    }

    if(jam == 10){
      if(menit >= 0){
        if(detik >= 0){
          ccw();
          lp = 1;
          if(posN1 <= 220){
            Stops1(); 
            }         
          if(posN2 <= 20){
            Stops2();
            }
        }
      }
    }

    if(jam == 11){
      if(menit >= 0){
        if(detik >= 0){
          ccw();
          lp = 2;
          if(posN1 <= 160){
            Stops1(); 
            }         
          if(posN2 <= -40){
            Stops2();
            }
        }
      }
    }

    if(jam == 12){
      if(menit >= 0){
        if(detik >= 0){
          ccw();
          lp = 2;
          if(posN1 <= 100){
            Stops1(); 
            }         
          if(posN2 <= -100){
            Stops2();
            }
        }
      }
    }

    if(jam == 13){
      if(menit >= 0){
        if(detik >= 0){
          ccw3();
          lp = 2;
          if(posN1 <= 40){
            Stops1(); 
            }         
          if(posN2 <= -160){
            Stops2();
            }
        }
      }
    }

    if(jam == 14){
      if(menit >= 0){
        if(detik >= 0){
          ccw3();
          lp = 3;
          if(posN1 <= -20){
            Stops1(); 
            }         
          if(posN2 <= -200){
            Stops2();
            }
        }
      }
    }

    if(jam == 15){
      if(menit >= 0){
        if(detik >= 0){
          ccw3();
          lp = 3;
          if(posN1 <= -80){
            Stops1(); 
            }         
          if(posN2 <= -280){
            Stops2();
            }
        }
      }
    }

    if(jam == 16){
      if(menit >= 0){
        if(detik >= 0){
          ccw3();
          lp = 3;
          if(posN1 <= -140){
            Stops1(); 
            }         
          if(posN2 <= -340){
            Stops2();
            }
        }
      }
    }
    
    if(jam == 17){
      if(menit >= 0){
        if(detik >= 0){
          ccw3();
          lp = 3;
          if(posN1 <= -200){
            Stops1(); 
            }         
          if(posN2 <= -400){
            Stops2();
            }
        }
      }
    }

    if(jam == 18){
      if(menit >= 0){
        if(detik >= 0){
          cw3();
           lp = 4;
          if(posN1 >= 0){
            Stops1(); 
            }         
          if(posN2 >= 0){
            Stops2();
            }
        }
      }
    }
   }

//Program manual
 
  
  if(buttonVal2 == HIGH){ 
    ccw();
  }else if(buttonVal1 == HIGH){
    cw();
  }else{Stop();}

  if(buttonVal2 == HIGH){ 
    ccw2();
  }
  else if(buttonVal1 == HIGH){
    cw2();
  }else{Stops2();}

//program button
    if(buttonVal1 == HIGH){
      cw();
      steps = 1;
      }   
    else if(buttonVal2 == HIGH){ 
      ccw();
      steps = 2;
      }
    else {}

    if(steps == 1){
      if(posN1 >= 400){
        Stops1(); 
        }         
      if(posN2 >= 200){
        Stops2();
        }
      }
    if(steps == 2){
      if(posN1 <= -200){
        Stops1(); 
        }         
      if(posN2 <= -400){
        Stops2();
        }
      }

//program gerak menggunakan RTC
    if(jam == 7){
      if(menit == 0){
        if(detik >= 5){
          cw();
          steps =1;
        }
      }
    }

    if(jam == 7){
      if(menit == 1){
        if(detik >= 0){
          ccw();
          steps =2;
        }
      }
    }

    if(steps == 1){
      if(posN1 >= 400){
        Stops1(); 
        }         
      if(posN2 >= 200){
        Stops2();
        }
      }
    if(steps == 2){
      if(posN1 <= -200){
        Stops1(); 
        }         
      if(posN2 <= -400){
        Stops2();
        }
      }

//Program gerak dengan interupt
    if(buttonVal1 == HIGH){
      steps = 21;
    }
    else if(buttonVal2 == HIGH){
      steps = 20;
      }
    else{}

    if(steps == 21){
       if(lp == 1){
         ccw1();
         if(posN1<=0){
           Stops1();
           }
       }
       if(lp == 2){
         cw1();
         if(posN1>=0){
           Stops1();
           }
       } 
      } 
    
    if(steps == 20){
      if(jam == 7){
        if(menit == 0){
          if(detik >= 5){
            cw1();
            lp = 1;
            if(posN1 >= 40){
            Stops1(); 
            }
          }
        }
      }
  
      if(jam == 7){
        if(menit == 1){
          if(detik >= 5){
            ccw1();
            lp = 2;
            if(posN1 <= -40){
            Stops1(); 
            }
          }
        }
      }
    }
