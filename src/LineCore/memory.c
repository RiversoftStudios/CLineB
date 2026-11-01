/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 Riversoft Studios */

#include <LineKernel/syscall.h>
#include <LineKernel/contents_t.h>
#include "LineCore/size_t.h"
#include "LineCore/intptr_t.h"

void free(void* ptr)
{
	syscall3(SYS_free, (uintptr_t)ptr, 0, 0);
}

void* malloc(size_t size)
{
	uintptr_t retval = syscall3(SYS_alloc, size, 0, 0);
	return (void*)retval;
}
