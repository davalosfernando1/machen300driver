//DEFINICIONES
#define NMOTOR 12 // los motores y el final
#define DELAYPWMA 6
#define DELAYPWMB 3
#define LEDCPU 13
#define MOTOR 1 //EMPIEZA EN 1
#define FASTADC 1

#ifndef cbi                    // PARA EL ADC
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

//VARIABLES
unsigned long tiempo,watch,corrientet;
byte dato[NMOTOR];
int vel;
int anterior=0;
int com = 0;
long mayor =0;
long menor =165000;
long temp=0;
boolean dir =false; 
boolean dirant=false;
boolean RXcompleto =false;
boolean Corriente=false;
boolean latch=false;
// 11 ( AL 7 DEL HIP AHI .:. LE CORRESPONDE EL A1) ES EL ALTO Y 3 EL BAJO   // IF DIR FALSE usamos este brazo para PWM ElSE para dar tierra
//  6 ES EL ALTO Y 5 ES EL BAJO // IF DIR TRUE usamos este brazo para PWM ElSE para dar tierra
//ICP1
unsigned int serinp;

void setup() {
pwmstart();
#if FASTADC
 // set prescale to 16
 sbi(ADCSRA,ADPS2) ;
 cbi(ADCSRA,ADPS1) ;
 cbi(ADCSRA,ADPS0) ;
#endif

Serial.begin(38400);
vel=0;
pinMode(A5,INPUT);
//ICP1
//pinMode( 8, INPUT ); //sum
//setup_timer1();
//END ICP1
watch=0;
}

void loop() {
  RXcompleto = false;
  
  int analog0 = analogRead(A0);
  int analog1 = analogRead(A1);
    
  if(!dirant && analog0>910 && anterior>0 && analog0<990  )
  {
    vel=0;
    Corriente = true;
    corrientet=millis();
  }
  if(dirant && analog1>910 && anterior>0 && analog1<990 )
  {
    vel=0;
    Corriente = true;
    corrientet=millis();
  } 
  
  if( Corriente && ( (millis() -corrientet) > 2000 || ( !dir && analog0<800 && anterior>0  ) || (dir && analog1<800 && anterior>0) ) )
  Corriente = false;
  
  if ( com ==100 ){
  if(!Corriente)
  //recibirpot();
  //para serial se debe de cancelar la funcion de icp1
  //recibirserial();
  recibirpwmkeita();
  //para icp1
  com = 0;
  }
 
    if(   ( (millis()-tiempo)>=DELAYPWMA && vel>anterior && dirant==dir  ) || ( millis()-tiempo>=DELAYPWMB && (vel<anterior || dir!=dirant ) )  )
    {
    drivervel(11,6);
    tiempo = millis();
    }
  
 
 // para serial o pwm 
 
 if(RXcompleto)
 watch = millis();
 if(  (millis() - watch) > 10000   )
    {
    vel=0;
    }
 
  com++;
  
    
}


