#ifndef YOYO_SRC_ERROR_H
#define YOYO_SRC_ERROR_H

#include <cerrno>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <lib/logger/log.h>

namespace ErrorHandler
{
    void die(const char* s);
}

#endif // YOYO_SRC_ERROR_H