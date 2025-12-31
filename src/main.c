#include <stdlib.h>
#include <poll.h>
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

    int ret = 0;
    struct Board *board = NULL;

    ret = board_alloc(&board);
    if (ret) {
        goto exit;
    }
    ret = board_load(board, INITIAL_BOARD);
    if (ret) {
        goto exit;
    }

    ret = ui_init(25, 25);
    if (ret) {
        goto exit;
    }

    while (1) {
        ui_clear();
        int x = -1, y = -1;
        while (board_next_alive(board, &x, &y)) {
            ui_set_alive(x, y);
        }

        board_step(board);
        ui_update();
        poll(NULL, 0, 250);
    }


exit:
    ui_cleanup();
    board_free(board);

    return ret;
}
