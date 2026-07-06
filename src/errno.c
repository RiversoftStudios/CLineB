/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 River Games */

#include "LineCore/errnos.h"

int errno = 0;

char* strerror(int errnum)
{
    switch (errnum) {
        case EIO:
            return "I/O error";
        case ENOSYS:
            return "Function not implemented";
        case ENOENT:
            return "No such entry";
        default:
            return "???";
    }
}
