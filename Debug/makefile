################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/I2C/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/EEPROM/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ElectricWaterHeaterProject.lss \

FLASH_IMAGE += \
ElectricWaterHeaterProject.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ElectricWaterHeaterProject.elf secondary-outputs

# Tool invocations
ElectricWaterHeaterProject.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ElectricWaterHeaterProject.map -mmcu=atmega32 -o "ElectricWaterHeaterProject.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ElectricWaterHeaterProject.lss: ElectricWaterHeaterProject.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ElectricWaterHeaterProject.elf  >"ElectricWaterHeaterProject.lss"
	@echo 'Finished building: $@'
	@echo ' '

ElectricWaterHeaterProject.hex: ElectricWaterHeaterProject.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ElectricWaterHeaterProject.elf  "ElectricWaterHeaterProject.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ElectricWaterHeaterProject.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ElectricWaterHeaterProject.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ElectricWaterHeaterProject.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
