#include <ncurses.h>
#include <locale.h>
#include <errno.h>

#include "ui.h"


#define ALIVE   L"██"
#define DEAD    L"  "



WINDOW *base;
WINDOW *margin;
WINDOW *board;


int ui_init(int width, int height) {
    int ret = 0;

    if (width < 0 || height < 0) {
        return EINVAL;
    }

    if (NULL == setlocale(LC_ALL, "")) {
        return -1;
    }

    if (NULL == initscr()) {
        return -1;
    }

    noecho();
    curs_set(0); // invisible cursor

    if (2 * width - 2 > LINES) {
        width = (LINES - 2) / 2;
        ret = EDOM;
    }

    if (height - 2 > COLS) {
        height = COLS - 2;
        ret = EDOM;
    }

    base = derwin(stdscr, height + 2, 2 * width + 2, 0, COLS / 2 - width - 1);
    if (base == NULL) {
        return -1;
    }

    // margin variable exists if I later choose to grow base other things, like 
    // a message box
    margin = base;

    board = derwin(margin, height, 2 * width, 1, 1);
    if (board == NULL) {
        return -1;
    }

    box(margin, ACS_VLINE, ACS_HLINE);

    return ret;
}

void ui_cleanup(void) {
    endwin();
}

void ui_clear(void) {
    wclear(board);
}

int ui_set_alive(int x, int y) {
    if (ERR == mvwprintw(board, y, 2 * x, "%ls", ALIVE)) {
        return -1;
    }
    return 0;
}

// void ui_set_dead(int x, int y);

void ui_update(void) {
    wrefresh(margin);
    wrefresh(board);
}
