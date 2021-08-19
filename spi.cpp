#include "spi.h"




int SPI::SpiOpenPort(spiPort port)
{
    (port == SpiPort0) ? (portPath = "/dev/spidev0.0") : (portPath = "/dev/spidev0.1");
    spi_cs = open(portPath, O_RDWR);
    return spi_cs;
}


int SPI::SpiClosePort()
{


}


int SPI::setSpiParams(int port, int )    
{


}  
int SPI::SpiClosePort()
{


}


int SPI::SpiWriteRead()
{


}

