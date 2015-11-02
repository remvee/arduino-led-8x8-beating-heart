TARGET       = out
ARDUINO_PORT = /dev/ttyACM3

# Arduino One
MCU			= atmega328p
F_CPU			= 16000000
AVRDUDE_ARD_BAUDRATE	= 115200
AVRDUDE_ARD_PROGRAMMER	= arduino

# Ubuntu / Arch Linux
ARDUINO_DIR  = /usr/share/arduino
include /usr/share/arduino/Arduino.mk
