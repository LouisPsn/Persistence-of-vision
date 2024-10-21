install :
	avrdude -p atmega328p -c usbasp -P /dev/ttyACM0 -U flash:w:build/main.bin

main : src/main.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/main.c
	avr-objcopy -O binary build/main.elf build/main.bin


bluetooth: src/bluetooth.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/bluetooth.c
	avr-objcopy -O binary build/main.elf build/main.bin
