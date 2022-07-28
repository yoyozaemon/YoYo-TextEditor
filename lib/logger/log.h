#ifndef LOGGER_LIBRARY_H
#define LOGGER_LIBRARY_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <dirent.h>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <malloc.h>
#include <cerrno>
#include <cstdarg>
#include <cstdint>

#define LOG_FILE_NAME "yoyoeditorlog.txt"
#define INIT_MSG "LOG FILE CREATED FOR YOYO-TEXTEDITOR"

namespace Logger {
    void create_log_file();
    void append_log(char* date, char* input);
    bool check_log();
    char* time_now();
    char* formated_string(char* format, ...);
}

#endif //LOGGER_LIBRARY_H

