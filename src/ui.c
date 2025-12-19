#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "state.h"
#include "ui.h"

#define BOX_HOR "─"
#define BOX_VER "│"
#define BOX_CTL "┌"
#define BOX_CTR "┐"
#define BOX_CBL "└"
#define BOX_CBR "┘"

#define SCALE_WIDTH 3
#define SCALE_HEIGHT 1

#define ALIVE "█"

#define CC_SAVE_CURSOR_LOCATION "\x1b[s"
#define CC_RESTORE_CURSOR_LOCATION "\x1b[u"

#define CC_MOVE_CURSOR_DOWN "\x1b[%iB"
#define CC_MOVE_CURSOR_RIGHT "\x1b[%iC"
#define CC_MOVE_CURSOR_LEFT "\x1b[%iD"

struct UI {
    size_t screenWidth;
    size_t screenHeight;
    size_t width;
    size_t height;
};

struct UI ui;

static void draw(struct UI *ui, struct State *s) {
    size_t x, y, xCell, yCell = 0;

    printf("%s", BOX_CTL);
    for (size_t i = 0; i < ui->screenWidth; i++) {
        printf("%s", BOX_HOR);
    }
    printf("%s\n", BOX_CTR);

    for (y = 0; ;) {
        printf("%s", BOX_VER);
        for (x = 0; ;) {
            if (y == yCell && x == xCell) {

            }
        }
        printf("%s\n", BOX_VER);
    }


    printf("%s", BOX_CBL);
    for (size_t i = 0; i < ui->screenWidth; i++) {
        printf("%s", BOX_HOR);
    }
    printf("%s\n", BOX_CBR);
}

static void draw_empty(struct UI *ui) {
    printf("%s", BOX_CTL);
    for (size_t i = 0; i < ui->screenWidth; i++) {
        printf("%s", BOX_HOR);
    }
    printf("%s\n", BOX_CTR);

    for (size_t i = 0; i < ui->screenHeight; i++) {
        printf("%s%*s%s\n", BOX_VER, (int) ui->screenWidth, "", BOX_VER);
    }

    printf("%s", BOX_CBL);
    for (size_t i = 0; i < ui->screenWidth; i++) {
        printf("%s", BOX_HOR);
    }
    printf("%s\n", BOX_CBR);
}

void ui_init(size_t width, size_t height) {
    ui.width = width;
    ui.height = height;
    ui.screenWidth = SCALE_WIDTH * width;
    ui.screenHeight = SCALE_HEIGHT * height;

    draw_empty(&ui);
}

void ui_update(struct State *s) {
    draw(&ui, s);
}
