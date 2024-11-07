avr = avr-gcc
dude = avrdude
obj = avr-objcopy
chip = atmega328p
freq = 13000000

install :
	$(dude) -p $(chip) -c usbasp -P /dev/ttyACM0 -U flash:w:build/main.bin

bluetooth : src/bluetooth.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -c -o build/bluetooth.elf src/bluetooth.c

hall : src/c/hall.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/hall.elf src/c/hall.c

horloge : src/c/horloge.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/horloge.elf src/c/horloge.c

print_letter : src/c/print_letter.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/print_letter.elf src/c/print_letter.c

print_word : src/c/print_word.c print_letter
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/print_word.elf src/c/print_word.c

SPI_led : src/c/SPI_led.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/SPI_led.elf src/c/SPI_led.c

interrupt : src/c/interrupt_1.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/interrupt.elf src/c/interrupt_1.c

led : src/led.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/led.c
	$(obj) -O binary build/main.elf build/main.bin

hall : src/hall.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/hall.c
	$(obj) -O binary build/main.elf build/main.bin

spi : src/SPI.c SPI_led
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/SPI.c build/SPI_led.elf
	$(obj) -O binary build/main.elf build/main.bin

horloge : src/horloge.c SPI_led interrupt horloge hall
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/horloge.c build/SPI_led.elf build/interrupt.elf build/horloge.elf build/hall.elf
	$(obj) -O binary build/main.elf build/main.bin

letter : src/letter.c SPI_led print_word interrupt
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/letter.c build/print_word.elf build/print_letter.elf build/SPI_led.elf build/interrupt.elf
	$(obj) -O binary build/main.elf build/main.bin

clock : src/clock.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/clock.c
	$(obj) -O binary build/main.elf build/main.bin