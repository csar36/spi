#include <fcntl.h>				//Needed for SPI port
#include <sys/ioctl.h>			//Needed for SPI port
#include <linux/spi/spidev.h>	//Needed for SPI port
#include <unistd.h>			//Needed for SPI port
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstring>
enum spiPort{
    SpiPort0 = 0,
    SpiPort1 = 1,
};


class spi
{

    public:             //public to test; protected within mfrc class
        struct spi_ioc_transfer spi;
        int spi_device = 0;    
        unsigned char spi_mode = SPI_MODE_0;
        unsigned char spi_bitsPerWord = 8;
        unsigned int spi_speed = 500000;


    public:
        int SpiOpenPort(spiPort port);
        int SpiClosePort();
        int setSpiParams();       
        int SpiClosePort();
        int SpiWriteRead();

    private: 
        std::string portPath;
        int spi_cs;
        
};