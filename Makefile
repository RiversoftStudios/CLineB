# SPDX-License-Identifier: GPL-3.0-or-later
# SPDX-FileCopyrightText: Copyright (C) 2026 Riversoft Studios

include arches/$(ARCH).mk

ifdef VERBOSE
	Q =
else
	Q = @
endif

ifdef LLVM
	CC = clang --target=$(ARCH_TARGET)
	AR = llvm-ar
else # GCC
	CC = $(ARCH_TARGET)-gcc
	AR = $(ARCH_TARGET)-ar
endif

CFLAGS ?= -O2
# $(LINEKERNEL_PATH) is required.
CFLAGS += -Wall -Wextra -Wpedantic -std=c89 -ffreestanding -nostdlib -nostdinc -I./include -I$(LINEKERNEL_PATH)/include -DARCH_$(ARCH)
OBJ = src/errno.o src/LineCore/console.o src/LineCore/file.o

# TODO: crt0.s
all: CLineB.a

%.o: %.c
	@echo "CC $< -> $@"
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

CLineB.a: $(OBJ)
	@echo "AR $(words $(filter %, $^)) objects -> $@"
	$(Q)$(AR) rcs $@ $(OBJ)

clean:
	rm -f $(OBJ) CLineB.a

.PHONY: all clean
