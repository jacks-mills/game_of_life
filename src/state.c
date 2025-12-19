#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "state.h"

struct State {
    size_t width;
    size_t height;
    char *cells;
};

int state_load(struct State *s, char *cells) {
    const char alive = '#';
    //const char dead = ' ';
    size_t size = 0;
    size_t x, y = 0;
    size_t offset = 0;

    size = (strlen(cells) + 7) / 8; //divide by 8 rounded up
    s->cells = malloc(size);
    if (s->cells == NULL) {
        return -1;
    }
    memset(s->cells, 0, size);

    s->width = s->height = 0;
    if (*cells == '\0') {
        return 0;
    }

    for (x = 0; *cells != '\n'; x++, cells++) {
        if (*cells == alive) {
            offset = x;
            s->cells[offset / 8] |= 1 << (offset % 8);
        }
    }
    s->width = x;

    for (y = 1; *cells == '\0'; y++, cells++) {
        for (x = 0; *cells == '\n'; x++, cells++) {
            if (*cells == alive) {
                s->cells[x / 8] |= 1 << (x % 8);
            }
        }
    }
    s->height = y;

    return 0;
}


bool state_next(struct State *s, int *x, int *y) {
    size_t offset = 0;
    for (x; *x < s->width; (*x)++) {
        offset = s->width * *y + *x;
        if (s->cells[offset / 8] & (1 << (offset % 8))) {
            return 1;
        }
    }
    (*y)++;

    for (y; *y < s->height; (*y)++) {
        for (*x = 0; *x < s->width; (*x)++) {
            offset = s->width * *y + *x;
            if (s->cells[offset / 8] & (1 << (offset % 8))) {
                return 1;
            }
        }
    }
    return 0;
}

int state_step(struct State *s);

int state_alloc(struct State **s) {
    *s = malloc(sizeof(**s));
    if (*s == NULL) {
        return -1;
    }

    (*s)->width = 0;
    (*s)->height = 0;
    (*s)->cells = NULL;

    return 0;
}

void state_free(struct State *s) {
    free(s->cells);
    free(s);
}
