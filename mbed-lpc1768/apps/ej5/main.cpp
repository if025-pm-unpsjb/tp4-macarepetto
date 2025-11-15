#include "mbed.h"
#include <ctype.h>

Serial pc(USBTX, USBRX);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main()
{
    while(1)
    {
        char buf[16] = {0};
        int i = 0;
        pc.printf("\nIngrese milisegundos y presione Enter: ");
        while (i < 15) {
            char c = pc.getc();
            if (c == '\r' || c == '\n') break;
            if (isdigit((unsigned char)c)) {
                buf[i++] = c;
                pc.putc(c);
            }
        }
        int ms = atoi(buf);
        pc.printf("\nSe ingresó: %d ms...\n", ms);

    	for(int i = 0; i < 16; i++){
    		int index = 0;
            int binario[4] = {0, 0, 0, 0};
    	    int decimal = i;
    	    while (decimal > 0 && index < 4) {
    	        binario[index] = decimal % 2;
    	        decimal /= 2;
    	        index++;
    	    }
    	        led1 = binario[0];
    	        led2 = binario[1];
    	        led3 = binario[2];
    	        led4 = binario[3];
    	        wait_ms(ms);
    	}
    }
}
