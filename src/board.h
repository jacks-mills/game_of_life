#ifndef _BOARD_H
#define _BOARD_H

#include <stdbool.h>

struct Board;

int board_alloc(struct Board **s);
void board_free(struct Board *s);

int board_load(struct Board *s, char *cells);

bool board_next_alive(struct Board *s, int *x, int *y);
int board_step(struct Board *s);


#endif //_BOARD_H
