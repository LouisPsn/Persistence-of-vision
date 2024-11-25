avr = avr-gcc
dude = avrdude
obj = avr-objcopy
chip = atmega328p
freq = 13000000

install :
	$(dude) -p $(chip) -c usbasp -P /dev/ttyACM0 -U flash:w:build/main.bin

bluetooth : src/c/bluetooth.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/bluetooth.elf src/c/bluetooth.c

clock : src/c/clock.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/clock.elf src/c/clock.c

hall : src/c/hall.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/hall.elf src/c/hall.c

horloge : src/c/horloge.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/horloge.elf src/c/horloge.c

old_letter : src/c/old_letter.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/old_letter.elf src/c/old_letter.c

word : src/c/word.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/word.elf src/c/word.c

buffer : src/c/buffer.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/buffer.elf src/c/buffer.c

new_word : src/c/new_word.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/new_word.elf src/c/new_word.c

SPI_led : src/c/SPI_led.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/SPI_led.elf src/c/SPI_led.c

interrupt : src/c/interrupt.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/interrupt.elf src/c/interrupt.c

test_led : src/test_led.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_led.c
	$(obj) -O binary build/main.elf build/main.bin

test_hall : src/test_hall.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_hall.c
	$(obj) -O binary build/main.elf build/main.bin

test_spi : src/test_SPI.c SPI_led
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_SPI.c build/SPI_led.elf
	$(obj) -O binary build/main.elf build/main.bin

test_horloge : src/test_horloge.c SPI_led interrupt horloge hall clock
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_horloge.c build/SPI_led.elf build/interrupt.elf build/horloge.elf build/hall.elf build/clock.elf
	$(obj) -O binary build/main.elf build/main.bin

test_letter : src/test_letter.c SPI_led old_letter word interrupt
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_letter.c build/word.elf build/old_letter.elf build/SPI_led.elf build/interrupt.elf
	$(obj) -O binary build/main.elf build/main.bin

test_new_word : src/test_new_word.c SPI_led new_word interrupt buffer
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf build/SPI_led.elf src/test_new_word.c build/interrupt.elf build/buffer.elf build/new_word.elf
	$(obj) -O binary build/main.elf build/main.bin

test_clock : src/test_clock.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_clock.c
	$(obj) -O binary build/main.elf build/main.bin