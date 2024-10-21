all:main


main:src/main.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o main.elf src/main.c
	avr-objcopy -O binary main.elf main.bin


install:main.bin
	avrdude -p atmega328p -c usbasp -P /dev/ttyACM0 -U flash:w:main.bin

clean:
	rm -f *.elf *.bin
