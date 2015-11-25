################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/spiffs/subdir.mk
-include arduino/core/subdir.mk
-include Libraries/ESP8266mDNS/subdir.mk
-include Libraries/ESP8266WiFi/src/subdir.mk
-include Libraries/ESP8266WebServer/src/subdir.mk
-include Libraries/EEPROM/subdir.mk
-include Libraries/ArduinoJson/src/Internals/subdir.mk
-include Libraries/ArduinoJson/src/Arduino/subdir.mk
-include Libraries/ArduinoJson/src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
arduino.ar \

ELF += \
esp8266_common.elf \

EEP += \
esp8266_common.eep \

FLASH_IMAGE += \
esp8266_common.bin \


# All Target
all: esp8266_common

# Tool invocations
esp8266_common: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/sudiv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-size" -A "/media/common/Projects/arduino165/esp8266_common/Release/esp8266_common.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/sudiv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-ar" cru  "/media/common/Projects/arduino165/esp8266_common/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

esp8266_common.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/sudiv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-gcc" -g -Os -nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static "-L/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//lib" "-L/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//ld" "-Teagle.flash.1m64.ld" -Wl,-wrap,system_restart_local -Wl,-wrap,register_chipv6_phy  -o "/media/common/Projects/arduino165/esp8266_common/Release/esp8266_common.elf" -Wl,--start-group   $(LINK_OBJ) $(AR)  "/media/common/Projects/arduino165/esp8266_common/Release/arduino.ar" -lm -lgcc -lhal -lphy -lnet80211 -llwip -lwpa -lmain -lpp -lsmartconfig -lwps -lcrypto -Wl,--end-group  "-L/media/common/Projects/arduino165/esp8266_common/Release"
	@echo 'Finished building: $@'
	@echo ' '

esp8266_common.eep: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

esp8266_common.bin: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/sudiv/.arduino15/packages/esp8266/tools/esptool/0.4.5/esptool" -eo "/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/bootloaders/eboot/eboot.elf" -bo "/media/common/Projects/arduino165/esp8266_common/Release/esp8266_common.bin" -bm qio -bf 40 -bz 1M -bs .text -bp 4096 -ec -eo "/media/common/Projects/arduino165/esp8266_common/Release/esp8266_common.elf" -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS) esp8266_common
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
