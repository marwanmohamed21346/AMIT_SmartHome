################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/External_Interrupt/External_Interrupt_Prog.c 

OBJS += \
./MCAL/External_Interrupt/External_Interrupt_Prog.o 

C_DEPS += \
./MCAL/External_Interrupt/External_Interrupt_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/External_Interrupt/%.o: ../MCAL/External_Interrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


