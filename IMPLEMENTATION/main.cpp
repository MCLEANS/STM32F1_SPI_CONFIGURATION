#include "stm32f10x.h"

void setup_SPI(){
  //enable RCC clocks for GPIO and SPI
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

  //Set pins to alternate function push-pull mode {PA5,PA6,PA7}

  GPIOA->CRL &= ~(GPIO_CRL_MODE5);
  GPIOA->CRL &= ~(GPIO_CRL_MODE7);
  GPIOA->CRL |= GPIO_CRL_MODE5;
  GPIOA->CRL |= GPIO_CRL_MODE7;

  GPIOA->CRL &= ~(GPIO_CRL_CNF5);
  GPIOA->CRL &= ~(GPIO_CRL_CNF7);
  GPIOA->CRL |= GPIO_CRL_CNF5_1;
  GPIOA->CRL |= GPIO_CRL_CNF7_1;


  //SPI1->CR1 = 0x31C;
  //SPI1->CR2 = 0;
  //SPI1->CR1 |= 0x40;
  


  //configure SPI
  //set half-duplex unidirectional mode.
  SPI1->CR1 &=  ~SPI_CR1_BIDIMODE;
  SPI1->CR1 |= SPI_CR1_BIDIOE;
  //configure to master
  SPI1->CR1 |= SPI_CR1_MSTR;

  SPI1->CR1 |= SPI_CR1_SSI;
  //Select 8 bit data frame
  SPI1->CR1 &= ~SPI_CR1_DFF;
  //Enable software slave management
  SPI1->CR1 |= SPI_CR1_SSM;
  //Set most significant bit first
  SPI1->CR1 &= ~(SPI_CR1_LSBFIRST);
  //SET clock division factor(4 in this case)(36/4);
  SPI1->CR1 |= SPI_CR1_BR_2;
  //SET clock phase and polarity
  SPI1->CR1 &= ~(SPI_CR1_CPOL);
  SPI1->CR1 &= ~(SPI_CR1_CPHA);
  //Slave select output enable
  SPI1->CR2 |= SPI_CR2_SSOE;
  //Enable the SPI
  SPI1->CR1 |=  SPI_CR1_SPE;
  

}

void send_SPI(uint8_t data){

      GPIOA->BSRR = GPIO_BSRR_BR4;        // reset NSS pin
    
    SPI1->DR = data;                    // send data out SPI
    while( !(SPI1->SR & SPI_SR_TXE) );  // wait until transmit buffer empty
    while( SPI1->SR & SPI_SR_BSY );     // wait until SPI not busy
    
    GPIOA->BSRR = GPIO_BSRR_BS4;    
 /*
  SPI1->DR = data;
   while(!(SPI1->SR & SPI_SR_TXE)){} */
  
}

int main(){
  setup_SPI();
  send_SPI('U');
 


  while(1){

  }
}