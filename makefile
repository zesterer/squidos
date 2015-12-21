COMPONENT_DIR=src

BUILD_DIR=$(PWD)/build
export BUILD_DIR

GRUB_CFG=$(COMPONENT_DIR)/grub.cfg

SQUIDOS_BIN=$(BUILD_DIR)/squidos.bin
SQUIDOS_ISO=$(BUILD_DIR)/squidos.iso

.PHONY: all clean run kernel grub setup

default: all

all: setup kernel grub

clean:
	test -d $(BUILD_DIR) || rm -r $(BUILD_DIR)/**

setup:
	test -d $(BUILD_DIR) || mkdir $(BUILD_DIR)

kernel: setup
	$(MAKE) -C $(COMPONENT_DIR)

grub: kernel
	mkdir -p $(BUILD_DIR)/isodir/boot/grub/
	cp ${SQUIDOS_BIN} $(BUILD_DIR)/isodir/boot/squidos.bin
	cp ${GRUB_CFG} $(BUILD_DIR)/isodir/boot/grub/grub.cfg
	grub2-mkrescue -o $(SQUIDOS_ISO) $(BUILD_DIR)/isodir
	@echo "Created bootable ISO"

run:
	qemu-system-i386 -cdrom ${SQUIDOS_ISO}
