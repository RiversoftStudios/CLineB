#include <errno.h>

char* strerror(int errnum)
{
    switch (errnum) {
        case EIO:
            return "I/O error";
        case ENOSYS:
            return "Function not implemented";
        default:
            return "???";
    }
}
