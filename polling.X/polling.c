#pragma config FOSC = XT    // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF   // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF  // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF  // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF    // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF    // Data EEPROM Memory Code Protection bit
#pragma config WRT = OFF    // Flash Program Memory Write Enable bits
#pragma config CP = OFF     // Flash Program Memory Code Protection bit

#include <xc.h>
#define _XTAL_FREQ 4000000  // 4MHz

void transmit(char C)
{
    TXREG=C;
    while(TRMT==0);
    __delay_ms(500);
}

void main(void)
{
    TRISB=0x00;
    TRISC=0x80;
    PORTB=0x00;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    GIE=0;   // Interrupt bits are disabled/cleared for polling
    PEIE=0;
    RCIE=0;
    RCIF=0;
    while(1) 
    {
        if(RCIF)
        {
            char C=RCREG;
            transmit(C);
            PORTB=0xFF;
            __delay_ms(500);
            PORTB=0x00;
            __delay_ms(500);
        }
        transmit('C');
        __delay_ms(500);
    }
    return;
}
