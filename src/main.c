#include <sys/select.h>
#include <stdio.h>
#include "board.h"
#include "ui.h"

#define INITIAL_BOARD \
    "                         \n" \
    "   #                     \n" \
    " # #                     \n" \
    "  ##                     \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \
    "                         \n" \

int main(int argc, char **argv) {

    struct Board *board = NULL;
    struct UI *ui = NULL;

    board_alloc(&board);
    board_load(board, INITIAL_BOARD);

    ui_alloc(&ui);
    ui_init(ui, 25, 25);

    while (1) {
        ui_set_dead_all(ui);
        ui_update(ui);

        int x = -1, y = 0;
        while (board_next_alive(board, &x, &y)) {
            ui_set_alive(ui, x, y);
        }
        ui_update(ui);
        fflush(stdout);
        board_step(board);
        select(0, NULL, NULL, NULL, &((struct timeval) {.tv_sec = 0, .tv_usec = 250000}));
    }

    board_free(board);
    ui_free(ui);

    return 0;
}
