#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "board.h"

#define ALIVE   '#'
#define DEAD    ' '

struct Board {
    int width;
    int height;

    char *front;
    char *back;
};

int board_alloc(struct Board **b) {
    *b = malloc(sizeof(struct Board));
    if (*b == NULL) {
        return -1;
    }
    memset(*b, 0, sizeof(struct Board));
    return 0;
}

void board_free(struct Board *b) {
    free(b->front);
    free(b->back);
    free(b);
}

int board_load(struct Board *b, char *cells) {
    { // extract width and height information
        b->width = 0;
        for (char *cursor = cells; *cursor != '\n'; cursor++) {
            b->width++;
        }

        b->height = strlen(cells) / (b->width + 1); // b->width + 1 due to newline character

        if (b->width * b->height == 0) {
            b->front = NULL;
            return 0;
        }
    }

    { // extract cell information
        size_t boardSpace = sizeof(*b->front) * b->width * b->height;
        b->front = malloc(boardSpace);
        b->back = malloc(boardSpace);
        if (b->front == NULL || b->back == NULL) {
            free(b->front);
            free(b->back);
            return -1;
        }
        memset(b->front, DEAD, boardSpace);

        int i = 0;
        while (*cells != '\0'){
            if (*cells == '\n') {
                cells++;
                continue;
            }

            if (*cells != ' ') {
               b->front[i] = ALIVE;
            }

            i++;
            cells++;
        }
    }

    return 0;
}

bool board_next_alive(struct Board *b, int *x, int *y) {
    int i = b->width * *y + *x + 1;
    if (*x < 0 || *y < 0) {
        i = 0;
    }

    while (i < b->width * b->height) {
        if (b->front[i] == ALIVE) {
            *y = i / b->width;
            *x = i % b->width;
            return true;
        }
        i++;
    }
    return false;
}

int board_step(struct Board *b) {
    int offsets[8] = {-b->width -1, -b->width, -b->width + 1, -1, 1, b->width -1, b->width, b->width + 1};
    for (int i = 0; i < b->width * b->height; i++) {
        int neighbours = 0;
        for (int j = 0; j < sizeof(offsets)/sizeof(*offsets); j++) {
            int k = offsets[j] + i;

            if (k < 0 || k >= b->width * b->height) {
                continue;
            }

            if (b->front[k] == DEAD) {
                continue;
            }

            neighbours++;
        }

        bool aliveCondition = neighbours == 3 || (neighbours == 2 && b->front[i] == ALIVE);
        b->back[i] = aliveCondition ? ALIVE : DEAD;
    }

    char *tmp = b->front;
    b->front = b->back;
    b->back = tmp;

    return 1;
}

void board_print(struct Board *b) {
    printf("width: %i\n", b->width);
    printf("height: %i\n", b->height);

    {
        int labelLength = 0;
        labelLength = printf("cells: [");

        if (b->width * b->height != 0) {
            printf("%c", b->front[0] == ALIVE ? ALIVE : '_');
        }

        for (int i = 1; i < b->width * b->height; i++) {
            if (i % b->width == 0) {
                printf("\n%*s", labelLength, "");
            }
            printf("%c", b->front[i] == ALIVE ? ALIVE : '_');
        }

        printf("]\n");
    }

}
