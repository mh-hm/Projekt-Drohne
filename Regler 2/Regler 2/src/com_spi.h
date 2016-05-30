/*
 * com_spi.h
 *
 * Created: 30.05.2016 11:26:51
 *  Author: martin
 */ 


#ifndef COM_SPI_H_
#define COM_SPI_H_



spi_status_t com_spi_init(void);

void com_spi_txrd_int_handler(void);



#endif /* COM_SPI_H_ */