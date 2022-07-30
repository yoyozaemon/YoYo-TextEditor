#ifndef YOYO_SRC_WINDOW_H
#define YOYO_SRC_WINDOW_H

#include <unistd.h>
#include <sys/ioctl.h>
#include <cstdio>

#include "RawMode.h"
#include "IO.h"

extern EditorConfig e;

namespace Windows
{
    int get_window_size(int *rows, int *cols);
    int get_cursor_position(int *rows, int *cols);
    void move_cursor(int key);
    void move_cursor_end_line();
    void update_screen();
    void handle_change(int unused__attribute__((unused)));
}

#endif // YOYO_SRC_WINDOW_H

