//20. Diseñar una solución programable de manera tal que las salidas A0 y A1 se activen si B0 está
//activo, las salidas A2 y A3 se activen si B1 está activo, las salidas A4 y A5 se activen si B2
//está activo, las salidas A6 y A7 se activen si B3 está activo.

#include <Arduino.h>
int est[4]={0,0,0,0};
int pinesB[4]={0,1,2,3};
void setup(){
    RCC -> APB2ENR|=RCC_APB2ENR_IOPAEN;
    RCC -> APB2ENR|=RCC_APB2ENR_IOPBEN;
    RCC -> APB2ENR|=RCC_APB2ENR_IOPCEN;
    
    GPIOA -> CRL = 0x11111111; //output MHz push-pull
    /* NO USEN TODO EL PUERTO*/
 // GPIOB -> CRL = 0x00004444; //Floating input
    
    GPIOB -> CRL |= GPIO_CRL_CNF0_0 | ~GPIO_CRL_MODE0;
    GPIOB -> CRL |= GPIO_CRL_CNF1_0 | ~GPIO_CRL_MODE1;
    GPIOB -> CRL |= GPIO_CRL_CNF2_0 | ~GPIO_CRL_MODE2;
    GPIOB -> CRL |= GPIO_CRL_CNF3_0 | ~GPIO_CRL_MODE3;
    
    /*GPIOB-> CRL &= ~(1<<4*pinesB[0])&~(1<<4*pinesB[0]+1) -> MODE
                  |(1<<4*pinesB[0]+2)&~(1<<4*pinesB[0]+3); -> CNF
    */

    /* n:numero del pin - Lo mismo para el mode
    11   GPIO_CRL_CNFn
    10   GPIO_CRL_CNFn_1
    01   GPIO_CRL_CNFn_0
    00  ~GPIO_CRL_CNFn
    
    GPIOx -> CRL |= (1<<4*n)  |(1<<4*n+1)
                 |  (1<<4*n+2)|(1<<4*n+3);
    
    
    */
}
void loop(){
    for(int i=0;i>3;i++){
        est[i] =GPIOB -> IDR&=(pinesB[i]<<0);
    }
//B0
    if(est[0]){
        GPIOA -> BSRR|=GPIO_BSRR_BS0|GPIO_BSRR_BS1;
    }
    else {
        GPIOA -> BSRR|=GPIO_BSRR_BR0|GPIO_BSRR_BR1;
    }
//B1
    if(est[1]){
        GPIOA -> BSRR|=GPIO_BSRR_BS2|GPIO_BSRR_BS3;
    }
    else {
        GPIOA -> BSRR|=GPIO_BSRR_BR2|GPIO_BSRR_BR3;
    }
//B2
    if(est[2]){
        GPIOA -> BSRR|=GPIO_BSRR_BS4|GPIO_BSRR_BS5;
    }
    else {
        GPIOA -> BSRR|=GPIO_BSRR_BR4|GPIO_BSRR_BR5;
    }
//B3
    if(est[3]){
        GPIOA -> BSRR|=GPIO_BSRR_BS6|GPIO_BSRR_BS7;
    }
    else {
        GPIOA -> BSRR|=GPIO_BSRR_BR6|GPIO_BSRR_BR7;
    }
}