//CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include<stdio.h>
#define _XTAL_FREQ 4000000 //4MHz
void delay()
{
    for(int i=0;i<1000;i++)
    {
        TMR0=0;
        while(TMR0IF==0);
        TMR0IF=0;
    }
}
void time_string(char *buffer)
{
    while(*buffer)
    {
        TXREG=*buffer++;
        while(TRMT==0); 
    }
}
void main(void) 
{
    //TMR0=0;
    OPTION_REG=0x81;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    TRISC=0x00;
    PORTC=0x00;
    GIE=0;
    PEIE=0;
    RCIE=0;
    
    int hr=0,sec=0,min=0;
    char buffer[20];
    while(1)
    {
        sec++;
        if(sec>=60)
        {
            sec=0;
            min++;
        }
        if(min>=60)
        {
            min=0;
            hr++;
        }
        if(hr>=24)
        {
            hr=0;
        }
        sprintf(buffer,"%d:%d:%d \r",hr,min,sec);
        time_string(buffer);
        delay();
    }
    return;
}
