/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 River Games */

#if !defined(_CLineB___ERRNO_H__)
#define _CLineB___ERRNO_H__

#include <LineCore/errnos.h>

#include <CLineB/decl.h>
_CLineB___BEGIN_DECL

char* strerror(int errnum);

_CLineB___END_DECL

#endif
