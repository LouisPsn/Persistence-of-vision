install :
	avrdude -p atmega328p -c usbasp -P /dev/ttyACM0 -U flash:w:build/main.bin


bluetooth : src/bluetooth.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -c -o build/bluetooth.o src/bluetooth.c

functions_hall : src/functions_hall.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_hall.o src/functions_hall.c

functions_horloge : src/functions_horloge.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_horloge.o src/functions_horloge.c

functions_print_letter : src/functions_print_letter.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_print_letter.o src/functions_print_letter.c

functions_print_word : src/functions_print_word.c functions_print_letter
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_print_word.o src/functions_print_word.c build/interrupt.o

functions_SPI_led : src/functions_SPI_led.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/functions_SPI_led.o src/functions_SPI_led.c

interrupt : src/interrupt.c
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -c -o build/interrupt.o src/interrupt.c

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

letter : src/letter.c functions_SPI_led functions_print_word interrupt 
	avr-gcc -mmcu=atmega328p -DF_CPU=13000000 -Os -o build/main.elf src/letter.c build/functions_print_word.o build/functions_SPI_led.o
	avr-objcopy -O binary build/main.elf build/main.bin
