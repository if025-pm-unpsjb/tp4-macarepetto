#include "mbed.h"

Serial pc(USBTX, USBRX);

PwmOut led1(LED1);
PwmOut led2(LED2);
PwmOut led3(LED3);
PwmOut led4(LED4);

void allOFF() {
    led1.period_ms(500); led2.period_ms(500); led3.period_ms(500); led4.period_ms(500);
    led1 = 0; led2 = 0; led3 = 0; led4 = 0;
}

int main()
{
    pc.printf("Hello World Ejercicio 4!\n");
    while(1)
    {
        char c = pc.getc();
        if (c == '\r' || c == '\n') continue;
        allOFF();
        pc.printf("\nLed solicitado: ");
    	pc.putc(c);
        int n = c - '0';         // '1'..'4' -> 1..4
        switch (n) {
            case 1: led1.period_ms(500);   // periodo total 500 ms
            		led1.write(0.5f);
            		break;
            case 2: led2.period_ms(500);   // periodo total 500 ms
            		led2.write(0.5f);
            		break;
            case 3: led3.period_ms(500);   // periodo total 500 ms
            		led3.write(0.5f);
            		break;
            case 4: led4.period_ms(500);   // periodo total 500 ms
            		led4.write(0.5f);
            		break;
            default:
                pc.printf("\nValor invalido. Use 1..4");
            }
      }
}

