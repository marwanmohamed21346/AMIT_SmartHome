/*
 * RTOS_PROG.c
 *
 *  Created on: Jun 14, 2024
 *      Author: Mahmoud
 */


#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/TIMERS/TIMER_init.h"
#include "../MCAL/GLOBAL_INTERRUPT/Global_Interrupt_interface.h"
#include "RTOS_CONFG.h"
#include "RTOS_INTERFACE.h"
#include "RTOS_PRAIVET.h"

typedef struct RTOS_TASK
{
	u16 periodecty;
	void(*TASK_func)(void);
	u8 TASK_status;

}TASK_t;

///////////////////3////////
TASK_t SystenTask[NUM_OF_TASK];//{{2000,SPEED},{1000,AIRBAG},{3000,FUNC}}

void START_RTOS()
{

	// init timer
	vTIMER0_INIT();
	//set compare match
	vTIMER0_Compare_OCR0(249);
	//set call back
	vTIMER0_OC_CallBack(&SCHEDULAR);
	//enable GI
	vGlobal_interrupt_Enable();
	// start timer
	vTIMER0_START();
}

void CREATE_TASK_RTOS(u8 priorty , u16 periodicty , void(*ptr_func)(void))
{

	if(ptr_func!=NULLPTR && priorty<=NUM_OF_TASK )
	{
		if(SystenTask[priorty].TASK_func == NULLPTR)
		{
		SystenTask[priorty].periodecty=periodicty;
		SystenTask[priorty].TASK_func=ptr_func;
		SystenTask[priorty].TASK_status=RESUME;
		}

	}


}



void SUSBEND_TASK(u8 perirty)
{
	SystenTask[perirty].TASK_status=SUSBEND;
}

void RESUME_TASK(u8 perirty)
{
	SystenTask[perirty].TASK_status=RESUME;
}

void DELETE_TASK(u8 perirty)
{
	SystenTask[perirty].TASK_func=NULLPTR;
}


static void SCHEDULAR()
{

	volatile static u16 systic_counter =0;
	systic_counter++;//1000->1000ms
	u8 TASK_counter;
	for(TASK_counter=0 ; TASK_counter<NUM_OF_TASK  ; TASK_counter++)
	{
		if(SystenTask[TASK_counter].TASK_status==RESUME)
		{
			if((systic_counter % (SystenTask[TASK_counter].periodecty))==0 )
			{
				if(SystenTask[TASK_counter].TASK_func !=NULLPTR)
				{
					SystenTask[TASK_counter].TASK_func();
				}

			}

		}
	}
}

