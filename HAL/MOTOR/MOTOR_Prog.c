/*
 * MOTOR_Prog.c
 *
 *  Created on: May 17, 2024
 *      Author: Mahmoud
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMERS/TIMER_init.h"
#include "../../MCAL/TIMERS/TIMER_praivat.h"
#include "MOTOR_CONF.h"
#include "MOTOR_init.h"

void Start_motor(u8 motorID, u8 Direction)
{
	switch(motorID)
	{
	case MOTOR_A:
		if(Direction==DIRECTION_CW)
		{
			/****************************PIN DIRECTION***************/
			vSet_Pin_Direction(MOTOR_A_PORT_NEGATIVE,MOTOR_A_PIN_NEGATIVE,OUTPUT);
			vSet_Pin_Direction(MOTOR_A_PORT_PSTIVE,MOTOR_A_PIN_PSTIVE,OUTPUT);
			vSet_Pin_Direction(MOTOR_A_PORT_ENABLE,MOTOR_A_PIN_ENABLE,OUTPUT);
			/****************************PIN VALUE***************/
			vSet_Pin_OUTPUTvalue(MOTOR_A_PORT_NEGATIVE,MOTOR_A_PIN_NEGATIVE,LOW);
			vSet_Pin_OUTPUTvalue(MOTOR_A_PORT_PSTIVE,MOTOR_A_PIN_PSTIVE,HIGH);
			vSet_Pin_OUTPUTvalue(MOTOR_A_PORT_ENABLE,MOTOR_A_PIN_ENABLE,HIGH);

		}
		else if (Direction==DIRECTION_CCW)
		{
			/****************************PIN DIRECTION***************/
			vSet_Pin_Direction(MOTOR_A_PORT_NEGATIVE,MOTOR_A_PIN_NEGATIVE,OUTPUT);
			vSet_Pin_Direction(MOTOR_A_PORT_PSTIVE,MOTOR_A_PIN_PSTIVE,OUTPUT);
			vSet_Pin_Direction(MOTOR_A_PORT_ENABLE,MOTOR_A_PIN_ENABLE,OUTPUT);
			/****************************PIN VALUE***************/
			vSet_Pin_OUTPUTvalue(MOTOR_A_PORT_NEGATIVE,MOTOR_A_PIN_NEGATIVE,HIGH);
			vSet_Pin_OUTPUTvalue(MOTOR_A_PORT_PSTIVE,MOTOR_A_PIN_PSTIVE,LOW);
			vSet_Pin_OUTPUTvalue(MOTOR_A_PORT_ENABLE,MOTOR_A_PIN_ENABLE,HIGH);

		}
		break;
	case MOTOR_B:
		if(Direction==DIRECTION_CW)
		{
			/****************************PIN DIRECTION***************/
			vSet_Pin_Direction(MOTOR_B_PORT_NEGATIVE,MOTOR_B_PIN_NEGATIVE,OUTPUT);
			vSet_Pin_Direction(MOTOR_B_PORT_PSTIVE,MOTOR_B_PIN_PSTIVE,OUTPUT);
			vSet_Pin_Direction(MOTOR_B_PORT_ENABLE,MOTOR_B_PIN_ENABLE,OUTPUT);
			/****************************PIN VALUE***************/
			vSet_Pin_OUTPUTvalue(MOTOR_B_PORT_NEGATIVE,MOTOR_B_PIN_NEGATIVE,LOW);
			vSet_Pin_OUTPUTvalue(MOTOR_B_PORT_PSTIVE,MOTOR_B_PIN_PSTIVE,HIGH);
			vSet_Pin_OUTPUTvalue(MOTOR_B_PORT_ENABLE,MOTOR_B_PIN_ENABLE,HIGH);

		}
		else if (Direction==DIRECTION_CCW)
		{
			/****************************PIN DIRECTION***************/
			vSet_Pin_Direction(MOTOR_B_PORT_NEGATIVE,MOTOR_B_PIN_NEGATIVE,OUTPUT);
			vSet_Pin_Direction(MOTOR_B_PORT_PSTIVE,MOTOR_B_PIN_PSTIVE,OUTPUT);
			vSet_Pin_Direction(MOTOR_B_PORT_ENABLE,MOTOR_B_PIN_ENABLE,OUTPUT);
			/****************************PIN VALUE***************/
			vSet_Pin_OUTPUTvalue(MOTOR_B_PORT_NEGATIVE,MOTOR_B_PIN_NEGATIVE,HIGH);
			vSet_Pin_OUTPUTvalue(MOTOR_B_PORT_PSTIVE,MOTOR_B_PIN_PSTIVE,LOW);
			vSet_Pin_OUTPUTvalue(MOTOR_B_PORT_ENABLE,MOTOR_B_PIN_ENABLE,HIGH);


		}

		break;

	}
}
void STop_motor(u8 motorID)
{

	switch(motorID)
	{
	case MOTOR_A:

		/****************************PIN DIRECTION***************/
		vSet_Pin_Direction(MOTOR_A_PORT_NEGATIVE,MOTOR_A_PIN_NEGATIVE,OUTPUT);
		vSet_Pin_Direction(MOTOR_A_PORT_PSTIVE,MOTOR_A_PIN_PSTIVE,OUTPUT);
		vSet_Pin_Direction(MOTOR_A_PORT_ENABLE,MOTOR_A_PIN_ENABLE,OUTPUT);
		/****************************PIN VALUE***************/
		vSet_Pin_OUTPUTvalue(MOTOR_A_PORT_NEGATIVE,MOTOR_A_PIN_NEGATIVE,LOW);
		vSet_Pin_OUTPUTvalue(MOTOR_A_PORT_PSTIVE,MOTOR_A_PIN_PSTIVE,LOW);
		vSet_Pin_OUTPUTvalue(MOTOR_A_PORT_ENABLE,MOTOR_A_PIN_ENABLE,LOW);

		break;
	case MOTOR_B:

		/****************************PIN DIRECTION***************/
		vSet_Pin_Direction(MOTOR_B_PORT_NEGATIVE,MOTOR_B_PIN_NEGATIVE,OUTPUT);
		vSet_Pin_Direction(MOTOR_B_PORT_PSTIVE,MOTOR_B_PIN_PSTIVE,OUTPUT);
		vSet_Pin_Direction(MOTOR_B_PORT_ENABLE,MOTOR_B_PIN_ENABLE,OUTPUT);
		/****************************PIN VALUE***************/
		vSet_Pin_OUTPUTvalue(MOTOR_B_PORT_NEGATIVE,MOTOR_B_PIN_NEGATIVE,LOW);
		vSet_Pin_OUTPUTvalue(MOTOR_B_PORT_PSTIVE,MOTOR_B_PIN_PSTIVE,LOW);
		vSet_Pin_OUTPUTvalue(MOTOR_B_PORT_ENABLE,MOTOR_B_PIN_ENABLE,LOW);
		break;


	}
}
void speed_control (u8 motorID,u8 Direction , u8 duty_cycle)
{
    // you complet this code
}
