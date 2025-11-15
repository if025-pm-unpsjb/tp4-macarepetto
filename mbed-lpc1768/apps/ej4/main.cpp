#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main()
{
    pc.printf("Hello World Ejercicio 4!\n");
    while(1)
    {
        char c = pc.getc();
        if (c == '\r' || c == '\n') continue;
        led1 = 0;
        led2 = 0;
        led3 = 0;
        led4 = 0;
        pc.printf("\nLed solicitado: ");
    	pc.putc(c);
        int n = c - '0';         // '1'..'4' -> 1..4
        switch (n) {
            case 1: led1 = 1; break;
            case 2: led2 = 1; break;
            case 3: led3 = 1; break;
            case 4: led4 = 1; break;
            default:
                pc.printf("Valor invalido. Use 1..4\n");
            }
      }
}

