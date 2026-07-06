#!/usr/bin/env bash
. arches/${ARCH}.sh
${CCPREFIX}ld -nostdlib ../libc/crt0.o hello.o ../libc/libc.a -o hello.elf
