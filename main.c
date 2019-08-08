#include <p18f4550.h>
#include <string.h>
#include <delays.h>
#include <timers.h>

#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP = OFF
#pragma config XINST = OFF

#define DELAY   255
#define DELAYEF 255

// defines the size of the char[] nome string
#define MAX     31
#define REP     20
#define MAXEF   20

// defines displays activations
#define DISP1   PORTAbits.RA5 = 1; PORTAbits.RA2 = 0; PORTEbits.RE0 = 0; PORTEbits.RE2 = 0;
#define DISP2   PORTAbits.RA5 = 0; PORTAbits.RA2 = 1; PORTEbits.RE0 = 0; PORTEbits.RE2 = 0;
#define DISP3   PORTAbits.RA5 = 0; PORTAbits.RA2 = 0; PORTEbits.RE0 = 1; PORTEbits.RE2 = 0;
#define DISP4   PORTAbits.RA5 = 0; PORTAbits.RA2 = 0; PORTEbits.RE0 = 0; PORTEbits.RE2 = 1;   
#define DISPON  PORTAbits.RA5 = 1; PORTAbits.RA2 = 1; PORTEbits.RE0 = 1; PORTEbits.RE2 = 1;   
#define DISPOFF PORTAbits.RA5 = 0; PORTAbits.RA2 = 0; PORTEbits.RE0 = 0; PORTEbits.RE2 = 0;   

// defines each segment in each displays
#define A1      PORTD = 0x01; DISP1; Delay1KTCYx(DELAYEF);
#define B1      PORTD = 0x02; DISP1; Delay1KTCYx(DELAYEF);
#define C1      PORTD = 0x04; DISP1; Delay1KTCYx(DELAYEF);
#define D1      PORTD = 0x08; DISP1; Delay1KTCYx(DELAYEF);
#define E1      PORTD = 0x10; DISP1; Delay1KTCYx(DELAYEF);
#define F1      PORTD = 0x20; DISP1; Delay1KTCYx(DELAYEF);
#define G1      PORTD = 0x40; DISP1; Delay1KTCYx(DELAYEF);
#define A2      PORTD = 0x01; DISP2; Delay1KTCYx(DELAYEF);
#define B2      PORTD = 0x02; DISP2; Delay1KTCYx(DELAYEF);
#define C2      PORTD = 0x04; DISP2; Delay1KTCYx(DELAYEF);
#define D2      PORTD = 0x08; DISP2; Delay1KTCYx(DELAYEF);
#define E2      PORTD = 0x10; DISP2; Delay1KTCYx(DELAYEF);
#define F2      PORTD = 0x20; DISP2; Delay1KTCYx(DELAYEF);
#define G2      PORTD = 0x40; DISP2; Delay1KTCYx(DELAYEF);
#define A3      PORTD = 0x01; DISP3; Delay1KTCYx(DELAYEF);
#define B3      PORTD = 0x02; DISP3; Delay1KTCYx(DELAYEF);
#define C3      PORTD = 0x04; DISP3; Delay1KTCYx(DELAYEF);
#define D3      PORTD = 0x08; DISP3; Delay1KTCYx(DELAYEF);
#define E3      PORTD = 0x10; DISP3; Delay1KTCYx(DELAYEF);
#define F3      PORTD = 0x20; DISP3; Delay1KTCYx(DELAYEF);
#define G3      PORTD = 0x40; DISP3; Delay1KTCYx(DELAYEF);
#define A4      PORTD = 0x01; DISP4; Delay1KTCYx(DELAYEF);
#define B4      PORTD = 0x02; DISP4; Delay1KTCYx(DELAYEF);
#define C4      PORTD = 0x04; DISP4; Delay1KTCYx(DELAYEF);
#define D4      PORTD = 0x08; DISP4; Delay1KTCYx(DELAYEF);
#define E4      PORTD = 0x10; DISP4; Delay1KTCYx(DELAYEF);
#define F4      PORTD = 0x20; DISP4; Delay1KTCYx(DELAYEF);
#define G4      PORTD = 0x40; DISP4; Delay1KTCYx(DELAYEF);

// defines alphabet letters based in the 7 segment display
#define LA  0x77
#define LB  0x7c
#define LC  0x39
#define LD  0x5e
#define LE  0x79
#define LF  0x71
#define LG  0x6f
#define LH  0x76
#define LI  0x19
#define LJ  0x1e
#define LK  0x7a
#define LL  0x38
#define LM  0x37
#define LN  0x54
#define LO  0x3f
#define LP  0x73
#define LQ  0x67
#define LR  0x50
#define LS  0x6d
#define LT  0x78
#define LU  0x1c
#define LV  0x3e
#define LW  0x1d
#define LX  0x70
#define LY  0x6e
#define LZ  0x29
#define LSP 0x00

int cont = 0, i = 0, j = 0, k = 0, controle = 0, control_efeito = 0, c = 0;

void decode ( char l ) {
    switch ( l ) {
        case 'A':
            PORTD = LA;    
            break;
        case 'B':
            PORTD = LB;            
            break;
        case 'C':
            PORTD = LC;
            break;
        case 'D':
            PORTD = LD;        
            break;
        case 'E':
            PORTD = LE;        
            break;
        case 'F':
            PORTD = LF;        
            break;
        case 'G':
            PORTD = LG;        
            break;
        case 'H':
            PORTD = LH;        
            break;
        case 'I':
            PORTD = LI;        
            break;
        case 'J':
            PORTD = LJ;
            break;
        case 'K':
            PORTD = LK;        
            break;
        case 'L':
            PORTD = LL;        
            break;
        case 'M':
            PORTD = LM;
            break;
        case 'N':
            PORTD = LN;        
            break;
        case 'O':
            PORTD = LO;        
            break;
        case 'P':
            PORTD = LP;     
            break;   
        case 'Q':
            PORTD = LQ;        
            break;
        case 'R':
            PORTD = LR;
            break;
        case 'S':
            PORTD = LS;
            break;
        case 'T':
            PORTD = LT;
            break;
        case 'U':
            PORTD = LU;        
            break;
        case 'V':
            PORTD = LV;        
            break;
        case 'W':
            PORTD = LW;        
            break;
        case 'X':
            PORTD = LX;
            break;
        case 'Y':
            PORTD = LY;        
            break;
        case 'Z':
            PORTD = LZ;
            break;
        case ' ':
            PORTD = LSP;
            break;
    }   
}

void efeito() {
    for ( k = 0; k < MAXEF; k++ ) {
        D1 D2 D3 D4 C4 G4 G3 G2 G1 F1 A1 A2 A3 A4 B4 G4 G3 G2 G1 E1
        D1 D2 D3 D4 C4 G4 G3 G2 G1 F1 A1 A2 A3 A4 B4 G4 G3 G2 G1 E1
        D1 D2 D3 D4 C4 G4 G3 G2 G1 F1 A1 A2 A3 A4 B4 G4 G3 G2 G1 E1
        D1 D2 D3 D4 C4 G4 G3 G2 G1 F1 A1 A2 A3 A4 B4 G4 G3 G2 G1 E1

        E1 F1 A1 B1 C1 E2 F2 A2 B2 C2 E3 F3 A3 B3 C3 E4 F4 A4 B4 C4
        C4 B4 A4 F4 E4 C3 B3 A3 F3 E3 C2 B2 A2 F2 E2 C1 B1 A1 F1 E1
        E1 F1 A1 B1 C1 E2 F2 A2 B2 C2 E3 F3 A3 B3 C3 E4 F4 A4 B4 C4
        C4 B4 A4 F4 E4 C3 B3 A3 F3 E3 C2 B2 A2 F2 E2 C1 B1 A1 F1 E1

        E1 F1 A1 B1 C1 D1 E1 G1 C1 E2 F2 A2 B2 C2 D2 E2 G2 C2 E3 F3 A3 B3 C3 D3 E3 G3 C3 E4 F4 A4 B4 C4 D4 E4 G4 C4 
        C4 B4 A4 F4 E4 D4 C4 G4 E4 C3 B3 A3 F3 E3 D3 C3 G3 E3 C2 B2 A2 F2 E2 D2 C2 G2 E2 C1 B1 A1 F1 E1 D1 C1 G1 E1
        E1 F1 A1 B1 C1 D1 E1 G1 C1 E2 F2 A2 B2 C2 D2 E2 G2 C2 E3 F3 A3 B3 C3 D3 E3 G3 C3 E4 F4 A4 B4 C4 D4 E4 G4 C4 
        C4 B4 A4 F4 E4 D4 C4 G4 E4 C3 B3 A3 F3 E3 D3 C3 G3 E3 C2 B2 A2 F2 E2 D2 C2 G2 E2 C1 B1 A1 F1 E1 D1 C1 G1 E1
    }
}

void main ( ) {
    
    char nome[] = "LEONAM TEIXEIRA DE VASCONCELOS ";
    
    INTCON2bits.RBPU = 0;
    ADCON1           = 0x0F;    
   
    // display 8 bit pins in PORTD 
    TRISD = 0x00;

    // display activation bit's half in PORTA and half in PORTE
    TRISA = 0x00;
    TRISE = 0x00;

    // button for inverting the direction of the letters passing
    // through the 4 displays is detected by PORTB
    TRISB = 0xFF;
    
    DISPON;
    
    while ( 1 ) {
        if (!PORTBbits.RB0) {
            controle = 0; 
            c = 1;
        }
        if (!PORTBbits.RB1) {
            controle = 1;
            c = 1;
        }
        if ( c ) {
            for ( k = 0; k < REP * 2; k++ ) {
                for ( j = 0; j < 4; j ++ ) {
                    cont = ( cont + 1 ) % 4;
                    if ( cont == 0 ){
                        DISP1             
                        decode ( nome[ i ] );
                    } else if ( cont == 1 ) {
                        DISP2
                        decode ( nome[ ( i + 1 ) % MAX ] );
                    } else if ( cont == 2 ) {
                        DISP3       
                        decode ( nome[ ( i + 2 ) % MAX ] );
                    } else if ( cont == 3 ) {      
                        DISP4
                        decode ( nome[ ( i + 3 ) % MAX ] );
                    }
                    Delay100TCYx(DELAY);    
                }
            }        
            c = 0;
        }
        for ( k = 0; k < REP; k++ ) {
            for ( j = 0; j < 4; j ++ ) {
                cont = ( cont + 1 ) % 4;
                if ( cont == 0 ){
                    DISP1             
                    decode ( nome[ i ] );
                } else if ( cont == 1 ) {
                    DISP2
                    decode ( nome[ ( i + 1 ) % MAX ] );
                } else if ( cont == 2 ) {
                    DISP3       
                    decode ( nome[ ( i + 2 ) % MAX ] );
                } else if ( cont == 3 ) {      
                    DISP4
                    decode ( nome[ ( i + 3 ) % MAX ] );
                }
                Delay100TCYx(DELAY);    
            }
        }        
    }
        
    if ( !controle ) {
        i = ( i + 1 ) % MAX;
    } else {
        i = ( i + ( MAX - 1 ) ) % MAX;
    }
}
