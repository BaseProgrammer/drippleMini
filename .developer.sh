# Exports
export gcc=/usr/local/i386elfgcc/bin/i386-elf-gcc
export ld=/usr/local/i386elfgcc/bin/i386-elf-ld

# Convert "kernel.c" to an O bin file
sudo ${gcc} -ffreestanding -c os/kernel/kernel.c -o bin/kernel.o

# Convert "kernel_entry.asm" to an O bin file
nasm os/kernel_entry.asm -f elf -o bin/kernel_entry.o

# Convert "bootsect.asm" to a bin file
nasm os/bootsect.asm -f bin -o bin/bootsect.bin

# Linker the files into a bin file
sudo ${ld} -o kernel.bin -Ttext 0x1000 --oformat binary bin/kernel_entry.o bin/kernel.o bin/ports.o bin/screen.o




cd bin/
cat bin/bootsect.bin bin/kernel.bin > drippleos.bin
mv drippleos.bin ../
cd ../
qemu-system-i386 -fda drippleos.bin