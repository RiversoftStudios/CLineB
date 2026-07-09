include arches/$(ARCH).mk

CC = $(CCPREFIX)gcc
AR = $(CCPREFIX)ar
CFLAGS ?= -O2
# even though we are using -std=gnu99, headers MUST be compatible with -std=c89
# $(LINEKERNEL_PATH) is required.
CFLAGS += -Wall -Wextra -std=gnu99 -ffreestanding -nostdlib -nostdinc -nostartfiles -I./include -I$(LINEKERNEL_PATH)/include -DARCH_$(ARCH)
OBJ = src/errno.o src/LineCore/console.o

# TODO: crt0.s
all: CLineB.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

CLineB.a: $(OBJ)
	$(AR) rcs $@ $(OBJ)

clean:
	rm -f $(OBJ)

.PHONY: all clean
