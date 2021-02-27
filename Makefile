C_SOURCES = $(wildcard os/kernel/*.c os/drivers/*.c)
HEADERS = $(wildcard os/kernel/*.h os/drivers/*.h)
OBJ = ${C_SOURCES:.c=.o}

CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
GDB = /usr/local/i386elfgcc/bin/i386-elf-gdb
LD = /usr/local/i386elfgcc/bin/i386-elf-ld
CFLAGS = -g

drippleos.bin: bin/bootsect.bin bin/kernel.bin
	cat $^ > drippleos.bin

kernel.bin: bin/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ --oformat binary

# Debug
kernel.elf: bin/kernel_entry.o ${OBJ}
	i386-elf-ld -o $@ -Ttext 0x1000 $^ 

run: drippleos.bin
	qemu-system-i386 -fda drippleos.bin

debug: drippleos.bin bin/kernel.elf
	qemu-system-i386 -s -fda drippleos.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin bin/*.bin bin/*.o os/kernel/*.o os/drivers/*.o 