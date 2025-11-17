/*
 * main.c
 *
 *  Created on: 13 oct. 2022
 *      Author: fep
 */

#include "app.h"         // <= Su propia cabecera (opcional)
#include "../../example/inc/app.h"         // <= Su propia cabecera (opcional)

#include "sapi.h"        // <= Biblioteca sAPI
#define CIAA_BOARD_LEDR      LEDR
#define CIAA_BOARD_LEDG      LEDG
#define CIAA_BOARD_LEDB      LEDB
#define CIAA_BOARD_LED1      LED1
#define CIAA_BOARD_LED2      LED2
#define CIAA_BOARD_LED3      LED3
#define CIAA_BOARD_BUTTON1    TEC1
#define CIAA_BOARD_BUTTON2    TEC2
#define CIAA_BOARD_BUTTON3    TEC3
#define CIAA_BOARD_BUTTON4    TEC4

bool_t buttonPrevValue1 = ON;
bool_t buttonPrevValue2 = ON;
bool_t buttonPrevValue3 = ON;
bool_t buttonPrevValue4 = ON;

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main( void )
{
   // ---------- CONFIGURACIONES ------------------------------

   // Inicializar y configurar la plataforma
   boardConfig();
   uartConfig(UART_USB, 9600);
   uartWriteString(UART_USB, "Control RGB activo: El botón 1 encender el LEDRGB, el 2 el R, el 3 el G y el 4 el B.\r\n");

   // Crear varias variables del tipo booleano
   bool_t buttonValue1 = OFF;
   bool_t buttonValue2 = OFF;
   bool_t buttonValue3 = OFF;
   bool_t buttonValue4 = OFF;

   bool_t ledValueR    = OFF;
   bool_t ledValueG    = OFF;
   bool_t ledValueB    = OFF;

   // Crear variable del tipo tick_t para contar tiempo
   tick_t timeCount   = 0;

   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {

       // 1. LECTURA DE BOTONES
       buttonValue1 = gpioRead( CIAA_BOARD_BUTTON1 );
       buttonValue2 = gpioRead( CIAA_BOARD_BUTTON2 );
       buttonValue3 = gpioRead( CIAA_BOARD_BUTTON3 );
       buttonValue4 = gpioRead( CIAA_BOARD_BUTTON4 );

       // 2. INVERSIÓN DE LÓGICA
       // Se invierte porque gpioRead() devuelve 0/OFF (presionado) o 1/ON (liberado).
       // Queremos que el valor sea 1/ON cuando está presionado.
       if (buttonPrevValue1 == ON && buttonValue1 == OFF) {
    	   ledValueR = !ledValueR;
    	   ledValueG = !ledValueG;
    	   ledValueB = !ledValueB;
           uartWriteString(UART_USB, "Boton 1 presionado. LEDRGB: ");
           gpioWrite( CIAA_BOARD_LEDR, ledValueR );
           gpioWrite( CIAA_BOARD_LEDG, ledValueG );
           gpioWrite( CIAA_BOARD_LEDB, ledValueB );
           if (ledValueB && ledValueR && ledValueG) {
                 uartWriteString(UART_USB, "ON\r\n");
             } else {
                 uartWriteString(UART_USB, "OFF\r\n");
             }
       }
	   buttonPrevValue1 = buttonValue1;

       if (buttonPrevValue2 == ON && buttonValue2 == OFF) {
    	   ledValueR = !ledValueR;
           uartWriteString(UART_USB, "Boton 2 presionado. LEDR: ");
           gpioWrite( CIAA_BOARD_LEDR, ledValueR );
           if (ledValueR) {
                 uartWriteString(UART_USB, "ON\r\n");
             } else {
                 uartWriteString(UART_USB, "OFF\r\n");
             }
       }
	   buttonPrevValue2 = buttonValue2;

       if (buttonPrevValue3 == ON && buttonValue3 == OFF) {
    	   ledValueG = !ledValueG;
           uartWriteString(UART_USB, "Boton 3 presionado. LEDG: ");
           gpioWrite( CIAA_BOARD_LEDG, ledValueG );
           if (ledValueG) {
                 uartWriteString(UART_USB, "ON\r\n");
             } else {
                 uartWriteString(UART_USB, "OFF\r\n");
             }
       }
	   buttonPrevValue3 = buttonValue3;

       if (buttonPrevValue4 == ON && buttonValue4 == OFF) {
    	   ledValueB = !ledValueB;
           uartWriteString(UART_USB, "Boton 4 presionado. LEDB: ");
           gpioWrite( CIAA_BOARD_LEDB, ledValueB );
           if (ledValueB) {
                 uartWriteString(UART_USB, "ON\r\n");
             } else {
                 uartWriteString(UART_USB, "OFF\r\n");
             }
       }
	   buttonPrevValue4 = buttonValue4;
    }

    return 0;
 }
