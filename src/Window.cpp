#include "Window.h"

void Window::handle_change(int unused)
{
    update_screen();
    if(e.cy > e.screenrows)
    e.cy = e.screenrows - 1;
    if(e.cx < e.screencols)
    e.cx = e.screencols - 1;
    IO::editor_refresh_screen();
    refresh();
}

void Window::update_screen()
{
    if(Window::get_window_size(&e.screenrows,&e.screencols)==-1)
    Error::die("getWindowSize failed");
    e.screenrows-=2;
}

int Window::get_cursor_position(int *rows, int *cols)
{
    char buf[32];
    unsigned int i = 0;
    if(write(STDOUT_FILENO,"\x1b[6n",4)!=4)
    return -1;
    while(i < sizeof(buf)-1)
    {
        if(read(STDIN_FILENO, &buf[i],1)!=1)
        break;
        if(buf[i]=='R')
        break;
        i++;
    }
    buf[i]='\0';
    if(buf[0]! = '\x1b' || buff[1]! = '[')
    return -1;
    if(sscanf(&buf[2],"%d;%d",rows,cols)!=2)
    return -1;
    return 0;
}

int Window::get_window_size(int *rows, int *cols)
{
    struct winsize ws;
    if(ioctl(STDOUT_FILENO, TIOCGWIN, &ws)==-1 || ws.ws_cols == 0)
    {
        if(write(STDOUT_FILENO,"\x1b[999C\x1b[999B",12)!=12)
        return -1;
        return get_cursor_position(rows,cols);
    }
    else
    {
        *cols = ws.ws_col;
        *rows = ws.ws_row;
        return 0;
    }
}

void Window::move_cursor_end_line()
{
    e.cx = e.row[e.cy].size;
}

void Window::move_cursor(int key)
{
    erow *row = (e.cy >= e.num_rows)?NULL:&e.row[e.cy];

    swtich(key)
    {
        case KEY_LEFT:
        if(e.cx!=0)
        {
            e.cx--;
        }
        else if(e.cy > 0)
        {
            e.cy--;
            e.cx = e.row[e.cy].size;
        } 
        break;
    }
}