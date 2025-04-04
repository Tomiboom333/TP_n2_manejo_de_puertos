//7. Diseñar una solución programable de manera tal que en el Puerto A se obtenga 
//el resultado de la operación or entre el Puerto B y el literal 0x23.

#include <Arduino.h>

void setup(){
    RCC -> APB2ENR|=RCC_APB2ENR_IOPAEN;
    RCC -> APB2ENR|=RCC_APB2ENR_IOPBEN;

    GPIOA -> CRL = 0x11111111; //output MHz push-pull
    GPIOA -> CRH = 0x11111111;
    
    GPIOB -> CRL = 0x44444444; //Floating input
    GPIOB -> CRH = 0x44444444;
}
void loop(){
    uint16_t est =GPIOB -> IDR;
    est = est | 0x23;
    GPIOA -> BSRR = est;
}