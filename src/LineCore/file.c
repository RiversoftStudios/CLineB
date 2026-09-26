/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 Riversoft Studios */

#include <LineKernel/syscall.h>
#include <LineKernel/contents_t.h>
#include "LineCore/size_t.h"
#include "LineCore/intptr_t.h"
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
	case 0: \
		return 0; \
	default: \
		errno = EIO; \
		return -1; \
}


int close(int fileno)
{
	int retval = syscall3(SYS_close, fileno, 0, 0);
	HANDLE_RETVAL()
}

int open(const char* filename)
{
	int retval = syscall3(SYS_open, (uintptr_t)filename, 0, 0);
	if (retval > 0) return retval;
	HANDLE_RETVAL()
}

int rename(const char* oldpath, const char* newpath)
{
	int retval = syscall3(SYS_rename, (uintptr_t)oldpath, (uintptr_t)newpath, 0);
	HANDLE_RETVAL()
}

int makedir(const char* path)
{
	int retval = syscall3(SYS_makedir, (uintptr_t)path, 0, 0);
	HANDLE_RETVAL()
}

int removedir(const char* path)
{
	int retval = syscall3(SYS_removedir, (uintptr_t)path, 0, 0);
	HANDLE_RETVAL()
}

int remove(const char* filename)
{
	int retval = syscall3(SYS_remove, (uintptr_t)filename, 0, 0);
	HANDLE_RETVAL()
}

size_t fsize(int fileno)
{
	return syscall3(SYS_size, fileno, 0, 0);
}

ssize_t write(int fileno, const void* buf, size_t nbyte)
{
	int retval = syscall3(SYS_write, fileno, (uintptr_t)buf, nbyte);
	/* From: "retval other Bytes written", "retval negative Unknown error" */
	if (retval >= 0) return retval;
	HANDLE_RETVAL()
}

ssize_t read(int fileno, void* buf, size_t count)
{
	int retval = syscall3(SYS_read, fileno, (uintptr_t)buf, count);
	/* From: "retval other Bytes read", "retval negative Unknown error" */
	if (retval >= 0) return retval;
	HANDLE_RETVAL()
}

int listdir(const char* path, contents_t* fcontents, size_t count)
{
	int retval = syscall3(SYS_list, (uintptr_t)path, (uintptr_t)fcontents, count);
	HANDLE_RETVAL()
}
