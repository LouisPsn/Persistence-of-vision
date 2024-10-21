SCRIPT:= hall_blink

build : src/$(SCRIPT).c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/$(SCRIPT).elf src/$(SCRIPT).c
	avr-objcopy -O binary build/$(SCRIPT).elf build/$(SCRIPT).bin

install :
	avrdude -p atmega328p -c usbasp -P /dev/ttyACM0 -U flash:w:build/$(SCRIPT).bin