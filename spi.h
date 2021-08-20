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
#include <iostream>
enum SpiPort{
    SpiPort0 = 0,
    SpiPort1 = 1,
};


class spi
{

    public: 
        struct spi_ioc_transfer spi;
        uint8_t spi_mode = SPI_MODE_0;
        uint8_t spi_bitsPerWord = 8;
        uint32_t spi_speed = 500000; 
        uint16_t spi_delay = 0;
        uint8_t spi_csChange = 0;
    public:

        int SpiOpenPort(spiPort _port);
        int SpiClosePort();
        void setSpiParams(uint8_t _spi_mode, uint8_t _spi_bitsPerWord, uint32_t _spi_speed, uint16_t _spi_delay, uint8_t spi_csChange);   
        int adjustSpiParams();    
        int SpiWriteRead(unsigned char* TxData, unsigned char* RxData, int len);

    private: 
        std::string portPath;
        int spi_cs;
        int fd;
        
};