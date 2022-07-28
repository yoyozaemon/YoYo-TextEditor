#include<RawMode.h>
#include<IO.h>
#include<File.h>
#include<lib/logger/log.h>

int main(int argc, char* argv){
    RawMode::enable();
    RawMode::init();
    if(argc >= 2){
        File::editor_open(argv[1]);
    }

    RawMode::editor_set_status_message("Input CTRL-H for help");
    if(!Logger::check_log())
    {
        Logger::create_log_file();
        RawMode::editor_set_status_message("Log file created");
    }
    IO io=IO();
    refresh();
    while(1)
    {
        io.editor_refresh_screen();
        io.editor_process_keypress();       
    }
}