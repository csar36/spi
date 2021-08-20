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

enum SpiPort{
    SpiPort0 = 0,
    SpiPort1 = 1,
};


class spi
{

    public: 
        struct spi_ioc_transfer spi;
        int spi_device = 0;    
        unsigned char spi_mode = SPI_MODE_0;
        uint8_t spi_bitsPerWord = 8;
        uint32_t spi_speed = 500000; 
        uint16_t spi_delay = 0;
    public:

        int SpiOpenPort(spiPort _port);
        int SpiClosePort();
        void setSpiParams(int _spi_device, unsigned char _spi_mode, unsigned char _spi_bitsPerWord, unsigned char _spi_speed);   
        int adjustSpiParams();    
        int SpiWriteRead();

    private: 
        std::string portPath;
        int spi_cs;
        int fd;
        
};