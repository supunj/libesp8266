################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_cache.c \
/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_check.c \
/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_gc.c \
/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_hydrogen.c \
/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_nucleus.c 

C_DEPS += \
./arduino/spiffs_cache.c.d \
./arduino/spiffs_check.c.d \
./arduino/spiffs_gc.c.d \
./arduino/spiffs_hydrogen.c.d \
./arduino/spiffs_nucleus.c.d 

AR_OBJ += \
./arduino/spiffs_cache.c.o \
./arduino/spiffs_check.c.o \
./arduino/spiffs_gc.c.o \
./arduino/spiffs_hydrogen.c.o \
./arduino/spiffs_nucleus.c.o 


# Each subdirectory must supply rules for building sources it contributes
arduino/spiffs_cache.c.o: /home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_cache.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sudiv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266mDNS" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer/src" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/EEPROM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/spiffs_check.c.o: /home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_check.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sudiv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266mDNS" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer/src" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/EEPROM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/spiffs_gc.c.o: /home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_gc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sudiv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266mDNS" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer/src" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/EEPROM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/spiffs_hydrogen.c.o: /home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_hydrogen.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sudiv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266mDNS" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer/src" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/EEPROM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/spiffs_nucleus.c.o: /home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266/spiffs/spiffs_nucleus.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/sudiv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/esp8266" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266mDNS" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WebServer/src" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson" -I"/home/sudiv/opt/arduino-1.6.5-r5/libraries/ArduinoJson/src" -I"/home/sudiv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/EEPROM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


