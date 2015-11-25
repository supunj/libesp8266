################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/EEPROM/EEPROM.cpp 

LINK_OBJ += \
./Libraries/EEPROM/EEPROM.cpp.o 

CPP_DEPS += \
./Libraries/EEPROM/EEPROM.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/EEPROM/EEPROM.cpp.o: /home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/EEPROM/EEPROM.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/sudiv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266mDNS" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer/src" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/EEPROM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


