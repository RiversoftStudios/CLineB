/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 Riversoft Studios */

#if !defined(_LineCore___INTPTR_T_H__)
#define _LineCore___INTPTR_T_H__

#include <LineCore/size_t.h>

/* Assuming ILP32 and LP64 for now, since ELF follows this(?) */
typedef size_t uintptr_t;
typedef ssize_t intptr_t;

#endif
