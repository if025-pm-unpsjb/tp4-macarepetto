/*
 * main.c
 *
 *  Created on: 13 oct. 2022
 *      Author: fep
 */
#include "sapi.h"

#define UART_USED   UART_USB
#define BAUD_RATE   9600
#define BUFFER_SIZE 32

int main(void) {

    boardConfig();
    uartConfig(UART_USED, BAUD_RATE);

    uint8_t bufferEntrada[BUFFER_SIZE];
    uint8_t data;
    uint8_t contador = 0;

    uartWriteString(UART_USED, "ECHO: Listo para recibir. Para terminar ingrese ENTER.\r\n");

    while(true) {

        // 1. Intentar leer un byte.
        if(uartReadByte(UART_USED, &data)) {

            // 2. Si es \r (Retorno de carro) o \n (Nueva línea), lo tratamos como terminador.
            if (data == '\n' || data == '\r') {

                // Si el mensaje tiene contenido
                if (contador > 0) {

                    // 3. Terminar la cadena
                    bufferEntrada[contador] = '\0';

                    // 4. Enviar el mensaje completo
                    uartWriteString(UART_USED, "ECHO: ");
                    uartWriteString(UART_USED, (const char*)bufferEntrada);
                    uartWriteString(UART_USED, "\r\n");
                }

                // 5. Reiniciar el contador para el siguiente mensaje
                contador = 0;

            }
            // 6. Si no es terminador y hay espacio
            else if (contador < (BUFFER_SIZE - 1)) {

                // Almacenar el byte
            	bufferEntrada[contador] = data;
                contador++;
            }
        }
    }
    return 0;
}
