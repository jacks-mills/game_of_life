#ifndef _STATE_H
#define _STATE_H

#include <stdbool.h>

struct State;

int state_load(struct State *s, char *cells);
bool state_next(struct State *s, int *x, int *y);
int state_step(struct State *s);

int state_alloc(struct State **s);
void state_free(struct State *s);

#endif //_STATE_H
