C_COMPILER=i686-elf-gcc
CXX_COMPILER=i686-elf-g++
OBJCOPY=i686-elf-objcopy

BOOT_S="src/boot.s"
BOOT_O="build/boot.o"

KERNEL_C="src/kernel.c"
KERNEL_O="build/kernel.o"

LINKER_LD="src/linker.ld"

GRUB_CFG="src/grub.cfg"

SQUIDOS_ELF="build/squidos.elf"

SQUIDOS_BIN="build/squidos.bin"

SQUIDOS_ISO="build/squidos.iso"

default: all

clean:
	rm ${BOOT_O} ${KERNEL_O} ${SQUIDOS_ELF} ${SQUIDOS_BIN}

all:
	${C_COMPILER} -fpic -ffreestanding -c ${BOOT_S} -o ${BOOT_O}
	@echo "Compiled BOOT_S"
	${C_COMPILER} -fpic -ffreestanding -std=gnu99 -c ${KERNEL_C} -o ${KERNEL_O} -O2 -Wall -Wextra
	@echo "Compiled KERNEL_C"
	${C_COMPILER} -T ${LINKER_LD} -o ${SQUIDOS_BIN} -ffreestanding -O2 -nostdlib ${BOOT_O} ${KERNEL_O} -lgcc
	@#${OBJCOPY} ${SQUIDOS_ELF} -O binary ${SQUIDOS_BIN}
	@echo "Linked KERNEL_C & BOOT_S"
	mkdir -p build/isodir/boot/grub
	cp ${SQUIDOS_BIN} build/isodir/boot/squidos.bin
	cp ${GRUB_CFG} build/isodir/boot/grub/grub.cfg
	grub2-mkrescue -o ${SQUIDOS_ISO} build/isodir
	@echo "Created bootable ISO"

run:
	qemu-system-i386 -cdrom ${SQUIDOS_ISO}
