/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 NexusSfan */

#ifndef _CLineB___LINECORE_CONSOLE_H__
#define _CLineB___LINECORE_CONSOLE_H__

#ifndef _CLineB__NEEDS
#define _CLineB__NEEDS
#define _CLineB__NEEDS_WRITESTRING
#define _CLineB__NEEDS_GETCHAR
#define _CLineB__NEEDS_TERMCOLOR
#define _CLineB__NEEDS_TERMSCOLOR
#define _CLineB__NEEDS_TERMCLEAR
#define _CLineB__NEEDS_TERMCURSOR
#endif

#ifdef _CLineB__NEEDS_WRITESTRING
int writestring(char* array);
#endif

#ifdef _CLineB__NEEDS_TERMCOLOR
#include <LineKernel/linecolor_t.h>
int termcolor(linecolor_t fg_color, linecolor_t bg_color);
#endif

#ifdef _CLineB__NEEDS_TERMSCOLOR
int termscolor(void);
#endif

#ifdef _CLineB__NEEDS_TERMCLEAR
int termclear(void);
#endif

#ifdef _CLineB__NEEDS_TERMCURSOR
int termcursor(int x, int y);
#endif

#ifdef _CLineB__NEEDS_GETCHAR
int getchar(void);
#endif

#undef _CLineB__NEEDS_WRITESTRING
#undef _CLineB__NEEDS_GETCHAR
#undef _CLineB__NEEDS_TERMCOLOR
#undef _CLineB__NEEDS_TERMSCOLOR
#undef _CLineB__NEEDS_TERMCLEAR
#undef _CLineB__NEEDS_TERMCURSOR
#undef _CLineB__NEEDS

#endif
