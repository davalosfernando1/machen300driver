/*void drivervel (int H1, int L1, int H2, int L2)
{
  if ( dir )  //USAMOS LOS H1 Y L1 para control y el L2 para tierra
      {
      if( dir!=dirant )
        {
          for(int x = 1; x<= ( vel + anterior ) ;x++)
          {
            if(anterior-x>=0)
            {
              analogWrite(H2,anterior-x);  //venimos del anterior por eso switcheamos el 2
              if(anterior-x==0)
              digitalWrite(L1,LOW);
            }
            
            else
            {
              digitalWrite(L2,HIGH);
              analogWrite(H1,x-anterior );
            }
            delay(DELAYPWM);
          }
        }
      else
        {
        if (vel-anterior>0)  //AUMENTAMOS
       {
        digitalWrite(L1,LOW);digitalWrite(L2,HIGH); delay(DELAYPWM);
        for(int x = 1;x<=(vel-anterior);x++)
            {
            
            analogWrite(H1, (anterior+x) );
            delay(DELAYPWM);
            } }
        else                //RESTAMOS
        {
          for(int x = 1;x<=(anterior-vel);x++)
            {
            analogWrite(H1,anterior-x );
            delay(DELAYPWM);
            }
          }
        }
      }
    else    //USAMOS LOS H2 Y L2 para control y el L1 para tierra
      {
        if( dir==dirant )
        {
          if (vel-anterior>0)
          {
           digitalWrite(L2,LOW);digitalWrite(L1,HIGH); delay(DELAYPWM);
          for(int x = 1;x<=(vel-anterior);x++)
            {
            analogWrite(H2,(anterior+x));
            delay(DELAYPWM);
            }}
          else 
           for(int x = 1;x<=(anterior-vel);x++)
            {
            analogWrite(H2,(anterior-x));
            delay(DELAYPWM);
            } 
        }
        else
        {
          for(int x = 1;x<=( anterior + vel );x++)
          {
            if(anterior-x>=0)
            {
              analogWrite(H1,anterior-x);
              if(anterior-x==0)
              digitalWrite(L2,LOW);
            }
            else
            {
              digitalWrite(L1,HIGH);
              analogWrite(H2,x-anterior );
            }
            delay(DELAYPWM);
          }
        }
      }
      if(vel==0)
      {
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
      }
  }*/
/*  
  void drivervel (int H1, int L1, int H2, int L2)
{
  if ( dir )  //USAMOS LOS H1 Y L1 para control y el L2 para tierra
      {
      if( dir!=dirant )
        {
            if(anterior-1>=0)
            {
              analogWrite(H2,anterior-1);  //venimos del anterior por eso switcheamos el 2
              anterior--;
              if(anterior==0)
              {
              digitalWrite(L1,LOW);
              dirant = dir;
              }
            }
            if(anterior-1<0)
            {
              dirant = dir;
            }
        }
   else
      {
        if (vel-anterior>0)  //AUMENTAMOS
         {
          digitalWrite(L1,LOW);digitalWrite(L2,HIGH); 
          analogWrite(H1, (anterior+1) );
          anterior++;
         }
        else                //RESTAMOS
         {
           analogWrite(H1,anterior-1 );
           anterior--;
         }
       }
     }
  else    //USAMOS LOS H2 Y L2 para control y el L1 para tierra
      {
        if( dir==dirant )
        {
          if (vel-anterior>0)
            {
            digitalWrite(L2,LOW);digitalWrite(L1,HIGH);
            analogWrite(H2, ++anterior );
            }
          else 
            {
             analogWrite(H2, --anterior );
            }
        }
        else
        {
            if(anterior-1>=0)
            {
              analogWrite(H1,anterior-1);
              anterior--;
              if(anterior==0)
              {
                digitalWrite(L2,LOW);
                dirant = dir;
              }
            }
            if(anterior-1<0)
            {
              dirant = dir;
            }
        }
      }
      if(anterior<=0)
      {
        digitalWrite(L1,LOW);
        digitalWrite(L2,LOW);
      }
  }
  
ISR(TIMER2_COMPA_vect) {
    if(OCR2A>1 && OCR2A<240)
    { __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
    PORTD |= (1<<PD3);
     //digitalWrite(3,HIGH);
   }
}

ISR(TIMER0_COMPA_vect) {
  if(OCR0A>1 && OCR0A<240)
    {  
     __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
  PORTD |= (1<<PD5);
   // digitalWrite(5,HIGH);
    }
}

ISR(TIMER2_COMPB_vect) { 
  if(OCR2A>1)
  PORTD &= ~(1<<PD3);
  // __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
}

ISR(TIMER0_COMPB_vect) {
  if(OCR0A>1)
    PORTD &= ~(1<<PD5);
  //__asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
}*/
