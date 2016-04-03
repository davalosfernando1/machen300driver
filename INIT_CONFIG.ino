void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x7; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

void pwmstart()
{
analogWrite(3,0);
analogWrite(11,0);
analogWrite(5,0);
analogWrite(6,0);

cli();
setPwmFrequency(6,8);
setPwmFrequency(11,8);
//PHASE PWM NOOOO
/*TCCR0B&=0b11110111; // queremos el phase pwm
TCCR0A&=0b11111100; // PHASE PWM
//TCCR0A|=0b00000001; // PHASE PWM
sbi(TCCR0A,WGM00);    // PHASE PWM*/ 
TIMSK0|=0b00000110; // INTERRUPCIONES
TIMSK2|=0b00000110; // INTERRUPCIONES*/
TCCR2A|=0b00000011; // FAST PWM
OCR2B = 241;
OCR0B = 241;
sei();
digitalWrite(LEDCPU,HIGH);
delay(200);
digitalWrite(LEDCPU,LOW);
delay(200);
digitalWrite(LEDCPU,HIGH);
delay(200);
digitalWrite(LEDCPU,LOW);
}
