#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main()
{
    while(1)
    {
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
    	        wait(1);
    	}
    }
}
