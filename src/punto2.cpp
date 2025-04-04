//2. Diseñar una solución programable de manera tal que en
//el Puerto A se visualice el complemento a 1 del Puerto B.

#include <Arduino.h>

void setup(){
    RCC -> APB2ENR|=RCC_APB2ENR_IOPAEN;
    RCC -> APB2ENR|=RCC_APB2ENR_IOPBEN;

    GPIOA -> CRL = 0x44444444;
    GPIOA -> CRH = 0x44444444;

    GPIOB -> CRL = 0x11111111;
    GPIOB -> CRH = 0x11111111;
}
void loop(){
    uint16_t est =GPIOB -> IDR;
    est = ~est;
    GPIOA -> BSRR = est;
}

