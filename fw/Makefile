MCU = attiny25
# change hfuse to 0x5D to disable reset pin
FUSES = -U lfuse:w:0xD2:m -U hfuse:w:0xDD:m -U efuse:w:0xFF:m -U lock:w:0xFF:m
F_CPU = 8000000
FORMAT = ihex
BUILDDIR = build
TARGET = $(BUILDDIR)/nv-h5b
OBJDIR = obj
SRC = $(wildcard src/*.c)
OPT = s
CSTANDARD = c99
DEBUG = dwarf-2

CDEFS = -DF_CPU=$(F_CPU)UL

CFLAGS = -g$(DEBUG)
CFLAGS += $(CDEFS)
CFLAGS += -O$(OPT)
CFLAGS += -Wall
CFLAGS += -pedantic
CFLAGS += -Wa,-adhlns=$(<:%.c=$(OBJDIR)/%.lst)
CFLAGS += -std=$(CSTANDARD)

LDFLAGS = -Wl,-Map=$(TARGET).map,--cref,-section-start=.fwversion=0x7E0

#---------------- Programming Options (avrdude) ----------------

AVRDUDE_PROGRAMMER = stk500
AVRDUDE_PORT = /dev/ttyUSB0
AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex
AVRDUDE_FLAGS = -p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER)

#============================================================================

# Define programs and commands.
CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size
AR = avr-ar rcs
NM = avr-nm
AVRDUDE = avrdude
REMOVE = rm -f
REMOVEDIR = rm -rf
COPY = cp


# Define Messages
# English
MSG_SIZE_BEFORE = Size before:
MSG_SIZE_AFTER = Size after:
MSG_FLASH = Creating load file for Flash:
MSG_EEPROM = Creating load file for EEPROM:
MSG_EXTENDED_LISTING = Creating Extended Listing:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = Linking:
MSG_COMPILING = Compiling C:

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
LST = $(SRC:%.c=$(OBJDIR)/%.lst)
GENDEPFLAGS = -MMD -MP -MF .dep/$(@F).d

ALL_CFLAGS = -mmcu=$(MCU) -I. $(CFLAGS) $(GENDEPFLAGS)

all: sizebefore build sizeafter
build: elf hex eep lss sym

elf: $(TARGET).elf
hex: $(TARGET).hex
eep: $(TARGET).eep
lss: $(TARGET).lss
sym: $(TARGET).sym

HEXSIZE = $(SIZE) --target=$(FORMAT) $(TARGET).hex
ELFSIZE = $(SIZE) --mcu=$(MCU) --format=avr $(TARGET).elf

sizebefore:
	@if test -f $(TARGET).elf; then echo; echo $(MSG_SIZE_BEFORE); $(ELFSIZE); \
	2>/dev/null; echo; fi

sizeafter:
	@if test -f $(TARGET).elf; then echo; echo $(MSG_SIZE_AFTER); $(ELFSIZE); \
	2>/dev/null; echo; fi

program: $(TARGET).hex $(TARGET).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH)

fuses:
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(FUSES)

program_minipro:
	minipro -p $(MCU) -w $(TARGET).hex
	minipro -p $(MCU) -c config -w fuses.conf

$(BUILDDIR)/%.hex: $(BUILDDIR)/%.elf
	@echo
	@echo $(MSG_FLASH) $@
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@

$(BUILDDIR)/%.eep: $(BUILDDIR)/%.elf
	@echo
	@echo $(MSG_EEPROM) $@
	-$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 --no-change-warnings -O $(FORMAT) $< $@ || exit 0

$(BUILDDIR)/%.lss: $(BUILDDIR)/%.elf
	@echo
	@echo $(MSG_EXTENDED_LISTING) $@
	$(OBJDUMP) -h -S $< > $@

$(BUILDDIR)/%.sym: $(BUILDDIR)/%.elf
	@echo
	@echo $(MSG_SYMBOL_TABLE) $@
	$(NM) -n $< > $@

.SECONDARY : $(TARGET).elf
.PRECIOUS : $(OBJ)
%.elf: $(OBJ)
	@echo
	@echo $(MSG_LINKING) $@
	$(CC) $(ALL_CFLAGS) $^ --output $@ $(LDFLAGS)

$(OBJDIR)/%.o : %.c
	@echo
	@echo $(MSG_COMPILING) $<
	$(CC) -c $(ALL_CFLAGS) $< -o $@

clean:
	$(REMOVEDIR) $(BUILDDIR)
	$(REMOVEDIR) $(OBJDIR)
	$(REMOVEDIR) .dep

$(shell mkdir -p $(dir $(OBJ)) 2>/dev/null)
$(shell mkdir -p $(dir $(TARGET)) 2>/dev/null)

-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

.PHONY : all sizebefore sizeafter build elf hex eep lss sym clean program fuses
