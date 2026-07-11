/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 River Games */

#include <LineKernel/syscall.h>
#include "LineCore/size_t.h"
#include "errno.h"

#define HANDLE_RETVAL() switch (retval) { \
	case -32: \
		errno = ENODRV; \
		return -1; \
	case -9: \
		errno = ENOENT; \
		return -1; \
	case -11: \
		errno = EUSED; \
		return -1; \
	case -5: \
		errno = EBADF; \
		return -1; \
	default: \
		errno = EIO; \
		return -1; \
}


int close(int fileno)
{
	int retval = syscall3(SYS_close, fileno, 0, 0);
	if (retval == 0) return 0;
	HANDLE_RETVAL()
}

int open(const char* filename)
{
	int retval = syscall3(SYS_open, (long)filename, 0, 0);
	if (retval > 0) return retval;
	HANDLE_RETVAL()
}

int rename(const char* oldpath, const char* newpath)
{
	int retval = syscall3(SYS_rename, (long)oldpath, (long)newpath, 0);
	if (retval == 0) return 0;
	HANDLE_RETVAL()
}

int makedir(const char* path)
{
	int retval = syscall3(SYS_makedir, (long)path, 0, 0);
	if (retval == 0) return 0;
	HANDLE_RETVAL()
}

int removedir(const char* path)
{
	int retval = syscall3(SYS_removedir, (long)path, 0, 0);
	if (retval == 0) return 0;
	HANDLE_RETVAL()
}

int removefile(const char* filename)
{
	int retval = syscall3(SYS_removedir, (long)filename, 0, 0);
	if (retval == 0) return 0;
	HANDLE_RETVAL()
}

int write(int fileno, const void* buf, size_t nbyte)
{
	int retval = syscall3(SYS_write, fileno, (long)buf, nbyte);
	if (retval == 0) return 0;
	HANDLE_RETVAL()
}
