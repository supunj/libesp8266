#!/bin/bash

export ESP_ROOT=$HOME/esp8266

DEV_BASE=$(dirname $(readlink -f "$0"))
echo "Development base - "$DEV_BASE

# use 0.4.5 as 0.4.5+ seems to be broken
export ESP_TOOL=$DEV_BASE/esptool/0.4.5/esptool

git clone https://github.com/esp8266/Arduino.git $ESP_ROOT
cd $ESP_ROOT/tools
python get.py

# use 2.0.0 version
git checkout 2.0.0

cd $DEV_BASE

make -f libesp8266.mk clean
make -f libesp8266.mk upload
