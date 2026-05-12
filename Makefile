TARGET  = firmware
CC      = riscv64-elf-gcc
OBJCOPY = riscv64-elf-objcopy

# Added -I. to tell the compiler to look in the current directory for your .h file
CFLAGS  = -march=rv32ec -mabi=ilp32e -Os -nostdlib -nostartfiles -I.
LDFLAGS = -T linker.ld

# Added utils.c to the source and objects
SRC     = startup.s main.c utils.c
OBJ     = startup.o main.o utils.o

all: $(TARGET).elf $(TARGET).bin

startup.o: startup.s
	$(CC) $(CFLAGS) -c startup.s -o startup.o

# Update the variable to point to the actual file
HDR = register_map.h

# ... other variables ...

# Update the rules to use $(HDR)
main.o: main.c $(HDR)
	$(CC) $(CFLAGS) -c main.c -o main.o

utils.o: utils.c $(HDR)
	$(CC) $(CFLAGS) -c utils.c -o utils.o

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(TARGET).elf

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

# ... rest of your script (flash, clean) ...
clean:
	rm -f *.o firmware.elf firmware.bin
