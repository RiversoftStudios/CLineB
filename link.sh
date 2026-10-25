#!/usr/bin/env bash
# SPDX-License-Identifier: CC0-1.0
# SPDX-FileCopyrightText: Copyright (C) 2026 Riversoft Studios
. arches/${ARCH}.sh
${ARCH_TARGET}-ld -nostartfiles -nostdlib ../TODO/crt0.o $1 ../TODO/CLineB.a -o $2
