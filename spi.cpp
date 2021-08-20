#include "spi.h"




int SPI::SpiOpenPort(SpiPort port)
{
    (port == SpiPort0) ? (portPath = "/dev/spidev0.0") : (portPath = "/dev/spidev0.1");
    fd = open(portPath.c_str(), O_RDWR);
    (fd < 0) ? (std::cout << "Fehler beim öffnen des Ports" << std::endl);
    return fd;
}


int SPI::SpiClosePort()
{   (close(fd)<0) ? (std::cout << "Fehler beim Schließen des Ports"<<std::endl);
    return fd;
}


void SPI::setSpiParams(uint8_t _spi_mode, uint8_t _spi_bitsPerWord, uint32_t _spi_speed, uint16_t _spi_delay = 0, uint8_t _spi_csChange = 0)    
{
   spi_mode = _spi_mode;
   spi_bitsPerWord=_spi_bitsPerWord;
   spi_speed = _spi_speed;
   spi_delay = _spi_delay;
   spi_csChange = _spi_csChange
}  


int SPI::adjustSpiParams()
{
    if (ioctl (fd, SPI_IOC_WR_MODE, &spi_mode)            < 0)
    {
      std::cout << "Fehler beim Setzen spi_mode" <<std::endl;
    }
    if (ioctl (fd, SPI_IOC_RD_MODE, &spi_mode)            < 0)
    {
      printf("Fehler");
    }
  
    if (ioctl (fd, SPI_IOC_WR_BITS_PER_WORD, &spi_bitsPerWord) < 0)
    {
      printf("Fehler beim Setzen spi_bitsPerWord");
    }


    if (ioctl (fd, SPI_IOC_WR_MAX_SPEED_HZ, &spi_speed)   < 0)
    {
      printf("Fehler beim Setzen spi_speed");
    }
    return fd;

}


int SPI::SpiWriteRead(unsigned char* TxData, unsigned char* RxData, int len)
{

  memset (&spi, 0, sizeof (spi)) ;          

  spi.tx_buf        = (unsigned long)TxData;
  spi.rx_buf        = (unsigned long)RxData;
  spi.len           = len ;
  spi.delay_usecs   = spi_delay ;
  spi.speed_hz      = spi_speed;
  spi.bits_per_word = spi_bitsPerWord ;
  spi.cs_change     = spi_csChange;


  if((ioctl(fd, SPI_IOC_MESSAGE(1), &spi)<0))
  {
    printf("Fehler");
  }

}

