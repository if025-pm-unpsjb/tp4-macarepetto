#include "mbed.h"


PwmOut led1(LED1);
PwmOut led2(LED2);
PwmOut led3(LED3);
PwmOut led4(LED4);

int main()
{
    while(1)
    {
   	    // specify period first
    	led1.write(0.10f);      // 50% duty cycle, relative to period
    	wait(1);
    	led1 = 0;
    	wait(1);
    	led2.write(0.30f);      // 50% duty cycle, relative to period
    	wait(1);
    	led2 = 0;
    	wait(1);
    	led3.write(0.60f);      // 50% duty cycle, relative to period
    	wait(1);
    	led3 = 0;
    	wait(1);
    	led4.write(1.0f);
    	wait(1);
    	led4 = 0;
    	wait(1);


    }
}
