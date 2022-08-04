#ifndef YOYO_SRC_FILE_H
#define YOYO_SRC_FILE_H

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>

#include "RawMode.h"
#include "Error.h"
#include "Row.h"
#include "IO.h"

namespace Syntax
{
    void editor_update_syntax(erow* row);
    int editor_syntax_color(int hl);
    int is_separator(int c);
    void editor_select_syntax_highlight();
}

namespace File
{
    void editor_open(char* filename);
    char* editor_rows_to_string(int* buflen);
    void save();
    void search();
    void editor_find_callback(char* query,int key);
}

#endif // YOYO_SRC_FILE_H
