/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
� Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : HW3_903119
Version : 
Date    : 3/29/2015
Author  : ROOT
Company : eng
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 4.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/

#include <mega32.h>
#include <delay.h>
#include <math.h>
flash char digit[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void sevenSegment(int input)
{int decimal,unit;
decimal=floor(input/10);
unit=(input%10);
 PORTA=digit[unit]; 
    PORTB.1=0;
    PORTB.0=1;
   delay_ms(150); 
    PORTB.0=0;
   PORTB.1=1;
 PORTA=digit[decimal];   
    
     delay_ms(150);    
}

void sevenSegment2(int input)
{int decimal,unit;
decimal=floor(input/10);
unit=(input%10);
 PORTD=digit[unit]; 
    PORTB.2=1;
    PORTB.3=0;
   delay_ms(150); 
    PORTB.2=0;
   PORTB.3=1;
 PORTD=digit[decimal];   
    
     delay_ms(150);    
}
int counterLightVertical,counterLightHorizontal;
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{ counterLightVertical+=1;
   counterLightHorizontal+=1;
// Place your code here
 if(counterLightVertical>12501)
 counterLightVertical=0; 
 if(counterLightHorizontal>12500)
  counterLightHorizontal=0;

}


// Declare your global variables here

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0xFF;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0xFF;

// Port C initialization
// Func7=In Func6=In Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=T State6=T State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTC=0x00;
DDRC=0x3F;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0xFF;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 62.500 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x03;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x01;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Global enable interrupts
#asm("sei")

while (1)
      {
     //this area control vertical traphic light
         if(counterLightVertical<=4500)
          {PORTC.0=0;
          PORTC.1=0;
          PORTC.2=1;
          sevenSegment(18-(counterLightVertical/250));
          
           }      
          if(4500<counterLightVertical&& counterLightVertical<=5000)
          {PORTC.0=0;
          PORTC.1=1;
          PORTC.2=0; 
          sevenSegment(20-(counterLightVertical/250));
          }
          if(5000<counterLightVertical && counterLightVertical<=12500)
          {PORTC.0=1;
          PORTC.1=0;
          PORTC.2=0; 
          sevenSegment(50-(counterLightVertical/250));
          }
          if(counterLightVertical>12500) 
          {PORTC.2=0; 
           PORTC.0=0;
           PORTC.1=0;
         
                }    
                
           //this area control Horizontal traphic light
           if(counterLightHorizontal<=7000)
           {PORTC.3=0; 
           PORTC.4=0;
           PORTC.5=1;  
           sevenSegment2(28-(counterLightHorizontal/250));
           }    
           if(counterLightHorizontal> 7000&&counterLightHorizontal<=7500)
           {PORTC.3=0; 
           PORTC.4=1;
           PORTC.5=0;
           sevenSegment2(30-(counterLightHorizontal/250));
           } 
           
           if(counterLightHorizontal> 7500&&counterLightHorizontal<=12500)
           {PORTC.3=1; 
           PORTC.4=0;
           PORTC.5=0;  
           sevenSegment2(50-(counterLightHorizontal/250));
           }  
             if(counterLightHorizontal>12500)
           {PORTC.3=0; 
           PORTC.4=0;
           PORTC.5=0;
           }  
     

      }
}
