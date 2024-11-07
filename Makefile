install :
	avrdude -p atmega328p -c usbasp -P /dev/ttyACM0 -U flash:w:build/main.bin


bluetooth : src/bluetooth.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -c -o build/bluetooth.elf src/bluetooth.c

functions_hall : src/Functions_in_c/functions_hall.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_hall.elf src/Functions_in_c/functions_hall.c

functions_horloge : src/Functions_in_c/functions_horloge.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_horloge.elf src/Functions_in_c/functions_horloge.c

functions_print_letter : src/Functions_in_c/functions_print_letter.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_print_letter.elf src/Functions_in_c/functions_print_letter.c

functions_print_word : src/Functions_in_c/functions_print_word.c functions_print_letter
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_print_word.elf src/Functions_in_c/functions_print_word.c

functions_SPI_led : src/Functions_in_c/functions_SPI_led.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_SPI_led.elf src/Functions_in_c/functions_SPI_led.c

interrupt : src/Functions_in_c/functions_interrupt_1.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/interrupt.elf src/Functions_in_c/functions_interrupt_1.c

led : src/led.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/led.c
	avr-objcopy -O binary build/main.elf build/main.bin

hall : src/hall.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/hall.c
	avr-objcopy -O binary build/main.elf build/main.bin

spi : src/SPI.c functions_SPI_led
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/SPI.c build/functions_SPI_led.elf
	avr-objcopy -O binary build/main.elf build/main.bin

horloge : src/horloge.c functions_SPI_led interrupt functions_horloge functions_hall
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/horloge.c build/functions_SPI_led.elf build/interrupt.elf build/functions_horloge.elf build/functions_hall.elf
	avr-objcopy -O binary build/main.elf build/main.bin

letter : src/letter.c functions_SPI_led functions_print_word interrupt
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/letter.c build/functions_print_word.elf build/functions_print_letter.elf build/functions_SPI_led.elf build/interrupt.elf
	avr-objcopy -O binary build/main.elf build/main.bin

clock : src/clock.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/clock.c
	avr-objcopy -O binary build/main.elf build/main.bin