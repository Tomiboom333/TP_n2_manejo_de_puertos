//16. Diseñar una solución programable de manera tal que las salidas A0,A2, A4 y A6 se activen 
//si B0 está activo; y las salidas A1, A3,A5 y A7 se activen si B0 está inactivo.

#include <Arduino.h>

void setup(){
    RCC -> APB2ENR|=RCC_APB2ENR_IOPAEN;
    RCC -> APB2ENR|=RCC_APB2ENR_IOPBEN;

    GPIOA -> CRL = 0x11111111; //output MHz push-pull

    GPIOB -> CRL |= GPIO_CRL_CNF0_0 | ~GPIO_CRL_MODE0; //Floating input
}
void loop(){
    uint16_t est =GPIOB -> IDR&=(1<<0);
    if(est){
        GPIOA -> BSRR|=GPIO_BSRR_BS0|GPIO_BSRR_BS2
                     |GPIO_BSRR_BS4|GPIO_BSRR_BS6
                     |GPIO_BSRR_BR1|GPIO_BSRR_BR3
                     |GPIO_BSRR_BR5|GPIO_BSRR_BR7;
    }
    else {
        GPIOA -> BSRR|=GPIO_BSRR_BS1|GPIO_BSRR_BS3
                     |GPIO_BSRR_BS5|GPIO_BSRR_BS7
                     |GPIO_BSRR_BR0|GPIO_BSRR_BR2
                     |GPIO_BSRR_BR4|GPIO_BSRR_BR6;
    }
}