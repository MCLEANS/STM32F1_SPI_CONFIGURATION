#include "stm32f10x.h"

void setup_SPI(){
      RCC->APB2ENR    |= RCC_APB2ENR_IOPAEN;  // enable GPIOA clock
    RCC->APB2ENR    |= RCC_APB2ENR_SPI1EN;  // enable SPI1 clock
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    
    // reset PA4, PA5, PA7 MODE and CNF to 0b00
    GPIOA->CRL &= ~(
                    (GPIO_CRL_MODE4 | GPIO_CRL_CNF4) |
                    (GPIO_CRL_MODE5 | GPIO_CRL_CNF5) |
                    (GPIO_CRL_MODE7 | GPIO_CRL_CNF7)
                    );
    
    // init PA4 NSS  - Mode = 11 (50Mhz) - CNF = 0b00
    GPIOA->CRL |= GPIO_CRL_MODE4;
    
    // init PA5 SCK  - Mode = 11 (50Mhz) - CNF = 0b10 (Alt Function PP)
    GPIOA->CRL |= GPIO_CRL_MODE5 | GPIO_CRL_CNF5_1;
    
    // init PA7 MOSI - Mode = 11 (50Mhz) - CNF = 0b10 (Alt Function PP)
    GPIOA->CRL |= GPIO_CRL_MODE7 | GPIO_CRL_CNF7_1;
    
    GPIOA->BSRR = GPIO_BSRR_BS4;            // set the SS pin high
   
    
    // initialize the SPI configuration register
    SPI1->CR1  |= SPI_CR1_SSM   // software slave management enabled
                | SPI_CR1_SSI   // internal slave select
                | SPI_CR1_MSTR  // SPI master mode
                | SPI_CR1_BR_2
                | SPI_CR1_BIDIMODE
                | SPI_CR1_BIDIOE
                | SPI_CR1_BR_1;// bit rate prescale /32 (72MHz/32 = 2.25MHz)

    SPI1->CR2 |= SPI_CR2_SSOE;
    
    SPI1->CR1  |= SPI_CR1_SPE;  // enable SPI
}

void send_SPI(uint8_t data){

    GPIOA->BSRR = GPIO_BSRR_BR4;        // reset NSS pin
    
    SPI1->DR = data;                    // send data out SPI
    while( !(SPI1->SR & SPI_SR_TXE) );  // wait until transmit buffer empty
    while( SPI1->SR & SPI_SR_BSY );     // wait until SPI not busy
    
    GPIOA->BSRR = GPIO_BSRR_BS4;        // set NSS pin
  
}

int main(){
  


     RCC->APB2ENR    |= RCC_APB2ENR_IOPAEN;  // enable GPIOA clock
    RCC->APB2ENR    |= RCC_APB2ENR_SPI1EN;  // enable SPI1 clock
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

    // reset PA4, PA5, PA7 MODE and CNF to 0b00
    GPIOA->CRL &= ~(
                    (GPIO_CRL_MODE3 | GPIO_CRL_CNF3) |
                    (GPIO_CRL_MODE5 | GPIO_CRL_CNF5) |
                    (GPIO_CRL_MODE7 | GPIO_CRL_CNF7)
                    );
    
    // init PA4 NSS  - Mode = 11 (50Mhz) - CNF = 0b00
    GPIOA->CRL |= GPIO_CRL_MODE3;
    
    // init PA5 SCK  - Mode = 11 (50Mhz) - CNF = 0b10 (Alt Function PP)
    GPIOA->CRL |= GPIO_CRL_MODE5 | GPIO_CRL_CNF5_1;
    
    // init PA7 MOSI - Mode = 11 (50Mhz) - CNF = 0b10 (Alt Function PP)
    GPIOA->CRL |= GPIO_CRL_MODE7 | GPIO_CRL_CNF7_1;
    
    GPIOA->BSRR = GPIO_BSRR_BS3;   
    GPIOA->BSRR = GPIO_BSRR_BS7;   



  SPI1->CR1  |= SPI_CR1_SSM| SPI_CR1_SSI| SPI_CR1_MSTR|SPI_CR1_BR_2|SPI_CR1_BR_1;  

  SPI1->CR2 |= SPI_CR2_SSOE;

  SPI1->CR1  |= SPI_CR1_SPE;  // enable SPI



  
for(volatile int i = 0; i < 2000000;i++){}
  
  
  
        // set NSS pin
  
for(volatile int i = 0; i < 20;i++){
  
 
 
      GPIOA->ODR &= ~GPIO_ODR_ODR3;        // reset NSS pin
     
    SPI1 -> DR  = 0x56;

    while( !(SPI1->SR & SPI_SR_TXE) );  // wait until transmit buffer empty

    GPIOA->ODR |= GPIO_ODR_ODR3;        // set NSS pin


}





  



  while(1){


    


        
  }
}