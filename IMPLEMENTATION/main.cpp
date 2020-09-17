#include "stm32f10x.h"

void setup_SPI(){
  //Turn on the RCC clocks GPIO and SPI
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

  //SET GPIO PINS TO ALTERNATE FUNCION (PA5,PA6,PA7)
  

}

int main(void) {


  while(1){

  }
}
