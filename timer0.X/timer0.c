#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 4000000 //4MHz
/*void delay()    // timer0
{
    TMR0=0;
    while(TMR0IF==0);
    TMR0IF=0;
}
void main(void)
{
    TRISB=0x00;
    OPTION_REG=0x81;
    while(1)
    {
        PORTB=0xFF;
        delay();
        PORTB=0x00;
        delay();
    }
    return;
}*/
/*void delay()   //timer1
{
    TMR1=0;
    while(TMR1IF==0);
    TMR1IF=0;
}
void main(void)
{
    TRISB=0x00;
    T1CON=0x21;
    while(1)
    {
        PORTB=0xFF;
        delay();
        PORTB=0x00;
        delay();
    }
    return;
}*/
void delay()  //timer2
{
    PR2=100;
    TMR2=0;
    while(TMR2IF==PR2);
    TMR2IF=0;
}
void main(void)
{
    TRISB=0x00;
    T2CON=0x05 ;
    while(1)
    {
        PORTB=0xFF;
        delay();
        PORTB=0x00;
        delay();
    }
    return;
}
