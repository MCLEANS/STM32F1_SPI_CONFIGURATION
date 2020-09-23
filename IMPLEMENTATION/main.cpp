#include "stm32f10x.h"


int main(){

  //Enable GPIO,SPI,AFIO RCC clocks.
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
  
  //SET pins PA5 and PA7 to Alternate function push-pull
  GPIOA->CRL &= ~GPIO_CRL_CNF5;
  GPIOA->CRL &= ~GPIO_CRL_MODE5;

  GPIOA->CRL |= GPIO_CRL_MODE5;
  GPIOA->CRL |= GPIO_CRL_CNF5_1;

  GPIOA->CRL &= ~GPIO_CRL_CNF7;
  GPIOA->CRL &= ~GPIO_CRL_MODE7;

  GPIOA->CRL |= GPIO_CRL_MODE7;
  GPIOA->CRL |= GPIO_CRL_CNF7_1;

  GPIOA->CRL &= ~GPIO_CRL_CNF3;
  GPIOA->CRL &= ~GPIO_CRL_MODE3;

  //Set PA4 to general purpose output
  GPIOA->CRL |= GPIO_CRL_MODE3;
  GPIOA->CRL &= ~GPIO_CRL_CNF3;

  //Set PA4 HIGH


  SPI1->CR1  &= ~SPI_CR1_SPE;

  SPI1->CR1 &= ~SPI_CR1_BR;
  SPI1->CR1 |=  SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BIDIOE; 

  SPI1->CR1 &= ~SPI_CR1_CPHA;
  SPI1->CR1 |= SPI_CR1_CPOL;

  SPI1->CR1 &= ~SPI_CR1_DFF;

  SPI1->CR1 |= SPI_CR1_LSBFIRST;


  SPI1->CR1  |= SPI_CR1_SSM | SPI_CR1_SSI; 

  SPI1->CR1 |= SPI_CR1_MSTR;

  SPI1->CR1  |= SPI_CR1_SPE;  // enable SPI 

 
    
  

  while(1){      

    SPI1->CR1  |= SPI_CR1_SPE;  // enable SPI 
    GPIOA->BSRR |= GPIO_BSRR_BR3;        // reset NSS pin
    SPI1->DR = 0b11001010;                    // send data out SPI
    while( !(SPI1->SR & SPI_SR_TXE) );  // wait until transmit buffer is empty
    GPIOA->BSRR |= GPIO_BSRR_BS3;        // set NSS pin


    }
}