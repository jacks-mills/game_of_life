#ifndef _CONSOLE_CODES_H
#define _CONSOLE_CODES_H


#define MOVE_UP                         "\033[%iA"
#define MOVE_DOWN                       "\033[%iB"
#define MOVE_RIGHT                      "\033[%iC"
#define MOVE_LEFT                       "\033[%iD"

#define JUMP                            "\033[%i;%iH" // row;col
#define JUMP_ORIGIN                     "\033[H"
#define CLEAR                           "\033[H\033[J"
#define ERASE_LINE_RIGHT                "\033[K"

#define CURSOR_SAVE_POSITION            "\033[s"
#define CURSOR_RESTORE_POSITION         "\033[u"

#define TEXT_RESET                      "\033[m"
#define TEXT_BOLD                       "\033[1m"
#define TEXT_BOLD_UNSET                 "\033[22m"

#define TEXT_COLOUR_FG_BLACK            "\033[30m"
#define TEXT_COLOUR_FG_RED              "\033[31m"
#define TEXT_COLOUR_FG_GREEN            "\033[32m"
#define TEXT_COLOUR_FG_BROWN            "\033[33m"
#define TEXT_COLOUR_FG_BLUE             "\033[34m"
#define TEXT_COLOUR_FG_MAGENTA          "\033[35m"
#define TEXT_COLOUR_FG_CYAN             "\033[36m"
#define TEXT_COLOUR_FG_WHITE            "\033[37m"

#define TEXT_COLOUR_FG_BRIGHT_BLACK     "\033[90m"
#define TEXT_COLOUR_FG_BRIGHT_RED       "\033[91m"
#define TEXT_COLOUR_FG_BRIGHT_GREEN     "\033[92m"
#define TEXT_COLOUR_FG_BRIGHT_BROWN     "\033[93m"
#define TEXT_COLOUR_FG_BRIGHT_BLUE      "\033[94m"
#define TEXT_COLOUR_FG_BRIGHT_MAGENTA   "\033[95m"
#define TEXT_COLOUR_FG_BRIGHT_CYAN      "\033[96m"
#define TEXT_COLOUR_FG_BRIGHT_WHITE     "\033[97m"

#define TEXT_COLOUR_FG_256              "\033[38;5;%im"
#define TEXT_COLOUR_FG_24_BIT           "\033[38;2;%i;%i;%im" //r;g;b
#define TEXT_COLOUR_FG_RESET            "\033[39m"


#endif //_CONSOLE_CODES_H
