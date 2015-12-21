COMPONENT_SUB_DIRS=src

C_COMPILER=i686-elf-gcc
CXX_COMPILER=i686-elf-g++
OBJCOPY=i686-elf-objcopy

BOOT_S="boot.s"
BOOT_O="$(BUILD_DIR)/boot.o"

SRC_FILES := $(wildcard *.cpp)
#OBJ_FILES=$(patsubst %.c,%.o,$(wildcard *.c))

TERMINAL_C="terminal.cpp"
TERMINAL_O="$(BUILD_DIR)/terminal.o"

LINKER_LD="linker.ld"

SQUIDOS_ELF="$(BUILD_DIR)/squidos.elf"
SQUIDOS_BIN="$(BUILD_DIR)/squidos.bin"

.PHONY: all kernel

default: all

all: bootstrap kernel link

bootstrap:
	${CXX_COMPILER} -fpic -ffreestanding -c ${BOOT_S} -o ${BOOT_O}
	@echo "Compiled BOOT_S"

kernel: $(patsubst %.cpp,%.o,$(SRC_FILES))
%.o: %.cpp
	${CXX_COMPILER} -fpic -ffreestanding -std=c++11 -c $< -o $@ -O2 -Wall -Wextra
	@echo "Compiled KERNEL_C and TERMINAL_C"
	
	@#${OBJCOPY} ${SQUIDOS_ELF} -O binary ${SQUIDOS_BIN}
	@#echo "Object-copied ELF into BIN"

link: $(SRC_FILES:%.cpp=%.o)
	${CXX_COMPILER} -T ${LINKER_LD} -o ${SQUIDOS_BIN} -ffreestanding -O2 -nostdlib ${BOOT_O} $^ -lgcc
	@echo "Linked KERNEL_C & BOOT_S"
