avr = avr-gcc
dude = avrdude
obj = avr-objcopy
chip = atmega328p
freq = 13000000

install :
	$(dude) -p $(chip) -c usbasp -P /dev/ttyACM0 -U flash:w:build/main.bin

install_test :
	$(dude) -p $(chip) -c usbasp -P /dev/ttyACM0 -U flash:w:build/pov-demo.bin

bluetooth : src/c/bluetooth.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/bluetooth.elf src/c/bluetooth.c

clock : src/c/clock.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/clock.elf src/c/clock.c

hall : src/c/hall.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/hall.elf src/c/hall.c

old_letter : src/c/old_letter.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/old_letter.elf src/c/old_letter.c

word : src/c/word.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/word.elf src/c/word.c

buffer : src/c/buffer.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/buffer.elf src/c/buffer.c

display : src/c/display.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/display.elf src/c/display.c

SPI_led : src/c/SPI_led.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/SPI_led.elf src/c/SPI_led.c

interrupt : src/c/interrupt.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/interrupt.elf src/c/interrupt.c

digit : src/c/digit_horloge.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -c -o build/digit_horloge.elf src/c/digit_horloge.c

test_led : src/test_led.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_led.c
	$(obj) -O binary build/main.elf build/main.bin

test_hall : src/test_hall.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_hall.c
	$(obj) -O binary build/main.elf build/main.bin

test_spi : src/test_SPI.c SPI_led
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_SPI.c build/SPI_led.elf
	$(obj) -O binary build/main.elf build/main.bin

test_letter : src/test_letter.c SPI_led old_letter word interrupt
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_letter.c build/word.elf build/old_letter.elf build/SPI_led.elf build/interrupt.elf
	$(obj) -O binary build/main.elf build/main.bin

test_display : src/test_display.c SPI_led display interrupt buffer clock
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf build/SPI_led.elf src/test_display.c build/interrupt.elf build/buffer.elf build/display.elf build/clock.elf
	$(obj) -O binary build/main.elf build/main.bin

test_clock : src/test_clock.c
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_clock.c build/clock.elf build/bluetooth.elf
	$(obj) -O binary build/main.elf build/main.bin

test_digit : src/test_digit.c clock SPI_led interrupt bluetooth buffer clock interrupt display digit
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o build/main.elf src/test_digit.c build/digit_horloge.elf build/bluetooth.elf build/SPI_led.elf build/buffer.elf build/clock.elf build/interrupt.elf build/display.elf
	$(obj) -O binary build/main.elf build/main.bin

main : src/main.c clock SPI_led interrupt bluetooth buffer display digit word old_letter
	$(avr) -mmcu=$(chip) -DF_CPU=$(freq) -Os -o  build/main.elf src/main.c build/clock.elf build/SPI_led.elf build/interrupt.elf build/bluetooth.elf build/buffer.elf build/display.elf build/digit_horloge.elf build/word.elf build/old_letter.elf
	$(obj) -O binary build/main.elf build/main.bin