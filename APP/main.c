/*
 * main.c
 *
 *  Created on: Apr 6, 2024
 *      Author: Mahmoud
 *      APP LAYER MAIN.C
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/External_Interrupt/External_Interrupt_Interface.h"
#include "../MCAL/GLOBAL_INTERRUPT/Global_Interrupt_interface.h"
#include "../MCAL/ADC/ADC_init.h"
#include "../MCAL/DIO/DIO_CONF.h"
#include "../MCAL/TIMERS/TIMER_init.h"
#include "../MCAL/TIMERS/TIMER_confg.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LCD/LCD_Confg.h"
#include "../HAL/EEPROM/EEPROM_init.h"
#include "../MCAL/UART/UART_int.h"
#include "../MCAL/SPI/SPI_init.h"
#include "../MCAL/SPI/SPI_conf.h"
#include "../MCAL/SPI/SPI_praivat.h"
#include "../MCAL/TWI/TWI_init.h"
#include "../RTOS/RTOS_INTERFACE.h"
#include "../MCAL/WDT/WDT.h"


#include "../HAL/KEYPAD/KEYPAD_CONF.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"
#include <util/delay.h>
#include <avr/io.h>


void AIRBAG (void)
{
	vTOGGLE_Pin(PORT_A,PIN_0);//
}
void speed (void)
{

	vTOGGLE_Pin(PORT_A,PIN_1);
	SUSBEND_TASK(0);
	}


void light (void)
{
	vTOGGLE_Pin(PORT_A,PIN_2);
	RESUME_TASK(0);
}


void func (void)
{
	vTOGGLE_Pin(PORT_A,PIN_2);
	RESUME_TASK(0);
}
//MASTER
int main()
{
	vSet_Pin_Direction(PORT_A,PIN_0,OUTPUT);
	vSet_Pin_Direction(PORT_A,PIN_1,OUTPUT);
	vSet_Pin_Direction(PORT_A,PIN_2,OUTPUT);
	vSet_Pin_OUTPUTvalue(PORT_A,PIN_3,OUTPUT);

	CREATE_TASK_RTOS(0,1000,&AIRBAG);
	CREATE_TASK_RTOS(1,4000,&speed);
	CREATE_TASK_RTOS(2,8000,&light);

	DELETE_TASK(2);
	CREATE_TASK_RTOS(2,8000,&func);

	START_RTOS();




	while(1)
	{




	}

}



/*
 *
 *
 *SET_BIT(TCCR1A,7);
	CLEAR_BIT(TCCR1A,6);
	CLEAR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

	OCRA1=374;
	ICU11=4999;
 *
 * void servo(s8 angle)
{
	if(angle<0)
	{
	angle=angle*-1;
	u16 ton= (u16)1500 - (((u16)500* angle)/90);
		OCRA1=(ton/4)-1;
	}
	else if(angle>0)
		{

		u16 ton= (u16)1500 + (((u16)500* angle)/90);
			OCRA1=(ton/4)-1;
		}
	else if(angle==0)
	{
		OCRA1=373;
	}

}
 *
 */

/*
 *
 *
 *creat_task(0,15000,&task1);
	creat_task(1,2000,&task2);
	creat_task(2,3000,&task3);
	startsch();
 *#define sus 1
#define res 2
typedef struct task
{
	u16 periodecty;
	void (*taskFunc)(void);
	int status ;

}task_t;

task_t array[3];

void creat_task(u8 periorty , u16 periodecty , void (*Func)(void))
{

		array[periorty].periodecty=periodecty;
		array[periorty].taskFunc=Func;
		array[periorty].status=res;

}

void scedular(void)
{
	static u16 c=0;
	c++;
	for(u8 i=0;i<3;i++)
	{
		if(array[i].status==res)
		{
		if(c%(array[i].periodecty)==0)
		{
			array[i].taskFunc();
		}
		}
	}
}

void susb(int per)
{
	array[per].status=sus;
}

void resu(int per)
{
	array[per].status=res;
}

void task1()
{



	vTOGGLE_Pin(PORT_A,PIN_0);
}

void task2()
{



	vTOGGLE_Pin(PORT_A,PIN_1);
	//resu(0);
}

void task3()
{



	vTOGGLE_Pin(PORT_A,PIN_2);
	//susb(0);
}

void startsch()
{
	vGlobal_interrupt_Enable();
		vTIMER0_INIT();
		vTIMER0_Compare_OCR0(249);
		vTIMER0_OC_CallBack(&scedular);
		vTIMER0_START();
}

 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
static u16 t1,t2,t3,flag=0;
void func(void)
{
    if(flag==0)
    {
    	t1=ICR1;
    	Timer1_InputCaptureEdge(FALLING);
    	flag=1;
    }
    else if(flag==1)
    {
    	t2=ICR1;
    	Timer1_InputCaptureEdge(RISING);
    	flag=2;
    }
    else  if (flag==2)
    {
    	t3=ICR1;
    	Timer1_ICU_InterruptDisable();
    	flag=3;
    }
    _delay_us(10);
}
void pwm_measure(u32 *freq,u8 *duty)
{
	u16 TON , TOFF;
	Timer1_ICU_SetCallBack(func);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	flag=0;
	while(flag<3);

	TON=t2-t1;
	TOFF=t3-t2;
 *duty= ((u32)TON*100)/(u32)(TON+TOFF);
 *freq= (u32)1000000/(u32)(TON+TOFF);


 *
 *
 *
 *
 */





















/*
int main()
{


	DDRC=0b00000011;

	DDRD=0xff;

	u8 i=0,j=0;


	PORTD=~ssd_array[0];
	PORTC=0b00000011;


	while(1)
	{

for(i=0;i<10;i++)
{
		PORTC=0b0000001;
		PORTD=~ssd_array[i];
		_delay_ms(4);
		PORTC=0b00000010;
		PORTD = ~ssd_array[j];
		_delay_ms(3);
		if(i==9)
		{
			j++;
		}
		if(j==10)
		{
			j=0;
		}
}

			PORTC=0b00000010;
			i=0;
			j++;
			PORTD = ~ssd_array[j];
			//_delay_ms(1);





		}


	}

 */


