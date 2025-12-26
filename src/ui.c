#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "console_codes.h"
#include "ui.h"


//y/x == 2.5, therefore x axis needs to be 2.5 times wider

#define X_TO_Y_SCALE        2

#define FULL               "██"
#define EMPTY              "  "

#define BOX_HORI "─"
#define BOX_VERT "│"
#define BOX_TOPL "┌"
#define BOX_TOPR "┐"
#define BOX_BOTL "└"
#define BOX_BOTR "┘"

#define ALIVE   '#'
#define DEAD    ' '


struct UI {
    int width;
    int height;

    bool rendered;

    char *alive;
};


int ui_alloc(struct UI **ui) {
    *ui = malloc(sizeof(**ui));
    if (*ui == NULL) {
        return -1;
    }
    return 0;
}

void ui_free(struct UI *ui) {
    free(ui->alive);
    free(ui);
}

void ui_init(struct UI *ui, int width, int height) {
    ui->width = width; 
    ui->height = height;
    ui->rendered = false;
    ui->alive = malloc(sizeof(*ui->alive) * width * height);
    if (ui->alive == NULL) {
        return; // oopy
    }
    memset(ui->alive, DEAD, sizeof(*ui->alive) * width * height);
}

void ui_set_dead_all(struct UI *ui) {
    memset(ui->alive, DEAD, sizeof(*ui->alive) * ui->width * ui->height);
}

void ui_set_alive(struct UI *ui, int x, int y) {
    ui->alive[y * ui->width + x] = ALIVE;
}

static void draw_border(struct UI *ui) {
    int horizontalLength = ui->width * X_TO_Y_SCALE;
    int verticalLength = ui->height;

    printf(BOX_TOPL);
    for (int i = 0; i < horizontalLength; i++) {
        printf(BOX_HORI);
    }
    printf("%s\n", BOX_TOPR);

    for (int i = 0; i < verticalLength; i++) {
        printf(BOX_VERT);
        if (horizontalLength > 0) {
            printf(MOVE_RIGHT, horizontalLength);
        }
        printf("%s\n", BOX_VERT);
    }

    printf(BOX_BOTL);
    for (int i = 0; i < horizontalLength; i++) {
        printf(BOX_HORI);
    }
    printf("%s\n", BOX_BOTR);

}

void ui_update(struct UI *ui) {
    if (!ui->rendered) {
       printf(CLEAR);
       draw_border(ui); 
       ui->rendered = true;
    }

    printf(MOVE_UP, ui->height + 1);
    printf(MOVE_RIGHT, 1);

    if (ui->width * ui->height != 0) {
        printf("%s", (ui->alive[0] == ALIVE) ? FULL : EMPTY);
    }

    for (int i = 1; i < ui->width * ui->height; i++) {
        if (i % ui->width == 0) {
            printf(MOVE_LEFT, ui->width * X_TO_Y_SCALE);
            printf(MOVE_DOWN, 1);
        }
        printf("%s", (ui->alive[i] == ALIVE) ? FULL : EMPTY);
    }
    printf(MOVE_LEFT, ui->width * X_TO_Y_SCALE + 1); 
    printf(MOVE_DOWN, 2);
    fflush(stdout);
}
