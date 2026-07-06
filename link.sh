#!/usr/bin/env bash
. arches/${ARCH}.sh
${CCPREFIX}ld -nostdlib ../TODO/crt0.o $1 ../TODO/CLineB.a -o $2
