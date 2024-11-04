install :
	avrdude -p atmega328p -c usbasp -P /dev/ttyACM0 -U flash:w:build/main.bin

led : src/led.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/led.c
	avr-objcopy -O binary build/main.elf build/main.bin

hall : src/hall.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/hall.c
	avr-objcopy -O binary build/main.elf build/main.bin

spi : src/SPI.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/SPI.c
	avr-objcopy -O binary build/main.elf build/main.bin

horloge : src/horloge.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/horloge.c
	avr-objcopy -O binary build/main.elf build/main.bin

letter : src/letter.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/letter.c
	avr-objcopy -O binary build/main.elf build/main.bin
