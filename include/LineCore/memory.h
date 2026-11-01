/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 Riversoft Studios */

#if !defined(_CLineB___LINECORE_MEMORY_H__)
#define _CLineB___LINECORE_MEMORY_H__

#if !defined(_CLineB__NEEDS)
#define _CLineB__NEEDS
#define _CLineB__NEEDS_MALLOC
#define _CLineB__NEEDS_FREE
#endif

#include <CLineB/decl.h>
#include <CLineB/compilers.h>
#include <LineCore/size_t.h>
_CLineB___BEGIN_DECL

#if defined(_CLineB__NEEDS_FREE)
void free(void* ptr);
#endif

#if defined(_CLineB__NEEDS_MALLOC)
void* malloc(size_t size) ATTRIBUTE_MALLOC(free, 1);
#endif

#undef _CLineB__NEEDS_MALLOC
#undef _CLineB__NEEDS_FREE
#undef _CLineB__NEEDS

#endif
