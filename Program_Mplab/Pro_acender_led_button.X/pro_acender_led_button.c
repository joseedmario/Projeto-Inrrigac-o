/* 
 * File:   pro_acender_led_button.c
 * Author: JoséEdmário
 * Este projeto tem o objetivo de responder aos requisitos de estagio IFBA solicitado pelo prof. jonas Bomfin de homena
 *
 * Created on 2 de Agosto de 2014, 21:58
 */

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

// PIC 16F877A CONFIGURAÇÃO DOS BITS
#include <xc.h>
#define _XTAL_FREQ 10000000      // Frequencia interna do oscilador 10MHz
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

//programa principal
void main() {
TRISD = 0b00000000; //definindo todos os pinos portD como saida
PORTD = 0b00000000; //zera todos os pinos portD
TRISB = 0b11111111; //definindo todos os pinos portB como entrada

//laço de repetiçao infinito
while (1)
 {
if (PORTBbits.RB1==1) //se botão presionado faça;
  {
    PORTDbits.RD3=1; //manda 5v na portD.RD3 para o led (acenda o led)
    __delay_ms(1000); // agarde 1000ms = 1s
    PORTDbits.RD3=0; // apague o led manda 0v na portD.RD3
     __delay_ms(500); // agarde 500ms = 0.5s
  }
else        //se não, faça;
  {
    PORTDbits.RD3=0; //apague o led
  }

 }

}

