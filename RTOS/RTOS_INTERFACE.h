/*
 * RTOS_INTERFACE.h
 *
 *  Created on: Jun 14, 2024
 *      Author: Mahmoud
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_

void START_RTOS();

void CREATE_TASK_RTOS(u8 priorty , u16 periodicty , void(*ptr_func)(void));


void SUSBEND_TASK(u8 perirty);

void RESUME_TASK(u8 perirty);


void DELETE_TASK(u8 perirty);


#endif /* RTOS_RTOS_INTERFACE_H_ */
