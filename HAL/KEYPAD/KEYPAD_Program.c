/*
 * KEYPAD_Program.c
 *
 *  Created on: Apr 26, 2024
 *      Author: Mahmoud
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "KEYPAD_CONF.h"
#include "KEYPAD_interface.h"

u8 COL_PORT[4]={COL1_PORT,COL2_PORT,COL3_PORT,COL4_PORT};
u8 COL_PIN[4]={COL1_PIN,COL2_PIN,COL3_PIN,COL4_PIN};


u8 ROW_PORT[4]={ROW1_PORT,ROW2_PORT,ROW3_PORT,ROW4_PORT};
u8 ROW_PIN[4]={ROW1_PIN,ROW2_PIN,ROW3_PIN,ROW4_PIN};


u8 key_p[4][4]={
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'c','0','=','+'},


};

void vKEYPAD_init()
{
	vSet_Pin_Direction(COL1_PORT,COL1_PIN,OUTPUT);
	vSet_Pin_Direction(COL2_PORT,COL2_PIN,OUTPUT);
	vSet_Pin_Direction(COL3_PORT,COL3_PIN,OUTPUT);
	vSet_Pin_Direction(COL4_PORT,COL4_PIN,OUTPUT);

	vSet_Pin_Direction(ROW1_PORT,ROW1_PIN,INPUT);
	vSet_Pin_Direction(ROW2_PORT,ROW2_PIN,INPUT);
	vSet_Pin_Direction(ROW3_PORT,ROW3_PIN,INPUT);
	vSet_Pin_Direction(ROW4_PORT,ROW4_PIN,INPUT);


	vSet_Pin_OUTPUTvalue(COL1_PORT,COL1_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(COL2_PORT,COL2_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(COL3_PORT,COL3_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(COL4_PORT,COL4_PIN,HIGH);


	vSet_Pin_OUTPUTvalue(ROW1_PORT,ROW1_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(ROW2_PORT,ROW2_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(ROW3_PORT,ROW3_PIN,HIGH);
	vSet_Pin_OUTPUTvalue(ROW4_PORT,ROW4_PIN,HIGH);


}
u8 u8KEY_PRESSED()
{
	u8 KEY= NO_KEY;
	for(u8 col=0;col<4;col++)
	{
		vSet_Pin_OUTPUTvalue(COL_PORT[col],COL_PIN[col],LOW);
		for(u8 row=0;row<4;row++)
		{
			if(vGIT_PIN(ROW_PORT[row],ROW_PIN[row])==0)
			{
				KEY=key_p[row][col];
			}
			while(vGIT_PIN(ROW_PORT[row],ROW_PIN[row])==0);
		}
		vSet_Pin_OUTPUTvalue(COL_PORT[col],COL_PIN[col],HIGH);
	}
	return KEY;

}
