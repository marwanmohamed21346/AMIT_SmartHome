/*
 * UART_conf.h
 *
 *  Created on: May 24, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_UART_UART_CONF_H_
#define MCAL_UART_UART_CONF_H_


#define BOUD_RATE   103

//////////////////////////////////////

#define SET_2DS      0
#define NOT_SET_2DS  1

#define SPEED_MODE  NOT_SET_2DS

/////////////////////////////////////////////

#define DISSABLE_PARITY  0
#define EVEN_PARITY      1
#define ODD_PARITY       2

#define PARITY_MODE      DISSABLE_PARITY

///////////////////////////////////////////
#define ONE_STOP        0
#define TWO_STOP        1

#define SELECT_STOP    ONE_STOP
///////////////////////////////////////////
#define BIT_5            0
#define BIT_6            1
#define BIT_7            2
#define BIT_8            3
#define BIT_9            4

#define SELECT_NUM_BIT   BIT_8
/////////////////////////////////////////////


#endif /* MCAL_UART_UART_CONF_H_ */
