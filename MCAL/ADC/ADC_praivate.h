/*
 * ADC_praivate.h
 *
 *  Created on: May 4, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_ADC_ADC_PRAIVATE_H_
#define MCAL_ADC_ADC_PRAIVATE_H_



#define ADMUX   	*((volatile u8*)(0x27)) 	// ADC Multiplexer Register
#define ADCSRA  	*((volatile u8*)(0x26)) 	// ADC Control And Status Register
#define ADCH	    *((volatile u8*)(0x25))		// ADC High Register
#define ADCL 	    *((volatile u8*)(0x24)) 		// ADC Low Register
#define SFIOR	    *((volatile u8*))0x50)) 		// ADC Low Register
#define ADC_Reg     *((volatile u16*)0x24) 		// ADC all Register

#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0

#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

#define ACME 3
#define PUD 2
#define PSR2 1
#define PSR10 0


#endif /* MCAL_ADC_ADC_PRAIVATE_H_ */
