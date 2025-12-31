#ifndef _BOARD_H
#define _BOARD_H

#include <stdbool.h>

struct Board;

int  board_alloc(struct Board **b);
void board_free(struct Board *b);

int  board_load(struct Board *b, char *cells);
//int  board_load_from_file(struct Board *b, char *cells);

bool board_next_alive(struct Board *b, int *x, int *y);
void board_step(struct Board *b);


#endif //_BOARD_H
