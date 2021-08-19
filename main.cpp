





#if 1
#include <iostream>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>                // Needed for SPI port
#include <sys/ioctl.h>            // Needed for SPI port
#include <linux/spi/spidev.h>     // Needed for SPI port

static const uint8_t     spiBPW   = 8 ;
static const uint16_t    spiDelay = 0 ;
//static const uint8_t     LSBFirst = 1 ;
static const uint32_t    speed = 100000;


int configSPI(int mode)
{
  int fd;
    if ((fd = open ("/dev/spidev0.0", O_RDWR)) < 0)
    {
      printf("Fehler");
    }

  if (ioctl (fd, SPI_IOC_WR_MODE, &mode)            < 0)
    {
      printf("Fehler");
    }
 if (ioctl (fd, SPI_IOC_RD_MODE, &mode)            < 0)
    {
      printf("Fehler");
    }
  
  if (ioctl (fd, SPI_IOC_WR_BITS_PER_WORD, &spiBPW) < 0)
    {
      printf("Fehler");
    }


  if (ioctl (fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed)   < 0)
    {
      printf("Fehler");
    }


  return fd;
}

void spiWR(int fd, unsigned char* TxData, unsigned char* RxData, int len)
{
  struct spi_ioc_transfer spi ;

  memset (&spi, 0, sizeof (spi)) ;

  spi.tx_buf        = (unsigned long)TxData;
  spi.rx_buf        = (unsigned long)RxData;
  spi.len           = len ;
  spi.delay_usecs   = spiDelay ;
  spi.speed_hz      = speed;
  spi.bits_per_word = spiBPW ;
  spi.cs_change     = 0;


  if((ioctl(fd, SPI_IOC_MESSAGE(1), &spi)<0))
  {
    printf("Fehler");
  }
}


#define VersionReg              0x37 << 1  


int main()
{
    int retVel;
    int speed, mode, fd;
    unsigned char TxData[]= {0, 0, 0};
    unsigned char RxData[]= {0, 0, 0};


    //Daten präperierien
    for(int i =0 ;i < 3; i++)
    { 
      TxData[i] = 0xEE;
  

     // printf("Data %d: %u \n",i, TxData[i]);
    }
    //printf("%u \t %u \t \n", TxData[0], TxData[1]);

  
    fd = configSPI(0);
    spiWR(fd, TxData, RxData, 3);
    printf("%u \t %u \t %u \t \n", TxData[0], TxData[1], TxData[2]);
    printf("%u \t %u \t %u \t \n", RxData[0], RxData[1], RxData[2]);

  return 0;
}
#endif