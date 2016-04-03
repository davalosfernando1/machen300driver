void recibirserial() {
  
  if(Serial.available()>0 ) {
    byte c = Serial.read(); 
    if(c==0)
    {
     for(int x = 0 ; x<NMOTOR ; x++)
     {
     while(Serial.available()==0);
     dato[x]=Serial.read();
     //Serial.println(dato[x]);
     }
     if(dato[NMOTOR-1]==128)
     {
         RXcompleto = true;
         digitalWrite(LEDCPU, !digitalRead(LEDCPU) );
         if(dato[MOTOR]<=127)
          { 
           dir = false;
           vel = dato[MOTOR]*2 + 1;
           if(dato[MOTOR]==1)
           vel = 0;
          }
         else
          {
           dir = true;
           vel = (dato[MOTOR] - 127) * 2 -1;
          }
     }
    }

    }
  
}

void recibirpot() {
  vel = 0;
  int valor=analogRead(A5);
  if(valor>=603 )
    { 
    vel=map(valor,603,1023,0,255);
    dir = true;
    RXcompleto = true;
    digitalWrite(LEDCPU, !digitalRead(LEDCPU) );
    }
  if(valor<=420 )
    {
    vel=map(valor,420,0,0,255);
    dir = false;
    RXcompleto = true;  
    digitalWrite(LEDCPU, !digitalRead(LEDCPU) );
    }
  
  }

void recibirpwm() {
vel = 0;
   while(digitalRead(A5));
   temp = pulseIn(A5,HIGH,165000);  
  if (temp!=0)
  {
  if ( temp>mayor)
  mayor = temp;
  if (temp<menor)
  menor = temp;
  
     long rango = mayor - menor; 
     long valor = temp - menor;
     if( valor >= rango/2 )
     { 
       vel =map(valor,rango/2,rango,0,255);
      // vel=map(valor,420,0,0,255);
    dir = false;
    RXcompleto = true;  
    digitalWrite(LEDCPU, !digitalRead(LEDCPU) );
     }
     if(valor<rango/2)
      { 
        vel =map(valor,rango/2,0,0,255);
      // vel=map(valor,420,0,0,255);
      dir = true;
      RXcompleto = true;  
      digitalWrite(LEDCPU, !digitalRead(LEDCPU) );
       } 
  }
}  
  
void recibirpwmkeita() { 
   vel = 0;
   while(digitalRead(A5));
   temp = pulseIn(A5,HIGH,165000);  
  if (temp!=0)
  {
  if ( temp>mayor)
  mayor = temp;
  if (temp<menor)
  menor = temp;
  
     long rango = mayor - menor; 
     long valor = temp - menor;
     if( valor >= rango/2 )
     { 
       vel =map(valor,rango/2,rango,0,255);
      // vel=map(valor,420,0,0,255);
    dir = false;
    RXcompleto = true;  
    digitalWrite(LEDCPU, !digitalRead(LEDCPU) );
     }
     if(valor<rango/2)
      { 
        vel =map(valor,rango/2,0,0,255);
      // vel=map(valor,420,0,0,255);
      dir = true;
      RXcompleto = true;  
      digitalWrite(LEDCPU, !digitalRead(LEDCPU) );
       } 
  }
  }


/*void setup_timer1(){
//disable all interupts
TIMSK1 &= ~( _BV(TOIE1) | _BV(ICIE1) | _BV(OCIE1A) | _BV(OCIE1B));

//set timer mode
TCCR1A &= ~( _BV(WGM11) | _BV(WGM10) );
TCCR1B &= ~( _BV(WGM12) | _BV(WGM13) | _BV(ICNC1));

//capture raising edge
TCCR1B |= _BV(ICES1); //capture raising edge

//prescaler 1/8
TCCR1B |= _BV(CS11);
TCCR1B &= ~( _BV(CS12) | _BV(CS10) );

//disable outputs
TCCR1A &= ~( _BV(COM1A0) | _BV(COM1A1) | _BV(COM1B0) | _BV(COM1B1));

//enable capture interupt
TIMSK1 |= _BV(ICIE1);
}


ISR(TIMER1_CAPT_vect){
static unsigned int lasticr; //icr at last caputre

unsigned int licr;

//TCCR1B ^= _BV(ICES1);
licr=ICR1-lasticr;
lasticr=ICR1;

if(licr>1200){ 
  //pulse too long, means start of new frame
  vel=0;
}
else
  {
  if(licr>=500 && licr<=735)
    { //pulse good, take reading, go to next channel
    vel=map(licr,500,735,0,255);
    dir = true;
    RXcompleto = true;
    digitalWrite(LEDCPU, !digitalRead(LEDCPU) );
    }
  if(licr>=765 && licr<=1050)
    {
    vel=map(licr,765,1050,0,255);
    dir = false;
    RXcompleto = true;  
    digitalWrite(LEDCPU, !digitalRead(LEDCPU) );
    }
   
  }
}
*/

