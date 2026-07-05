/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 River Games */

#if !defined(_CLineB___LINECORE_CONSOLE_H__)
#define _CLineB___LINECORE_CONSOLE_H__

#if !defined(_CLineB__NEEDS)
#define _CLineB__NEEDS
#define _CLineB__NEEDS_WRITESTRING
#define _CLineB__NEEDS_GETCHAR
#define _CLineB__NEEDS_TERMCOLOR
#define _CLineB__NEEDS_TERMSCOLOR
#define _CLineB__NEEDS_TERMCLEAR
#define _CLineB__NEEDS_TERMCURSOR
#endif

#include <CLineB/decl.h>
_CLineB___BEGIN_DECL

#if defined(_CLineB__NEEDS_WRITESTRING)
int writestring(char* array);
#endif

#if defined(_CLineB__NEEDS_TERMCOLOR)
#include <LineKernel/linecolor_t.h>
int termcolor(linecolor_t fg_color, linecolor_t bg_color);
#endif

#if defined(_CLineB__NEEDS_TERMSCOLOR)
int termscolor(void);
#endif

#if defined(_CLineB__NEEDS_TERMCLEAR)
int termclear(void);
#endif

#if defined(_CLineB__NEEDS_TERMCURSOR)
int termcursor(int x, int y);
#endif

#if defined(_CLineB__NEEDS_GETCHAR)
int getchar(void);
#endif

_CLineB___END_DECL

#undef _CLineB__NEEDS_WRITESTRING
#undef _CLineB__NEEDS_GETCHAR
#undef _CLineB__NEEDS_TERMCOLOR
#undef _CLineB__NEEDS_TERMSCOLOR
#undef _CLineB__NEEDS_TERMCLEAR
#undef _CLineB__NEEDS_TERMCURSOR
#undef _CLineB__NEEDS

#endif
