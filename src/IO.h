#pragma once

#ifndef YOYO_SRC_IO_H
#define YOYO_SRC_IO_H

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <cstdarg>
#include <lib/logger/log.h>

#include "IO.h"
#include "Error.h"
#include "RawMode.h"
#include "Window.h"
#include "Row.h"
#include "File.h"

#define CTRL_KEY(k)((k)&0x1f)
#define INPUT_BUFFER_INIT \
{         \
    NULL,0     \
}

#define QUIT_TIMES 3
#define VERSION "0.0.2->Alpha"
#define BACKSPACE 127
#define ENTER 10

struct InputBuffer
{
    char *b;
    int len;
};

extern EditorConfig e;

class IO
{
    public:
    ~IO();
    static void editor_process_keypress();
    static void editor_refresh_screen();
    static void editor_draw_rows(struct InputBuffer *inputBuffer);
    static void append(struct InputBuffer *inputBuffer, const char *s, int len);
    static void free_input_buffer(struct InputBuffer *inputBuffer);
    static void editor_scroll();
    static void editor_draw_status_bar(struct InputBuffer *inputBuffer);
    static void editor_insert_char(int c);
    static void editor_delete_char();
    static void editor_insert_new_line();
    static char *editor_prompt(char *prompt, void(*callback)(char *, int));
    static void line_numbers(struct InputBuffer *inputBuffer,int lineNum);
    static void toogle_line_nums();
};
#endif // YOYO_SRC_IO_H