C_SOURCES = $(wildcard os/kernel/*.c os/drivers/*.c os/cpu/*.c os/libc/*.c)
HEADERS = $(wildcard os/kernel/*.h os/drivers/*.h os/cpu/*.h os/libc/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o os/cpu/interrupt.o} 

CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
GDB = /usr/local/i386elfgcc/bin/i386-elf-gdb
LD = /usr/local/i386elfgcc/bin/i386-elf-ld

CFLAGS = -g -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs \
		 -Wall -Wextra

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
	rm -rf bin/*.o bin/*.bin os/cpu/*.o *.o *.bin *.elf os/kernel/*.bin os/drivers/*.o drippleos.bin *.dis *.bin os/lib/*.o os/libc/*.o