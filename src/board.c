#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"

struct Board {
    size_t width;
    size_t height;
    char *cells;
};

int board_load(struct Board *s, char *cells);
bool board_next(struct Board *s, int *x, int *y);
int board_step(struct Board *s);
int board_alloc(struct Board **s);
void board_free(struct Board *s);
