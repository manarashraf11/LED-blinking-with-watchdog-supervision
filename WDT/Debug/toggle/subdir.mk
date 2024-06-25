################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../toggle/toggle.c 

OBJS += \
./toggle/toggle.o 

C_DEPS += \
./toggle/toggle.d 


# Each subdirectory must supply rules for building sources it contributes
toggle/%.o: ../toggle/%.c toggle/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\20114\Downloads\final_project\final_project\WDGM" -I"C:\Users\20114\Downloads\final_project\final_project\WDGDRV" -I"C:\Users\20114\Downloads\final_project\final_project\toggle" -I"C:\Users\20114\Downloads\final_project\final_project\timer" -I"C:\Users\20114\Downloads\final_project\final_project\Lib" -I"C:\Users\20114\Downloads\final_project\final_project\LED" -I"C:\Users\20114\Downloads\final_project\final_project\GPIO" -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


