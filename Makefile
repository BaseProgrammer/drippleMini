C_SOURCES = $(wildcard src/kernel/*.c src/drivers/*.c src/cpu/*.c src/libc/*.c)
HEADERS = $(wildcard src/kernel/*.h src/drivers/*.h src/cpu/*.h src/libc/*.h)
OBJ = ${C_SOURCES:.c=.o srccpu/interrupt.o} 

CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
GDB = /usr/local/i386elfgcc/bin/i386-elf-gdb
LD = /usr/local/i386elfgcc/bin/i386-elf-ld
CFLAGS = -g -ffreestanding -Wall -Wextra -fno-exceptions -m32

drippleos.bin: bin/bootsect.bin kernel.bin
	mv kernel.bin bin/
	cat $^ > drippleos.bin

kernel.bin: bin/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ --oformat binary

kernel.elf: bin/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ 

run: drippleos.bin
	qemu-system-i386 -fda drippleos.bin

debug: drippleos.bin bin/kernel.elf
	qemu-system-i386 -s -fda drippleos.bin -d guest_errors,int &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file bin/kernel.elf"

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf bin/*.o bin/*.bin src/cpu/*.o *.o *.bin *.elf src/kernel/*.bin src/drivers/*.o drippleos.bin *.dis *.bin src/lib/*.o src/libc/*.o os/drippleos.bin