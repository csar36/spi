#include "spi.h"



int main()
{
  unsigned char TxData [] = {0xEE, 0xEE};
  unsigned char RxData [] ={0,0};

  spi test;
  test.SpiOpenPort(SpiPort0);
  test.setSpiParams(SPI_MODE_0, 8, 500000);
  test.adjustSpiParams();
  test.SpiWriteRead(TxData, RxData, 2);
  std::cout << static_cast<int> RxData[0] << std::endl << static_cast<int> RxData[1] << std::endl;
  


}
